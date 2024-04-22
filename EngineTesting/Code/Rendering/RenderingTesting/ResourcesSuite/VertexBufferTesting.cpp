/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/12 19:18)

#include "VertexBufferTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBaseDetail.h"
#include "Rendering/Resources/Buffers/MemberLayout.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Flags/UsageType.h"

#include <gsl/pointers>

Rendering::VertexBufferTesting::VertexBufferTesting(const OStreamShared& stream)
    : ParentType{ stream, GraphicsObjectType::VertexBuffer, GraphicsObjectType::VertexBuffer, "VertexBuffer" }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VertexBufferTesting)

Rendering::GraphicsObjectSharedPtr Rendering::VertexBufferTesting::Create(const std::string& name, GraphicsObjectType graphicsObjectType) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    System::UnusedFunction(graphicsObjectType);

    return VertexBuffer::Create(name, numVertices);
}

int Rendering::VertexBufferTesting::GetStreamSizeShifting() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return 7 * CoreTools::GetStreamSize<int32_t>() + 2 * CoreTools::GetStreamSize<int64_t>();
}

void Rendering::VertexBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::VertexBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest<VertexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneObjectTest<VertexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest<VertexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(IsNullObjectTest<VertexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(UniqueIdTest<VertexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest<VertexBuffer>);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateStorageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ActiveElementTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StorageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetChannelTest);
}

void Rendering::VertexBufferTesting::DefaultTest()
{
    const auto vertexBuffer = VertexBuffer::Create(GetGraphicsObjectName(), numVertices);

    ASSERT_FALSE(vertexBuffer->IsCreateStorage());
    ASSERT_EQUAL(vertexBuffer->GetNumElements(), numVertices);
    ASSERT_EQUAL(vertexBuffer->GetElementSize(), 0);
    ASSERT_EQUAL(vertexBuffer->GetNumBytes(), 0);
    ASSERT_EQUAL(vertexBuffer->GetUsage(), UsageType::Immutable);
    ASSERT_EQUAL(vertexBuffer->GetCopy(), CopyType::None);
    ASSERT_EQUAL(vertexBuffer->GetOffset(), 0);
    ASSERT_EQUAL(vertexBuffer->GetNumActiveElements(), numVertices);
    ASSERT_EQUAL(vertexBuffer->GetNumActiveBytes(), 0);

    vertexBuffer->SetUsage(UsageType::DynamicUpdate);
    ASSERT_EQUAL(vertexBuffer->GetUsage(), UsageType::DynamicUpdate);

    vertexBuffer->SetCopy(CopyType::Bidirectional);
    ASSERT_EQUAL(vertexBuffer->GetCopy(), CopyType::Bidirectional);
}

void Rendering::VertexBufferTesting::CreateStorageTest()
{
    const VertexFormat::AttributeContainer attributeContainer{ VertexFormatAttribute{ DataFormatType::R32G32B32A32Float, VertexFormatFlags::Semantic::Position, 0, 0 } };
    const auto vertexFormat = VertexFormat::Create("VertexFormat", attributeContainer);
    const auto vertexSize = vertexFormat->GetVertexSize();

    const auto vertexBuffer0 = VertexBuffer::Create(GetGraphicsObjectName(), *vertexFormat, numVertices, true);

    ASSERT_TRUE(vertexBuffer0->IsCreateStorage());
    ASSERT_EQUAL(vertexBuffer0->GetNumElements(), numVertices);
    ASSERT_EQUAL(vertexBuffer0->GetElementSize(), vertexSize);
    ASSERT_EQUAL(vertexBuffer0->GetNumBytes(), numVertices * vertexSize);
    ASSERT_EQUAL(vertexBuffer0->GetNumActiveElements(), numVertices);
    ASSERT_EQUAL(vertexBuffer0->GetNumActiveBytes(), numVertices * vertexSize);
    ASSERT_TRUE(vertexBuffer0->StandardUsage());

    vertexBuffer0->DestroyStorage();
    ASSERT_FALSE(vertexBuffer0->IsCreateStorage());

    vertexBuffer0->CreateStorage();
    ASSERT_TRUE(vertexBuffer0->IsCreateStorage());

    const auto vertexBuffer1 = VertexBuffer::Create(GetGraphicsObjectName(), *vertexFormat, numVertices, false);

    ASSERT_FALSE(vertexBuffer1->IsCreateStorage());
    ASSERT_EQUAL(vertexBuffer1->GetNumElements(), numVertices);
    ASSERT_EQUAL(vertexBuffer1->GetElementSize(), vertexSize);
    ASSERT_EQUAL(vertexBuffer1->GetNumBytes(), numVertices * vertexSize);
    ASSERT_EQUAL(vertexBuffer1->GetNumActiveElements(), numVertices);
    ASSERT_EQUAL(vertexBuffer1->GetNumActiveBytes(), numVertices * vertexSize);
    ASSERT_TRUE(vertexBuffer1->StandardUsage());
    ASSERT_EQUAL(vertexBuffer1->GetFormat().GetName(), vertexFormat->GetName());
    ASSERT_EQUAL(vertexBuffer1->GetFormat().GetVertexSize(), vertexFormat->GetVertexSize());
    ASSERT_EQUAL(vertexBuffer1->GetFormat().GetNumAttributes(), vertexFormat->GetNumAttributes());

    vertexBuffer1->CreateStorage();
    ASSERT_TRUE(vertexBuffer1->IsCreateStorage());

    vertexBuffer1->DestroyStorage();
    ASSERT_FALSE(vertexBuffer1->IsCreateStorage());

    const VertexBuffer::StorageType storage(numBytes - stride);
    const StructuredBuffer structuredBuffer{ GetGraphicsObjectName(), numVertices - 1, stride, storage };
    const auto vertexBuffer2 = VertexBuffer::Create(GetGraphicsObjectName(), *vertexFormat, structuredBuffer);

    ASSERT_TRUE(vertexBuffer2->IsCreateStorage());
    ASSERT_EQUAL(vertexBuffer2->GetNumElements(), numVertices - 1);
    ASSERT_EQUAL(vertexBuffer2->GetElementSize(), vertexSize);
    ASSERT_EQUAL(vertexBuffer2->GetNumBytes(), numVertices * vertexSize - vertexSize);
    ASSERT_EQUAL(vertexBuffer2->GetNumActiveElements(), numVertices - 1);
    ASSERT_EQUAL(vertexBuffer2->GetNumActiveBytes(), numVertices * vertexSize - vertexSize);
    ASSERT_FALSE(vertexBuffer2->StandardUsage());
    ASSERT_EQUAL(vertexBuffer2->GetStructuredBuffer()->GetName(), structuredBuffer.GetName());
    ASSERT_EQUAL(vertexBuffer2->GetStructuredBuffer()->GetNumElements(), structuredBuffer.GetNumElements());
    ASSERT_EQUAL(vertexBuffer2->GetStructuredBuffer()->GetElementSize(), structuredBuffer.GetElementSize());

    vertexBuffer2->DestroyStorage();
    ASSERT_FALSE(vertexBuffer2->IsCreateStorage());

    vertexBuffer2->CreateStorage();
    ASSERT_TRUE(vertexBuffer2->IsCreateStorage());
}

