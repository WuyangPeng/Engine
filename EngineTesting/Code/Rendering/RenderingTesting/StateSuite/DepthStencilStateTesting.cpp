///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:03)

#include "DepthStencilStateTesting.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBaseDetail.h"
#include "Rendering/State/DepthStencilState.h"
#include "Rendering/State/Flags/DepthStencilStateComparison.h"
#include "Rendering/State/Flags/DepthStencilStateOperation.h"
#include "Rendering/State/Flags/DepthStencilStateWriteMask.h"

using System::operator++;
using namespace std::literals;

Rendering::DepthStencilStateTesting::DepthStencilStateTesting(const OStreamShared& stream)
    : ParentType{ stream, GraphicsObjectType::DepthStencilState, GraphicsObjectType::RasterizerState, "DepthStencilState"s },
      depthEnable{ true },
      writeMask{ DepthStencilStateWriteMask::All },
      comparison{ DepthStencilStateComparison::LessEqual },
      stencilEnable{ false },
      stencilReadMask{ 0xFF },
      stencilWriteMask{ 0xFF },
      frontFace{},
      backFace{},
      reference{ 0 },
      depthStencilState{ DepthStencilState::Create(GetGraphicsObjectName()) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DepthStencilStateTesting)

void Rendering::DepthStencilStateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::DepthStencilStateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest<DepthStencilState>);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneObjectTest<DepthStencilState>);
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest<DepthStencilState>);
    ASSERT_NOT_THROW_EXCEPTION_0(IsNullObjectTest<DepthStencilState>);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIDTest<DepthStencilState>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
}

void Rendering::DepthStencilStateTesting::AccessTest()
{
    const auto name = GetGraphicsObjectName();

    ASSERT_EQUAL(depthStencilState->GetName(), name);
    ASSERT_ENUM_EQUAL(depthStencilState->GetType(), GetGraphicsObjectType());

    ASSERT_TRUE(depthStencilState->IsDrawingState());

    ASSERT_FALSE(depthStencilState->IsBuffer());
    ASSERT_FALSE(depthStencilState->IsTexture());
    ASSERT_FALSE(depthStencilState->IsTextureArray());
    ASSERT_FALSE(depthStencilState->IsShader());
}

Rendering::GraphicsObjectSharedPtr Rendering::DepthStencilStateTesting::Create(const std::string& name, GraphicsObjectType graphicsObjectType) const
{
    System::UnusedFunction(graphicsObjectType);

    return DepthStencilState::Create(name);
}

