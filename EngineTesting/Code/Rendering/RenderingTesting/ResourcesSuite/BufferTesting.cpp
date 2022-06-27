///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 15:54)

#include "BufferTesting.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/VertexFormatElement.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, BufferTesting)

void Rendering::BufferTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(VertexBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IndexBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::BufferTesting::VertexBufferTest()
{
    auto firstVertexBuffer = VertexBuffer::Create();

    ASSERT_EQUAL(firstVertexBuffer->GetNumElements(), 0);
    ASSERT_EQUAL(firstVertexBuffer->GetElementSize(), 0);
    ASSERT_ENUM_EQUAL(firstVertexBuffer->GetUsage(), BufferUsage::Quantity);
    ASSERT_EQUAL(firstVertexBuffer->GetNumBytes(), 0);

    auto secondVertexBuffer = VertexBuffer::Create(7, 8, BufferUsage::Dynamic);

    ASSERT_EQUAL(secondVertexBuffer->GetNumElements(), 7);
    ASSERT_EQUAL(secondVertexBuffer->GetElementSize(), 8);
    ASSERT_ENUM_EQUAL(secondVertexBuffer->GetUsage(), BufferUsage::Dynamic);
    ASSERT_EQUAL(secondVertexBuffer->GetNumBytes(), 56);

    secondVertexBuffer->SetNumElements(4);

    ASSERT_EQUAL(secondVertexBuffer->GetNumElements(), 4);
    ASSERT_EQUAL(secondVertexBuffer->GetElementSize(), 8);
    ASSERT_ENUM_EQUAL(secondVertexBuffer->GetUsage(), BufferUsage::Dynamic);
    ASSERT_EQUAL(secondVertexBuffer->GetNumBytes(), 56);

    ASSERT_UNEQUAL_NULL_PTR(secondVertexBuffer->GetReadOnlyData());
}

void Rendering::BufferTesting::IndexBufferTest()
{
    auto firstIndexBuffer = IndexBuffer::Create();

    ASSERT_EQUAL(firstIndexBuffer->GetNumElements(), 0);
    ASSERT_EQUAL(firstIndexBuffer->GetElementSize(), 0);
    ASSERT_ENUM_EQUAL(firstIndexBuffer->GetUsage(), BufferUsage::Quantity);
    ASSERT_EQUAL(firstIndexBuffer->GetNumBytes(), 0);
    ASSERT_EQUAL(firstIndexBuffer->GetOffset(), 0);

    auto secondIndexBuffer = IndexBuffer::Create(7, 8, BufferUsage::Dynamic);

    ASSERT_EQUAL(secondIndexBuffer->GetNumElements(), 7);
    ASSERT_EQUAL(secondIndexBuffer->GetElementSize(), 8);
    ASSERT_ENUM_EQUAL(secondIndexBuffer->GetUsage(), BufferUsage::Dynamic);
    ASSERT_EQUAL(secondIndexBuffer->GetNumBytes(), 56);
    ASSERT_EQUAL(secondIndexBuffer->GetOffset(), 0);

    secondIndexBuffer->SetNumElements(4);

    ASSERT_EQUAL(secondIndexBuffer->GetNumElements(), 4);
    ASSERT_EQUAL(secondIndexBuffer->GetElementSize(), 8);
    ASSERT_ENUM_EQUAL(secondIndexBuffer->GetUsage(), BufferUsage::Dynamic);
    ASSERT_EQUAL(secondIndexBuffer->GetNumBytes(), 56);
    ASSERT_EQUAL(secondIndexBuffer->GetOffset(), 0);

    secondIndexBuffer->SetOffset(4);

    ASSERT_EQUAL(secondIndexBuffer->GetNumElements(), 4);
    ASSERT_EQUAL(secondIndexBuffer->GetElementSize(), 8);
    ASSERT_ENUM_EQUAL(secondIndexBuffer->GetUsage(), BufferUsage::Dynamic);
    ASSERT_EQUAL(secondIndexBuffer->GetNumBytes(), 56);
    ASSERT_EQUAL(secondIndexBuffer->GetOffset(), 4);

    ASSERT_UNEQUAL_NULL_PTR(secondIndexBuffer->GetReadOnlyData());
}

void Rendering::BufferTesting::StreamTest() noexcept
{
}

void Rendering::BufferTesting::FileTest() noexcept
{
}
