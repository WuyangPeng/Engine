/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/24 16:57)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_SORT_POINTS_ON_CIRCLE_H
#define MATHEMATICS_RATIONAL_RATIONAL_SORT_POINTS_ON_CIRCLE_H

#include "Mathematics/MathematicsDll.h"

#include "CircleSortObject.h"

#include <array>
#include <vector>

/// 输入point是点，而center是要围绕其对点进行排序的中心点。
/// 对于初始点center和非零方向direction，参考光线（角度0）为center + t * direction。
/// 方向不必是单位长度。
/// 如果sortCcw为“true”，则从参考射线逆时针方向的角度为正值，且为[0,pi]。参考射线顺时针方向的角度为负值，单位为(-pi,0]。
/// 如果sortCCW为“false”，则参考射线的顺时针方向角度为正值，单位为[0,pi]。参考射线的逆时针方向角度则为负值，表示为(-pi,0]。
/// 输出“Indices[]”提供了间接排序。
/// 排序的点为P[indices[0]], P[indices[1]], ..., P[indices[P.size()-1]]
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
        using CircleSortObject = CircleSortObject<T>;

    public:
        CLASS_INVARIANT_DECLARE;

        /// 排序算法使用std::atan2并包含算术运算，
        /// 当T为'float'或'double'时，所有运算都会出现浮点舍入错误。
        /// T的精确有理类型不能解决问题，因为std::atan2存在数学错误，
        /// 因为函数不能仅使用算术运算来产生精确的角度。
        NODISCARD static Indices ByAngle(const Points& point,
                                         const Vector2& center,
                                         const Vector2& direction,
                                         bool sortCcw);

        /// 排序算法只使用算术运算。它支持float'或'double'的T，
        /// 但由于舍入误差，不能保证正确性在理论上是正确的。
        /// 如果T是精确有理类型，则输出在理论上是正确的。
        NODISCARD static Indices ByGeometry(const Points& point,
                                            const Vector2& center,
                                            const Vector2& direction,
                                            bool sortCcw);

    private:
        using CircleSortObjectContainer = std::vector<CircleSortObject>;
        using SortFunction = bool (*)(const CircleSortObject& lhs, const CircleSortObject& rhs);

        NODISCARD static Indices Sort(const Points& point,
                                      const Vector2& center,
                                      const Vector2& direction,
                                      bool sortCcw,
                                      SortFunction sortFunction);

    private:
        NODISCARD static bool LessThanByAngle(const CircleSortObject& lhs, const CircleSortObject& rhs);
        NODISCARD static bool LessThanByGeometry(const CircleSortObject& lhs, const CircleSortObject& rhs);
    };
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_SORT_POINTS_ON_CIRCLE_H