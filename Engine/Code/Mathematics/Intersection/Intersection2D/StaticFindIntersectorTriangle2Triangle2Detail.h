///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 17:52)

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
    // ��λ���㱻��ʼ��Ϊtriangle1�� ���㼯���ڶ�������0��ÿ���߽����޼����õ��Ż���
    auto vertex0 = triangle0.GetVertex();
    auto vertex1 = triangle1.GetVertex();
    auto intersection = vertex1;

    for (auto i1 = 2, i0 = 0; i0 < 3; i1 = i0++)
    {
        const auto& vector0 = vertex1.at(i0);
        const auto& vector1 = vertex1.at(i1);

        // �ü����� <V0[i1],V0[i0]>.
        const Vector2 axis{ vector1.GetY() - vector0.GetY(), vector0.GetX() - vector1.GetX() };
        auto dot = Vector2Tools::DotProduct(axis, vector1);
        intersection = ClipConvexPolygonAgainstLine(axis, dot, intersection);
        if (intersection.empty())
        {
            // ��������ȫ���޼���û���ཻ������
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
    // �ٶ����붥��Ϊ��ʱ��˳�� ˳���Ǵ˺����Ĳ���ʽ��

    // ���Զ������ߵ���һ�ࡣ
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
            // �������κ����ཻ��
            Intersection result{};

            if (0 < firstIndex)
            {
                // �����ϵĵ�һ���������㡣
                auto currentIndex = firstIndex;
                auto previousIndex = currentIndex - 1;
                auto t = dotProduct.at(currentIndex) / (dotProduct.at(currentIndex) - dotProduct.at(previousIndex));
                result.emplace_back(intersection.at(currentIndex) + t * (intersection.at(previousIndex) - intersection.at(currentIndex)));

                // �������ߵ����ࡣ
                while (currentIndex < quantity && Math::GetValue(0) < dotProduct.at(currentIndex))
                {
                    result.emplace_back(intersection.at(currentIndex++));
                }

                // �����ϵ����һ���������㡣
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
            else  // firstIndex Ϊ 0
            {
                // �������е����ࡣ
                auto currentIndex = 0;
                while (currentIndex < quantity && Math::GetValue(0) < dotProduct.at(currentIndex))
                {
                    result.emplace_back(intersection.at(currentIndex++));
                }

                // �����ϵ����һ���������㡣
                auto previousIndex = currentIndex - 1;
                auto t = dotProduct.at(currentIndex) / (dotProduct.at(currentIndex) - dotProduct.at(previousIndex));
                result.emplace_back(intersection.at(currentIndex) + t * (intersection.at(previousIndex) - intersection.at(currentIndex)));

                // ��������Ķ��㡣
                while (currentIndex < quantity && dotProduct.at(currentIndex) <= Math::GetValue(0))
                {
                    ++currentIndex;
                }

                // �����ϵĵ�һ���������㡣
                if (currentIndex < quantity)
                {
                    previousIndex = currentIndex - 1;
                    t = dotProduct.at(currentIndex) / (dotProduct.at(currentIndex) - dotProduct.at(previousIndex));
                    result.emplace_back(intersection.at(currentIndex) + t * (intersection.at(previousIndex) - intersection.at(currentIndex)));

                    // �������ߵ����ࡣ
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
            // ���򣬶������ȫλ���ߵ����࣬����ִ���κβ�����
            return intersection;
        }
    }
    else
    {
        // ����β����ߵ������ཻ����ȫ�����С�
        return Intersection{};
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H