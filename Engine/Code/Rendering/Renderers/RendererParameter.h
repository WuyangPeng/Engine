///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/05 20:44)

#ifndef RENDERING_RENDERERS_RENDERER_PARAMETER_H
#define RENDERING_RENDERERS_RENDERER_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "RendererBasis.h"
#include "RenderersFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(RendererParameter, RendererParameterImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererParameter
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(RendererParameter);

        using String = System::String;
        using ColourType = Colour<float>;
        using WindowsBrushTypes = System::WindowsBrushTypes;

    public:
        explicit RendererParameter(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD RendererTypes GetRendererType() const noexcept;

        NODISCARD DataFormatType GetColorFormat() const noexcept;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultisamples() const noexcept;
        NODISCARD ColourType GetClearColor() const noexcept;

        NODISCARD std::string GetWindowTitle() const;
        NODISCARD int GetXPosition() const noexcept;
        NODISCARD int GetYPosition() const noexcept;
        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD bool IsAllowResize() const noexcept;

        void Resize(int width, int height);

        NODISCARD RendererBasis GetRendererBasis() const noexcept;

        NODISCARD String GetWindowMenuName() const;
        NODISCARD String GetWindowClassName() const;

        NODISCARD int GetIcon() const noexcept;
        NODISCARD bool IsIconDefault() const noexcept;
        NODISCARD int GetCursor() const noexcept;
        NODISCARD bool IsCursorDefault() const noexcept;
        NODISCARD WindowsBrushTypes GetBackground() const noexcept;

    private:
        NODISCARD static PackageType CreateRendererParameter(const std::string& fileName);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_PARAMETER_H
