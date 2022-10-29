///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/03 18:49)

#include "RasterizerStateTesting.h"
#include "System/Helper/EnumMacro.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBaseDetail.h"
#include "Rendering/State/Flags/DepthStencilStateComparison.h"
#include "Rendering/State/Flags/DepthStencilStateOperation.h"
#include "Rendering/State/Flags/DepthStencilStateWriteMask.h"
#include "Rendering/State/Flags/RasterizerStateCull.h"
#include "Rendering/State/Flags/RasterizerStateFill.h"
#include "Rendering/State/RasterizerState.h"

namespace Rendering
{
    ENUM_INCREMENTABLE_OPERATOR_DEFINE(RasterizerStateFill)
    ENUM_INCREMENTABLE_OPERATOR_DEFINE(RasterizerStateCull)
}

using namespace std::literals;

Rendering::RasterizerStateTesting::RasterizerStateTesting(const OStreamShared& stream)
    : ParentType{ stream, GraphicsObjectType::RasterizerState, GraphicsObjectType::NumTypes, "RasterizerState"s },
      fill{ RasterizerStateFill::Solid },
      cull{ RasterizerStateCull::Back },
      frontCCW{ true },
      depthBias{ 0 },
      depthBiasClamp{ 0.0f },
      slopeScaledDepthBias{ 0.0f },
      enableDepthClip{ true },
      enableScissor{ false },
      enableMultisample{ false },
      enableAntialiasedLine{ false },
      rasterizerState{ RasterizerState::Create(GetGraphicsObjectName()) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RasterizerStateTesting)

void Rendering::RasterizerStateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::RasterizerStateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest<RasterizerState>);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneObjectTest<RasterizerState>);
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest<RasterizerState>);
    ASSERT_NOT_THROW_EXCEPTION_0(IsNullObjectTest<RasterizerState>);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIDTest<RasterizerState>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
}

void Rendering::RasterizerStateTesting::AccessTest()
{
    const auto name = GetGraphicsObjectName();

    ASSERT_EQUAL(rasterizerState->GetName(), name);
    ASSERT_ENUM_EQUAL(rasterizerState->GetType(), GetGraphicsObjectType());

    ASSERT_TRUE(rasterizerState->IsDrawingState());

    ASSERT_FALSE(rasterizerState->IsBuffer());
    ASSERT_FALSE(rasterizerState->IsTexture());
    ASSERT_FALSE(rasterizerState->IsTextureArray());
    ASSERT_FALSE(rasterizerState->IsShader());
}

Rendering::GraphicsObjectSharedPtr Rendering::RasterizerStateTesting::Create(const std::string& name, GraphicsObjectType graphicsObjectType) const
{
    System::UnusedFunction(graphicsObjectType);

    return RasterizerState::Create(name);
}

