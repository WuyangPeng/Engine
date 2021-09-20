// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/07 14:29)

#include "OffsetStateTesting.h"
#include "Rendering/Shaders/OffsetState.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, OffsetStateTesting) 

void Rendering::OffsetStateTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::OffsetStateTesting
	::InitTest()
{
	OffsetState firstOffsetState;

	ASSERT_FALSE(firstOffsetState.IsFillEnabled());
	ASSERT_FALSE(firstOffsetState.IsLineEnabled());
	ASSERT_FALSE(firstOffsetState.IsPointEnabled());
	ASSERT_APPROXIMATE(firstOffsetState.GetScale(), 0.0f, 1e-8f);
	ASSERT_APPROXIMATE(firstOffsetState.GetBias(), 0.0f, 1e-8f);

	firstOffsetState.SetFillEnabled(true);
	ASSERT_TRUE(firstOffsetState.IsFillEnabled());

	firstOffsetState.SetLineEnabled(true);
	ASSERT_TRUE(firstOffsetState.IsLineEnabled());

	firstOffsetState.SetPointEnabled(true);
	ASSERT_TRUE(firstOffsetState.IsPointEnabled());

	firstOffsetState.SetScale(1.5f);
	ASSERT_APPROXIMATE(firstOffsetState.GetScale(), 1.5f, 1e-8f);

	firstOffsetState.SetBias(1.6f);
	ASSERT_APPROXIMATE(firstOffsetState.GetBias(), 1.6f, 1e-8f);
}

void Rendering::OffsetStateTesting
	::CopyTest()
{ 
	OffsetState firstOffsetState;

	firstOffsetState.SetFillEnabled(true);
	firstOffsetState.SetLineEnabled(true);
	firstOffsetState.SetPointEnabled(true);
	firstOffsetState.SetScale(1.5f);
	firstOffsetState.SetBias(1.6f);

	OffsetState secondOffsetState(firstOffsetState);

	ASSERT_EQUAL(firstOffsetState.IsFillEnabled(), secondOffsetState.IsFillEnabled());
	ASSERT_EQUAL(firstOffsetState.IsLineEnabled(), secondOffsetState.IsLineEnabled());
	ASSERT_EQUAL(firstOffsetState.IsPointEnabled(), secondOffsetState.IsPointEnabled());
	ASSERT_APPROXIMATE(firstOffsetState.GetScale(), secondOffsetState.GetScale(), 1e-8f);
	ASSERT_APPROXIMATE(firstOffsetState.GetBias(), secondOffsetState.GetBias(), 1e-8f);

	secondOffsetState.SetScale(2.5f);
	ASSERT_APPROXIMATE(firstOffsetState.GetScale(), 1.5f, 1e-8f);
	ASSERT_APPROXIMATE(secondOffsetState.GetScale(), 2.5f, 1e-8f);
}

void Rendering::OffsetStateTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;	 
// 
// 	OffsetStateSharedPtr firstOffsetState(new OffsetState);
// 
// 	firstOffsetState->SetFillEnabled(true);
// 	firstOffsetState->SetLineEnabled(true);
// 	firstOffsetState->SetPointEnabled(true);
// 	firstOffsetState->SetScale(1.5f);
// 	firstOffsetState->SetBias(1.6f);
// 
// 	outTopLevel.Insert(firstOffsetState);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
// 
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
// 
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	OffsetStateSharedPtr secondOffsetState =	inTopLevel[0].PolymorphicDowncastObjectSharedPtr<OffsetStateSharedPtr>();
// 
// 	ASSERT_EQUAL(firstOffsetState->IsFillEnabled(), secondOffsetState->IsFillEnabled());
// 	ASSERT_EQUAL(firstOffsetState->IsLineEnabled(), secondOffsetState->IsLineEnabled());
// 	ASSERT_EQUAL(firstOffsetState->IsPointEnabled(), secondOffsetState->IsPointEnabled());
// 	ASSERT_APPROXIMATE(firstOffsetState->GetScale(), secondOffsetState->GetScale(), 1e-8f);
// 	ASSERT_APPROXIMATE(firstOffsetState->GetBias(), secondOffsetState->GetBias(), 1e-8f);
}
