///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/05 14:27)

#ifndef RENDERING_RENDERERS_RENDERER_BASIS_H
#define RENDERING_RENDERERS_RENDERER_BASIS_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererBasis
    {
    public:
        using ClassType = RendererBasis;

    public:
        RendererBasis() noexcept;
        RendererBasis(int width, int height, DataFormatType colorFormat, DataFormatType depthStencilFormat, int numMultisamples);

        NODISCARD bool IsValid() const noexcept;

        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD DataFormatType GetColorFormat() const noexcept;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultisamples() const noexcept;

        void SetSize(int width, int height);
        void SetDataFormat(DataFormatType aColorFormat, DataFormatType aDepthStencilFormat) noexcept;
        void SetMultisamplesNumber(int numMultisamples);

    private:
        int windowWidth;
        int windowHeight;
        DataFormatType colorFormat;
        DataFormatType depthStencilFormat;
        int multisamplesNumber;
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_BASIS_H
