///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/18 10:56)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_ACHIEVE_H

#include "StaticFindIntersectorTriangle2Triangle2.h"
#include "Detail/FindIntersectorTriangle2Triangle2ImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::StaticFindIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, const Real epsilon)
    : ParentType{ epsilon }, m_Impl{ std::make_shared<ImplType>(triangle0, triangle1) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTriangle0();
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTriangle1();
}

template <typename Real>
int Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPoint(index);
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::Find()
{
    auto triangle0 = m_Impl->GetTriangle0();
    auto triangle1 = m_Impl->GetTriangle1();

    // ��λ���㱻��ʼ��Ϊtriangle1�� ���㼯���ڶ�������0��ÿ���߽����޼����õ��Ż���
    auto vertex0 = triangle0.GetVertex();
    auto vertex1 = triangle1.GetVertex();
    auto intersection = vertex1;

    for (auto i1 = 2, i0 = 0; i0 < 3; i1 = i0++)
    {
        const auto& vertor0 = vertex1.at(i0);
        const auto& vertor1 = vertex1.at(i1);

        // �ü����� <V0[i1],V0[i0]>.
        const Vector2D axis{ vertor1.GetY() - vertor0.GetY(), vertor0.GetX() - vertor1.GetX() };
        auto dot = Vector2DTools::DotProduct(axis, vertor1);
        intersection = ClipConvexPolygonAgainstLine(axis, dot, intersection);
        if (intersection.empty())
        {
            // ��������ȫ���޼���û���ཻ������
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    this->SetIntersectionType(IntersectionType::Point);
    m_Impl->SetPoint(intersection);
}

template <typename Real>
typename Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::Intersection Mathematics::StaticFindIntersectorTriangle2Triangle2<Real>::ClipConvexPolygonAgainstLine(const Vector2D& axis, Real dot, const Intersection& intersection)
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
        auto diff = Vector2DTools::DotProduct(axis, value) - dot;
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            // �������κ����ཻ��
            Intersection result{};

            if (0 < firstIndex)
            {
                // �����ϵĵ�һ���������㡣
                auto currentIndex = firstIndex;
                auto previousIndex = currentIndex - 1;
                auto t = dotProduct[currentIndex] / (dotProduct[currentIndex] - dotProduct[previousIndex]);
                result.emplace_back(intersection[currentIndex] + t * (intersection[previousIndex] - intersection[currentIndex]));

                // �������ߵ����ࡣ
                while (currentIndex < quantity && Math::GetValue(0) < dotProduct[currentIndex])
                {
                    result.emplace_back(intersection[currentIndex++]);
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
                t = dotProduct[currentIndex] / (dotProduct[currentIndex] - dotProduct[previousIndex]);
                result.emplace_back(intersection[currentIndex] + t * (intersection[previousIndex] - intersection[currentIndex]));
            }
            else  // firstIndex Ϊ 0
            {
                // �������е����ࡣ
                auto currentIndex = 0;
                while (currentIndex < quantity && Math::GetValue(0) < dotProduct[currentIndex])
                {
                    result.emplace_back(intersection[currentIndex++]);
                }

                // �����ϵ����һ���������㡣
                auto previousIndex = currentIndex - 1;
                auto t = dotProduct[currentIndex] / (dotProduct[currentIndex] - dotProduct[previousIndex]);
                result.emplace_back(intersection[currentIndex] + t * (intersection[previousIndex] - intersection[currentIndex]));

                // ��������Ķ��㡣
                while (currentIndex < quantity && dotProduct[currentIndex] <= Math::GetValue(0))
                {
                    ++currentIndex;
                }

                // �����ϵĵ�һ���������㡣
                if (currentIndex < quantity)
                {
                    previousIndex = currentIndex - 1;
                    t = dotProduct[currentIndex] / (dotProduct[currentIndex] - dotProduct[previousIndex]);
                    result.emplace_back(intersection[currentIndex] + t * (intersection[previousIndex] - intersection[currentIndex]));

                    // �������ߵ����ࡣ
                    while (currentIndex < quantity && Math::GetValue(0) < dotProduct[currentIndex])
                    {
                        result.emplace_back(intersection[currentIndex++]);
                    }
                }
                else
                {
                    // currentIndex = 0
                    previousIndex = quantity - 1;
                    t = dotProduct[0] / (dotProduct[0] - dotProduct[previousIndex]);
                    result.emplace_back(intersection[0] + t * (intersection[previousIndex] - intersection[0]));
                }
            }

#include STSTEM_WARNING_POP

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

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_ACHIEVE_H