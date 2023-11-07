///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 20:10)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_SORT_POINTS_ON_CIRCLE_H
#define MATHEMATICS_RATIONAL_RATIONAL_SORT_POINTS_ON_CIRCLE_H

#include "Mathematics/MathematicsDll.h"

#include <array>
#include <vector>

namespace Mathematics
{
    template <typename T>
    class SortPointsOnCircle final
    {
    public:
        using ClassType = SortPointsOnCircle<T>;

        using Vector2 = std::array<T, 2>;
        using Points = std::vector<Vector2>;
        using Indices = std::vector<int>;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static Indices ByAngle(const Points& point,
                                         const Vector2& center,
                                         const Vector2& direction,
                                         bool sortCcw);

        NODISCARD static Indices ByGeometry(const Points& point,
                                            const Vector2& center,
                                            const Vector2& direction,
                                            bool sortCcw);

    private:
        struct SortObject
        {
            SortObject(const Vector2& w, int index);
            SortObject();

            Vector2 w;
            int index;
        };

        NODISCARD static bool LessThanByAngle(const SortObject& lhs, const SortObject& rhs);
        NODISCARD static bool LessThanByGeometry(const SortObject& object0, const SortObject& object1);
    };
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_SORT_POINTS_ON_CIRCLE_H