void Rendering::DepthStencilStateTesting::StreamTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest<DepthStencilState>);
    ASSERT_THROW_EXCEPTION_0(FactoryExceptionTest<DepthStencilState>);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest<DepthStencilState>);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterTest<DepthStencilState>);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkTest<DepthStencilState>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamCreateTest<DepthStencilState>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamCreateExceptionTest);

    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetDepthEnableTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetWriteMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetComparisonTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetStencilEnableTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetStencilReadMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetStencilWriteMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetReferenceTest);

    ASSERT_NOT_THROW_EXCEPTION_0(SetFrontFaceFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetFrontFaceDepthFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetFrontFacePassTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetFrontFaceComparisonTest);

    ASSERT_NOT_THROW_EXCEPTION_0(SetBackFaceFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetBackFaceDepthFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetBackFacePassTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetBackFaceComparisonTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::DepthStencilStateTesting::GetStreamingSizeTest()
{
    auto streamingSize = CoreTools::GetStreamSize(DepthStencilState::GetCurrentRttiType().GetName());
    streamingSize += 8;
    streamingSize += CoreTools::GetStreamSize(GetGraphicsObjectName());
    streamingSize += CoreTools::GetStreamSize(GetGraphicsObjectType());

    streamingSize += CoreTools::GetStreamSize(depthStencilState->IsDepthEnable());
    streamingSize += CoreTools::GetStreamSize(depthStencilState->GetWriteMask());
    streamingSize += CoreTools::GetStreamSize(depthStencilState->GetComparison());
    streamingSize += CoreTools::GetStreamSize(depthStencilState->IsStencilEnable());
    streamingSize += CoreTools::GetStreamSize(depthStencilState->GetStencilReadMask());
    streamingSize += CoreTools::GetStreamSize(depthStencilState->GetStencilWriteMask());
    streamingSize += RENDERING_STREAM_SIZE(depthStencilState->GetFrontFace());
    streamingSize += RENDERING_STREAM_SIZE(depthStencilState->GetBackFace());
    streamingSize += CoreTools::GetStreamSize(depthStencilState->GetReference());

    ASSERT_EQUAL(streamingSize, depthStencilState->GetStreamingSize());
}

void Rendering::DepthStencilStateTesting::StreamCreateExceptionTest()
{
    auto saveFileBuffer = SaveTest<DepthStencilState>(*depthStencilState);

    const auto index = GetCorrectIndex(depthStencilState);
    ASSERT_GREATER_FAILURE_THROW(index, 0, "缓冲区大小不足。");

    for (auto type = GraphicsObjectType::None; type < GraphicsObjectType::NumTypes; ++type)
    {
        if (type == GraphicsObjectType::DepthStencilState)
            continue;

        *saveFileBuffer->GetBuffer(index) = System::EnumCastUnderlying<char>(type);
    }
}

void Rendering::DepthStencilStateTesting::LoadExceptionTest(const FileBufferSharedPtr& saveFileBuffer)
{
    CoreTools::BufferSource bufferSource{ saveFileBuffer };

    auto saveTestingType = DepthStencilState::Create(GetGraphicsObjectName());

    saveTestingType->Load(bufferSource);
}

int Rendering::DepthStencilStateTesting::GetCorrectIndex(const DepthStencilStateSharedPtr& state) const
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

void Rendering::DepthStencilStateTesting::DepthStencilStateTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateSaveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateValueTest);
}

void Rendering::DepthStencilStateTesting::DepthStencilStateValueTest()
{
    ASSERT_EQUAL(depthStencilState->IsDepthEnable(), depthEnable);
    ASSERT_ENUM_EQUAL(depthStencilState->GetWriteMask(), writeMask);
    ASSERT_ENUM_EQUAL(depthStencilState->GetComparison(), comparison);
    ASSERT_EQUAL(depthStencilState->IsStencilEnable(), stencilEnable);
    ASSERT_EQUAL(depthStencilState->GetStencilReadMask(), stencilReadMask);
    ASSERT_EQUAL(depthStencilState->GetStencilWriteMask(), stencilWriteMask);

    ASSERT_EQUAL(depthStencilState->GetReference(), reference);
}

void Rendering::DepthStencilStateTesting::DepthStencilStateSaveTest()
{
    constexpr auto bufferSize = 1024;

    auto objectRegister = CoreTools::ObjectRegister::Create();
    ASSERT_EQUAL(1, depthStencilState->Register(*objectRegister));
    CoreTools::BufferTarget bufferTarget{ bufferSize, objectRegister };

    depthStencilState->Save(bufferTarget);

    auto fileBuffer = bufferTarget.GetFileBuffer();

    OriginalBuffer buffer{ fileBuffer->begin(), fileBuffer->end() };

    const auto streamingSize = CoreTools::GetStreamSize(DepthStencilState::GetCurrentRttiType().GetName());

    CoreTools::BufferSource bufferSource{ CorrectFileBuffer(streamingSize, buffer) };
    depthStencilState = DepthStencilState::Create(GetGraphicsObjectName());
    depthStencilState->Load(bufferSource);
}

void Rendering::DepthStencilStateTesting::ConstructorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
}

void Rendering::DepthStencilStateTesting::SetDepthEnableTest()
{
    depthStencilState->SetDepthEnable(false);
    depthEnable = false;
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);

    depthStencilState->SetDepthEnable(true);
    depthEnable = true;
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
}

void Rendering::DepthStencilStateTesting::SetWriteMaskTest()
{
    for (auto mask = DepthStencilStateWriteMask::Zero; mask <= DepthStencilStateWriteMask::All; ++mask)
    {
        depthStencilState->SetWriteMask(mask);
        writeMask = mask;
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
    }
}

