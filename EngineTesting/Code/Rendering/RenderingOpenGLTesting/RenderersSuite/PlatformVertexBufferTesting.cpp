// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/09 15:29)

#include "PlatformVertexBufferTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Rendering/Renderers/PlatformVertexBuffer.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/SceneGraph/LoadVisual.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PlatformVertexBufferTesting)

void Rendering::PlatformVertexBufferTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(VertexBufferTest);

    RendererManager::Destroy();
}

void Rendering::PlatformVertexBufferTesting::VertexBufferTest() noexcept
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
    // 	platformVertexBuffer.Lock(BufferLocking::WriteOnly);
    // 	platformVertexBuffer.Unlock();
    // 	platformVertexBuffer.Disable(renderer.get(),0);
}
