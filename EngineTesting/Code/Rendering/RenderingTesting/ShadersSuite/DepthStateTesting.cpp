// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/07 14:26)

#include "DepthStateTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Shaders/DepthState.h"

#include SYSTEM_WARNING_DISABLE(26440)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, DepthStateTesting)

void Rendering::DepthStateTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::DepthStateTesting::InitTest()
{
    DepthState firstDepthState;

    ASSERT_TRUE(firstDepthState.IsEnabled());
    ASSERT_TRUE(firstDepthState.IsWritable());
    ASSERT_ENUM_EQUAL(firstDepthState.GetCompare(), DepthStateFlags::CompareMode::LessEqual);

    firstDepthState.SetEnabled(false);
    ASSERT_FALSE(firstDepthState.IsEnabled());

    firstDepthState.SetWritable(false);
    ASSERT_FALSE(firstDepthState.IsWritable());

    firstDepthState.SetCompare(DepthStateFlags::CompareMode::GreaterEqual);
    ASSERT_ENUM_EQUAL(firstDepthState.GetCompare(), DepthStateFlags::CompareMode::GreaterEqual);
}

void Rendering::DepthStateTesting::CopyTest()
{
    DepthState firstDepthState;
    firstDepthState.SetEnabled(false);
    firstDepthState.SetWritable(false);
    firstDepthState.SetCompare(DepthStateFlags::CompareMode::GreaterEqual);

    DepthState secondDepthState(firstDepthState);

    ASSERT_EQUAL(firstDepthState.IsEnabled(), secondDepthState.IsEnabled());
    ASSERT_EQUAL(firstDepthState.IsWritable(), secondDepthState.IsWritable());
    ASSERT_ENUM_EQUAL(firstDepthState.GetCompare(), secondDepthState.GetCompare());

    secondDepthState.SetCompare(DepthStateFlags::CompareMode::Less);
    ASSERT_ENUM_EQUAL(secondDepthState.GetCompare(), DepthStateFlags::CompareMode::Less);
    ASSERT_ENUM_EQUAL(firstDepthState.GetCompare(), DepthStateFlags::CompareMode::GreaterEqual);
}

void Rendering::DepthStateTesting::StreamTest()
{
    // 	CoreTools::OutTopLevel outTopLevel;
    //
    // 	DepthStateSharedPtr firstDepthState(new DepthState);
    //
    // 	firstDepthState->SetEnabled(false);
    // 	firstDepthState->SetWritable(false);
    // 	firstDepthState->SetCompare(DepthStateFlags::CompareMode::GreaterEqual);
    //
    // 	outTopLevel.Insert(firstDepthState);
    //
    // 	CoreTools::BufferOutStream outStream(outTopLevel);
    //
    // 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
    //
    // 	CoreTools::BufferInStream inStream(fileBufferPtr);
    //
    // 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
    //
    // 	DepthStateSharedPtr secondDepthState = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<DepthStateSharedPtr>();
    //
    // 	ASSERT_EQUAL(firstDepthState->IsEnabled(), secondDepthState->IsEnabled());
    // 	ASSERT_EQUAL(firstDepthState->IsWritable(), secondDepthState->IsWritable());
    // 	ASSERT_ENUM_EQUAL(firstDepthState->GetCompare(), secondDepthState->GetCompare());
}
