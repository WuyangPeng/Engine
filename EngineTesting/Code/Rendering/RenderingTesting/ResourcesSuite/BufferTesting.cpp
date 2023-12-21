/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/12 19:18)

#include "BufferTesting.h"
#include "Detail/BufferTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBaseDetail.h"
#include "Rendering/Resources/Buffers/MemberLayout.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

#include <gsl/pointers>

Rendering::BufferTesting::BufferTesting(const OStreamShared& stream)
    : ParentType{ stream, GraphicsObjectType::Buffer, GraphicsObjectType::NumTypes, "Buffer" }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BufferTesting)

Rendering::GraphicsObjectSharedPtr Rendering::BufferTesting::Create(const std::string& name, GraphicsObjectType graphicsObjectType) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<BufferTest>(name, graphicsObjectType);
}

int Rendering::BufferTesting::GetStreamSizeShifting() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return 7 * CoreTools::GetStreamSize<int32_t>();
}

void Rendering::BufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::BufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest<BufferTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneObjectTest<BufferTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest<BufferTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(IsNullObjectTest<BufferTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIdTest<BufferTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest<BufferTest>);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateStorageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ActiveElementTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StorageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CheckMemberTest);
}

void Rendering::BufferTesting::DefaultTest()
{
    BufferTest bufferTest{ GetGraphicsObjectName(), GetGraphicsObjectType() };

    ASSERT_FALSE(bufferTest.IsCreateStorage());
    ASSERT_EQUAL(bufferTest.GetNumElements(), 0);
    ASSERT_EQUAL(bufferTest.GetElementSize(), 0);
    ASSERT_EQUAL(bufferTest.GetNumBytes(), 0);
    ASSERT_ENUM_EQUAL(bufferTest.GetUsage(), UsageType::Immutable);
    ASSERT_ENUM_EQUAL(bufferTest.GetCopy(), CopyType::None);
    ASSERT_EQUAL(bufferTest.GetOffset(), 0);
    ASSERT_EQUAL(bufferTest.GetNumActiveElements(), 0);
    ASSERT_EQUAL(bufferTest.GetNumActiveBytes(), 0);

    bufferTest.SetUsage(UsageType::DynamicUpdate);
    ASSERT_ENUM_EQUAL(bufferTest.GetUsage(), UsageType::DynamicUpdate);

    bufferTest.SetCopy(CopyType::Bidirectional);
    ASSERT_ENUM_EQUAL(bufferTest.GetCopy(), CopyType::Bidirectional);
}

void Rendering::BufferTesting::CreateStorageTest()
{
    constexpr auto numElements = 5;
    constexpr auto elementSize = 6;
    constexpr auto numBytes = numElements * elementSize;

    BufferTest bufferTest0{ GetGraphicsObjectName(), numElements, elementSize, GetGraphicsObjectType(), true };

    ASSERT_TRUE(bufferTest0.IsCreateStorage());
    ASSERT_EQUAL(bufferTest0.GetNumElements(), numElements);
    ASSERT_EQUAL(bufferTest0.GetElementSize(), elementSize);
    ASSERT_EQUAL(bufferTest0.GetNumBytes(), numBytes);
    ASSERT_EQUAL(bufferTest0.GetNumActiveElements(), numElements);
    ASSERT_EQUAL(bufferTest0.GetNumActiveBytes(), numBytes);

    bufferTest0.DestroyStorage();
    ASSERT_FALSE(bufferTest0.IsCreateStorage());

    bufferTest0.CreateStorage();
    ASSERT_TRUE(bufferTest0.IsCreateStorage());

    BufferTest bufferTest1{ GetGraphicsObjectName(), numElements, elementSize, GetGraphicsObjectType(), false };

    ASSERT_FALSE(bufferTest1.IsCreateStorage());
    ASSERT_EQUAL(bufferTest1.GetNumElements(), numElements);
    ASSERT_EQUAL(bufferTest1.GetElementSize(), elementSize);
    ASSERT_EQUAL(bufferTest1.GetNumBytes(), numBytes);
    ASSERT_EQUAL(bufferTest1.GetNumActiveElements(), numElements);
    ASSERT_EQUAL(bufferTest1.GetNumActiveBytes(), numBytes);

    bufferTest1.CreateStorage();
    ASSERT_TRUE(bufferTest1.IsCreateStorage());

    bufferTest1.DestroyStorage();
    ASSERT_FALSE(bufferTest1.IsCreateStorage());

    const BufferTest::StorageType storage(numBytes);
    BufferTest bufferTest2{ GetGraphicsObjectName(), numElements, elementSize, storage, GetGraphicsObjectType() };

    ASSERT_TRUE(bufferTest2.IsCreateStorage());
    ASSERT_EQUAL(bufferTest2.GetNumElements(), numElements);
    ASSERT_EQUAL(bufferTest2.GetElementSize(), elementSize);
    ASSERT_EQUAL(bufferTest2.GetNumBytes(), numBytes);
    ASSERT_EQUAL(bufferTest2.GetNumActiveElements(), numElements);
    ASSERT_EQUAL(bufferTest2.GetNumActiveBytes(), numBytes);

    bufferTest2.DestroyStorage();
    ASSERT_FALSE(bufferTest2.IsCreateStorage());

    bufferTest2.CreateStorage();
    ASSERT_TRUE(bufferTest2.IsCreateStorage());
}

void Rendering::BufferTesting::ActiveElementTest()
{
    constexpr auto numElements = 5;
    constexpr auto elementSize = 6;

    BufferTest bufferTest{ GetGraphicsObjectName(), numElements, elementSize, GetGraphicsObjectType(), true };

    ASSERT_EQUAL(bufferTest.GetNumActiveElements(), numElements);

    bufferTest.SetNumActiveElements(1);
    ASSERT_EQUAL(bufferTest.GetNumActiveElements(), 1);
    ASSERT_EQUAL(bufferTest.GetNumActiveBytes(), elementSize);
}

void Rendering::BufferTesting::StorageTest()
{
    constexpr auto numElements = 5;
    constexpr auto elementSize = 6;
    constexpr auto numBytes = numElements * elementSize;

    BufferTest bufferTest{ GetGraphicsObjectName(), numElements, elementSize, GetGraphicsObjectType(), true };

    constexpr auto testValue0 = 'a';
    constexpr auto testValue1 = 'b';
    BufferTest::StorageType storage(numBytes);
    storage.at(0) = testValue0;
    storage.at(2) = testValue1;

    bufferTest.SetStorage(storage);

    auto span0 = bufferTest.GetStorage();

    ASSERT_EQUAL(span0.Increase<char>(), testValue0);

    const gsl::not_null data0{ bufferTest.GetOriginalData() };

    ASSERT_EQUAL(*data0, testValue0);

    auto span1 = bufferTest.GetStorage(2);

    ASSERT_EQUAL(span1.Increase<char>(), testValue1);

    const gsl::not_null data1{ bufferTest.GetOriginalData(2) };

    ASSERT_EQUAL(*data1, testValue1);
}

void Rendering::BufferTesting::CheckMemberTest()
{
    constexpr auto numElements = 5;
    constexpr auto elementSize = 6;

    BufferTest bufferTest{ GetGraphicsObjectName(), numElements, elementSize, GetGraphicsObjectType(), true };

    const MemberLayout memberLayout0{ GetGraphicsObjectName(), 0, numElements };

    bufferTest.CheckMember(0, memberLayout0);

    const MemberLayout memberLayout1{ GetGraphicsObjectName(), 0, 0 };

    bufferTest.CheckMember(memberLayout1);
}
