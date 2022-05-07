// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:24)

#include "AlphaStateTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Shaders/AlphaState.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, AlphaStateTesting)

void Rendering::AlphaStateTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::AlphaStateTesting::InitTest()
{
    AlphaState firstAlphaState{ CoreTools::DisableNotThrow::Disable };

    ASSERT_FALSE(firstAlphaState.IsBlendEnabled());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::SourceBlendMode::SourceAlpha, firstAlphaState.GetSourceBlend());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::DestinationBlendMode::OneMinusSourceAlpha, firstAlphaState.GetDestinationBlend());
    ASSERT_FALSE(firstAlphaState.IsCompareEnabled());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::CompareMode::Always, firstAlphaState.GetCompare());
    ASSERT_APPROXIMATE(0.0f, firstAlphaState.GetReference(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstAlphaState.GetConstantColor(), Colour<float>(0.0f, 0.0f, 0.0f, 0.0f), 1e-8f);

    firstAlphaState.SetBlendEnabled(true);
    ASSERT_TRUE(firstAlphaState.IsBlendEnabled());

    firstAlphaState.SetSourceBlend(AlphaStateFlags::SourceBlendMode::DestinationColor);
    ASSERT_ENUM_EQUAL(AlphaStateFlags::SourceBlendMode::DestinationColor, firstAlphaState.GetSourceBlend());

    firstAlphaState.SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::One);
    ASSERT_ENUM_EQUAL(AlphaStateFlags::DestinationBlendMode::One, firstAlphaState.GetDestinationBlend());

    firstAlphaState.SetCompareEnabled(true);
    ASSERT_TRUE(firstAlphaState.IsCompareEnabled());

    firstAlphaState.SetCompare(AlphaStateFlags::CompareMode::Less);
    ASSERT_ENUM_EQUAL(AlphaStateFlags::CompareMode::Less, firstAlphaState.GetCompare());

    firstAlphaState.SetReference(0.5f);
    ASSERT_APPROXIMATE(0.5f, firstAlphaState.GetReference(), 1e-8f);

    firstAlphaState.SetConstantColor(Colour<float>(0.5f, 0.1f, 0.4f, 0.2f));
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstAlphaState.GetConstantColor(), Colour<float>(0.5f, 0.1f, 0.4f, 0.2f), 1e-8f);
}

void Rendering::AlphaStateTesting::CopyTest()
{
    AlphaState firstAlphaState(CoreTools::DisableNotThrow::Disable);
    firstAlphaState.SetBlendEnabled(true);
    firstAlphaState.SetSourceBlend(AlphaStateFlags::SourceBlendMode::DestinationColor);
    firstAlphaState.SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::One);
    firstAlphaState.SetCompareEnabled(true);
    firstAlphaState.SetCompare(AlphaStateFlags::CompareMode::Less);
    firstAlphaState.SetReference(0.5f);
    firstAlphaState.SetConstantColor(Colour<float>(0.5f, 0.1f, 0.4f, 0.2f));

    AlphaState secondAlphaState(firstAlphaState);

    ASSERT_EQUAL(firstAlphaState.IsBlendEnabled(), secondAlphaState.IsBlendEnabled());
    ASSERT_ENUM_EQUAL(secondAlphaState.GetSourceBlend(), firstAlphaState.GetSourceBlend());
    ASSERT_ENUM_EQUAL(secondAlphaState.GetDestinationBlend(), firstAlphaState.GetDestinationBlend());
    ASSERT_EQUAL(firstAlphaState.IsCompareEnabled(), secondAlphaState.IsCompareEnabled());
    ASSERT_ENUM_EQUAL(secondAlphaState.GetCompare(), firstAlphaState.GetCompare());
    ASSERT_APPROXIMATE(secondAlphaState.GetReference(), firstAlphaState.GetReference(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstAlphaState.GetConstantColor(), secondAlphaState.GetConstantColor(), 1e-8f);

    secondAlphaState.SetReference(0.51f);

    ASSERT_APPROXIMATE(secondAlphaState.GetReference(), 0.51f, 1e-8f);
    ASSERT_APPROXIMATE(firstAlphaState.GetReference(), 0.5f, 1e-8f);
}
#include SYSTEM_WARNING_DISABLE(26440)
void Rendering::AlphaStateTesting::StreamTest()
{
    // 	CoreTools::OutTopLevel outTopLevel;
    //
    // 	AlphaStateSharedPtr firstAlphaState(new AlphaState(CoreTools::DisableNotThrow::Disable));
    // 	firstAlphaState->SetBlendEnabled(true);
    // 	firstAlphaState->SetSourceBlend(AlphaStateFlags::SourceBlendMode::DestinationColor);
    // 	firstAlphaState->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::One);
    // 	firstAlphaState->SetCompareEnabled(true);
    // 	firstAlphaState->SetCompare(AlphaStateFlags::CompareMode::Less);
    // 	firstAlphaState->SetReference(0.5f);
    // 	firstAlphaState->SetConstantColor(Colour<float>(0.5f, 0.1f, 0.4f, 0.2f));
    //
    // 	outTopLevel.Insert(firstAlphaState);
    //
    // 	CoreTools::BufferOutStream outStream(outTopLevel);
    //
    // 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
    //
    // 	CoreTools::BufferInStream inStream(fileBufferPtr);
    //
    // 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
    //
    // 	AlphaStateSharedPtr secondAlphaState = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<AlphaStateSharedPtr>();
    //
    // 	ASSERT_EQUAL(firstAlphaState->IsBlendEnabled(), secondAlphaState->IsBlendEnabled());
    // 	ASSERT_ENUM_EQUAL(secondAlphaState->GetSourceBlend(), firstAlphaState->GetSourceBlend());
    // 	ASSERT_ENUM_EQUAL(secondAlphaState->GetDestinationBlend(), firstAlphaState->GetDestinationBlend());
    // 	ASSERT_EQUAL(firstAlphaState->IsCompareEnabled(), secondAlphaState->IsCompareEnabled());
    // 	ASSERT_ENUM_EQUAL(secondAlphaState->GetCompare(), firstAlphaState->GetCompare());
    // 	ASSERT_APPROXIMATE(secondAlphaState->GetReference(), firstAlphaState->GetReference(), 1e-8f);
    // 	ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstAlphaState->GetConstantColor(),secondAlphaState->GetConstantColor(),1e-8f);
}