void Rendering::VertexBufferTesting::ActiveElementTest()
{
    const VertexFormat::AttributeContainer attributeContainer{ VertexFormatAttribute{ DataFormatType::R32G32B32A32Float, VertexFormatFlags::Semantic::Position, 0, 0 } };
    const auto vertexFormat = VertexFormat::Create("VertexFormat", attributeContainer);
    const auto vertexSize = vertexFormat->GetVertexSize();
    const auto vertexBuffer = VertexBuffer::Create(GetGraphicsObjectName(), *vertexFormat, numVertices, true);

    ASSERT_EQUAL(vertexBuffer->GetNumActiveElements(), numVertices);

    vertexBuffer->SetNumActiveElements(1);
    ASSERT_EQUAL(vertexBuffer->GetNumActiveElements(), 1);
    ASSERT_EQUAL(vertexBuffer->GetNumActiveBytes(), vertexSize);
}

void Rendering::VertexBufferTesting::StorageTest()
{
    const VertexFormat::AttributeContainer attributeContainer{ VertexFormatAttribute{ DataFormatType::R32G32B32A32Float, VertexFormatFlags::Semantic::Position, 0, 0 } };
    const auto vertexFormat = VertexFormat::Create("VertexFormat", attributeContainer);
    const auto storageSize = vertexFormat->GetVertexSize() * numVertices;
    const auto vertexBuffer = VertexBuffer::Create(GetGraphicsObjectName(), *vertexFormat, numVertices, true);

    constexpr auto testValue0 = 'a';
    constexpr auto testValue1 = 'b';
    VertexBuffer::StorageType storage(storageSize);
    storage.at(0) = testValue0;
    storage.at(2) = testValue1;

    vertexBuffer->SetStorage(storage);

    auto span0 = vertexBuffer->GetStorage();

    ASSERT_EQUAL(span0.Increase<char>(), testValue0);

    const gsl::not_null data0{ vertexBuffer->GetOriginalData() };

    ASSERT_EQUAL(*data0, testValue0);

    auto span1 = vertexBuffer->GetStorage(2);

    ASSERT_EQUAL(span1.Increase<char>(), testValue1);

    const gsl::not_null data1{ vertexBuffer->GetOriginalData(2) };

    ASSERT_EQUAL(*data1, testValue1);
}

void Rendering::VertexBufferTesting::GetChannelTest()
{
    const VertexFormat::AttributeContainer attributeContainer{ VertexFormatAttribute{ DataFormatType::R32G32B32A32Float, VertexFormatFlags::Semantic::Position, 0, 0 } };
    const auto vertexFormat = VertexFormat::Create("VertexFormat", attributeContainer);
    const auto storageSize = vertexFormat->GetVertexSize() * numVertices;
    const auto vertexBuffer = VertexBuffer::Create(GetGraphicsObjectName(), *vertexFormat, numVertices, true);

    constexpr auto testValue0 = 'a';
    VertexBuffer::StorageType storage(storageSize);
    storage.at(0) = testValue0;

    vertexBuffer->SetStorage(storage);

    auto span0 = vertexBuffer->GetChannel(VertexFormatFlags::Semantic::Position, 0, VertexBuffer::DataFormatTypeContainer{});

    ASSERT_EQUAL(span0.Increase<char>(), testValue0);

    auto span1 = vertexBuffer->GetConstChannel(VertexFormatFlags::Semantic::Position, 0, VertexBuffer::DataFormatTypeContainer{});

    ASSERT_EQUAL(span1.Increase<char>(), testValue0);
}
