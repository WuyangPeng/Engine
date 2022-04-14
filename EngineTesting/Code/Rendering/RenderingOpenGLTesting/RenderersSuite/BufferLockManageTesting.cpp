// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/09 15:22)

#include "BufferLockManageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/SceneGraph/Visual.h"

#include "Rendering/SceneGraph/LoadVisual.h"

#include "Rendering/Renderers/PlatformIndexBuffer.h"
#include "Rendering/Renderers/PlatformVertexBuffer.h"

#include "Rendering/Renderers/BufferLockManagerDetail.h"

#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/IndexBuffer.h"



UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, BufferLockManageTesting)

void Rendering::BufferLockManageTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(VertexBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IndexBufferTest);

    RendererManager::Destroy();
}

void Rendering::BufferLockManageTesting::VertexBufferTest() noexcept
{
    // 	VisualSmartPointer firstTrianglesStrip = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/RenderersSuite/TrianglesStrip.trv"));
    //
    // 	VertexBufferSmartPointer vertexbuffer = firstTrianglesStrip->GetVertexBuffer();
    //
    // 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
    // 	renderer->Init();
    //
    // 	PlatformVertexBuffer platformVertexBuffer(renderer.get(), vertexbuffer.GetData());
    //
    // 	platformVertexBuffer.Enable(renderer.get(), vertexbuffer->GetElementSize(), 0, 0);
    //
    // 	{
    // 		BufferLockManager<PlatformVertexBuffer> manage(platformVertexBuffer);
    // 		manage.Lock(BufferLocking::WriteOnly);
    // 	}
    //
    // 	platformVertexBuffer.Disable(renderer.get(),0);
}

void Rendering::BufferLockManageTesting::IndexBufferTest() noexcept
{
    // 	VisualSmartPointer firstTrianglesStrip = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/RenderersSuite/TrianglesStrip.trv"));
    //
    // 	IndexBufferSmartPointer indexbuffer = firstTrianglesStrip->GetIndexBuffer();
    //
    // 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
    // 	renderer->Init();
    //
    // 	PlatformIndexBuffer platformIndexBuffer(renderer.get(),indexbuffer.GetData());
    //
    // 	platformIndexBuffer.Enable(renderer.get());
    //
    // 	{
    // 		BufferLockManager<PlatformIndexBuffer> manage(platformIndexBuffer);
    // 		manage.Lock(BufferLocking::WriteOnly);
    // 	}
    //
    // 	platformIndexBuffer.Disable(renderer.get());
}
