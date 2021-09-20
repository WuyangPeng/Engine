// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/09 15:36)

#include "OpenGLRenderTargetDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/RenderTarget.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/OpenGLRenderer/OpenGLRenderTargetData.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, OpenGLRenderTargetDataTesting)

void Rendering::OpenGLRenderTargetDataTesting
	::MainTest()
{ 
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(OpenGLRenderTargetDataTest);

	RendererManager::Destroy();
}

void Rendering::OpenGLRenderTargetDataTesting
	::OpenGLRenderTargetDataTest()
{
// 	RenderTargetSmartPointer firstRenderTarget(NEW0 RenderTarget(5,TextureFormat::A8B8G8R8,1024,768,false,true));
// 
// 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
// 	renderer->Init();
// 
// 	OpenGLRenderTargetData openGLRenderTargetData(renderer.get(),firstRenderTarget.GetData());
// 
// 	openGLRenderTargetData.Enable(renderer.get());
// 
// 	openGLRenderTargetData.Disable(renderer.get());
// 
// 	for (int i = 0;i < 5;++i)
// 	{
// 		ConstTexture2DSmartPointer texture2D = openGLRenderTargetData.ReadColor(i,renderer.get());
// 
// 		ASSERT_UNEQUAL_NULL_PTR(texture2D);
// 	}	
}

