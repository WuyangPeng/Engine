///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:35)

#ifndef FRAMEWORK_APPLICATION_RENDERER_DATA_IMPL_H
#define FRAMEWORK_APPLICATION_RENDERER_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>
#include <string>

namespace Rendering
{
    class RendererDataImpl
    {
    public:
        using ClassType = RendererDataImpl;
        using Renderer = Rendering::Renderer;
        using TextureFormat = Rendering::TextureFormat;
        using Colour = Rendering::Colour<float>;
        using RendererSharedPtr = std::shared_ptr<Renderer>;
        using RendererTypes = Rendering::RendererTypes;

    public:
        explicit RendererDataImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        void LoadConfiguration(const std::string& fileName);

        void ClearColor();
        void Resize(int width, int height);

        void DrawMessage(int x, int y, const Colour& color, const std::string& message);

        NODISCARD DataFormatType GetColorFormat() const noexcept;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultisamples() const noexcept;
        NODISCARD Colour GetClearColor() const noexcept;

        NODISCARD std::string GetWindowTitle() const;
        NODISCARD int GetXPosition() const noexcept;
        NODISCARD int GetYPosition() const noexcept;
        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD bool IsAllowResize() const noexcept;
        NODISCARD RendererTypes GetRendererType() const;

    private:
        RendererSharedPtr renderer;
    };
}

#endif  // FRAMEWORK_APPLICATION_RENDERER_DATA_IMPL_H
