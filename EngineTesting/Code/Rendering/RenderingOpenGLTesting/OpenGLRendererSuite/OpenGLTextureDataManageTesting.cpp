// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:36)

#include "OpenGLTextureDataManageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Rendering/Resources/LoadTexture.h"
#include "Rendering/OpenGLRenderer/OpenGLTextureDataDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/OpenGLRenderer/OpenGLTextureDataManageDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, OpenGLTextureDataManageTesting)

void Rendering::OpenGLTextureDataManageTesting
	::MainTest()
{ 
	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(Texture1DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Texture2DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Texture3DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TextureCubeTest);

	RendererManager::Destroy();
}
 
void Rendering::OpenGLTextureDataManageTesting
	::Texture1DTest()
{
	Texture1DSharedPtr firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture1D.trt"));

	OpenGLTextureData<Texture1D> data(firstTexture1D.get());

	ASSERT_TRUE(0 < data.GetTexture());

	data.Enable (0);	
	{
		OpenGLTextureDataManager<OpenGLTextureData<Texture1D> > manage(data);
		ASSERT_UNEQUAL_NULL_PTR(manage.Lock(0, BufferLocking::WriteOnly));
	}

	data.Disable (0);
}

void Rendering::OpenGLTextureDataManageTesting
	::Texture2DTest()
{
	Texture2DSharedPtr firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture2D.trt"));

	OpenGLTextureData<Texture2D> data(firstTexture2D.get());

	ASSERT_TRUE(0 < data.GetTexture());

	data.Enable (0);	
	{
		OpenGLTextureDataManager<OpenGLTextureData<Texture2D> > manage(data);
		ASSERT_UNEQUAL_NULL_PTR(manage.Lock(0, BufferLocking::WriteOnly));
	}

	data.Disable (0);
}

void Rendering::OpenGLTextureDataManageTesting
	::Texture3DTest()
{
	auto firstTexture3D = LoadTexture::Load3DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture3D.trt"));

	OpenGLTextureData<Texture3D> data(firstTexture3D.get());

	ASSERT_TRUE(0 < data.GetTexture());

	data.Enable (0);	
	{
		OpenGLTextureDataManager<OpenGLTextureData<Texture3D> > manage(data);
		ASSERT_UNEQUAL_NULL_PTR(manage.Lock(0, BufferLocking::WriteOnly));
	}

	data.Disable (0);
}

void Rendering::OpenGLTextureDataManageTesting
	::TextureCubeTest()
{
    auto firstTextureCube = LoadTexture::LoadCubeFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/TextureCube.trt"));

	OpenGLTextureData<TextureCube> data(firstTextureCube.get());

	ASSERT_TRUE(0 < data.GetTexture());

	data.Enable (0);	
	{
		OpenGLTextureDataManager<OpenGLTextureData<TextureCube> > manage(data);
		ASSERT_UNEQUAL_NULL_PTR(manage.Lock(3, 0, BufferLocking::WriteOnly));
	}

	data.Disable (0);
}