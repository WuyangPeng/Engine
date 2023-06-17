///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:35)

#ifndef RENDERING_RENDERERS_RENDERER_PARAMETER_IMPL_H
#define RENDERING_RENDERERS_RENDERER_PARAMETER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Renderers/WindowsParameter.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <string>

namespace Rendering
{
    class RendererParameterImpl
    {
    public:
        using ClassType = RendererParameterImpl;

        using String = System::String;
        using ColourType = Colour<float>;
        using WindowsBrushTypes = System::WindowsBrushTypes;

    public:
        explicit RendererParameterImpl(RendererTypes rendererType);

        CLASS_INVARIANT_DECLARE;

        void SetRendererType(RendererTypes aRendererType) noexcept;

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
        NODISCARD RendererTypes GetRendererType() const noexcept;

        void SetTextureFormat(DataFormatType colorFormat, DataFormatType depthStencilFormat, int numMultisamples);

        void SetClearColor(float red, float green, float blue, float alpha);

        void SetWindowParameter(const std::string& windowTitle, int width, int height, int x, int y, bool allowResize);

        void Resize(int width, int height);

        NODISCARD RendererBasis GetRendererBasis() const noexcept;

        NODISCARD String GetWindowClassName() const;
        void SetWindowClassName(const String& className);

        NODISCARD String GetWindowMenuName() const;
        void SetWindowMenuName(const String& menuName);

        NODISCARD int GetIcon() const noexcept;
        NODISCARD bool IsIconDefault() const noexcept;
        NODISCARD int GetCursor() const noexcept;
        NODISCARD bool IsCursorDefault() const noexcept;
        NODISCARD WindowsBrushTypes GetBackground() const noexcept;

        void SetWindowPictorialParameter(int icon, bool isIconDefault, int cursor, bool isCursorDefault, WindowsBrushTypes background);

    private:
        RendererTypes rendererType;
        RendererBasis rendererBasis;
        WindowsParameter windowsParameter;
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_PARAMETER_IMPL_H
