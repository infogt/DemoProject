use strict;
use warnings;
use XML::LibXML;
use XML::XPath;
use XML::LibXML::Reader;
use List::MoreUtils qw(uniq);

#------------------------------------------------------------
# Global variables used in the script
#------------------------------------------------------------

# Specify the XML file
my $file = "C:/RubensFolder/WorkArea/EA_WS/05_WorkingCopy/XML/Workingcopy.xml";

# Specify the template file
my $fileTemplate = "test_Led4.cppt";

# Specify output folder
my $dirOutput = "output";

my @LightModuleStates;
my $LightModuleNumOfStates;
my @LightModuleMethods;
my $LightModuleNumOfMethods;
my @LightModuleTransitions;
my $LightModuleNumOfTransitions;
my @LightModuleMethodCalls;
my $LightModuleNumOfMethodCalls;
my %LightModuleNewState;
my %LightModuleMethodCall_InitToSUT;
my $Method_ReadCurrentState = "GetCurrentState";
my $Method_ValidNewState = "";
my $Method_TestCode_IniSt_To_StUnderTest = "";
my $Method_TestCode_CallMethod = "";
	
#------------------------------------------------------------

# Read the files
my $parser = XML::LibXML->new( );
my $doc = $parser->parse_file( $file );

open(TEMPLATE, $fileTemplate) or die "Could not open file '$fileTemplate' $!";
my @templateLines = <TEMPLATE>;
close(TEMPLATE);

my $xpc = XML::LibXML::XPathContext->new($doc);

# List the states in the state diagram
my @nodelist = $xpc->findnodes('//UML:CompositeState.substate/UML:SimpleState', $doc);
foreach my $node (@nodelist) 
{
	my $value = $node->findvalue('./@name');
	push @LightModuleStates, $value;
}
@LightModuleStates = sort @LightModuleStates;
$LightModuleNumOfStates = @LightModuleStates;

# List the methods in the eap file
my @nodelist2 = $xpc->findnodes('//UML:ModelElement.stereotype/UML:Stereotype[@name="method"]', $doc);
foreach my $context (@nodelist2) 
{
	my $xp = XML::XPath->new( context => $context );
	my $parent = $context->getParentNode->getParentNode;
	my $value = $parent->findvalue('./@name');
	push @LightModuleMethods, $value;
}
$LightModuleNumOfMethods = @LightModuleMethods;

# List the transitions in the eap file
my @nodelist3 = $xpc->findnodes('//UML:StateMachine.transitions/UML:Transition/UML:ModelElement.taggedValue', $doc);
foreach my $context (@nodelist3) 
{
	my $xp = XML::XPath->new( context => $context );
	my $srcState = $context->findvalue('./UML:TaggedValue[@tag="ea_sourceName"]/@value');
	my $desState = $context->findvalue('./UML:TaggedValue[@tag="ea_targetName"]/@value');
	
	my $trig = $context->getParentNode->findvalue('./UML:Transition.trigger/UML:Event/@name');
	
	my $TransInfo = "$srcState" . "\t\t-> " . "$desState" . "\t\t: " . "$trig";
	push @LightModuleTransitions, $TransInfo;
}
$LightModuleNumOfTransitions = @LightModuleTransitions;

# List of all method calls
my @nodelist4 = $xpc->findnodes('//UML:StateMachine.transitions/UML:Transition/UML:ModelElement.taggedValue/UML:TaggedValue[@tag="TestData"]', $doc);
foreach my $context (@nodelist4) 
{
	my $xp = XML::XPath->new( context => $context );
	#my $srcState = $context->findvalue('./UML:TaggedValue[@tag="ea_sourceName"]/@value');
	#my $desState = $context->findvalue('./UML:TaggedValue[@tag="ea_targetName"]/@value');

	#print "\n", $context;
	
	push @LightModuleMethodCalls, $context->findvalue('./@value');
}
@LightModuleMethodCalls = uniq (sort @LightModuleMethodCalls);
$LightModuleNumOfMethodCalls = @LightModuleMethodCalls;	
	
