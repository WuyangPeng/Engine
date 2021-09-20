// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:28)

#include "PlatformTexture3DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Resources/LoadTexture.h"
#include "Rendering/Renderers/PlatformTexture3D.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PlatformTexture3DTesting) 

void Rendering::PlatformTexture3DTesting
	::MainTest()
{ 
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(Texture3DTest);

	RendererManager::Destroy();
}

void Rendering::PlatformTexture3DTesting
	::Texture3DTest()
{
// 	Texture3DSmartPointer firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture3D.trt"));
// 
// 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
// 	renderer->Init();
// 
// 	PlatformTexture3D texture(renderer.get(), firstTexture3D.GetData());
// 
// 	texture.Enable(renderer.get(), 0);
// 	
// 	ASSERT_UNEQUAL_NULL_PTR(texture.Lock(0, BufferLocking::WriteOnly));
// 	texture.Unlock(0);
// 
// 	texture.Disable(renderer.get(),0);
}



 