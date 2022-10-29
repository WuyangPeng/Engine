///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/10/01 14:46)

#include "GraphicsObjectTesting.h"
#include "GraphicsObjectTestingBaseDetail.h"
#include "Detail/GraphicsObjectTest.h"
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

using namespace std::literals;

Rendering::GraphicsObjectTesting::GraphicsObjectTesting(const OStreamShared& stream)
    : ParentType{ stream, GraphicsObjectType::None, GraphicsObjectType::NumTypes, "GraphicsObjectTest"s }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GraphicsObjectTesting)

void Rendering::GraphicsObjectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::GraphicsObjectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest<GraphicsObjectTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneObjectTest<GraphicsObjectTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest<GraphicsObjectTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(IsNullObjectTest<GraphicsObjectTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIDTest<GraphicsObjectTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest<GraphicsObjectTest>);
}

void Rendering::GraphicsObjectTesting::AccessTest()
{
    for (auto type = GraphicsObjectType::None; type < GraphicsObjectType::NumTypes; ++type)
    {
        const auto name = GetGraphicsObjectName() + std::to_string(System::EnumCastUnderlying(type));

        auto graphicsObjectTest = GraphicsObjectTest::Create(name, type);

        ASSERT_EQUAL(graphicsObjectTest->GetName(), name);
        ASSERT_ENUM_EQUAL(graphicsObjectTest->GetType(), type);

        ASSERT_NOT_THROW_EXCEPTION_2(BufferTest, type, *graphicsObjectTest);
        ASSERT_NOT_THROW_EXCEPTION_2(TextureTest, type, *graphicsObjectTest);
        ASSERT_NOT_THROW_EXCEPTION_2(TextureArrayTest, type, *graphicsObjectTest);
        ASSERT_NOT_THROW_EXCEPTION_2(ShaderTest, type, *graphicsObjectTest);
        ASSERT_NOT_THROW_EXCEPTION_2(DrawingStateTest, type, *graphicsObjectTest);
    }
}

void Rendering::GraphicsObjectTesting::BufferTest(GraphicsObjectType type, const GraphicsObjectTest& graphicsObjectTest)
{
    if (GraphicsObjectType::Buffer <= type && type <= GraphicsObjectType::IndirectArgumentsBuffer)
    {
        ASSERT_TRUE(graphicsObjectTest.IsBuffer());
    }
    else
    {
        ASSERT_FALSE(graphicsObjectTest.IsBuffer());
    }
}

void Rendering::GraphicsObjectTesting::TextureTest(GraphicsObjectType type, const GraphicsObjectTest& graphicsObjectTest)
{
    if (GraphicsObjectType::TextureSingle <= type && type <= GraphicsObjectType::Texture3)
    {
        ASSERT_TRUE(graphicsObjectTest.IsTexture());
    }
    else
    {
        ASSERT_FALSE(graphicsObjectTest.IsTexture());
    }
}

void Rendering::GraphicsObjectTesting::TextureArrayTest(GraphicsObjectType type, const GraphicsObjectTest& graphicsObjectTest)
{
    if (GraphicsObjectType::TextureArray <= type && type <= GraphicsObjectType::TextureCubeArray)
    {
        ASSERT_TRUE(graphicsObjectTest.IsTextureArray());
    }
    else
    {
        ASSERT_FALSE(graphicsObjectTest.IsTextureArray());
    }
}

void Rendering::GraphicsObjectTesting::ShaderTest(GraphicsObjectType type, const GraphicsObjectTest& graphicsObjectTest)
{
    if (GraphicsObjectType::Shader <= type && type <= GraphicsObjectType::ComputeShader)
    {
        ASSERT_TRUE(graphicsObjectTest.IsShader());
    }
    else
    {
        ASSERT_FALSE(graphicsObjectTest.IsShader());
    }
}

void Rendering::GraphicsObjectTesting::DrawingStateTest(GraphicsObjectType type, const GraphicsObjectTest& graphicsObjectTest)
{
    if (GraphicsObjectType::DrawingState <= type && type <= GraphicsObjectType::RasterizerState)
    {
        ASSERT_TRUE(graphicsObjectTest.IsDrawingState());
    }
    else
    {
        ASSERT_FALSE(graphicsObjectTest.IsDrawingState());
    }
}

Rendering::GraphicsObjectSharedPtr Rendering::GraphicsObjectTesting::Create(const std::string& name, GraphicsObjectType graphicsObjectType) const
{
    return GraphicsObjectTest::Create(name, graphicsObjectType);
}
