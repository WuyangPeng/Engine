// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:28)

#include "PlatformTexture1DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Rendering/Renderers/PlatformTexture1D.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/LoadTexture.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PlatformTexture1DTesting)

void Rendering::PlatformTexture1DTesting ::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(Texture1DTest);

    RendererManager::Destroy();
}

void Rendering::PlatformTexture1DTesting ::Texture1DTest()
{
    auto firstTexture1D = LoadTexture::Load1DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture1D.trt"));

    RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
    renderer->Init();

    PlatformTexture1D texture(renderer.get(), firstTexture1D.get());

    texture.Enable(renderer.get(), 0);

    ASSERT_UNEQUAL_NULL_PTR(texture.Lock(0, BufferLocking::WriteOnly));
    texture.Unlock(0);

    texture.Disable(renderer.get(), 0);
}
