// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/07 14:36)

#include "StencilStateTesting.h"
#include "Rendering/Shaders/StencilState.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, StencilStateTesting)
#include SYSTEM_WARNING_DISABLE(26440) 

void Rendering::StencilStateTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::StencilStateTesting
	::InitTest()
{
	StencilState firstStencilState;

	ASSERT_FALSE(firstStencilState.IsEnabled());
	ASSERT_ENUM_EQUAL(firstStencilState.GetCompare(), StencilStateFlags::CompareMode::Never);
	ASSERT_EQUAL(firstStencilState.GetReference(),0u);
	ASSERT_EQUAL(firstStencilState.GetMask(),0xFFFFFFFF);
	ASSERT_EQUAL(firstStencilState.GetWriteMask(), 0xFFFFFFFF);
	ASSERT_ENUM_EQUAL(firstStencilState.GetOnFail(), StencilStateFlags::OperationType::Keep);
	ASSERT_ENUM_EQUAL(firstStencilState.GetOnZFail(), StencilStateFlags::OperationType::Keep);
	ASSERT_ENUM_EQUAL(firstStencilState.GetOnZPass(), StencilStateFlags::OperationType::Keep);

	firstStencilState.SetEnabled(true);
	ASSERT_TRUE(firstStencilState.IsEnabled());

	firstStencilState.SetCompare(StencilStateFlags::CompareMode::Greater);
	ASSERT_ENUM_EQUAL(firstStencilState.GetCompare(), StencilStateFlags::CompareMode::Greater);

	firstStencilState.SetReference(5);
	ASSERT_EQUAL(firstStencilState.GetReference(), 5u);

	firstStencilState.SetMask(0xFFFEEFFE);
	ASSERT_EQUAL(firstStencilState.GetMask(), 0xFFFEEFFE);

	firstStencilState.SetWriteMask(0xFDFEEFFE);
	ASSERT_EQUAL(firstStencilState.GetWriteMask(), 0xFDFEEFFE);

	firstStencilState.SetOnFail(StencilStateFlags::OperationType::Invert);
	ASSERT_ENUM_EQUAL(firstStencilState.GetOnFail(), StencilStateFlags::OperationType::Invert);
	
	firstStencilState.SetOnZFail(StencilStateFlags::OperationType::Increment);
	ASSERT_ENUM_EQUAL(firstStencilState.GetOnZFail(), StencilStateFlags::OperationType::Increment);

	firstStencilState.SetOnZPass(StencilStateFlags::OperationType::Zero);
	ASSERT_ENUM_EQUAL(firstStencilState.GetOnZPass(), StencilStateFlags::OperationType::Zero);

}

void Rendering::StencilStateTesting
	::CopyTest()
{ 
	StencilState firstStencilState;

	firstStencilState.SetEnabled(true);
	firstStencilState.SetCompare(StencilStateFlags::CompareMode::Greater);
	firstStencilState.SetReference(5);
	firstStencilState.SetMask(0xFFFEEFFE);
	firstStencilState.SetWriteMask(0xFDFEEFFE);
	firstStencilState.SetOnFail(StencilStateFlags::OperationType::Invert);
	firstStencilState.SetOnZFail(StencilStateFlags::OperationType::Increment);
	firstStencilState.SetOnZPass(StencilStateFlags::OperationType::Zero);

	StencilState secondStencilState(firstStencilState);

	ASSERT_EQUAL(firstStencilState.IsEnabled(), secondStencilState.IsEnabled());
	ASSERT_ENUM_EQUAL(firstStencilState.GetCompare(), secondStencilState.GetCompare());
	ASSERT_EQUAL(firstStencilState.GetReference(), secondStencilState.GetReference());
	ASSERT_EQUAL(firstStencilState.GetMask(), secondStencilState.GetMask());
	ASSERT_EQUAL(firstStencilState.GetWriteMask(), secondStencilState.GetWriteMask());
	ASSERT_ENUM_EQUAL(firstStencilState.GetOnFail(), secondStencilState.GetOnFail());
	ASSERT_ENUM_EQUAL(firstStencilState.GetOnZFail(), secondStencilState.GetOnZFail());
	ASSERT_ENUM_EQUAL(firstStencilState.GetOnZPass(), secondStencilState.GetOnZPass());
	
	firstStencilState.SetOnZFail(StencilStateFlags::OperationType::Invert);

	ASSERT_ENUM_EQUAL(firstStencilState.GetOnZFail(), StencilStateFlags::OperationType::Invert);
	ASSERT_ENUM_EQUAL(secondStencilState.GetOnZFail(), StencilStateFlags::OperationType::Increment);
}

void Rendering::StencilStateTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;	 
// 
// 	StencilStateSharedPtr firstStencilState(new StencilState);
// 
// 	firstStencilState->SetEnabled(true);
// 	firstStencilState->SetCompare(StencilStateFlags::CompareMode::Greater);
// 	firstStencilState->SetReference(5);
// 	firstStencilState->SetMask(0xFFFEEFFE);
// 	firstStencilState->SetWriteMask(0xFDFEEFFE);
// 	firstStencilState->SetOnFail(StencilStateFlags::OperationType::Invert);
// 	firstStencilState->SetOnZFail(StencilStateFlags::OperationType::Increment);
// 	firstStencilState->SetOnZPass(StencilStateFlags::OperationType::Zero);
// 
// 	outTopLevel.Insert(firstStencilState);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
// 
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
// 
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	StencilStateSharedPtr secondStencilState = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<StencilStateSharedPtr>();
// 
// 	ASSERT_EQUAL(firstStencilState->IsEnabled(), secondStencilState->IsEnabled());
// 	ASSERT_ENUM_EQUAL(firstStencilState->GetCompare(), secondStencilState->GetCompare());
// 	ASSERT_EQUAL(firstStencilState->GetReference(), secondStencilState->GetReference());
// 	ASSERT_EQUAL(firstStencilState->GetMask(), secondStencilState->GetMask());
// 	ASSERT_EQUAL(firstStencilState->GetWriteMask(), secondStencilState->GetWriteMask());
// 	ASSERT_ENUM_EQUAL(firstStencilState->GetOnFail(), secondStencilState->GetOnFail());
// 	ASSERT_ENUM_EQUAL(firstStencilState->GetOnZFail(), secondStencilState->GetOnZFail());
// 	ASSERT_ENUM_EQUAL(firstStencilState->GetOnZPass(), secondStencilState->GetOnZPass());
}
