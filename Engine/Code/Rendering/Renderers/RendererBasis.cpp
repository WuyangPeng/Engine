///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:50)

#include "Rendering/RenderingExport.h"

#include "RendererBasis.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::RendererBasis::RendererBasis(int width, int height, DataFormatType colorFormat, DataFormatType depthStencilFormat, int numMultisamples)
    : windowWidth{ width },
      windowHeight{ height },
      colorFormat{ colorFormat },
      depthStencilFormat{ depthStencilFormat },
      multisamplesNumber{ numMultisamples }
{
    if (!IsValid())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("渲染参数必须大于或等于零。"s));
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::RendererBasis::RendererBasis() noexcept
    : windowWidth{ 0 },
      windowHeight{ 0 },
      colorFormat{ DataFormatType::R32G32B32A32Float },
      depthStencilFormat{ DataFormatType::D24UNormS8UInt },
      multisamplesNumber{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

bool Rendering::RendererBasis::IsValid() const noexcept
{
    if (0 <= multisamplesNumber && 0 <= windowWidth && 0 <= windowHeight)
        return true;
    else
        return false;
}

Rendering::DataFormatType Rendering::RendererBasis::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return colorFormat;
}

Rendering::DataFormatType Rendering::RendererBasis::GetDepthStencilFormat() const noexcept
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

void Rendering::RendererBasis::SetSize(int width, int height)
{
    RENDERING_CLASS_IS_VALID_1;

    if (width < 0 || height < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入的宽度或高度小于零。"s));
    }

    windowWidth = width;
    windowHeight = height;
}

void Rendering::RendererBasis::SetDataFormat(DataFormatType aColorFormat, DataFormatType aDepthStencilFormat) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    colorFormat = aColorFormat;
    depthStencilFormat = aDepthStencilFormat;
}

void Rendering::RendererBasis::SetMultisamplesNumber(int numMultisamples)
{
    RENDERING_CLASS_IS_VALID_1;

    if (numMultisamples < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入的多重采样参数小于零。"s));
    }

    multisamplesNumber = numMultisamples;
}
