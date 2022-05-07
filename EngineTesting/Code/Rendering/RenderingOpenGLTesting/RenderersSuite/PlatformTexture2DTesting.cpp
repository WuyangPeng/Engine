// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 15:28)

#include "PlatformTexture2DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "Rendering/Renderers/PlatformTexture2D.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/LoadTexture.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PlatformTexture2DTesting)

void Rendering::PlatformTexture2DTesting::MainTest()
{
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(Texture2DTest);

    RendererManager::Destroy();
}
#include SYSTEM_WARNING_DISABLE(26414)
void Rendering::PlatformTexture2DTesting::Texture2DTest()
{
    auto firstTexture2D = LoadTexture::Load2DFromFile(SYSTEM_TEXT("Resource/OpenGLRendererSuite/Texture2D.trt"));

    RendererSharedPtr renderer(std::make_shared<Renderer>("Configuration/Renderer.json"));
    renderer->Init();

    PlatformTexture2D texture(renderer.get(), firstTexture2D.get());

    texture.Enable(renderer.get(), 0);

    ASSERT_UNEQUAL_NULL_PTR(texture.Lock(0, BufferLocking::WriteOnly));
    texture.Unlock(0);

    texture.Disable(renderer.get(), 0);
}
