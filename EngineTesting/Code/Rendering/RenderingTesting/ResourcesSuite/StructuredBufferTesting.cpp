/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/13 09:58)

#include "StructuredBufferTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBaseDetail.h"
#include "Rendering/Resources/Buffers/MemberLayout.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/CounterType.h"
#include "Rendering/Resources/Flags/UsageType.h"

#include <gsl/pointers>

Rendering::StructuredBufferTesting::StructuredBufferTesting(const OStreamShared& stream)
    : ParentType{ stream, GraphicsObjectType::StructuredBuffer, GraphicsObjectType::StructuredBuffer, "StructuredBuffer" }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, StructuredBufferTesting)

Rendering::GraphicsObjectSharedPtr Rendering::StructuredBufferTesting::Create(const std::string& name, GraphicsObjectType graphicsObjectType) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    System::UnusedFunction(graphicsObjectType);

    return std::make_shared<StructuredBuffer>(name, numElements, elementSize);
}

int Rendering::StructuredBufferTesting::GetStreamSizeShifting() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return 9 * CoreTools::GetStreamSize<int32_t>() + numElements * elementSize;
}

void Rendering::StructuredBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::StructuredBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest<StructuredBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneObjectTest<StructuredBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest<StructuredBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(IsNullObjectTest<StructuredBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIdTest<StructuredBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest<StructuredBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateStorageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ActiveElementTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StorageTest);
}

void Rendering::StructuredBufferTesting::DefaultTest()
{
    StructuredBuffer structuredBuffer{ GetGraphicsObjectName(), numElements, elementSize, false };

    ASSERT_FALSE(structuredBuffer.IsCreateStorage());
    ASSERT_EQUAL(structuredBuffer.GetNumElements(), numElements);
    ASSERT_EQUAL(structuredBuffer.GetElementSize(), elementSize);
    ASSERT_EQUAL(structuredBuffer.GetNumBytes(), numBytes);
    ASSERT_EQUAL(structuredBuffer.GetUsage(), UsageType::Immutable);
    ASSERT_EQUAL(structuredBuffer.GetCopy(), CopyType::None);
    ASSERT_EQUAL(structuredBuffer.GetOffset(), 0);
    ASSERT_EQUAL(structuredBuffer.GetNumActiveElements(), numElements);
    ASSERT_EQUAL(structuredBuffer.GetNumActiveBytes(), numBytes);
    ASSERT_EQUAL(structuredBuffer.GetCounterType(), CounterType::None);
    ASSERT_FALSE(structuredBuffer.GetKeepInternalCount());

    structuredBuffer.SetUsage(UsageType::DynamicUpdate);
    ASSERT_EQUAL(structuredBuffer.GetUsage(), UsageType::DynamicUpdate);

    structuredBuffer.SetCopy(CopyType::Bidirectional);
    ASSERT_EQUAL(structuredBuffer.GetCopy(), CopyType::Bidirectional);

    structuredBuffer.SetKeepInternalCount(true);
    ASSERT_FALSE(structuredBuffer.GetKeepInternalCount());

    structuredBuffer.MakeAppendConsume();
    ASSERT_EQUAL(structuredBuffer.GetCounterType(), CounterType::AppendConsume);
    ASSERT_EQUAL(structuredBuffer.GetUsage(), UsageType::ShaderOutput);

    structuredBuffer.SetKeepInternalCount(true);
    ASSERT_TRUE(structuredBuffer.GetKeepInternalCount());

    structuredBuffer.SetUsage(UsageType::DynamicUpdate);
    ASSERT_EQUAL(structuredBuffer.GetUsage(), UsageType::DynamicUpdate);

    structuredBuffer.MakeCounter();
    ASSERT_EQUAL(structuredBuffer.GetCounterType(), CounterType::Counter);
    ASSERT_EQUAL(structuredBuffer.GetUsage(), UsageType::ShaderOutput);
}

