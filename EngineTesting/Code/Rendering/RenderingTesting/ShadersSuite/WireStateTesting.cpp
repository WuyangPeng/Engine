// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/07 14:39)

#include "WireStateTesting.h"
#include "Rendering/Shaders/WireState.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, WireStateTesting) 

void Rendering::WireStateTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::WireStateTesting
	::InitTest()
{
	WireState firstWireState;

	ASSERT_FALSE(firstWireState.IsEnabled()); 

	firstWireState.SetEnabled(true);
	ASSERT_TRUE(firstWireState.IsEnabled()); 

}

void Rendering::WireStateTesting
	::CopyTest()
{ 
	WireState firstWireState;

	firstWireState.SetEnabled(true);

	WireState secondWireState(firstWireState);

	ASSERT_EQUAL(firstWireState.IsEnabled(), secondWireState.IsEnabled()); 
	
	firstWireState.SetEnabled(false);

	ASSERT_UNEQUAL(firstWireState.IsEnabled(), secondWireState.IsEnabled()); 
}

void Rendering::WireStateTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;	 
// 
// 	WireStateSharedPtr firstWireState(new WireState);
// 
// 	firstWireState->SetEnabled(true); 
// 
// 	outTopLevel.Insert(firstWireState);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
// 
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
// 
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	WireStateSharedPtr secondWireState =	inTopLevel[0].PolymorphicDowncastObjectSharedPtr<WireStateSharedPtr>();

/*	ASSERT_EQUAL(firstWireState->IsEnabled(), secondWireState->IsEnabled()); */
}
