///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/25 14:31)

#include "Rendering/RenderingExport.h"

#include "RendererBasis.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::RendererBasis::RendererBasis(int width, int height, DataFormatType colorFormat, DataFormatType depthStencilFormat, int numMultiSamples)
    : windowWidth{ width },
      windowHeight{ height },
      colorFormat{ colorFormat },
      depthStencilFormat{ depthStencilFormat },
      multiSamplesNumber{ numMultiSamples }
{
    if (!IsValid())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ⱦ����������ڻ�����㡣"s))
    }
}

Rendering::RendererBasis::RendererBasis() noexcept
    : windowWidth{ 0 },
      windowHeight{ 0 },
      colorFormat{ DataFormatType::R32G32B32A32Float },
      depthStencilFormat{ DataFormatType::D24UNormS8UInt },
      multiSamplesNumber{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

bool Rendering::RendererBasis::IsValid() const noexcept
{
    if (0 <= multiSamplesNumber && 0 <= windowWidth && 0 <= windowHeight)
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

int Rendering::RendererBasis::GetNumMultiSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return multiSamplesNumber;
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
        THROW_EXCEPTION(SYSTEM_TEXT("����Ŀ�Ȼ�߶�С���㡣"s))
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

void Rendering::RendererBasis::SetMultiSamplesNumber(int numMultiSamples)
{
    RENDERING_CLASS_IS_VALID_1;

    if (numMultiSamples < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����Ķ��ز�������С���㡣"s))
    }

    multiSamplesNumber = numMultiSamples;
}
