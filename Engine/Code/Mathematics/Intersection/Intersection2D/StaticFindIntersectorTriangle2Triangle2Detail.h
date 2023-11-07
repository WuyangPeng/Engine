///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H

#include "StaticFindIntersectorTriangle2Triangle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::StaticFindIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, const Real epsilon)
    : ParentType{ epsilon }, triangle0{ triangle0 }, triangle1{ triangle1 }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle0;
}

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle1;
}

template <typename Real>
int Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(point.size());
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point.at(index);
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::Find()
{
    // 电位交点被初始化为triangle1。 顶点集基于对三角形0的每个边进行修剪而得到优化。
    auto vertex0 = triangle0.GetVertex();
    auto vertex1 = triangle1.GetVertex();
    auto intersection = vertex1;

    for (auto i1 = 2, i0 = 0; i0 < 3; i1 = i0++)
    {
        const auto& vector0 = vertex1.at(i0);
        const auto& vector1 = vertex1.at(i1);

        // 裁剪边沿 <V0[i1],V0[i0]>.
        const Vector2 axis{ vector1.GetY() - vector0.GetY(), vector0.GetX() - vector1.GetX() };
        auto dot = Vector2Tools::DotProduct(axis, vector1);
        intersection = ClipConvexPolygonAgainstLine(axis, dot, intersection);
        if (intersection.empty())
        {
            // 三角形完全被修剪，没有相交发生。
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    this->SetIntersectionType(IntersectionType::Point);
    point = intersection;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::Intersection Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::ClipConvexPolygonAgainstLine(const Vector2& axis, Real dot, const Intersection& intersection)
{
    using Container = std::vector<Real>;
    // 假定输入顶点为逆时针顺序。 顺序是此函数的不变式。

    // 测试顶点在线的哪一侧。
    auto positive = 0;
    auto negative = 0;
    auto firstIndex = -1;
    Container dotProduct{};

    auto index = 0;
    for (const auto& value : intersection)
    {
        auto diff = Vector2Tools::DotProduct(axis, value) - dot;
        dotProduct.emplace_back(diff);
        if (Math::GetValue(0) < diff)
        {
            ++positive;
            if (firstIndex < 0)
            {
                firstIndex = index;
            }
        }
        else if (diff < Math::GetValue(0))
        {
            ++negative;
        }

        ++index;
    }

    const auto quantity = boost::numeric_cast<int>(intersection.size());
    if (0 < positive)
    {
        if (0 < negative)
        {
            // 线与多边形横向相交。
            Intersection result{};

            if (0 < firstIndex)
            {
                // 在线上的第一个剪辑顶点。
                auto currentIndex = firstIndex;
                auto previousIndex = currentIndex - 1;
                auto t = dotProduct.at(currentIndex) / (dotProduct.at(currentIndex) - dotProduct.at(previousIndex));
                result.emplace_back(intersection.at(currentIndex) + t * (intersection.at(previousIndex) - intersection.at(currentIndex)));

                // 顶点在线的正侧。
                while (currentIndex < quantity && Math::GetValue(0) < dotProduct.at(currentIndex))
                {
                    result.emplace_back(intersection.at(currentIndex++));
                }

                // 在线上的最后一个剪辑顶点。
                if (currentIndex < quantity)
                {
                    previousIndex = currentIndex - 1;
                }
                else
                {
                    currentIndex = 0;
                    previousIndex = quantity - 1;
                }
                t = dotProduct.at(currentIndex) / (dotProduct.at(currentIndex) - dotProduct.at(previousIndex));
                result.emplace_back(intersection.at(currentIndex) + t * (intersection.at(previousIndex) - intersection.at(currentIndex)));
            }
            else  // firstIndex 为 0
            {
                // 顶点在行的正侧。
                auto currentIndex = 0;
                while (currentIndex < quantity && Math::GetValue(0) < dotProduct.at(currentIndex))
                {
                    result.emplace_back(intersection.at(currentIndex++));
                }

                // 在线上的最后一个剪辑顶点。
                auto previousIndex = currentIndex - 1;
                auto t = dotProduct.at(currentIndex) / (dotProduct.at(currentIndex) - dotProduct.at(previousIndex));
                result.emplace_back(intersection.at(currentIndex) + t * (intersection.at(previousIndex) - intersection.at(currentIndex)));

                // 跳过负侧的顶点。
                while (currentIndex < quantity && dotProduct.at(currentIndex) <= Math::GetValue(0))
                {
                    ++currentIndex;
                }

                // 在线上的第一个剪辑顶点。
                if (currentIndex < quantity)
                {
                    previousIndex = currentIndex - 1;
                    t = dotProduct.at(currentIndex) / (dotProduct.at(currentIndex) - dotProduct.at(previousIndex));
                    result.emplace_back(intersection.at(currentIndex) + t * (intersection.at(previousIndex) - intersection.at(currentIndex)));

                    // 顶点在线的正侧。
                    while (currentIndex < quantity && Math::GetValue(0) < dotProduct.at(currentIndex))
                    {
                        result.emplace_back(intersection.at(currentIndex++));
                    }
                }
                else
                {
                    // currentIndex = 0
                    previousIndex = quantity - 1;
                    t = dotProduct.at(0) / (dotProduct.at(0) - dotProduct.at(previousIndex));
                    result.emplace_back(intersection.at(0) + t * (intersection.at(previousIndex) - intersection.at(0)));
                }
            }

            return result;
        }
        else
        {
            // 否则，多边形完全位于线的正侧，无需执行任何操作。
            return intersection;
        }
    }
    else
    {
        // 多边形不与线的正侧相交，请全部剪切。
        return Intersection{};
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H