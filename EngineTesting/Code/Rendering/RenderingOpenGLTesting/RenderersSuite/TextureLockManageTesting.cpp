// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:29)

#include "TextureLockManageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Rendering/Renderers/PlatformTexture1D.h"
#include "Rendering/Renderers/PlatformTexture2D.h"
#include "Rendering/Renderers/PlatformTexture3D.h"
#include "Rendering/Renderers/PlatformTextureCube.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Renderers/Renderer.h" 
#include "Rendering/Resources/LoadTexture.h"
#include "Rendering/Renderers/TextureLockManagerDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TextureLockManageTesting) 

void Rendering::TextureLockManageTesting
	::MainTest()
{ 
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(Texture1DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Texture2DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Texture3DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TextureCubeTest);

	RendererManager::Destroy();
}
#include SYSTEM_WARNING_DISABLE(26440)
void Rendering::TextureLockManageTesting
	::Texture1DTest()
{
// 	Texture1DSmartPointer firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture1D.trt"));
// 
// 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
// 	renderer->Init();
// 
// 	PlatformTexture1D texture(renderer.get(), firstTexture1D.GetData());
// 
// 	texture.Enable(renderer.get(), 0);
// 
// 	{
// 		TextureLockManager<PlatformTexture1D> manage(texture);
// 		ASSERT_UNEQUAL_NULL_PTR(manage.Lock(0, BufferLocking::WriteOnly));
// 	}
// 
// 	texture.Disable(renderer.get(),0);
}

void Rendering::TextureLockManageTesting
	::Texture2DTest()
{
// 	Texture2DSmartPointer firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture2D.trt"));
// 
// 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
// 	renderer->Init();
// 
// 	PlatformTexture2D texture(renderer.get(), firstTexture2D.GetData());
// 
// 	texture.Enable(renderer.get(), 0);
// 
// 	{
// 		TextureLockManager<PlatformTexture2D> manage(texture);
// 		ASSERT_UNEQUAL_NULL_PTR(manage.Lock(0, BufferLocking::WriteOnly));
// 	}
// 
// 	texture.Disable(renderer.get(),0);
}

void Rendering::TextureLockManageTesting
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
// 	{
// 		TextureLockManager<PlatformTexture3D> manage(texture);
// 		ASSERT_UNEQUAL_NULL_PTR(manage.Lock(0, BufferLocking::WriteOnly));
// 	}
// 
// 	texture.Disable(renderer.get(),0);
}

void Rendering::TextureLockManageTesting
	::TextureCubeTest()
{
// 	TextureCubeSmartPointer firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/TextureCube.trt"));
// 	
// 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
// 	renderer->Init();
// 
// 	PlatformTextureCube texture(renderer.get(), firstTextureCube.GetData());
// 
// 	texture.Enable(renderer.get(), 0);
// 
// 	{
// 		TextureLockManager<PlatformTextureCube> manage(texture);
// 		ASSERT_UNEQUAL_NULL_PTR(manage.Lock(2,0, BufferLocking::WriteOnly));
// 	}
// 
// 	texture.Disable(renderer.get(),0);
}

 