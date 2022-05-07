///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 19:09)

#include "Rendering/RenderingExport.h"

#include "RendererBasis.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RendererBasis::RendererBasis(int width, int height, TextureFormat colorFormat, TextureFormat depthStencilFormat, int numMultisamples) noexcept
    : windowWidth{ width },
      windowHeight{ height },
      colorFormat{ colorFormat },
      depthStencilFormat{ depthStencilFormat },
      multisamplesNumber{ numMultisamples }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::RendererBasis::RendererBasis() noexcept
    : windowWidth{ 0 },
      windowHeight{},
      colorFormat{ TextureFormat::DefaultColour },
      depthStencilFormat{ TextureFormat::DefaultDepth },
      multisamplesNumber{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::RendererBasis::IsValid() const noexcept
{
    if (0 <= multisamplesNumber && 0 <= windowWidth && 0 <= windowHeight)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::TextureFormat Rendering::RendererBasis::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return colorFormat;
}

Rendering::TextureFormat Rendering::RendererBasis::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return depthStencilFormat;
}

int Rendering::RendererBasis::GetNumMultisamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return multisamplesNumber;
}

int Rendering::RendererBasis::GetWidth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return windowWidth;
}

int Rendering::RendererBasis::GetHeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return windowHeight;
}

void Rendering::RendererBasis::SetSize(int width, int height) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    windowWidth = width;
    windowHeight = height;
}

void Rendering::RendererBasis::SetTextureFormat(TextureFormat aColorFormat, TextureFormat aDepthStencilFormat) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    colorFormat = aColorFormat;
    depthStencilFormat = aDepthStencilFormat;
}

void Rendering::RendererBasis::SetMultisamplesNumber(int numMultisamples) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    multisamplesNumber = numMultisamples;
}