void Rendering::RasterizerStateTesting::StreamTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest<RasterizerState>);
    ASSERT_THROW_EXCEPTION_0(FactoryExceptionTest<RasterizerState>);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest<RasterizerState>);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterTest<RasterizerState>);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkTest<RasterizerState>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamCreateTest<RasterizerState>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamCreateExceptionTest);

    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetFillTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetCullTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetFrontCCWTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetDepthBiasTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetDepthBiasClampTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetSlopeScaledDepthBiasTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetEnableDepthClipTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetEnableScissorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetEnableMultisampleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetEnableAntialiasedLineTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::RasterizerStateTesting::GetStreamingSizeTest()
{
    auto streamingSize = CORE_TOOLS_STREAM_SIZE(RasterizerState::GetCurrentRttiType().GetName());
    streamingSize += CORE_TOOLS_STREAM_SIZE(rasterizerState);
    streamingSize += CORE_TOOLS_STREAM_SIZE(GetGraphicsObjectName());
    streamingSize += CORE_TOOLS_STREAM_SIZE(GetGraphicsObjectType());

    streamingSize += CORE_TOOLS_STREAM_SIZE(rasterizerState->GetFill());
    streamingSize += CORE_TOOLS_STREAM_SIZE(rasterizerState->GetCull());
    streamingSize += CORE_TOOLS_STREAM_SIZE(rasterizerState->IsFrontCCW());
    streamingSize += CORE_TOOLS_STREAM_SIZE(rasterizerState->GetDepthBias());
    streamingSize += CORE_TOOLS_STREAM_SIZE(rasterizerState->GetDepthBiasClamp());
    streamingSize += CORE_TOOLS_STREAM_SIZE(rasterizerState->GetSlopeScaledDepthBias());
    streamingSize += CORE_TOOLS_STREAM_SIZE(rasterizerState->IsEnableDepthClip());
    streamingSize += CORE_TOOLS_STREAM_SIZE(rasterizerState->IsEnableScissor());
    streamingSize += CORE_TOOLS_STREAM_SIZE(rasterizerState->IsEnableMultisample());
    streamingSize += CORE_TOOLS_STREAM_SIZE(rasterizerState->IsEnableAntialiasedLine());

    ASSERT_EQUAL(streamingSize, rasterizerState->GetStreamingSize());
}

void Rendering::RasterizerStateTesting::StreamCreateExceptionTest()
{
    auto saveFileBuffer = SaveTest<RasterizerState>(*rasterizerState);

    const auto index = GetCorrectIndex(rasterizerState);
    ASSERT_GREATER_FAILURE_THROW(index, 0, "缓冲区大小不足。");

    for (auto type = GraphicsObjectType::None; type < GraphicsObjectType::NumTypes; ++type)
    {
        if (type == GraphicsObjectType::RasterizerState)
            continue;

        *saveFileBuffer->GetBuffer(index) = System::EnumCastUnderlying<char>(type);

        ASSERT_THROW_EXCEPTION_1(LoadExceptionTest, saveFileBuffer);
    }
}

void Rendering::RasterizerStateTesting::LoadExceptionTest(const FileBufferSharedPtr& saveFileBuffer)
{
    CoreTools::BufferSource bufferSource{ saveFileBuffer };

    auto saveTestingType = RasterizerState::Create(GetGraphicsObjectName());

    saveTestingType->Load(bufferSource);
}

int Rendering::RasterizerStateTesting::GetCorrectIndex(const RasterizerStateSharedPtr& state) const
{
    auto streamingSize = CORE_TOOLS_STREAM_SIZE(state);
    streamingSize += CORE_TOOLS_STREAM_SIZE(GetGraphicsObjectName());

#ifdef SYSTEM_LITTLE_ENDIAN

    const auto index = streamingSize;

#else  // !SYSTEM_LITTLE_ENDIAN

    const auto index = streamingSize + CORE_TOOLS_STREAM_SIZE(GetGraphicsObjectType()) - 1;

#endif  // SYSTEM_LITTLE_ENDIAN

    return index;
}

void Rendering::RasterizerStateTesting::RasterizerStateTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateSaveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateValueTest);
}

void Rendering::RasterizerStateTesting::RasterizerStateValueTest()
{
    ASSERT_ENUM_EQUAL(rasterizerState->GetFill(), fill);
    ASSERT_ENUM_EQUAL(rasterizerState->GetCull(), cull);
    ASSERT_EQUAL(rasterizerState->IsFrontCCW(), frontCCW);
    ASSERT_EQUAL(rasterizerState->GetDepthBias(), depthBias);
    ASSERT_EQUAL(rasterizerState->GetDepthBiasClamp(), depthBiasClamp);
    ASSERT_EQUAL(rasterizerState->GetSlopeScaledDepthBias(), slopeScaledDepthBias);
    ASSERT_EQUAL(rasterizerState->IsEnableDepthClip(), enableDepthClip);
    ASSERT_EQUAL(rasterizerState->IsEnableScissor(), enableScissor);
    ASSERT_EQUAL(rasterizerState->IsEnableMultisample(), enableMultisample);
    ASSERT_EQUAL(rasterizerState->IsEnableAntialiasedLine(), enableAntialiasedLine);
}

