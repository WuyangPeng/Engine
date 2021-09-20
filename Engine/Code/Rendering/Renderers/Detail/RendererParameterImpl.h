// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:04)

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

        TextureFormat GetColorFormat() const noexcept;
        TextureFormat GetDepthStencilFormat() const noexcept;
        int GetNumMultisamples() const noexcept;
        ColourType GetClearColor() const noexcept;

        const std::string GetWindowTitle() const;
        int GetXPosition() const noexcept;
        int GetYPosition() const noexcept;
        int GetWidth() const noexcept;
        int GetHeight() const noexcept;
        bool IsAllowResize() const noexcept;
        RendererTypes GetRendererType() const noexcept;

        void SetTextureFormat(TextureFormat colorFormat, TextureFormat depthStencilFormat, int numMultisamples) noexcept;

        void SetClearColor(float red, float green, float blue, float alpha) noexcept;

        void SetWindowParameter(const std::string& windowTitle, int width, int height, int x, int y, bool allowResize);

        void Resize(int width, int height) noexcept;

        const RendererBasis GetRendererBasis() const noexcept;

        System::String GetWindowClassName() const;
        void SetWindowClassName(const System::String& className);

        System::String GetWindowMenuName() const;
        void SetWindowMenuName(const System::String& menuName);

        int GetIcon() const noexcept;
        bool IsIconDefault() const noexcept;
        int GetCursor() const noexcept;
        bool IsCursorDefault() const noexcept;
        System::WindowsBrushTypes GetBackground() const noexcept;

        void SetWindowPictorialParameter(int icon, bool isIconDefault, int cursor, bool isCursorDefault, System::WindowsBrushTypes background) noexcept;

    private:
        RendererTypes m_Type;
        RendererBasis m_RendererBasis;
        ColourType m_Colour;
        std::string m_WindowTitle;
        int m_WindowX;
        int m_WindowY;
        bool m_IsAllowResize;
        System::String m_ClassName;
        System::String m_MenuName;
        int m_Icon = 0;
        bool m_IsIconDefault = false;
        int m_Cursor = 0;
        bool m_IsCursorDefault = false;
        ;
        System::WindowsBrushTypes m_Background{};
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_PARAMETER_IMPL_H
