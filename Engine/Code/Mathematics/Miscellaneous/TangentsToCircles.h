///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/24 22:08)

#ifndef MATHEMATICS_MISCELLANEOUS_TANGENTS_TO_CIRCLES_H
#define MATHEMATICS_MISCELLANEOUS_TANGENTS_TO_CIRCLES_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Objects2DFwd.h"

#include <array>

namespace Mathematics
{
    template <typename Real>
    class TangentsToCircles
    {
    public:
        using ClassType = TangentsToCircles<Real>;

    public:
        NODISCARD static bool GetTangentsToCircles(const Circle2<Real>& circle0, const Circle2<Real>& circle1, std::array<Line2<Real>, 4>& line);
    };
}

#endif  // MATHEMATICS_MISCELLANEOUS_TANGENTS_TO_CIRCLES_H
