// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:36)

#include "OpenGLTextureDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Rendering/Resources/LoadTexture.h"
#include "Rendering/OpenGLRenderer/OpenGLTextureDataDetail.h"
#include "Rendering/Renderers/RendererManager.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, OpenGLTextureDataTesting)

void Rendering::OpenGLTextureDataTesting
	::MainTest()
{ 
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(Texture1DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Texture2DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Texture3DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TextureCubeTest);

	RendererManager::Destroy();
}

void Rendering::OpenGLTextureDataTesting
	::Texture1DTest()
{
	auto firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture1D.trt"));
	
	OpenGLTextureData<Texture1D> data(firstTexture1D.get());

	ASSERT_TRUE(0 < data.GetTexture());

	data.Enable (0);	
	ASSERT_UNEQUAL_NULL_PTR(data.Lock(0, BufferLocking::WriteOnly));
	data.Unlock (0);
	data.Disable (0);
}

void Rendering::OpenGLTextureDataTesting
	::Texture2DTest()
{
    auto firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture2D.trt"));
	
	OpenGLTextureData<Texture2D> data(firstTexture2D.get());

	ASSERT_TRUE(0 < data.GetTexture());

	data.Enable (0);	
	ASSERT_UNEQUAL_NULL_PTR(data.Lock(0, BufferLocking::WriteOnly));
	data.Unlock (0);
	data.Disable (0);
}

void Rendering::OpenGLTextureDataTesting
	::Texture3DTest()
{
    auto firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture3D.trt"));

	OpenGLTextureData<Texture3D> data(firstTexture3D.get());

	ASSERT_TRUE(0 < data.GetTexture());

	data.Enable (0);	
	ASSERT_UNEQUAL_NULL_PTR(data.Lock(0, BufferLocking::WriteOnly));
	data.Unlock (0);
	data.Disable (0);
}

void Rendering::OpenGLTextureDataTesting
	::TextureCubeTest()
{
    auto firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/TextureCube.trt"));

	OpenGLTextureData<TextureCube> data(firstTextureCube.get());

	ASSERT_TRUE(0 < data.GetTexture());

	data.Enable (0);	
	ASSERT_UNEQUAL_NULL_PTR(data.Lock(2, 0, BufferLocking::WriteOnly));
	data.Unlock (2,0);
	data.Disable (0);
}