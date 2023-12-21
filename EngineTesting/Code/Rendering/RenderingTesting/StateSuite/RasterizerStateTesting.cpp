///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:03)

#include "RasterizerStateTesting.h"
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

using System::operator++;
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
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIdTest<RasterizerState>);
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
    CoreTools::InitTerm::ExecuteInitializer();

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

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::RasterizerStateTesting::GetStreamingSizeTest()
{
    auto streamingSize = CoreTools::GetStreamSize(RasterizerState::GetCurrentRttiType().GetName());
    streamingSize += 8;
    streamingSize += CoreTools::GetStreamSize(GetGraphicsObjectName());
    streamingSize += CoreTools::GetStreamSize(GetGraphicsObjectType());

    streamingSize += CoreTools::GetStreamSize(rasterizerState->GetFill());
    streamingSize += CoreTools::GetStreamSize(rasterizerState->GetCull());
    streamingSize += CoreTools::GetStreamSize(rasterizerState->IsFrontCCW());
    streamingSize += CoreTools::GetStreamSize(rasterizerState->GetDepthBias());
    streamingSize += CoreTools::GetStreamSize(rasterizerState->GetDepthBiasClamp());
    streamingSize += CoreTools::GetStreamSize(rasterizerState->GetSlopeScaledDepthBias());
    streamingSize += CoreTools::GetStreamSize(rasterizerState->IsEnableDepthClip());
    streamingSize += CoreTools::GetStreamSize(rasterizerState->IsEnableScissor());
    streamingSize += CoreTools::GetStreamSize(rasterizerState->IsEnableMultisample());
    streamingSize += CoreTools::GetStreamSize(rasterizerState->IsEnableAntialiasedLine());

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
    auto streamingSize = CoreTools::GetStreamSize(state);
    streamingSize += CoreTools::GetStreamSize(GetGraphicsObjectName());

#ifdef SYSTEM_LITTLE_ENDIAN

    const auto index = streamingSize;

#else  // !SYSTEM_LITTLE_ENDIAN

    const auto index = streamingSize + CoreTools::GetStreamSize(GetGraphicsObjectType()) - 1;

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

    const auto streamingSize = CoreTools::GetStreamSize(RasterizerState::GetCurrentRttiType().GetName());

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
