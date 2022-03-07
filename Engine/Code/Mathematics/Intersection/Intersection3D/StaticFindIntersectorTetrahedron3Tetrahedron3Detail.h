///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/03/02 23:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_DETAIL_H

#include "StaticFindIntersectorTetrahedron3Tetrahedron3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::StaticFindIntersectorTetrahedron3Tetrahedron3(const Tetrahedron3& tetrahedron0, const Tetrahedron3& tetrahedron1, const Real epsilon)
    : ParentType{ epsilon }, tetrahedron0{ tetrahedron0 }, tetrahedron1{ tetrahedron1 }, intersectionContainer{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Tetrahedron3<Real> Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::GetTetrahedron0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return tetrahedron0;
}

template <typename Real>
Mathematics::Tetrahedron3<Real> Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::GetTetrahedron1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return tetrahedron1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::Find()
{
    // �����������ƽ�档

    auto plane = tetrahedron0.GetPlanes();

    // Ҫ���еĳ�ʼ������tetrahedron1��
    IntersectionContainer intersection{};

    intersection.emplace_back(tetrahedron1);

    // ��������1������������0��ƽ���ϡ�
    for (auto i = 0; i < 4; ++i)
    {
        IntersectionContainer inside{};
        for (const auto& tetrahedron3 : intersection)
        {
            inside = SplitAndDecompose(tetrahedron3, plane.at(i), inside);
        }
        intersection = inside;
    }

    if (!intersection.empty())
    {
        intersectionContainer = intersection;

        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
typename Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::IntersectionContainer Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::GetIntersection() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intersectionContainer;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::IntersectionContainer Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::SplitAndDecompose(const Tetrahedron3& tetra, const Plane3& plane, const IntersectionContainer& inside)
{
    auto result = inside;
    auto tetraCopy = tetra;

    // ȷ��������ĵ�λ��ƽ�����һ�ࡣ
    std::array<Real, 4> distance{};
    std::array<int, 4> positiveIndex{};
    std::array<int, 4> negativeIndex{};
    std::array<int, 4> zeroIndex{};

    auto positive = 0;
    auto negative = 0;
    auto zero = 0;

    for (auto i = 0; i < 4; ++i)
    {
        distance.at(i) = plane.DistanceTo(tetraCopy.GetVertex(i));
        if (Math::GetValue(0) < distance.at(i))
        {
            positiveIndex.at(positive++) = i;
        }
        else if (distance.at(i) < Math::GetValue(0))
        {
            negativeIndex.at(negative++) = i;
        }
        else
        {
            zeroIndex.at(zero++) = i;
        }
    }

    // Ϊ��ʹ���ѷ�����c_i֮һ����Ϊ����һ��c_i����Ϊ����

    if (negative == 0)
    {
        // ��������ȫλ��ƽ������࣬��ȫ�ü���
        return result;
    }

    if (positive == 0)
    {
        // ��������ȫ��ƽ��ĸ��ࡣ
        result.emplace_back(tetraCopy);
        return result;
    }

    // �����屻ƽ��ֿ��� ȷ����β���Լ���ν��������ַֽ�Ϊ�����壨6������
    std::array<Vector3, 4> intp{};

    if (positive == 3)
    {
        // +++-
        for (auto i = 0; i < positive; ++i)
        {
            auto w0 = -distance.at(negativeIndex.at(0)) / (distance.at(positiveIndex.at(i)) - distance.at(negativeIndex.at(0)));
            auto w1 = +distance.at(positiveIndex.at(i)) / (distance.at(positiveIndex.at(i)) - distance.at(negativeIndex.at(0)));
            tetraCopy.SetVertex(positiveIndex.at(i), w0 * tetraCopy.GetVertex(positiveIndex.at(i)) + w1 * tetraCopy.GetVertex(negativeIndex.at(0)));
        }
        result.emplace_back(tetraCopy);
    }
    else if (positive == 2)
    {
        if (negative == 2)
        {
            // ++--
            for (auto i = 0; i < positive; ++i)
            {
                auto w0 = -distance.at(negativeIndex.at(0)) / (distance.at(positiveIndex.at(i)) - distance.at(negativeIndex.at(0)));
                auto w1 = +distance.at(positiveIndex.at(i)) / (distance.at(positiveIndex.at(i)) - distance.at(negativeIndex.at(0)));
                intp.at(i) = w0 * tetraCopy.GetVertex(positiveIndex.at(i)) + w1 * tetraCopy.GetVertex(negativeIndex.at(0));
            }
            for (auto i = 0; i < negative; ++i)
            {
                auto w0 = -distance.at(negativeIndex.at(1)) / (distance.at(positiveIndex.at(i)) - distance.at(negativeIndex.at(1)));
                auto w1 = +distance.at(positiveIndex.at(i)) / (distance.at(positiveIndex.at(i)) - distance.at(negativeIndex.at(1)));
                const auto nextIndex = i + 2;
                intp.at(nextIndex) = w0 * tetraCopy.GetVertex(positiveIndex.at(i)) + w1 * tetraCopy.GetVertex(negativeIndex.at(1));
            }

            tetraCopy.SetVertex(positiveIndex.at(0), intp.at(2));
            tetraCopy.SetVertex(positiveIndex.at(1), intp.at(1));

            result.emplace_back(tetraCopy);
            result.emplace_back(Tetrahedron3{ tetraCopy.GetVertex(negativeIndex.at(1)), intp.at(3), intp.at(2), intp.at(1) });
            result.emplace_back(Tetrahedron3{ tetraCopy.GetVertex(negativeIndex.at(0)), intp.at(0), intp.at(1), intp.at(2) });
        }
        else
        {
            // ++-0
            for (auto i = 0; i < positive; ++i)
            {
                auto w0 = -distance.at(negativeIndex.at(0)) / (distance.at(positiveIndex.at(i)) - distance.at(negativeIndex.at(0)));
                auto w1 = +distance.at(positiveIndex.at(i)) / (distance.at(positiveIndex.at(i)) - distance.at(negativeIndex.at(0)));
                tetraCopy.SetVertex(positiveIndex.at(i), w0 * tetraCopy.GetVertex(positiveIndex.at(i)) + w1 * tetraCopy.GetVertex(negativeIndex.at(0)));
            }
            result.emplace_back(tetraCopy);
        }
    }
    else if (positive == 1)
    {
        if (negative == 3)
        {
            // +---
            for (auto i = 0; i < negative; ++i)
            {
                auto w0 = -distance.at(negativeIndex.at(i)) / (distance.at(positiveIndex.at(0)) - distance.at(negativeIndex.at(i)));
                auto w1 = +distance.at(positiveIndex.at(0)) / (distance.at(positiveIndex.at(0)) - distance.at(negativeIndex.at(i)));
                intp.at(i) = w0 * tetraCopy.GetVertex(positiveIndex.at(0)) + w1 * tetraCopy.GetVertex(negativeIndex.at(i));
            }

            tetraCopy.SetVertex(positiveIndex.at(0), intp.at(0));

            result.emplace_back(tetraCopy);
            result.emplace_back(Tetrahedron3{ intp.at(0), tetraCopy.GetVertex(negativeIndex.at(1)), tetraCopy.GetVertex(negativeIndex.at(2)), intp.at(1) });
            result.emplace_back(Tetrahedron3{ tetraCopy.GetVertex(negativeIndex.at(2)), intp.at(1), intp.at(2), intp.at(0) });
        }
        else if (negative == 2)
        {
            // +--0
            for (auto i = 0; i < negative; ++i)
            {
                auto w0 = -distance.at(negativeIndex.at(i)) / (distance.at(positiveIndex.at(0)) - distance.at(negativeIndex.at(i)));
                auto w1 = +distance.at(positiveIndex.at(0)) / (distance.at(positiveIndex.at(0)) - distance.at(negativeIndex.at(i)));
                intp.at(i) = w0 * tetraCopy.GetVertex(positiveIndex.at(0)) + w1 * tetraCopy.GetVertex(negativeIndex.at(i));
            }

            tetraCopy.SetVertex(positiveIndex.at(0), intp.at(0));

            result.emplace_back(tetraCopy);
            result.emplace_back(Tetrahedron3{ intp.at(1), tetraCopy.GetVertex(zeroIndex.at(0)), tetraCopy.GetVertex(negativeIndex.at(1)), intp.at(0) });
        }
        else
        {
            // +-00

            auto w0 = -distance.at(negativeIndex.at(0)) / (distance.at(positiveIndex.at(0)) - distance.at(negativeIndex.at(0)));
            auto w1 = +distance.at(positiveIndex.at(0)) / (distance.at(positiveIndex.at(0)) - distance.at(negativeIndex.at(0)));
            tetraCopy.SetVertex(positiveIndex.at(0), w0 * tetraCopy.GetVertex(positiveIndex.at(0)) + w1 * tetraCopy.GetVertex(negativeIndex.at(0)));
            result.emplace_back(tetraCopy);
        }
    }

    return result;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_DETAIL_H