void Rendering::StructuredBufferTesting::CreateStorageTest()
{
    StructuredBuffer structuredBuffer0{ GetGraphicsObjectName(), numElements, elementSize, true };

    ASSERT_TRUE(structuredBuffer0.IsCreateStorage());
    ASSERT_EQUAL(structuredBuffer0.GetNumElements(), numElements);
    ASSERT_EQUAL(structuredBuffer0.GetElementSize(), elementSize);
    ASSERT_EQUAL(structuredBuffer0.GetNumBytes(), numBytes);
    ASSERT_EQUAL(structuredBuffer0.GetNumActiveElements(), numElements);
    ASSERT_EQUAL(structuredBuffer0.GetNumActiveBytes(), numBytes);

    structuredBuffer0.DestroyStorage();
    ASSERT_FALSE(structuredBuffer0.IsCreateStorage());

    structuredBuffer0.CreateStorage();
    ASSERT_TRUE(structuredBuffer0.IsCreateStorage());

    StructuredBuffer structuredBuffer1{ GetGraphicsObjectName(), numElements, elementSize, false };

    ASSERT_FALSE(structuredBuffer1.IsCreateStorage());
    ASSERT_EQUAL(structuredBuffer1.GetNumElements(), numElements);
    ASSERT_EQUAL(structuredBuffer1.GetElementSize(), elementSize);
    ASSERT_EQUAL(structuredBuffer1.GetNumBytes(), numBytes);
    ASSERT_EQUAL(structuredBuffer1.GetNumActiveElements(), numElements);
    ASSERT_EQUAL(structuredBuffer1.GetNumActiveBytes(), numBytes);

    structuredBuffer1.CreateStorage();
    ASSERT_TRUE(structuredBuffer1.IsCreateStorage());

    structuredBuffer1.DestroyStorage();
    ASSERT_FALSE(structuredBuffer1.IsCreateStorage());

    const StructuredBuffer::StorageType storage(numBytes);
    StructuredBuffer structuredBuffer2{ GetGraphicsObjectName(), numElements, elementSize, storage };

    ASSERT_TRUE(structuredBuffer2.IsCreateStorage());
    ASSERT_EQUAL(structuredBuffer2.GetNumElements(), numElements);
    ASSERT_EQUAL(structuredBuffer2.GetElementSize(), elementSize);
    ASSERT_EQUAL(structuredBuffer2.GetNumBytes(), numBytes);
    ASSERT_EQUAL(structuredBuffer2.GetNumActiveElements(), numElements);
    ASSERT_EQUAL(structuredBuffer2.GetNumActiveBytes(), numBytes);

    structuredBuffer2.DestroyStorage();
    ASSERT_FALSE(structuredBuffer2.IsCreateStorage());

    structuredBuffer2.CreateStorage();
    ASSERT_TRUE(structuredBuffer2.IsCreateStorage());
}

void Rendering::StructuredBufferTesting::ActiveElementTest()
{
    StructuredBuffer structuredBuffer{ GetGraphicsObjectName(), numElements, elementSize, true };

    ASSERT_EQUAL(structuredBuffer.GetNumActiveElements(), 5);

    structuredBuffer.SetNumActiveElements(1);
    ASSERT_EQUAL(structuredBuffer.GetNumActiveElements(), 1);
    ASSERT_EQUAL(structuredBuffer.GetNumActiveBytes(), elementSize);
}

void Rendering::StructuredBufferTesting::StorageTest()
{
    StructuredBuffer structuredBuffer{ GetGraphicsObjectName(), numElements, elementSize, true };

    constexpr auto testValue0 = 'a';
    constexpr auto testValue1 = 'b';
    StructuredBuffer::StorageType storage(numBytes);
    storage.at(0) = testValue0;
    storage.at(2) = testValue1;

    structuredBuffer.SetStorage(storage);

    auto span0 = structuredBuffer.GetStorage();

    ASSERT_EQUAL(span0.Increase<char>(), testValue0);

    const gsl::not_null data0{ structuredBuffer.GetOriginalData() };

    ASSERT_EQUAL(*data0, testValue0);

    auto span1 = structuredBuffer.GetStorage(2);

    ASSERT_EQUAL(span1.Increase<char>(), testValue1);

    const gsl::not_null data1{ structuredBuffer.GetOriginalData(2) };

    ASSERT_EQUAL(*data1, testValue1);
}
