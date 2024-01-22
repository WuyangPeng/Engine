/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:57)

#ifndef FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Framework/Application/PixelScreen.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE PixelViewMiddleLayerImpl
    {
    public:
        using ClassType = PixelViewMiddleLayerImpl;

        using Colour = Rendering::Colour<uint8_t>;
        using BaseRenderer = Rendering::BaseRenderer;
        using RendererSharedPtr = std::shared_ptr<BaseRenderer>;
        using ConstRendererSharedPtr = std::shared_ptr<const BaseRenderer>;

    public:
        PixelViewMiddleLayerImpl(int width, int height);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Colour GetPixel(int x, int y) const;
        NODISCARD bool IsDoFlip() const noexcept;

        void Resize(const WindowSize& windowSize, const Colour& colour);

        void ClearScreen(const Colour& colour);

        void DoFlip(bool doFlip);

        void SetPixel(int x, int y, const Colour& colour);

        void SetThickPixel(int x, int y, int thick, const Colour& colour);

        void DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& colour);

        void DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& colour, bool solid = false);

        void DrawCircle(int xCenter, int yCenter, int radius, const Colour& colour, bool solid = false);

        void Fill(int x, int y, const Colour& foreColour, const Colour& backColour);

        NODISCARD int GetScreenWidth() const noexcept;
        NODISCARD int GetScreenHeight() const noexcept;

    private:
        PixelScreen pixelScreen;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H
