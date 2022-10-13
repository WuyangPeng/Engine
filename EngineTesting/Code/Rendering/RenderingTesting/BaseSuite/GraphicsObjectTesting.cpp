///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/21 14:12)

#include "GraphicsObjectTesting.h"
#include "GraphicsObjectTestingBaseDetail.h"
#include "Detail/GraphicsObjectTest.h"
#include "System/Helper/EnumMacro.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
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

namespace Rendering
{
    ENUM_INCREMENTABLE_OPERATOR_DEFINE(GraphicsObjectType)
}

Rendering::GraphicsObjectTesting::GraphicsObjectTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    ASSERT_NOT_THROW_EXCEPTION_0(CloneObjectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetObjectByNameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IsNullObjectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIDTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
}

void Rendering::GraphicsObjectTesting::AccessTest()
{
    for (auto graphicsObjectType = GraphicsObjectType::None; graphicsObjectType < GraphicsObjectType::NumTypes; ++graphicsObjectType)
    {
        const auto name = "GraphicsObjectTest" + std::to_string(System::EnumCastUnderlying(graphicsObjectType));

        auto graphicsObjectTest = GraphicsObjectTest::Create(name, graphicsObjectType);

        ASSERT_EQUAL(graphicsObjectTest->GetName(), name);
        ASSERT_ENUM_EQUAL(graphicsObjectTest->GetType(), graphicsObjectType);

        BufferTest(graphicsObjectType, *graphicsObjectTest);
        TextureTest(graphicsObjectType, *graphicsObjectTest);
        TextureArrayTest(graphicsObjectType, *graphicsObjectTest);
        ShaderTest(graphicsObjectType, *graphicsObjectTest);
        DrawingStateTest(graphicsObjectType, *graphicsObjectTest);
    }
}

void Rendering::GraphicsObjectTesting::BufferTest(GraphicsObjectType graphicsObjectType, const GraphicsObjectTest& graphicsObjectTest)
{
    if (GraphicsObjectType::Buffer <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::IndirectArgumentsBuffer)
    {
        ASSERT_TRUE(graphicsObjectTest.IsBuffer());
    }
    else
    {
        ASSERT_FALSE(graphicsObjectTest.IsBuffer());
    }
}

void Rendering::GraphicsObjectTesting::TextureTest(GraphicsObjectType graphicsObjectType, const GraphicsObjectTest& graphicsObjectTest)
{
    if (GraphicsObjectType::TextureSingle <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::Texture3)
    {
        ASSERT_TRUE(graphicsObjectTest.IsTexture());
    }
    else
    {
        ASSERT_FALSE(graphicsObjectTest.IsTexture());
    }
}

void Rendering::GraphicsObjectTesting::TextureArrayTest(GraphicsObjectType graphicsObjectType, const GraphicsObjectTest& graphicsObjectTest)
{
    if (GraphicsObjectType::TextureArray <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::TextureCubeArray)
    {
        ASSERT_TRUE(graphicsObjectTest.IsTextureArray());
    }
    else
    {
        ASSERT_FALSE(graphicsObjectTest.IsTextureArray());
    }
}

void Rendering::GraphicsObjectTesting::ShaderTest(GraphicsObjectType graphicsObjectType, const GraphicsObjectTest& graphicsObjectTest)
{
    if (GraphicsObjectType::Shader <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::ComputeShader)
    {
        ASSERT_TRUE(graphicsObjectTest.IsShader());
    }
    else
    {
        ASSERT_FALSE(graphicsObjectTest.IsShader());
    }
}

void Rendering::GraphicsObjectTesting::DrawingStateTest(GraphicsObjectType graphicsObjectType, const GraphicsObjectTest& graphicsObjectTest)
{
    if (GraphicsObjectType::DrawingState <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::RasterizerState)
    {
        ASSERT_TRUE(graphicsObjectTest.IsDrawingState());
    }
    else
    {
        ASSERT_FALSE(graphicsObjectTest.IsDrawingState());
    }
}

