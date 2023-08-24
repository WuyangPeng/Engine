///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 14:56)

#ifndef FRAMEWORK_APPLICATION_PIXEL_SCREEN_DRAW_LINE_H
#define FRAMEWORK_APPLICATION_PIXEL_SCREEN_DRAW_LINE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/WindowCreate/WindowPoint.h"

#include <vector>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE PixelScreenDrawLine
    {
    public:
        using ClassType = PixelScreenDrawLine;

    public:
        PixelScreenDrawLine(int xMin, int yMin, int xMax, int yMax);

        CLASS_INVARIANT_DECLARE;

#ifdef OPEN_CLASS_INVARIANT

        NODISCARD bool IsEndpointCorrect() const;

#endif  // OPEN_CLASS_INVARIANT

        NODISCARD int GetSize() const;
        NODISCARD const WindowPoint& operator[](int index) const;

    private:
        using WindowPointContainer = std::vector<WindowPoint>;

    private:
        void Calculate();
        void DrawLineOnX();
        void DrawLineOnY();

    private:
        int xMin;
        int yMin;
        int xMax;
        int yMax;

        // 线段的方向。
        int distanceX;
        int distanceY;

        // 增量或减量取决于线的方向。
        int stepX;
        int stepY;

        WindowPointContainer line;
    };
}

#endif  // FRAMEWORK_APPLICATION_PIXEL_SCREEN_DRAW_LINE_H
