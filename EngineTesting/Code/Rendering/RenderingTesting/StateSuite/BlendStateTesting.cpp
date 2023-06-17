///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:03)

#include "BlendStateTesting.h"
#include "System/Helper/EnumOperator.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Helper/Constant.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBaseDetail.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/Flags/BlendStateColorWrite.h"

using namespace std::literals;
using System::operator++;

Rendering::BlendStateTesting::BlendStateTesting(const OStreamShared& stream)
    : ParentType{ stream, GraphicsObjectType::BlendState, GraphicsObjectType::DepthStencilState, "BlendState"s },
      enableAlphaToCoverage{ false },
      enableIndependentBlend{ false },
      blendStateTarget{},
      blendColor{ 0.0f, 0.0f, 0.0f, 0.0f },
      sampleMask{ 0xFFFFFFFFu },
      blendState{ BlendState::Create(GetGraphicsObjectName()) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BlendStateTesting)

void Rendering::BlendStateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::BlendStateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest<BlendState>);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneObjectTest<BlendState>);
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest<BlendState>);
    ASSERT_NOT_THROW_EXCEPTION_0(IsNullObjectTest<BlendState>);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIDTest<BlendState>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTest);
}

void Rendering::BlendStateTesting::AccessTest()
{
    const auto name = GetGraphicsObjectName();

    ASSERT_EQUAL(blendState->GetName(), name);
    ASSERT_ENUM_EQUAL(blendState->GetType(), GetGraphicsObjectType());

    ASSERT_TRUE(blendState->IsDrawingState());

    ASSERT_FALSE(blendState->IsBuffer());
    ASSERT_FALSE(blendState->IsTexture());
    ASSERT_FALSE(blendState->IsTextureArray());
    ASSERT_FALSE(blendState->IsShader());
}

Rendering::GraphicsObjectSharedPtr Rendering::BlendStateTesting::Create(const std::string& name, GraphicsObjectType graphicsObjectType) const
{
    System::UnusedFunction(graphicsObjectType);

    return BlendState::Create(name);
}

void Rendering::BlendStateTesting::StreamTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest<BlendState>);
    ASSERT_THROW_EXCEPTION_0(FactoryExceptionTest<BlendState>);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest<BlendState>);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterTest<BlendState>);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkTest<BlendState>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamCreateTest<BlendState>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamCreateExceptionTest);

    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetEnableAlphaToCoverageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetEnableIndependentBlendTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetBlendColorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetSampleMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetBlendStateTargetTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::BlendStateTesting::GetStreamingSizeTest()
{
    auto streamingSize = CoreTools::GetStreamSize(BlendState::GetCurrentRttiType().GetName());
    streamingSize += 8;
    streamingSize += CoreTools::GetStreamSize(GetGraphicsObjectName());
    streamingSize += CoreTools::GetStreamSize(GetGraphicsObjectType());

    streamingSize += CoreTools::GetStreamSize(blendState->IsEnableAlphaToCoverage());
    streamingSize += CoreTools::GetStreamSize(blendState->IsEnableIndependentBlend());
    streamingSize += RENDERING_STREAM_SIZE(blendState->GetBlendColor());
    streamingSize += CoreTools::GetStreamSize(blendState->GetSampleMask());
    streamingSize += blendState->GetBlendStateTarget(0).GetStreamingSize() * numBlendStateTargets;

    ASSERT_EQUAL(streamingSize, blendState->GetStreamingSize());
}

void Rendering::BlendStateTesting::StreamCreateExceptionTest()
{
    auto saveFileBuffer = SaveTest<BlendState>(*blendState);

    const auto index = GetCorrectIndex(blendState);
    ASSERT_GREATER_FAILURE_THROW(index, 0, "缓冲区大小不足。");

    for (auto type = GraphicsObjectType::None; type < GraphicsObjectType::NumTypes; ++type)
    {
        if (type == GraphicsObjectType::BlendState)
            continue;

        *saveFileBuffer->GetBuffer(index) = System::EnumCastUnderlying<char>(type);
    }
}