void Rendering::DepthStencilStateTesting::SetComparisonTest()
{
    for (auto stateComparison = DepthStencilStateComparison::Never; stateComparison <= DepthStencilStateComparison::Always; ++stateComparison)
    {
        depthStencilState->SetComparison(stateComparison);
        comparison = stateComparison;
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
    }
}

void Rendering::DepthStencilStateTesting::SetStencilEnableTest()
{
    depthStencilState->SetStencilEnable(true);
    stencilEnable = true;
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);

    depthStencilState->SetStencilEnable(false);
    stencilEnable = false;
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
}

void Rendering::DepthStencilStateTesting::SetStencilReadMaskTest()
{
    depthStencilState->SetStencilReadMask(0x0F);
    stencilReadMask = 0x0F;
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
}

void Rendering::DepthStencilStateTesting::SetStencilWriteMaskTest()
{
    depthStencilState->SetStencilWriteMask(0xFE);
    stencilWriteMask = 0xFE;
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
}

void Rendering::DepthStencilStateTesting::SetReferenceTest()
{
    depthStencilState->SetReference(5);
    reference = 5;
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
}

void Rendering::DepthStencilStateTesting::SetFrontFaceFailTest()
{
    for (auto operation = DepthStencilStateOperation::Keep; operation <= DepthStencilStateOperation::Decrease; ++operation)
    {
        depthStencilState->SetFrontFaceFail(operation);
        frontFace.SetFail(operation);
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
    }
}

void Rendering::DepthStencilStateTesting::SetFrontFaceDepthFailTest()
{
    for (auto operation = DepthStencilStateOperation::Keep; operation <= DepthStencilStateOperation::Decrease; ++operation)
    {
        depthStencilState->SetFrontFaceDepthFail(operation);
        frontFace.SetDepthFail(operation);
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
    }
}

void Rendering::DepthStencilStateTesting::SetFrontFacePassTest()
{
    for (auto operation = DepthStencilStateOperation::Keep; operation <= DepthStencilStateOperation::Decrease; ++operation)
    {
        depthStencilState->SetFrontFacePass(operation);
        frontFace.SetPass(operation);
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
    }
}

void Rendering::DepthStencilStateTesting::SetFrontFaceComparisonTest()
{
    for (auto depthStencilStateComparison = DepthStencilStateComparison::Never; depthStencilStateComparison <= DepthStencilStateComparison::Always; ++depthStencilStateComparison)
    {
        depthStencilState->SetFrontFaceComparison(depthStencilStateComparison);
        frontFace.SetComparison(depthStencilStateComparison);
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
    }
}

void Rendering::DepthStencilStateTesting::SetBackFaceFailTest()
{
    for (auto operation = DepthStencilStateOperation::Keep; operation <= DepthStencilStateOperation::Decrease; ++operation)
    {
        depthStencilState->SetBackFaceFail(operation);
        backFace.SetFail(operation);
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
    }
}

void Rendering::DepthStencilStateTesting::SetBackFaceDepthFailTest()
{
    for (auto operation = DepthStencilStateOperation::Keep; operation <= DepthStencilStateOperation::Decrease; ++operation)
    {
        depthStencilState->SetBackFaceDepthFail(operation);
        backFace.SetDepthFail(operation);
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
    }
}

void Rendering::DepthStencilStateTesting::SetBackFacePassTest()
{
    for (auto operation = DepthStencilStateOperation::Keep; operation <= DepthStencilStateOperation::Decrease; ++operation)
    {
        depthStencilState->SetBackFacePass(operation);
        backFace.SetPass(operation);
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
    }
}

void Rendering::DepthStencilStateTesting::SetBackFaceComparisonTest()
{
    for (auto depthStencilStateComparison = DepthStencilStateComparison::Never; depthStencilStateComparison <= DepthStencilStateComparison::Always; ++depthStencilStateComparison)
    {
        depthStencilState->SetBackFaceComparison(depthStencilStateComparison);
        backFace.SetComparison(depthStencilStateComparison);
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateTest);
    }
}
