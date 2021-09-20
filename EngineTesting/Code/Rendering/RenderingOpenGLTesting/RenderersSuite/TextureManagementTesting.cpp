// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:31)

#include "TextureManagementTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Renderers/PlatformIndexBuffer.h"
#include "Rendering/Resources/LoadTexture.h"
#include "Rendering/Renderers/TextureManagementDetail.h"
#include "Rendering/Renderers/PlatformTexture1D.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TextureManagementTesting) 

void Rendering::TextureManagementTesting
	::MainTest()
{ 
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(Texture1DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Texture2DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Texture3DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TextureCubeTest);

	RendererManager::Destroy();
}

void Rendering::TextureManagementTesting
	::Texture1DTest()
{
// 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
// 	renderer->Init();
// 
// 	TextureManagement<PlatformTexture1D> textureManagement(renderer);
// 
// 	for (int i = 0;i < 10;++i)
// 	{
// 		Texture1DSmartPointer firstTexture1D = 	LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture1D.trt"));
// 
// 		ASSERT_FALSE(textureManagement.IsInTextureMap(firstTexture1D));
// 
// 		if(i % 2 == 0)
// 			textureManagement.Bind(firstTexture1D);
// 
// 		textureManagement.Enable(firstTexture1D,0);
// 
// 		ASSERT_UNEQUAL_NULL_PTR(textureManagement.Lock(firstTexture1D,0,BufferLocking::ReadWrite));
// 		textureManagement.Unlock(firstTexture1D,0);
// 
// 		textureManagement.Update(firstTexture1D,0);
// 		textureManagement.Disable(firstTexture1D,0);
// 
// 		ASSERT_UNEQUAL_NULL_PTR(textureManagement.GetResource(firstTexture1D));
// 		ASSERT_TRUE(textureManagement.IsInTextureMap(firstTexture1D));
// 
// 		textureManagement.Unbind(firstTexture1D);
// 
// 		ASSERT_FALSE(textureManagement.IsInTextureMap(firstTexture1D));
// 	}
// 
// 	Texture1DSmartPointer secondTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture1D.trt"));
// 
// 	std::shared_ptr<PlatformTexture1D> platformTexture(new PlatformTexture1D(renderer.get(), secondTexture1D.GetData()));
// 	textureManagement.InsertTextureMap(secondTexture1D,platformTexture);
// 
// 	ASSERT_UNEQUAL_NULL_PTR(textureManagement.GetResource(secondTexture1D));
// 	ASSERT_TRUE(textureManagement.IsInTextureMap(secondTexture1D));
// 
// 	textureManagement.RemoveTextureMap(secondTexture1D);
// 
// 	ASSERT_FALSE(textureManagement.IsInTextureMap(secondTexture1D));
}

void Rendering::TextureManagementTesting
	::Texture2DTest()
{
// 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
// 	renderer->Init();
// 
// 	TextureManagement<PlatformTexture2D> textureManagement(renderer);
// 
// 	for (int i = 0;i < 10;++i)
// 	{
// 		Texture2DSmartPointer firstTexture2D = 	LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture2D.trt"));
// 
// 		ASSERT_FALSE(textureManagement.IsInTextureMap(firstTexture2D));
// 
// 		if(i % 2 == 0)
// 			textureManagement.Bind(firstTexture2D);
// 
// 		textureManagement.Enable(firstTexture2D,0);
// 
// 		ASSERT_UNEQUAL_NULL_PTR(textureManagement.Lock(firstTexture2D,0,BufferLocking::ReadWrite));
// 		textureManagement.Unlock(firstTexture2D,0);
// 
// 		textureManagement.Update(firstTexture2D,0);
// 		textureManagement.Disable(firstTexture2D,0);
// 
// 		ASSERT_UNEQUAL_NULL_PTR(textureManagement.GetResource(firstTexture2D));
// 		ASSERT_TRUE(textureManagement.IsInTextureMap(firstTexture2D));
// 
// 		textureManagement.Unbind(firstTexture2D);
// 
// 		ASSERT_FALSE(textureManagement.IsInTextureMap(firstTexture2D));
// 	}
// 
// 	Texture2DSmartPointer secondTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture2D.trt"));
// 
// 	std::shared_ptr<PlatformTexture2D> platformTexture(new PlatformTexture2D(renderer.get(), secondTexture2D.GetData()));
// 	textureManagement.InsertTextureMap(secondTexture2D,platformTexture);
// 
// 	ASSERT_UNEQUAL_NULL_PTR(textureManagement.GetResource(secondTexture2D));
// 	ASSERT_TRUE(textureManagement.IsInTextureMap(secondTexture2D));
// 
// 	textureManagement.RemoveTextureMap(secondTexture2D);
// 
// 	ASSERT_FALSE(textureManagement.IsInTextureMap(secondTexture2D));
}

