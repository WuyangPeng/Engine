///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/22 14:33)

#ifndef RENDERING_RENDERERS_RENDERER_PARAMETER_H
#define RENDERING_RENDERERS_RENDERER_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "RendererBasis.h"
#include "Flags/RendererTypes.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(RendererParameter, RendererParameterImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererParameter
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(RendererParameter);
        using Colour = Colour<float>;

    public:
        explicit RendererParameter(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        void LoadConfiguration(const std::string& fileName);

        NODISCARD RendererTypes GetRendererType() const noexcept;

        NODISCARD TextureFormat GetColorFormat() const noexcept;
        NODISCARD TextureFormat GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultisamples() const noexcept;
        NODISCARD Colour GetClearColor() const noexcept;

        NODISCARD std::string GetWindowTitle() const;
        NODISCARD int GetXPosition() const noexcept;
        NODISCARD int GetYPosition() const noexcept;
        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD bool IsAllowResize() const noexcept;

        void Resize(int width, int height);

        NODISCARD RendererBasis GetRendererBasis() const noexcept;

        NODISCARD System::String GetWindowMenuName() const;
        NODISCARD System::String GetWindowClassName() const;

        NODISCARD int GetIcon() const noexcept;
        NODISCARD bool IsIconDefault() const noexcept;
        NODISCARD int GetCursor() const noexcept;
        NODISCARD bool IsCursorDefault() const noexcept;
        NODISCARD System::WindowsBrushTypes GetBackground() const noexcept;

    private:
        void DoLoadConfiguration(const std::string& fileName);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_PARAMETER_H