# List of expected new states
foreach my $srcState (@LightModuleStates)
{
	foreach my $methodCall (@LightModuleMethodCalls)
	{
		my @nodelist5 = $xpc->findnodes(qq(//UML:StateMachine.transitions/UML:Transition/UML:ModelElement.taggedValue/UML:TaggedValue[\@tag = "TestData"][\@value = "$methodCall"]), $doc);
		
		foreach my $context (@nodelist5) 
		{
			#my $xp = XML::XPath->new( context => $context );
			if ( $context->findvalue('../UML:TaggedValue[@tag = "ea_sourceName"]/@value') eq $srcState )
			{
				my $newState = $context->findvalue('../UML:TaggedValue[@tag = "ea_targetName"]/@value');
				$LightModuleNewState{$srcState}{$methodCall} = $newState;
			}
		}
	}
}

# Methods to calls to reach the state under test
foreach my $srcState (@LightModuleStates)
{
	my @nodelist6 = $xpc->findnodes( qq(//UML:CompositeState.substate/UML:SimpleState[\@name = "$srcState"]), $doc );
	foreach my $node (@nodelist6) 
	{

		my $value = $node->findvalue('./@xmi.id');
				
		my @nodelist7 =	$xpc->findnodes( qq(//UML:TaggedValue[\@tag="TestData_InitToSUT"][\@modelElement="$value"]), $doc );
		foreach my $nodetemp (@nodelist7)
		{
			my $methodcall2 = $nodetemp->findvalue( './@value' );
			$LightModuleMethodCall_InitToSUT{$srcState} = $methodcall2;
		}
	}
}

# Generate the output file
my $datetime = localtime();

foreach my $state (@LightModuleStates) 
{
   	$Method_ValidNewState .= 
		"\n\t/* New states expected when methods are called in state $state */" .
		"\n\t{";

	foreach my $methodCall (@LightModuleMethodCalls) 
    {
      	$Method_ValidNewState .= 
			"\n\t\t$LightModuleNewState{$state}{$methodCall}, //Method $methodCall";
    }

   	$Method_ValidNewState .= 
		"\n\t}," .
		"\n";  
}

foreach my $state (@LightModuleStates) 
{
	my $temp = "/* No method call needed */";
	$temp = $LightModuleMethodCall_InitToSUT{$state} if(exists $LightModuleMethodCall_InitToSUT{$state});
	$Method_TestCode_IniSt_To_StUnderTest .= 
		"\n\t\t/* Transition from Initial State to $state */" .
		"\n\t\tcase $state:" .
		"\n\t\t\t$temp" .
		"\n\t\t\tbreak;" .
		"\n";		
}

my $caseNr = 0;
foreach my $methodCall (@LightModuleMethodCalls) 
{
	$Method_TestCode_CallMethod .=
		"\n\t\tcase $caseNr:" .
		"\n\t\t\t$methodCall" .
		"\n\t\t\tbreak;" .
		"\n";	
		
	$caseNr++;	
}

foreach(@templateLines)
{
	$_ =~ s/<DATETIME>/$datetime/g;
	$_ =~ s/<NUM_OF_STATES>/$LightModuleNumOfStates/g;
	$_ =~ s/<NUM_OF_METHODS>/$LightModuleNumOfMethods/g;
	$_ =~ s/<METHOD_GET_CURRENT_STATE>/$Method_ReadCurrentState/g;
	$_ =~ s/<METHOD_ValidNewState>/$Method_ValidNewState/g;
	$_ =~ s/<METHOD_TestCode_IniSt_To_StUnderTest>/$Method_TestCode_IniSt_To_StUnderTest/g;
	$_ =~ s/<METHOD_TestCode_CallMethod>/$Method_TestCode_CallMethod/g;	
}

mkdir "$dirOutput" unless(-d $dirOutput) or die "Unable to create directory $dirOutput\n";

my $fileOutput = substr($fileTemplate, 0, -1);
open(FILE, ">$dirOutput/$fileOutput") or die "Could not create file '$fileOutput' $!";
foreach(@templateLines)
{
	print FILE $_;
}
close(FILE);

# Debug data
=begin debugdata

print "\nTotal number of states = $LightModuleNumOfStates";
foreach my $state (@LightModuleStates) 
{
	print "\n", $state;

}
print "\n\n\n";



print "\nTotal number of methods = $LightModuleNumOfMethods";
foreach my $method (@LightModuleMethods) 
{
	print "\n", $method;

}
print "\n";

print "\nTotal number of transitions = $LightModuleNumOfTransitions";
print "\nSource state \t-> Destination state \t: Trigger function call";
foreach my $trans (@LightModuleTransitions) 
{
	print "\n", $trans;

}
print "\n";




print "\nTotal number of method calls = $LightModuleNumOfMethodCalls";
foreach my $methodCall (@LightModuleMethodCalls) 
{
	print "\n", $methodCall;

}
print "\n\n\n";




print "\nCurrent State - Method call : New State";
foreach my $state (sort keys %LightModuleNewState) 
{
    foreach my $methodcall (keys %{ $LightModuleNewState{$state} }) 
    {
        print "\n$state - $methodcall : $LightModuleNewState{$state}{$methodcall}";
    }
}

print "\n\n\n";



print "\nMethod Calls for Init state to State under test:";
foreach my $state (keys %LightModuleMethodCall_InitToSUT) 
{
	print "\n$state: $LightModuleMethodCall_InitToSUT{$state}";
}

=end debugdata
=cut

=begin comment


=end debugdata
=cut



=begin comment

use strict;
use warnings;
use XML::LibXML;

# Specify the XML file
my $file = "C:/RubensFolder/WorkArea/EA_WS/05_WorkingCopy/XML/Workingcopy.xml";

my $parser = XML::LibXML->new( );
my $doc = $parser->parse_file( $file );

my $root = $doc->getDocumentElement;   # this contains the complete document

purge_nselems( $root );
print $doc->toString;


sub purge_nselems {
  my $elem = shift;
  
  return unless( ref( $elem ) =~ /Element/ );
  if( $elem->prefix ) {
    my $parent = $elem->parentNode;
    $parent->removeChild( $elem );
  } elsif( $elem->hasChildNodes ) {
    my @children = $elem->getChildnodes;
    foreach my $child ( @children ) {
      &purge_nselems( $child );
    }
  }
}

=end comment
=cut


=begin comment

use strict;
use warnings;
use XML::XPath;

# Specify the XML file
my $file = "C:/RubensFolder/WorkArea/EA_WS/05_WorkingCopy/XML/Workingcopy.xml";

# Read the XML file
my $path = XML::XPath->new(filename => $file);

#Using absolute addressing to read the names of the states
print "\nAbsolute addressing to read the names of the states ";
print "\nUML: Simple States";
my $statenames = $path->find('/XMI/XMI.content/UML:Model/UML:Namespace.ownedElement/UML:Package/UML:Namespace.ownedElement/UML:ActivityModel/UML:StateMachine.top/UML:CompositeState/UML:CompositeState.substate/UML:SimpleState/@name');
foreach my $node ($statenames->get_nodelist) 
{
    print "\n", XML::XPath::XMLParser::as_string($node);
}

# Read the names of states by finding all states. Notice the // at the beginning of the path
print "\n\nUse // at the beginning of the path to read the names of the states ";
print "\nUML: Simple States";
my $nodeset = $path->find('//UML:CompositeState.substate/UML:SimpleState/@name'); # find all authors
foreach my $node ($nodeset->get_nodelist) 
{
    print "\n", XML::XPath::XMLParser::as_string($node); 
} 
=end comment
=cut