void Rendering::TextureManagementTesting
	::Texture3DTest()
{
// 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
// 	renderer->Init();
// 
// 	TextureManagement<PlatformTexture3D> textureManagement(renderer);
// 
// 	for (int i = 0;i < 10;++i)
// 	{
// 		Texture3DSmartPointer firstTexture3D = 	LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture3D.trt"));
// 
// 		ASSERT_FALSE(textureManagement.IsInTextureMap(firstTexture3D));
// 
// 		if(i % 2 == 0)
// 			textureManagement.Bind(firstTexture3D);
// 
// 		textureManagement.Enable(firstTexture3D,0);
// 
// 		ASSERT_UNEQUAL_NULL_PTR(textureManagement.Lock(firstTexture3D,0,BufferLocking::ReadWrite));
// 		textureManagement.Unlock(firstTexture3D,0);
// 
// 		textureManagement.Update(firstTexture3D,0);
// 		textureManagement.Disable(firstTexture3D,0);
// 
// 		ASSERT_UNEQUAL_NULL_PTR(textureManagement.GetResource(firstTexture3D));
// 		ASSERT_TRUE(textureManagement.IsInTextureMap(firstTexture3D));
// 
// 		textureManagement.Unbind(firstTexture3D);
// 
// 		ASSERT_FALSE(textureManagement.IsInTextureMap(firstTexture3D));
// 	}
// 
// 	Texture3DSmartPointer secondTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture3D.trt"));
// 
// 	std::shared_ptr<PlatformTexture3D> platformTexture(new PlatformTexture3D(renderer.get(), secondTexture3D.GetData()));
// 	textureManagement.InsertTextureMap(secondTexture3D,platformTexture);
// 
// 	ASSERT_UNEQUAL_NULL_PTR(textureManagement.GetResource(secondTexture3D));
// 	ASSERT_TRUE(textureManagement.IsInTextureMap(secondTexture3D));
// 
// 	textureManagement.RemoveTextureMap(secondTexture3D);
// 
// 	ASSERT_FALSE(textureManagement.IsInTextureMap(secondTexture3D));
}

void Rendering::TextureManagementTesting
	::TextureCubeTest()
{
// 	RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
// 	renderer->Init();
// 
// 	TextureManagement<PlatformTextureCube> textureManagement(renderer);
// 
// 	for (int i = 0;i < 10;++i)
// 	{
// 		TextureCubeSmartPointer firstTextureCube = 	LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/TextureCube.trt"));
// 
// 		ASSERT_FALSE(textureManagement.IsInTextureMap(firstTextureCube));
// 
// 		if(i % 2 == 0)
// 			textureManagement.Bind(firstTextureCube);
// 
// 		textureManagement.Enable(firstTextureCube,0);
// 
// 		ASSERT_UNEQUAL_NULL_PTR(textureManagement.LockCube(firstTextureCube,1,0,BufferLocking::ReadWrite));
// 		textureManagement.UnlockCube(firstTextureCube,1,0);
// 
// 		textureManagement.UpdateCube(firstTextureCube,2,0);
// 		textureManagement.Disable(firstTextureCube,0);
// 
// 		ASSERT_UNEQUAL_NULL_PTR(textureManagement.GetResource(firstTextureCube));
// 		ASSERT_TRUE(textureManagement.IsInTextureMap(firstTextureCube));
// 
// 		textureManagement.Unbind(firstTextureCube);
// 
// 		ASSERT_FALSE(textureManagement.IsInTextureMap(firstTextureCube));
// 	}
// 
// 	TextureCubeSmartPointer secondTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/TextureCube.trt"));
// 
// 	std::shared_ptr<PlatformTextureCube> platformTexture(new PlatformTextureCube(renderer.get(), secondTextureCube.GetData()));
// 	textureManagement.InsertTextureMap(secondTextureCube,platformTexture);
// 
// 	ASSERT_UNEQUAL_NULL_PTR(textureManagement.GetResource(secondTextureCube));
// 	ASSERT_TRUE(textureManagement.IsInTextureMap(secondTextureCube));
// 
// 	textureManagement.RemoveTextureMap(secondTextureCube);
// 
// 	ASSERT_FALSE(textureManagement.IsInTextureMap(secondTextureCube));
}






 