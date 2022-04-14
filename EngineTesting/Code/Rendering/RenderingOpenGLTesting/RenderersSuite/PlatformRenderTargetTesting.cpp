// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/09 15:27)

#include "PlatformRenderTargetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Resources/RenderTarget.h" 
#include "Rendering/Renderers/PlatformRenderTarget.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PlatformRenderTargetTesting) 

void Rendering::PlatformRenderTargetTesting
	::MainTest()
{ 
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(RenderTargetTest);

	RendererManager::Destroy();
}

void Rendering::PlatformRenderTargetTesting
	::RenderTargetTest() noexcept
{
// 	RenderTargetSmartPointer firstRenderTarget(NEW0 RenderTarget(5,TextureFormat::A8B8G8R8,1024,768,false,true));
// 
// 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
// 	renderer->Init();
// 
// 	PlatformRenderTarget platformRenderTarget(renderer.get(),firstRenderTarget.GetData());
// 
// 	platformRenderTarget.Enable(renderer.get());
// 
// 	platformRenderTarget.Disable(renderer.get());
// 
// 	for (int i = 0;i < 5;++i)
// 	{
// 		ConstTexture2DSmartPointer texture2D = platformRenderTarget.ReadColor(i,renderer.get());
// 
// 		ASSERT_UNEQUAL_NULL_PTR(texture2D);
// 	}	
}




 