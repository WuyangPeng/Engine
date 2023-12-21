/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/15 09:47)

#include "IndexBufferTesting.h"
#include "VertexBufferTesting.h"
#include "Detail/BufferTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBaseDetail.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/IndexFormat.h"
#include "Rendering/Resources/Flags/UsageType.h"

#include <gsl/pointers>

Rendering::IndexBufferTesting::IndexBufferTesting(const OStreamShared& stream)
    : ParentType{ stream, GraphicsObjectType::Buffer, GraphicsObjectType::NumTypes, "IndexBuffer" }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, IndexBufferTesting)

Rendering::GraphicsObjectSharedPtr Rendering::IndexBufferTesting::Create(const std::string& name, GraphicsObjectType graphicsObjectType) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    System::UnusedFunction(graphicsObjectType);

    return IndexBuffer::Create(name, IndexFormatType::PolygonPoint, numPrimitives);
}

int Rendering::IndexBufferTesting::GetStreamSizeShifting() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return 11 * CoreTools::GetStreamSize<int32_t>();
}

void Rendering::IndexBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::IndexBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest<IndexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneObjectTest<IndexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest<IndexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(IsNullObjectTest<IndexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIdTest<IndexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest<IndexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateStorageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ActiveElementTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StorageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PointTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
}

void Rendering::IndexBufferTesting::DefaultTest()
{
    const auto indexBuffer = IndexBuffer::Create(GetGraphicsObjectName(), IndexFormatType::PolygonPoint, numPrimitives);

    ASSERT_FALSE(indexBuffer->IsCreateStorage());
    ASSERT_EQUAL(indexBuffer->GetNumElements(), numPrimitives);
    ASSERT_EQUAL(indexBuffer->GetElementSize(), 0);
    ASSERT_EQUAL(indexBuffer->GetNumBytes(), 0);
    ASSERT_ENUM_EQUAL(indexBuffer->GetUsage(), UsageType::Immutable);
    ASSERT_ENUM_EQUAL(indexBuffer->GetCopy(), CopyType::None);
    ASSERT_EQUAL(indexBuffer->GetOffset(), 0);
    ASSERT_EQUAL(indexBuffer->GetNumActiveElements(), numPrimitives);
    ASSERT_EQUAL(indexBuffer->GetNumActiveBytes(), 0);

    indexBuffer->SetUsage(UsageType::DynamicUpdate);
    ASSERT_ENUM_EQUAL(indexBuffer->GetUsage(), UsageType::DynamicUpdate);

    indexBuffer->SetCopy(CopyType::Bidirectional);
    ASSERT_ENUM_EQUAL(indexBuffer->GetCopy(), CopyType::Bidirectional);
}

void Rendering::IndexBufferTesting::CreateStorageTest()
{
    const auto indexBuffer0 = IndexBuffer::Create(GetGraphicsObjectName(), IndexFormatType::PolygonPoint, numPrimitives, indexSize, true);

    ASSERT_TRUE(indexBuffer0->IsCreateStorage());
    ASSERT_TRUE(indexBuffer0->IsIndexed());
    ASSERT_EQUAL(indexBuffer0->GetNumElements(), numPrimitives);
    ASSERT_EQUAL(indexBuffer0->GetElementSize(), indexSize);
    ASSERT_EQUAL(indexBuffer0->GetNumBytes(), numBytes);
    ASSERT_EQUAL(indexBuffer0->GetNumActiveElements(), numPrimitives);
    ASSERT_EQUAL(indexBuffer0->GetNumActiveBytes(), numBytes);
    ASSERT_ENUM_EQUAL(indexBuffer0->GetPrimitiveType(), IndexFormatType::PolygonPoint);
    ASSERT_EQUAL(indexBuffer0->GetNumPrimitives(), numPrimitives);

    indexBuffer0->DestroyStorage();
    ASSERT_FALSE(indexBuffer0->IsCreateStorage());

    indexBuffer0->CreateStorage();
    ASSERT_TRUE(indexBuffer0->IsCreateStorage());

    const auto indexBuffer1 = IndexBuffer::Create(GetGraphicsObjectName(), IndexFormatType::PolygonPoint, numPrimitives, indexSize, false);

    ASSERT_FALSE(indexBuffer1->IsCreateStorage());
    ASSERT_FALSE(indexBuffer1->IsIndexed());
    ASSERT_EQUAL(indexBuffer1->GetNumElements(), numPrimitives);
    ASSERT_EQUAL(indexBuffer1->GetElementSize(), indexSize);
    ASSERT_EQUAL(indexBuffer1->GetNumBytes(), numBytes);
    ASSERT_EQUAL(indexBuffer1->GetNumActiveElements(), numPrimitives);
    ASSERT_EQUAL(indexBuffer1->GetNumActiveBytes(), numBytes);
    ASSERT_ENUM_EQUAL(indexBuffer1->GetPrimitiveType(), IndexFormatType::PolygonPoint);
    ASSERT_EQUAL(indexBuffer1->GetNumPrimitives(), numPrimitives);

    indexBuffer1->CreateStorage();
    ASSERT_TRUE(indexBuffer1->IsCreateStorage());

    indexBuffer1->DestroyStorage();
    ASSERT_FALSE(indexBuffer1->IsCreateStorage());
}