void Rendering::BlendStateTesting::LoadExceptionTest(const FileBufferSharedPtr& saveFileBuffer)
{
    CoreTools::BufferSource bufferSource{ saveFileBuffer };

    auto saveTestingType = BlendState::Create(GetGraphicsObjectName());

    saveTestingType->Load(bufferSource);
}

int Rendering::BlendStateTesting::GetCorrectIndex(const BlendStateSharedPtr& state) const
{
    auto streamingSize = CoreTools::GetStreamSize(state);
    streamingSize += CoreTools::GetStreamSize(GetGraphicsObjectName());

#ifdef SYSTEM_LITTLE_ENDIAN

    const auto index = streamingSize;

#else  // !SYSTEM_LITTLE_ENDIAN

    const auto index = streamingSize + CoreTools::GetStreamSize(GetGraphicsObjectType()) - 1;

#endif  // SYSTEM_LITTLE_ENDIAN

    return index;
}

void Rendering::BlendStateTesting::BlendStateTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateSaveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateValueTest);
}

void Rendering::BlendStateTesting::BlendStateValueTest()
{
    ASSERT_EQUAL(blendState->IsEnableAlphaToCoverage(), enableAlphaToCoverage);
    ASSERT_EQUAL(blendState->IsEnableIndependentBlend(), enableIndependentBlend);

    using ApproximateFunction = bool (*)(const Colour& lhs, const Colour& rhs, float epsilon);
    ApproximateFunction approximate = Approximate<float>;

    ASSERT_APPROXIMATE_USE_FUNCTION(approximate, blendState->GetBlendColor(), blendColor, 1e-8f);
    ASSERT_EQUAL(blendState->GetSampleMask(), sampleMask);

    for (auto i = 0; i < numBlendStateTargets; ++i)
    {
        ASSERT_EQUAL(blendState->GetBlendStateTarget(i), blendStateTarget.at(i));
    }
}

void Rendering::BlendStateTesting::BlendStateSaveTest()
{
    constexpr auto bufferSize = 1024;

    auto objectRegister = CoreTools::ObjectRegister::Create();
    ASSERT_EQUAL(1, blendState->Register(*objectRegister));
    CoreTools::BufferTarget bufferTarget{ bufferSize, objectRegister };

    blendState->Save(bufferTarget);

    auto fileBuffer = bufferTarget.GetFileBuffer();

    OriginalBuffer buffer{ fileBuffer->begin(), fileBuffer->end() };

    const auto streamingSize = CoreTools::GetStreamSize(BlendState::GetCurrentRttiType().GetName());

    CoreTools::BufferSource bufferSource{ CorrectFileBuffer(streamingSize, buffer) };
    blendState = BlendState::Create(GetGraphicsObjectName());
    blendState->Load(bufferSource);
}

void Rendering::BlendStateTesting::ConstructorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTest);
}

void Rendering::BlendStateTesting::SetEnableAlphaToCoverageTest()
{
    blendState->SetEnableAlphaToCoverage(true);
    enableAlphaToCoverage = true;
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTest);

    blendState->SetEnableAlphaToCoverage(false);
    enableAlphaToCoverage = false;
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTest);
}

void Rendering::BlendStateTesting::SetEnableIndependentBlendTest()
{
    blendState->SetEnableIndependentBlend(true);
    enableIndependentBlend = true;
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTest);

    blendState->SetEnableIndependentBlend(false);
    enableIndependentBlend = false;
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTest);
}

void Rendering::BlendStateTesting::SetBlendColorTest()
{
    const Colour colour{ 0.2f, 0.5f, 0.4f, 0.8f };
    blendState->SetBlendColor(colour);
    blendColor = colour;
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTest);
}

void Rendering::BlendStateTesting::SetSampleMaskTest()
{
    blendState->SetSampleMask(0xFF00FF00);
    sampleMask = 0xFF00FF00;
    ASSERT_NOT_THROW_EXCEPTION_0(BlendStateTest);
}

void Rendering::BlendStateTesting::SetBlendStateTargetTest()
{
    for (auto i = 0; i < numBlendStateTargets; ++i)
    {
        BlendStateTarget target{};
        target.SetEnable(true);
        target.SetMask(BlendStateColorWrite::EnableAlpha);
        blendStateTarget.at(i) = target;
        blendState->SetBlendStateTarget(i, target);
    }
}
