///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:06)

#ifndef RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_DETAIL_H
#define RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_DETAIL_H

#include "GraphicsObjectTestingBase.h"
#include "System/Helper/EnumOperator.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"

template <typename TestingType>
std::shared_ptr<TestingType> Rendering::GraphicsObjectTestingBase::Create(const std::string& name, GraphicsObjectType graphicsObjectType)
{
    return boost::polymorphic_pointer_cast<TestingType>(Create(name, graphicsObjectType));
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::RttiTest()
{
    auto testingType = Create<TestingType>(graphicsObjectName, beginGraphicsObjectType);

    GraphicsObjectRttiTrueTest(testingType, testingType);

    const auto nullObject = TestingType::GetNullObject();

    GraphicsObjectRttiFalseTest(testingType, nullObject);
    GraphicsObjectRttiFalseTest(nullObject, testingType);
}

template <typename LhsTestingTypeSharedPtr, typename RhsTestingTypeSharedPtr>
void Rendering::GraphicsObjectTestingBase::GraphicsObjectRttiTrueTest(const LhsTestingTypeSharedPtr& lhs, const RhsTestingTypeSharedPtr& rhs)
{
    ASSERT_TRUE(lhs->IsExactly(rhs->GetRttiType()));
    ASSERT_TRUE(lhs->IsDerived(rhs->GetRttiType()));

    ASSERT_TRUE(lhs->IsExactlyTypeOf(rhs.get()));
    ASSERT_TRUE(lhs->IsDerivedTypeOf(rhs.get()));
}

template <typename LhsTestingTypeSharedPtr, typename RhsTestingTypeSharedPtr>
void Rendering::GraphicsObjectTestingBase::GraphicsObjectRttiFalseTest(const LhsTestingTypeSharedPtr& lhs, const RhsTestingTypeSharedPtr& rhs)
{
    ASSERT_FALSE(lhs->IsExactly(rhs->GetRttiType()));
    ASSERT_FALSE(lhs->IsDerived(rhs->GetRttiType()));

    ASSERT_FALSE(lhs->IsExactlyTypeOf(rhs.get()));
    ASSERT_FALSE(lhs->IsDerivedTypeOf(rhs.get()));
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::CloneObjectTest()
{
    using System::operator++;
    for (auto type = beginGraphicsObjectType; type < endGraphicsObjectType; type = System::UnderlyingCastEnum<GraphicsObjectType>(System::EnumCastUnderlying(type) + 1))
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CloneObjectTrueTest<TestingType>, type);
    }
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::CloneObjectTrueTest(GraphicsObjectType graphicsObjectType)
{
    const auto name = graphicsObjectName + std::to_string(System::EnumCastUnderlying(graphicsObjectType));

    auto testingType = Create<TestingType>(name, graphicsObjectType);

    auto clone = boost::polymorphic_pointer_cast<TestingType>(testingType->CloneObject());

    ASSERT_EQUAL(testingType->GetName(), clone->GetName());
    ASSERT_ENUM_EQUAL(testingType->GetType(), clone->GetType());
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::IsNullObjectTest()
{
    auto testingType = Create<TestingType>(graphicsObjectName, beginGraphicsObjectType);
    ASSERT_FALSE(testingType->IsNullObject());
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::UniqueIDTest()
{
    auto testingType = Create<TestingType>(graphicsObjectName, beginGraphicsObjectType);
    ASSERT_LESS(0, testingType->GetUniqueId());

    constexpr auto uniqueID = 7;
    testingType->SetUniqueId(uniqueID);
    ASSERT_EQUAL(testingType->GetUniqueId(), uniqueID);
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::FactoryTest()
{
    TestingType::InitializeFactory();

    auto factoryFunction = OBJECT_MANAGER_SINGLETON.Find(TestingType::GetCurrentRttiType().GetName());

    ASSERT_UNEQUAL_NULL_PTR(factoryFunction);
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::FactoryExceptionTest()
{
    TestingType::TerminateFactory();

    MAYBE_UNUSED const auto factoryFunction = OBJECT_MANAGER_SINGLETON.Find(TestingType::GetCurrentRttiType().GetName());
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::NameTest()
{
    using System::operator++;
    for (auto type = beginGraphicsObjectType; type < endGraphicsObjectType; type = System::UnderlyingCastEnum<GraphicsObjectType>(System::EnumCastUnderlying(type) + 1))
    {
        const auto name = graphicsObjectName + std::to_string(System::EnumCastUnderlying(type));

        auto testingType = Create<TestingType>(name, type);

        ASSERT_NOT_THROW_EXCEPTION_2(GetObjectByNameTest<TestingType>, *testingType, name);
        ASSERT_NOT_THROW_EXCEPTION_2(GetConstObjectByNameTest<TestingType>, *testingType, name);
        ASSERT_NOT_THROW_EXCEPTION_2(GetAllObjectsByNameTest<TestingType>, *testingType, name);
        ASSERT_NOT_THROW_EXCEPTION_2(GetAllConstObjectsByNameTest<TestingType>, *testingType, name);
    }
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::GetObjectByNameTest(const TestingType& testingType, const std::string& name)
{
    auto clone = boost::polymorphic_pointer_cast<TestingType>(testingType.CloneObject());
    auto object = boost::polymorphic_pointer_cast<TestingType>(clone->GetObjectByName(name));

    ASSERT_EQUAL(testingType.GetName(), object->GetName());
    ASSERT_ENUM_EQUAL(testingType.GetType(), object->GetType());
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::GetConstObjectByNameTest(const TestingType& testingType, const std::string& name)
{
    auto clone = boost::polymorphic_pointer_cast<TestingType>(testingType.CloneObject());
    auto constObject = boost::polymorphic_pointer_cast<const TestingType>(clone->GetConstObjectByName(name));

    ASSERT_EQUAL(testingType.GetName(), constObject->GetName());
    ASSERT_ENUM_EQUAL(testingType.GetType(), constObject->GetType());
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::GetAllObjectsByNameTest(const TestingType& testingType, const std::string& name)
{
    auto clone = boost::polymorphic_pointer_cast<TestingType>(testingType.CloneObject());
    auto allObject = clone->GetAllObjectsByName(name);

    ASSERT_EQUAL_FAILURE_THROW(allObject.size(), 1u, "未找到名字为" + name + "的对象。");

    auto object = boost::polymorphic_pointer_cast<TestingType>(allObject.at(0));

    ASSERT_EQUAL(testingType.GetName(), object->GetName());
    ASSERT_ENUM_EQUAL(testingType.GetType(), object->GetType());
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::GetAllConstObjectsByNameTest(const TestingType& testingType, const std::string& name)
{
    auto clone = boost::polymorphic_pointer_cast<TestingType>(testingType.CloneObject());
    auto allConstObject = clone->GetAllConstObjectsByName(name);

    ASSERT_EQUAL_FAILURE_THROW(allConstObject.size(), 1u, "未找到名字为" + name + "的对象。");

    auto constObject = boost::polymorphic_pointer_cast<const TestingType>(allConstObject.at(0));

    ASSERT_EQUAL(testingType.GetName(), constObject->GetName());
    ASSERT_ENUM_EQUAL(testingType.GetType(), constObject->GetType());
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::StreamTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest<TestingType>);
    ASSERT_THROW_EXCEPTION_0(FactoryExceptionTest<TestingType>);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest<TestingType>);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest<TestingType>);
    ASSERT_NOT_THROW_EXCEPTION_0(RegisterTest<TestingType>);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkTest<TestingType>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamCreateTest<TestingType>);

    CoreTools::InitTerm::ExecuteTerminator();
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::GetStreamingSizeTest()
{
    auto testingType = Create<TestingType>(graphicsObjectName, beginGraphicsObjectType);

    auto streamingSize = CoreTools::GetStreamSize(TestingType::GetCurrentRttiType().GetName());
    streamingSize += 8;
    streamingSize += CoreTools::GetStreamSize(graphicsObjectName);
    streamingSize += CoreTools::GetStreamSize(beginGraphicsObjectType);

    ASSERT_EQUAL(streamingSize, testingType->GetStreamingSize());
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::RegisterTest()
{
    auto testingType = Create<TestingType>(graphicsObjectName, beginGraphicsObjectType);

    auto objectRegister = CoreTools::ObjectRegister::Create();
    ASSERT_EQUAL(1, testingType->Register(*objectRegister));
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::LinkTest()
{
    auto testingType = Create<TestingType>(graphicsObjectName, beginGraphicsObjectType);

    auto objectLink = CoreTools::ObjectLink::Create();
    testingType->Link(*objectLink);

    testingType->PostLink();
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::StreamCreateTest()
{
    using System::operator++;
    for (auto type = beginGraphicsObjectType; type < endGraphicsObjectType; type = System::UnderlyingCastEnum<GraphicsObjectType>(System::EnumCastUnderlying(type) + 1))
    {
        const auto name = graphicsObjectName + std::to_string(System::EnumCastUnderlying(type));

        auto testingType = Create<TestingType>(name, type);

        auto saveFileBuffer = SaveTest<TestingType>(*testingType);
        ASSERT_NOT_THROW_EXCEPTION_2(LoadTest<TestingType>, saveFileBuffer, *testingType);
    }
}

template <typename TestingType>
CoreTools::FileBufferSharedPtr Rendering::GraphicsObjectTestingBase::SaveTest(const TestingType& testingType)
{
    auto bufferTarget = CreateBufferTarget(testingType);
    testingType.Save(bufferTarget);

    auto fileBuffer = bufferTarget.GetFileBuffer();

    OriginalBuffer buffer{ fileBuffer->begin(), fileBuffer->end() };

    const auto streamingSize = CoreTools::GetStreamSize(TestingType::GetCurrentRttiType().GetName());

    RttiNameTest<TestingType>(streamingSize, buffer);

    return CorrectFileBuffer(streamingSize, buffer);
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::RttiNameTest(int endIndex, const OriginalBuffer& buffer)
{
    ASSERT_LESS_EQUAL_FAILURE_THROW(endIndex, boost::numeric_cast<int>(buffer.size()), "缓冲区大小不足于复制字符串。");

    std::string rttiName{ buffer.begin(), buffer.begin() + endIndex };

    ASSERT_UNEQUAL(rttiName.find(TestingType::GetCurrentRttiType().GetName()), std::string::npos);
}

template <typename TestingType>
CoreTools::BufferTarget Rendering::GraphicsObjectTestingBase::CreateBufferTarget(const TestingType& testingType)
{
    constexpr auto bufferSize = 1024;
    auto objectRegister = CoreTools::ObjectRegister::Create();
    ASSERT_EQUAL(1, testingType.Register(*objectRegister));

    BufferTarget bufferTarget{ bufferSize, objectRegister };
    return bufferTarget;
}

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::LoadTest(const FileBufferSharedPtr& saveFileBuffer, const TestingType& testingType)
{
    CoreTools::BufferSource bufferSource{ saveFileBuffer };

    auto saveTestingType = Create<TestingType>(graphicsObjectName, beginGraphicsObjectType);

    saveTestingType->Load(bufferSource);

    ASSERT_EQUAL(saveTestingType->GetName(), testingType.GetName());
    ASSERT_EQUAL(saveTestingType->GetType(), testingType.GetType());
}

#endif  // RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_DETAIL_H
