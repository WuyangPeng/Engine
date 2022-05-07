///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 10:13)

#ifndef RENDERING_RENDERERS_RENDERER_PARAMETER_IMPL_H
#define RENDERING_RENDERERS_RENDERER_PARAMETER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/RendererBasis.h"

#include <string>

namespace Rendering
{
    class RendererParameterImpl
    {
    public:
        using ClassType = RendererParameterImpl;
        using ColourType = Colour<float>;

    public:
        explicit RendererParameterImpl(RendererTypes type) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD TextureFormat GetColorFormat() const noexcept;
        NODISCARD TextureFormat GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultisamples() const noexcept;
        NODISCARD ColourType GetClearColor() const noexcept;

        NODISCARD std::string GetWindowTitle() const;
        NODISCARD int GetXPosition() const noexcept;
        NODISCARD int GetYPosition() const noexcept;
        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD bool IsAllowResize() const noexcept;
        NODISCARD RendererTypes GetRendererType() const noexcept;

        void SetTextureFormat(TextureFormat colorFormat, TextureFormat depthStencilFormat, int numMultisamples) noexcept;

        void SetClearColor(float red, float green, float blue, float alpha) noexcept;

        void SetWindowParameter(const std::string& aWindowTitle, int width, int height, int x, int y, bool allowResize);

        void Resize(int width, int height) noexcept;

        NODISCARD RendererBasis GetRendererBasis() const noexcept;

        NODISCARD System::String GetWindowClassName() const;
        void SetWindowClassName(const System::String& aClassName);

        NODISCARD System::String GetWindowMenuName() const;
        void SetWindowMenuName(const System::String& aMenuName);

        NODISCARD int GetIcon() const noexcept;
        NODISCARD bool IsIconDefault() const noexcept;
        NODISCARD int GetCursor() const noexcept;
        NODISCARD bool IsCursorDefault() const noexcept;
        NODISCARD System::WindowsBrushTypes GetBackground() const noexcept;

        void SetWindowPictorialParameter(int aIcon, bool aIsIconDefault, int aCursor, bool aIsCursorDefault, System::WindowsBrushTypes aBackground) noexcept;

    private:
        RendererTypes rendererTypes;
        RendererBasis rendererBasis;
        ColourType colour;
        std::string windowTitle;
        int windowX;
        int windowY;
        bool isAllowResize;
        System::String className;
        System::String menuName;
        int icon;
        bool isIconDefault;
        int cursor;
        bool isCursorDefault;
        System::WindowsBrushTypes background;
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_PARAMETER_IMPL_H
