/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/02 15:16)

#ifndef RENDERING_RENDERER_ENGINE_RENDERER_BASIS_H
#define RENDERING_RENDERER_ENGINE_RENDERER_BASIS_H

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
        RendererBasis(int width, int height, DataFormatType colorFormat, DataFormatType depthStencilFormat, int numMultiSamples);

        NODISCARD bool IsValid() const noexcept;

        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD DataFormatType GetColorFormat() const noexcept;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultiSamples() const noexcept;

        void SetSize(int width, int height);
        void SetDataFormat(DataFormatType aColorFormat, DataFormatType aDepthStencilFormat) noexcept;
        void SetMultiSamplesNumber(int numMultiSamples);

    private:
        int windowWidth;
        int windowHeight;
        DataFormatType colorFormat;
        DataFormatType depthStencilFormat;
        int multiSamplesNumber;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERER_BASIS_H
