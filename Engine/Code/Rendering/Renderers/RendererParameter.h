// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:39)

#ifndef RENDERING_RENDERERS_RENDERER_PARAMETER_H
#define RENDERING_RENDERERS_RENDERER_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "RendererBasis.h"
#include "Flags/RendererTypes.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"

EXPORT_SHARED_PTR(Rendering, RendererParameterImpl, RENDERING_DEFAULT_DECLARE);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererParameter
    {
    private:
        void Copy();

    public:
        TYPE_DECLARE(RendererParameter);
        using ClassShareType = CoreTools::DelayCopyUnsharedClasses;
        using Colour = Colour<float>;

    public:
        explicit RendererParameter(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        void LoadConfiguration(const std::string& fileName);

        RendererTypes GetRendererType() const noexcept;

        TextureFormat GetColorFormat() const noexcept;
        TextureFormat GetDepthStencilFormat() const noexcept;
        int GetNumMultisamples() const noexcept;
        Colour GetClearColor() const noexcept;

        const std::string GetWindowTitle() const;
        int GetXPosition() const noexcept;
        int GetYPosition() const noexcept;
        int GetWidth() const noexcept;
        int GetHeight() const noexcept;
        bool IsAllowResize() const noexcept;

        void Resize(int width, int height);

        const RendererBasis GetRendererBasis() const noexcept;

        System::String GetWindowMenuName() const;
        System::String GetWindowClassName() const;

        int GetIcon() const noexcept;
        bool IsIconDefault() const noexcept;
        int GetCursor() const noexcept;
        bool IsCursorDefault() const noexcept;
        System::WindowsBrushTypes GetBackground() const noexcept;

    private:
        void DoLoadConfiguration(const std::string& fileName);

    private:
        using RendererParameterImplPtr = std::shared_ptr<ImplType>;

    private:
        RendererParameterImplPtr impl;
    };
}

#endif  // RENDERING_RENDERERS_RENDERER_PARAMETER_H
