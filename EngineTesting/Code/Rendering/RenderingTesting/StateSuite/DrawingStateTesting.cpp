///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/02 0:41)

#include "DrawingStateTesting.h"
#include "Detail/DrawingStateTest.h"
#include "System/Helper/EnumMacro.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBaseDetail.h"

using namespace std::literals;

Rendering::DrawingStateTesting::DrawingStateTesting(const OStreamShared& stream)
    : ParentType{ stream, GraphicsObjectType::DrawingState, GraphicsObjectType::NumTypes, "DrawingStateTest"s }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DrawingStateTesting)

void Rendering::DrawingStateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::DrawingStateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest<DrawingStateTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneObjectTest<DrawingStateTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest<DrawingStateTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(IsNullObjectTest<DrawingStateTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIDTest<DrawingStateTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest<DrawingStateTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamCreateExceptionTest);
}

void Rendering::DrawingStateTesting::AccessTest()
{
    for (auto type = GraphicsObjectType::None; type < GraphicsObjectType::NumTypes; ++type)
    {
        if (GraphicsObjectType::DrawingState <= type && type <= GraphicsObjectType::RasterizerState)
        {
            ASSERT_NOT_THROW_EXCEPTION_1(DrawingStateTrueTest, type);
        }
        else
        {
            ASSERT_THROW_EXCEPTION_1(DrawingStateExceptionTest, type);
        }
    }
}

void Rendering::DrawingStateTesting::DrawingStateTrueTest(GraphicsObjectType type)
{
    const auto name = GetGraphicsObjectName() + std::to_string(System::EnumCastUnderlying(type));

    auto drawingStateTest = DrawingStateTest::Create(name, type);

    ASSERT_EQUAL(drawingStateTest->GetName(), name);
    ASSERT_ENUM_EQUAL(drawingStateTest->GetType(), type);

    ASSERT_TRUE(drawingStateTest->IsDrawingState());

    ASSERT_FALSE(drawingStateTest->IsBuffer());
    ASSERT_FALSE(drawingStateTest->IsTexture());
    ASSERT_FALSE(drawingStateTest->IsTextureArray());
    ASSERT_FALSE(drawingStateTest->IsShader());
}

void Rendering::DrawingStateTesting::DrawingStateExceptionTest(GraphicsObjectType type)
{
    const auto name = GetGraphicsObjectName() + std::to_string(System::EnumCastUnderlying(type));

    const auto drawingStateTest = DrawingStateTest::Create(name, type);
}

Rendering::GraphicsObjectSharedPtr Rendering::DrawingStateTesting::Create(const std::string& name, GraphicsObjectType graphicsObjectType) const
{
    return DrawingStateTest::Create(name, graphicsObjectType);
}

void Rendering::DrawingStateTesting::StreamCreateExceptionTest()
{
    auto drawingStateTest = DrawingStateTest::Create(GetGraphicsObjectName(), GetGraphicsObjectType());

    auto saveFileBuffer = SaveTest<DrawingStateTest>(*drawingStateTest);

    const auto index = GetCorrectIndex(*drawingStateTest);
    ASSERT_GREATER_FAILURE_THROW(index, 0, "缓冲区大小不足。");

    for (auto type = GraphicsObjectType::None; type < GraphicsObjectType::DrawingState; ++type)
    {
        *saveFileBuffer->GetBuffer(index) = System::EnumCastUnderlying<char>(type);

        ASSERT_THROW_EXCEPTION_1(LoadExceptionTest, saveFileBuffer);
    }
}

int Rendering::DrawingStateTesting::GetCorrectIndex(const DrawingStateTest& drawingStateTest) const
{
    const auto streamingSize = drawingStateTest.GetStreamingSize() - CORE_TOOLS_STREAM_SIZE(DrawingStateTest::GetCurrentRttiType().GetName());

#ifdef SYSTEM_LITTLE_ENDIAN

    const auto index = streamingSize - CORE_TOOLS_STREAM_SIZE(GetGraphicsObjectType());

#else  // !SYSTEM_LITTLE_ENDIAN

    const auto index = streamingSize - 1;

#endif  // SYSTEM_LITTLE_ENDIAN

    return index;
}

void Rendering::DrawingStateTesting::LoadExceptionTest(const FileBufferSharedPtr& saveFileBuffer)
{
    CoreTools::BufferSource bufferSource{ saveFileBuffer };

    auto saveTestingType = DrawingStateTest::Create(GetGraphicsObjectName(), GetGraphicsObjectType());

    saveTestingType->Load(bufferSource);
}
