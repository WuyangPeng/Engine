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
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

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

void Rendering::BufferTesting::VertexBufferTest() noexcept
{
}

void Rendering::BufferTesting::IndexBufferTest()
{
    auto firstIndexBuffer = IndexBuffer::Create(IndexFormatType::Polypoint, 5);

    ASSERT_EQUAL(firstIndexBuffer->GetElementSize(), 0);

    ASSERT_EQUAL(firstIndexBuffer->GetNumBytes(), 0);
    ASSERT_EQUAL(firstIndexBuffer->GetOffset(), 0);

    auto secondIndexBuffer = IndexBuffer::Create(IndexFormatType::Polypoint, 7, 8);

    ASSERT_EQUAL(secondIndexBuffer->GetElementSize(), 8);

    ASSERT_EQUAL(secondIndexBuffer->GetNumBytes(), 56);
    ASSERT_EQUAL(secondIndexBuffer->GetOffset(), 0);

    ASSERT_EQUAL(secondIndexBuffer->GetElementSize(), 8);

    ASSERT_EQUAL(secondIndexBuffer->GetNumBytes(), 56);
    ASSERT_EQUAL(secondIndexBuffer->GetOffset(), 0);

    secondIndexBuffer->SetOffset(4);

    ASSERT_EQUAL(secondIndexBuffer->GetNumElements(), 7);
    ASSERT_EQUAL(secondIndexBuffer->GetElementSize(), 8);

    ASSERT_EQUAL(secondIndexBuffer->GetNumBytes(), 56);
    ASSERT_EQUAL(secondIndexBuffer->GetOffset(), 4);
}

void Rendering::BufferTesting::StreamTest() noexcept
{
}

void Rendering::BufferTesting::FileTest() noexcept
{
}
