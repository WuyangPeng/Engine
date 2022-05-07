///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 14:53)

#ifndef RENDERING_RENDERERS_VIEWPORT_H
#define RENDERING_RENDERERS_VIEWPORT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Rendering
{
    class Viewport
    {
    public:
        constexpr Viewport(int xPosition, int yPosition, int width, int height)
            : xPosition{ xPosition }, yPosition{ yPosition }, width{ width }, height{ height }
        {
        }

        NODISCARD constexpr int GetXPosition() const
        {
            return xPosition;
        }

        NODISCARD constexpr int GetYPosition() const
        {
            return yPosition;
        }

        NODISCARD constexpr int GetWidth() const
        {
            return width;
        }

        NODISCARD constexpr int GetHeight() const
        {
            return height;
        }

        NODISCARD constexpr bool IsInViewport(int x, int y) const
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

#endif  // RENDERING_RENDERERS_VIEWPORT_H
