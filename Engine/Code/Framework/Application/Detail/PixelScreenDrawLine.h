///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/09 14:56)

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

        // �߶εķ���
        int distanceX;
        int distanceY;

        // ���������ȡ�����ߵķ���
        int stepX;
        int stepY;

        WindowPointContainer line;
    };
}

#endif  // FRAMEWORK_APPLICATION_PIXEL_SCREEN_DRAW_LINE_H