void Rendering::RasterizerStateTesting::RasterizerStateSaveTest()
{
    constexpr auto bufferSize = 1024;

    auto objectRegister = CoreTools::ObjectRegister::Create();
    ASSERT_EQUAL(1, rasterizerState->Register(*objectRegister));
    CoreTools::BufferTarget bufferTarget{ bufferSize, objectRegister };

    rasterizerState->Save(bufferTarget);

    auto fileBuffer = bufferTarget.GetFileBuffer();

    OriginalBuffer buffer{ fileBuffer->begin(), fileBuffer->end() };

    const auto streamingSize = CORE_TOOLS_STREAM_SIZE(RasterizerState::GetCurrentRttiType().GetName());

    CoreTools::BufferSource bufferSource{ CorrectFileBuffer(streamingSize, buffer) };
    rasterizerState = RasterizerState::Create(GetGraphicsObjectName());
    rasterizerState->Load(bufferSource);
}

void Rendering::RasterizerStateTesting::ConstructorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
}

void Rendering::RasterizerStateTesting::SetFillTest()
{
    for (auto rasterizerStateFill = RasterizerStateFill::Solid; rasterizerStateFill <= RasterizerStateFill::Wireframe; ++rasterizerStateFill)
    {
        rasterizerState->SetFill(rasterizerStateFill);
        fill = rasterizerStateFill;
        ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
    }
}

void Rendering::RasterizerStateTesting::SetCullTest()
{
    for (auto rasterizerStateCull = RasterizerStateCull::None; rasterizerStateCull <= RasterizerStateCull::Back; ++rasterizerStateCull)
    {
        rasterizerState->SetCull(rasterizerStateCull);
        cull = rasterizerStateCull;
        ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
    }
}

void Rendering::RasterizerStateTesting::SetFrontCCWTest()
{
    rasterizerState->SetFrontCCW(false);
    frontCCW = false;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);

    rasterizerState->SetFrontCCW(true);
    frontCCW = true;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
}

void Rendering::RasterizerStateTesting::SetDepthBiasTest()
{
    rasterizerState->SetDepthBias(2);
    depthBias = 2;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
}

void Rendering::RasterizerStateTesting::SetDepthBiasClampTest()
{
    rasterizerState->SetDepthBiasClamp(0.3f);
    depthBiasClamp = 0.3f;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
}

void Rendering::RasterizerStateTesting::SetSlopeScaledDepthBiasTest()
{
    rasterizerState->SetSlopeScaledDepthBias(0.5f);
    slopeScaledDepthBias = 0.5f;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
}

void Rendering::RasterizerStateTesting::SetEnableDepthClipTest()
{
    rasterizerState->SetEnableDepthClip(false);
    enableDepthClip = false;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);

    rasterizerState->SetEnableDepthClip(true);
    enableDepthClip = true;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
}

void Rendering::RasterizerStateTesting::SetEnableScissorTest()
{
    rasterizerState->SetEnableScissor(true);
    enableScissor = true;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);

    rasterizerState->SetEnableScissor(false);
    enableScissor = false;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
}

void Rendering::RasterizerStateTesting::SetEnableMultisampleTest()
{
    rasterizerState->SetEnableMultisample(true);
    enableMultisample = true;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);

    rasterizerState->SetEnableMultisample(false);
    enableMultisample = false;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
}

void Rendering::RasterizerStateTesting::SetEnableAntialiasedLineTest()
{
    rasterizerState->SetEnableAntialiasedLine(true);
    enableAntialiasedLine = true;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);

    rasterizerState->SetEnableAntialiasedLine(false);
    enableAntialiasedLine = false;
    ASSERT_NOT_THROW_EXCEPTION_0(RasterizerStateTest);
}