void Rendering::IndexBufferTesting::ActiveElementTest()
{
    const auto indexBuffer = IndexBuffer::Create(GetGraphicsObjectName(), IndexFormatType::PolygonPoint, numPrimitives, indexSize, true);

    ASSERT_EQUAL(indexBuffer->GetNumActiveElements(), numPrimitives);

    indexBuffer->SetNumActiveElements(1);
    ASSERT_EQUAL(indexBuffer->GetNumActiveElements(), 1);
    ASSERT_EQUAL(indexBuffer->GetNumActiveBytes(), indexSize);
    ASSERT_EQUAL(indexBuffer->GetNumActiveIndices(), numPrimitives);

    ASSERT_EQUAL(indexBuffer->GetNumActivePrimitives(), numPrimitives);
    ASSERT_EQUAL(indexBuffer->GetFirstPrimitive(), 0);
    ASSERT_EQUAL(indexBuffer->GetFirstIndex(), 0);

    indexBuffer->SetNumActivePrimitives(2);
    ASSERT_EQUAL(indexBuffer->GetNumActivePrimitives(), 2);
    ASSERT_EQUAL(indexBuffer->GetNumActiveIndices(), 2);
    ASSERT_EQUAL(indexBuffer->GetFirstPrimitive(), 0);
    ASSERT_EQUAL(indexBuffer->GetFirstIndex(), 0);

    indexBuffer->SetFirstPrimitive(1);

    ASSERT_EQUAL(indexBuffer->GetFirstPrimitive(), 1);
    ASSERT_EQUAL(indexBuffer->GetFirstIndex(), 1);
}

void Rendering::IndexBufferTesting::StorageTest()
{
    const auto indexBuffer = IndexBuffer::Create(GetGraphicsObjectName(), IndexFormatType::PolygonPoint, numPrimitives, indexSize, true);

    constexpr auto testValue0 = 'a';
    constexpr auto testValue1 = 'b';
    BufferTest::StorageType storage(numBytes);
    storage.at(0) = testValue0;
    storage.at(2) = testValue1;

    indexBuffer->SetStorage(storage);

    auto span0 = indexBuffer->GetStorage();

    ASSERT_EQUAL(span0.Increase<char>(), testValue0);

    const gsl::not_null data0{ indexBuffer->GetOriginalData() };

    ASSERT_EQUAL(*data0, testValue0);

    auto span1 = indexBuffer->GetStorage(2);

    ASSERT_EQUAL(span1.Increase<char>(), testValue1);

    const gsl::not_null data1{ indexBuffer->GetOriginalData(2) };

    ASSERT_EQUAL(*data1, testValue1);
}

void Rendering::IndexBufferTesting::PointTest()
{
    const auto indexBuffer0 = IndexBuffer::Create(GetGraphicsObjectName(), IndexFormatType::PolygonPoint, numPrimitives, 4, true);

    for (auto i = 0; i < numPrimitives; ++i)
    {
        indexBuffer0->SetPoint(i, i + 5);
    }

    for (auto i = 0; i < numPrimitives; ++i)
    {
        ASSERT_EQUAL(indexBuffer0->GetPoint(i), i + 5);
    }

    const auto indexBuffer1 = IndexBuffer::Create(GetGraphicsObjectName(), IndexFormatType::PolygonPoint, numPrimitives, 2, true);

    for (auto i = 0; i < numPrimitives; ++i)
    {
        indexBuffer1->SetPoint(i, i + 5);
    }

    for (auto i = 0; i < numPrimitives; ++i)
    {
        ASSERT_EQUAL(indexBuffer1->GetPoint(i), i + 5);
    }
}

void Rendering::IndexBufferTesting::SegmentTest()
{
    const auto indexBuffer0 = IndexBuffer::Create(GetGraphicsObjectName(), IndexFormatType::PolygonSegmentDisjoint, numPrimitives, 4, true);

    for (auto i = 0; i < numPrimitives; ++i)
    {
        indexBuffer0->SetSegment(i, i + 5, i + 7);
    }

    for (auto i = 0; i < numPrimitives; ++i)
    {
        ASSERT_EQUAL(indexBuffer0->GetSegment(i).first, i + 5);
        ASSERT_EQUAL(indexBuffer0->GetSegment(i).second, i + 7);
    }

    const auto indexBuffer1 = IndexBuffer::Create(GetGraphicsObjectName(), IndexFormatType::PolygonSegmentContiguous, numPrimitives, 2, true);

    for (auto i = 0; i < numPrimitives; ++i)
    {
        indexBuffer1->SetSegment(i, i + 2, i + 5);

        ASSERT_EQUAL(indexBuffer1->GetSegment(i).first, i + 2);
        ASSERT_EQUAL(indexBuffer1->GetSegment(i).second, i + 5);
    }
}

void Rendering::IndexBufferTesting::TriangleTest()
{
    const auto indexBuffer0 = IndexBuffer::Create(GetGraphicsObjectName(), IndexFormatType::TriangleMesh, numPrimitives, 4, true);

    for (auto i = 0; i < numPrimitives; ++i)
    {
        indexBuffer0->SetTriangle(i, i + 5, i + 7, i + 8);
    }

    for (auto i = 0; i < numPrimitives; ++i)
    {
        ASSERT_EQUAL(get<0>(indexBuffer0->GetTriangle(i)), i + 5);
        ASSERT_EQUAL(get<1>(indexBuffer0->GetTriangle(i)), i + 7);
        ASSERT_EQUAL(get<2>(indexBuffer0->GetTriangle(i)), i + 8);
    }

    const auto indexBuffer1 = IndexBuffer::Create(GetGraphicsObjectName(), IndexFormatType::TriangleStrip, numPrimitives, 2, true);

    for (auto i = 0; i < numPrimitives; ++i)
    {
        indexBuffer1->SetTriangle(i, i + 2, i + 4, i + 3);

        ASSERT_EQUAL(get<0>(indexBuffer1->GetTriangle(i)), i + 2);
        ASSERT_EQUAL(get<1>(indexBuffer1->GetTriangle(i)), i + 4);
        ASSERT_EQUAL(get<2>(indexBuffer1->GetTriangle(i)), i + 3);
    }
}
