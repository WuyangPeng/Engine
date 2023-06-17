///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 10:23)

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
