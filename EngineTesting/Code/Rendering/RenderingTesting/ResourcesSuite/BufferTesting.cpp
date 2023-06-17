///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:37)

#include "BufferTesting.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

Rendering::BufferTesting::BufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BufferTesting)

void Rendering::BufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::BufferTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(VertexBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IndexBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminator();
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
