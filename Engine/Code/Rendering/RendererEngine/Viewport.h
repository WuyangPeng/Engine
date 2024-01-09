/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 15:18)

#ifndef RENDERING_RENDERER_ENGINE_VIEWPORT_H
#define RENDERING_RENDERER_ENGINE_VIEWPORT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

/// 视窗管理，测量值在窗口坐标中。
/// 窗口的原点为(xPosition，yPosition)，窗口宽度为width，窗口高度为height。
/// DirectX视窗为左手坐标系，原点在窗口的左上角，x轴指向右侧，y轴指向下方。
/// OpenGL视窗是右手坐标系，原点在窗口的左下角，x轴指向右侧，y轴指向上方。
namespace Rendering
{
    class Viewport final
    {
    public:
        using ClassType = Viewport;

    public:
        constexpr Viewport(const int xPosition, const int yPosition, const int width, const int height) noexcept
            : xPosition{ xPosition }, yPosition{ yPosition }, width{ width }, height{ height }
        {
        }

        NODISCARD constexpr int GetXPosition() const noexcept
        {
            return xPosition;
        }

        NODISCARD constexpr int GetYPosition() const noexcept
        {
            return yPosition;
        }

        NODISCARD constexpr int GetWidth() const noexcept
        {
            return width;
        }

        NODISCARD constexpr int GetHeight() const noexcept
        {
            return height;
        }

        NODISCARD constexpr bool IsInViewport(const int x, const int y) const noexcept
        {
            return (xPosition <= x) && (x <= xPosition + width) && (yPosition <= y) && (y <= yPosition + height);
        }

    private:
        int xPosition;
        int yPosition;
        int width;
        int height;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_VIEWPORT_H
