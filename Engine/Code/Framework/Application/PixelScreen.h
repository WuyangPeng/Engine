///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 10:52)

#ifndef FRAMEWORK_APPLICATION_PIXEL_SCREEN_H
#define FRAMEWORK_APPLICATION_PIXEL_SCREEN_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"

FRAMEWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(PixelScreen, PixelScreenImpl);

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE PixelScreen
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(PixelScreen);
        using Colour = Rendering::Colour<uint8_t>;
        using RendererSharedPtr = std::shared_ptr<Rendering::Renderer>;
        using ConstRendererSharedPtr = std::shared_ptr<const Rendering::Renderer>;

    public:
        explicit PixelScreen(const WindowSize& size);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetScreenWidth() const noexcept;
        NODISCARD int GetScreenHeight() const noexcept;

        NODISCARD Colour GetPixel(int x, int y) const;

        void ClearScreen(const Colour& color);

        void Resize(const WindowSize& size, const Colour& color);

        NODISCARD bool IsDoFlip() const noexcept;
        void DoFlip(bool doFlip);
        void SetPixel(int x, int y, const Colour& color);
        void SetThickPixel(int x, int y, int thick, const Colour& color);

        void DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& color);
        void DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& color, bool solid = false);
        void DrawCircle(int xCenter, int yCenter, int radius, const Colour& color, bool solid = false);
        void Fill(int x, int y, const Colour& foreColor, const Colour& backColor);

        void Draw(const RendererSharedPtr& renderer);

    private:
        PackageType impl;
    };
}

#endif  // FRAMEWORK_APPLICATION_PIXEL_SCREEN_H
