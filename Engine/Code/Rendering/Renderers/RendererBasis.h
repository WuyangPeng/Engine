///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/21 19:08)

#ifndef RENDERING_RENDERERS_RENDERER_BASIS_H
#define RENDERING_RENDERERS_RENDERER_BASIS_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Flags/TextureFormat.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererBasis
    {
    public:
        using ClassType = RendererBasis;

    public:
        RendererBasis() noexcept;
        RendererBasis(int width, int height, TextureFormat colorFormat, TextureFormat depthStencilFormat, int numMultisamples) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD TextureFormat GetColorFormat() const noexcept;
        NODISCARD TextureFormat GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultisamples() const noexcept;

        void SetSize(int width, int height) noexcept;
        void SetTextureFormat(TextureFormat aColorFormat, TextureFormat aDepthStencilFormat) noexcept;
        void SetMultisamplesNumber(int numMultisamples) noexcept;

    private:
        int windowWidth;
        int windowHeight;
        TextureFormat colorFormat;
        TextureFormat depthStencilFormat;
        int multisamplesNumber;
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_BASIS_H
