// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/07 14:26)

#include "CullStateTesting.h"
#include "Rendering/Shaders/CullState.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CullStateTesting) 

void Rendering::CullStateTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::CullStateTesting
	::InitTest()
{
	CullState firstCullState;

	ASSERT_TRUE(firstCullState.IsEnabled());
	ASSERT_TRUE(firstCullState.IsCCWOrder());

	firstCullState.SetEnabled(false);
	ASSERT_FALSE(firstCullState.IsEnabled());

	firstCullState.SetCCWOrder(false);
	ASSERT_FALSE(firstCullState.IsCCWOrder());
}

void Rendering::CullStateTesting
	::CopyTest()
{ 
	CullState firstCullState;	

	firstCullState.SetEnabled(false);
	firstCullState.SetCCWOrder(false);

	CullState secondCullState(firstCullState);

	ASSERT_EQUAL(firstCullState.IsEnabled(), secondCullState.IsEnabled());
	ASSERT_EQUAL(firstCullState.IsCCWOrder(), secondCullState.IsCCWOrder());

	firstCullState.SetCCWOrder(true);

	ASSERT_UNEQUAL(firstCullState.IsCCWOrder(), secondCullState.IsCCWOrder());
}

void Rendering::CullStateTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;
// 
// 	CullStateSharedPtr firstCullState(new CullState);
// 
// 	firstCullState->SetEnabled(false);
// 	firstCullState->SetCCWOrder(false);
// 
// 	outTopLevel.Insert(firstCullState);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
// 
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
// 
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	CullStateSharedPtr secondCullState =	inTopLevel[0].PolymorphicDowncastObjectSharedPtr<CullStateSharedPtr>();
// 
// 	ASSERT_EQUAL(firstCullState->IsEnabled(), secondCullState->IsEnabled());
// 	ASSERT_EQUAL(firstCullState->IsCCWOrder(), secondCullState->IsCCWOrder());

}
