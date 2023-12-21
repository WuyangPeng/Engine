/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/12 14:55)

#include "ResourceTesting.h"
#include "Detail/ResourcesTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBaseDetail.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

#include <gsl/pointers>

Rendering::ResourceTesting::ResourceTesting(const OStreamShared& stream)
    : ParentType{ stream, GraphicsObjectType::Resource, GraphicsObjectType::NumTypes, "Resource" }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ResourceTesting)

Rendering::GraphicsObjectSharedPtr Rendering::ResourceTesting::Create(const std::string& name, GraphicsObjectType graphicsObjectType) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ResourcesTest>(name, graphicsObjectType);
}

int Rendering::ResourceTesting::GetStreamSizeShifting() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return 7 * CoreTools::GetStreamSize<int32_t>();
}

void Rendering::ResourceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ResourceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest<ResourcesTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneObjectTest<ResourcesTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest<ResourcesTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(IsNullObjectTest<ResourcesTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIdTest<ResourcesTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest<ResourcesTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateStorageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ActiveElementTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StorageTest);
}

void Rendering::ResourceTesting::DefaultTest()
{
    ResourcesTest resourceTest{ GetGraphicsObjectName(), GetGraphicsObjectType() };

    ASSERT_FALSE(resourceTest.IsCreateStorage());
    ASSERT_EQUAL(resourceTest.GetNumElements(), 0);
    ASSERT_EQUAL(resourceTest.GetElementSize(), 0);
    ASSERT_EQUAL(resourceTest.GetNumBytes(), 0);
    ASSERT_ENUM_EQUAL(resourceTest.GetUsage(), UsageType::Immutable);
    ASSERT_ENUM_EQUAL(resourceTest.GetCopy(), CopyType::None);
    ASSERT_EQUAL(resourceTest.GetOffset(), 0);
    ASSERT_EQUAL(resourceTest.GetNumActiveElements(), 0);
    ASSERT_EQUAL(resourceTest.GetNumActiveBytes(), 0);

    resourceTest.SetUsage(UsageType::DynamicUpdate);
    ASSERT_ENUM_EQUAL(resourceTest.GetUsage(), UsageType::DynamicUpdate);

    resourceTest.SetCopy(CopyType::Bidirectional);
    ASSERT_ENUM_EQUAL(resourceTest.GetCopy(), CopyType::Bidirectional);
}

void Rendering::ResourceTesting::CreateStorageTest()
{
    constexpr auto numElements = 5;
    constexpr auto elementSize = 6;
    constexpr auto numBytes = numElements * elementSize;

    ResourcesTest resourceTest0{ GetGraphicsObjectName(), numElements, elementSize, GetGraphicsObjectType(), true };

    ASSERT_TRUE(resourceTest0.IsCreateStorage());
    ASSERT_EQUAL(resourceTest0.GetNumElements(), numElements);
    ASSERT_EQUAL(resourceTest0.GetElementSize(), elementSize);
    ASSERT_EQUAL(resourceTest0.GetNumBytes(), numBytes);
    ASSERT_EQUAL(resourceTest0.GetNumActiveElements(), numElements);
    ASSERT_EQUAL(resourceTest0.GetNumActiveBytes(), numBytes);

    resourceTest0.DestroyStorage();
    ASSERT_FALSE(resourceTest0.IsCreateStorage());

    resourceTest0.CreateStorage();
    ASSERT_TRUE(resourceTest0.IsCreateStorage());

    ResourcesTest resourceTest1{ GetGraphicsObjectName(), numElements, elementSize, GetGraphicsObjectType(), false };

    ASSERT_FALSE(resourceTest1.IsCreateStorage());
    ASSERT_EQUAL(resourceTest1.GetNumElements(), numElements);
    ASSERT_EQUAL(resourceTest1.GetElementSize(), elementSize);
    ASSERT_EQUAL(resourceTest1.GetNumBytes(), numBytes);
    ASSERT_EQUAL(resourceTest1.GetNumActiveElements(), numElements);
    ASSERT_EQUAL(resourceTest1.GetNumActiveBytes(), numBytes);

    resourceTest1.CreateStorage();
    ASSERT_TRUE(resourceTest1.IsCreateStorage());

    resourceTest1.DestroyStorage();
    ASSERT_FALSE(resourceTest1.IsCreateStorage());

    const ResourcesTest::StorageType storage(numBytes);
    ResourcesTest resourceTest2{ GetGraphicsObjectName(), numElements, elementSize, storage, GetGraphicsObjectType() };

    ASSERT_TRUE(resourceTest2.IsCreateStorage());
    ASSERT_EQUAL(resourceTest2.GetNumElements(), numElements);
    ASSERT_EQUAL(resourceTest2.GetElementSize(), elementSize);
    ASSERT_EQUAL(resourceTest2.GetNumBytes(), numBytes);
    ASSERT_EQUAL(resourceTest2.GetNumActiveElements(), numElements);
    ASSERT_EQUAL(resourceTest2.GetNumActiveBytes(), numBytes);

    resourceTest2.DestroyStorage();
    ASSERT_FALSE(resourceTest2.IsCreateStorage());

    resourceTest2.CreateStorage();
    ASSERT_TRUE(resourceTest2.IsCreateStorage());
}

void Rendering::ResourceTesting::ActiveElementTest()
{
    constexpr auto numElements = 5;
    constexpr auto elementSize = 6;

    ResourcesTest resourceTest{ GetGraphicsObjectName(), numElements, elementSize, GetGraphicsObjectType(), true };

    ASSERT_EQUAL(resourceTest.GetNumActiveElements(), 5);

    resourceTest.SetNumActiveElements(1);
    ASSERT_EQUAL(resourceTest.GetNumActiveElements(), 1);
    ASSERT_EQUAL(resourceTest.GetNumActiveBytes(), elementSize);
}

void Rendering::ResourceTesting::StorageTest()
{
    constexpr auto numElements = 5;
    constexpr auto elementSize = 6;
    constexpr auto numBytes = numElements * elementSize;

    ResourcesTest resourceTest{ GetGraphicsObjectName(), numElements, elementSize, GetGraphicsObjectType(), true };

    constexpr auto testValue0 = 'a';
    constexpr auto testValue1 = 'b';
    ResourcesTest::StorageType storage(numBytes);
    storage.at(0) = testValue0;
    storage.at(2) = testValue1;

    resourceTest.SetStorage(storage);

    auto span0 = resourceTest.GetStorage();

    ASSERT_EQUAL(span0.Increase<char>(), testValue0);

    const gsl::not_null data0{ resourceTest.GetOriginalData() };

    ASSERT_EQUAL(*data0, testValue0);

    auto span1 = resourceTest.GetStorage(2);

    ASSERT_EQUAL(span1.Increase<char>(), testValue1);

    const gsl::not_null data1{ resourceTest.GetOriginalData(2) };

    ASSERT_EQUAL(*data1, testValue1);
}