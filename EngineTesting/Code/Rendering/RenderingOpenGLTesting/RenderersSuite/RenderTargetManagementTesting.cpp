// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/09 15:29)

#include "RenderTargetManagementTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Resources/RenderTarget.h" 
#include "Rendering/Renderers/RenderTargetManagement.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, RenderTargetManagementTesting) 

void Rendering::RenderTargetManagementTesting
	::MainTest()
{ 
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(RenderTargetTest);

	RendererManager::Destroy();
}

void Rendering::RenderTargetManagementTesting
	::RenderTargetTest()
{
// 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
// 	renderer->Init();
// 	RenderTargetManagement management(renderer);
// 
// 	for (int i = 0;i < 10;++i)
// 	{
// 		RenderTargetSmartPointer firstRenderTarget(NEW0 RenderTarget(5,TextureFormat::A8B8G8R8,1024,768,false,true));		 
// 
// 		if(i % 2 == 0)
// 			management.Bind(firstRenderTarget);
// 
// 		management.Enable(firstRenderTarget);
// 
// 		for (int textureIndex = 0;textureIndex < 5;++textureIndex)
// 		{
// 			ConstTexture2DSmartPointer texture2D = management.ReadColor(textureIndex,firstRenderTarget);
// 
// 			ASSERT_UNEQUAL_NULL_PTR(texture2D);
// 		}
// 
// 		ASSERT_UNEQUAL_NULL_PTR(management.GetResource(firstRenderTarget));
// 
// 		management.Disable(firstRenderTarget);
// 		management.Unbind(firstRenderTarget);	 
// 	}	
}
