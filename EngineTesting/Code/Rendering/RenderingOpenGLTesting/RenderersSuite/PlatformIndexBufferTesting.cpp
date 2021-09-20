// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/09 15:24)

#include "PlatformIndexBufferTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Renderers/PlatformIndexBuffer.h"
#include "Rendering/SceneGraph/LoadVisual.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PlatformIndexBufferTesting) 

void Rendering::PlatformIndexBufferTesting
	::MainTest()
{ 
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(IndexBufferTest);

	RendererManager::Destroy();
}

void Rendering::PlatformIndexBufferTesting
	::IndexBufferTest() 
{ 
// 	VisualSmartPointer firstTrianglesStrip = LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/RenderersSuite/TrianglesStrip.trv"));
// 
// 	IndexBufferSmartPointer indexbuffer = firstTrianglesStrip->GetIndexBuffer();
// 
// 	RendererSharedPtr renderer(new Renderer("Configuration/Renderer.json"));
// 	renderer->Init();
// 
// 	PlatformIndexBuffer platformIndexBuffer(renderer.get(),indexbuffer.GetData());
// 
// 	platformIndexBuffer.Enable(renderer.get());
// 	platformIndexBuffer.Lock(BufferLocking::WriteOnly);
// 	platformIndexBuffer.Unlock();
// 	platformIndexBuffer.Disable(renderer.get());
}


 