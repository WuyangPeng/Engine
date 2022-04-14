// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/09 15:28)

#include "PlatformTextureCubeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Rendering/Renderers/PlatformTextureCube.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/LoadTexture.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PlatformTextureCubeTesting)

void Rendering::PlatformTextureCubeTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(TextureCubeTest);

    RendererManager::Destroy();
}

void Rendering::PlatformTextureCubeTesting::TextureCubeTest() noexcept
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
    // 	ASSERT_UNEQUAL_NULL_PTR(texture.Lock(1,0, BufferLocking::WriteOnly));
    // 	texture.Unlock(1, 0);
    //
    // 	texture.Disable(renderer.get(),0);
}