void Rendering::GraphicsObjectTesting::CloneObjectTest()
{
    for (auto graphicsObjectType = GraphicsObjectType::None; graphicsObjectType < GraphicsObjectType::NumTypes; ++graphicsObjectType)
    {
        const auto name = "GraphicsObjectTest" + std::to_string(System::EnumCastUnderlying(graphicsObjectType));

        auto graphicsObjectTest = GraphicsObjectTest::Create(name, graphicsObjectType);

        auto clone = boost::polymorphic_pointer_cast<GraphicsObjectTest>(graphicsObjectTest->CloneObject());

        ASSERT_EQUAL(graphicsObjectTest->GetName(), clone->GetName());
        ASSERT_ENUM_EQUAL(graphicsObjectTest->GetType(), clone->GetType());
    }
}

void Rendering::GraphicsObjectTesting::GetObjectByNameTest()
{
    for (auto graphicsObjectType = GraphicsObjectType::None; graphicsObjectType < GraphicsObjectType::NumTypes; ++graphicsObjectType)
    {
        const auto name = "GraphicsObjectTest" + std::to_string(System::EnumCastUnderlying(graphicsObjectType));

        auto graphicsObjectTest = GraphicsObjectTest::Create(name, graphicsObjectType);

        auto clone = boost::polymorphic_pointer_cast<GraphicsObjectTest>(graphicsObjectTest->CloneObject());
        auto object = boost::polymorphic_pointer_cast<GraphicsObjectTest>(clone->GetObjectByName(name));

        ASSERT_EQUAL(graphicsObjectTest->GetName(), object->GetName());
        ASSERT_ENUM_EQUAL(graphicsObjectTest->GetType(), object->GetType());

        auto constObject = boost::polymorphic_pointer_cast<const GraphicsObjectTest>(clone->GetConstObjectByName(name));

        ASSERT_EQUAL(graphicsObjectTest->GetName(), constObject->GetName());
        ASSERT_ENUM_EQUAL(graphicsObjectTest->GetType(), constObject->GetType());

        auto allObject = clone->GetAllObjectsByName(name);

        ASSERT_EQUAL(allObject.size(), 1u);
        ASSERT_EQUAL(allObject.at(0), object);

        auto allConstObject = clone->GetAllConstObjectsByName(name);

        ASSERT_EQUAL(allConstObject.size(), 1u);
        ASSERT_EQUAL(allConstObject.at(0), constObject);
    }
}

void Rendering::GraphicsObjectTesting::IsNullObjectTest()
{
    const auto graphicsObjectType = GraphicsObjectType::None;
    const auto name = "GraphicsObjectTest";

    auto graphicsObjectTest = GraphicsObjectTest::Create(name, graphicsObjectType);
    ASSERT_FALSE(graphicsObjectTest->IsNullObject());
}

void Rendering::GraphicsObjectTesting::UniqueIDTest()
{
    const auto graphicsObjectType = GraphicsObjectType::None;
    const auto name = "GraphicsObjectTest";

    auto graphicsObjectTest = GraphicsObjectTest::Create(name, graphicsObjectType);
    ASSERT_LESS(0, graphicsObjectTest->GetUniqueID());

    constexpr auto uniqueID = 7;
    graphicsObjectTest->SetUniqueID(uniqueID);
    ASSERT_EQUAL(graphicsObjectTest->GetUniqueID(), uniqueID);
}

void Rendering::GraphicsObjectTesting::StreamTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_THROW_EXCEPTION_0(FactoryExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SaveTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::GraphicsObjectTesting::FactoryTest()
{
    GraphicsObjectTest::InitializeFactory();

    auto factoryFunction = OBJECT_MANAGER_SINGLETON.Find(GraphicsObjectTest::GetCurrentRttiType().GetName());

    ASSERT_UNEQUAL_NULL_PTR(factoryFunction);
}

void Rendering::GraphicsObjectTesting::FactoryExceptionTest()
{
    GraphicsObjectTest::TerminateFactory();

    MAYBE_UNUSED const auto factoryFunction = OBJECT_MANAGER_SINGLETON.Find(GraphicsObjectTest::GetCurrentRttiType().GetName());
}

void Rendering::GraphicsObjectTesting::GetStreamingSizeTest()
{
    const auto graphicsObjectType = GraphicsObjectType::None;
    const auto name = "GraphicsObjectTest";

    auto graphicsObjectTest = GraphicsObjectTest::Create(name, graphicsObjectType);

    auto streamingSize = CORE_TOOLS_STREAM_SIZE(GraphicsObjectTest::GetCurrentRttiType().GetName());
    streamingSize += CORE_TOOLS_STREAM_SIZE(graphicsObjectTest);
    streamingSize += CORE_TOOLS_STREAM_SIZE(name);
    streamingSize += CORE_TOOLS_STREAM_SIZE(graphicsObjectType);

    ASSERT_EQUAL(streamingSize, graphicsObjectTest->GetStreamingSize());
}

void Rendering::GraphicsObjectTesting::RegisterTest()
{
    const auto graphicsObjectType = GraphicsObjectType::None;
    const auto name = "GraphicsObjectTest";

    auto graphicsObjectTest = GraphicsObjectTest::Create(name, graphicsObjectType);

    auto objectRegister = CoreTools::ObjectRegister::Create();
    ASSERT_EQUAL(1, graphicsObjectTest->Register(*objectRegister));
}

void Rendering::GraphicsObjectTesting::LinkTest()
{
    const auto graphicsObjectType = GraphicsObjectType::None;
    const auto name = "GraphicsObjectTest";

    auto graphicsObjectTest = GraphicsObjectTest::Create(name, graphicsObjectType);

    auto objectLink = CoreTools::ObjectLink::Create();
    graphicsObjectTest->Link(*objectLink);

    graphicsObjectTest->PostLink();
}

void Rendering::GraphicsObjectTesting::SaveTest()
{
    constexpr auto noneGraphicsObjectType = GraphicsObjectType::None;
    const auto defaultName = "GraphicsObjectTest";

    for (auto graphicsObjectType = noneGraphicsObjectType; graphicsObjectType < GraphicsObjectType::NumTypes; ++graphicsObjectType)
    {
        const auto name = defaultName + std::to_string(System::EnumCastUnderlying(graphicsObjectType));

        auto graphicsObjectTest = GraphicsObjectTest::Create(name, graphicsObjectType);

        auto objectRegister = CoreTools::ObjectRegister::Create();
        ASSERT_EQUAL(1, graphicsObjectTest->Register(*objectRegister));
        CoreTools::BufferTarget bufferTarget{ 1024, objectRegister };

        graphicsObjectTest->Save(bufferTarget);

        auto fileBuffer = bufferTarget.GetFileBuffer();

        std::vector<char> buffer{ fileBuffer->begin(), fileBuffer->end() };

        const auto streamingSize = CORE_TOOLS_STREAM_SIZE(GraphicsObjectTest::GetCurrentRttiType().GetName());

        std::string saveName{};
        for (auto i = 0; i < streamingSize; ++i)
        {
            saveName.push_back(buffer.at(i));
        }

        auto saveFileBuffer = std::make_shared<CoreTools::FileBuffer>(buffer.size());

        for (auto i = streamingSize; i < boost::numeric_cast<int>(buffer.size()); ++i)
        {
            *(saveFileBuffer->GetBuffer(i - streamingSize)) = buffer.at(i);
        }

        CoreTools::BufferSource bufferSource{ saveFileBuffer };

        auto saveGraphicsObjectTest = GraphicsObjectTest::Create(defaultName, noneGraphicsObjectType);
        saveGraphicsObjectTest->Load(bufferSource);

        ASSERT_EQUAL(saveGraphicsObjectTest->GetName(), graphicsObjectTest->GetName());
        ASSERT_EQUAL(saveGraphicsObjectTest->GetType(), graphicsObjectTest->GetType());
    }
}
