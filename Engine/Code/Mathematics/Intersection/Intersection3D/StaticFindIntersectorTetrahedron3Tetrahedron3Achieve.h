///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/21 13:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_ACHIEVE_H

#include "StaticFindIntersectorTetrahedron3Tetrahedron3.h"
#include "Detail/StaticFindIntersectorTetrahedron3Tetrahedron3ImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::StaticFindIntersectorTetrahedron3Tetrahedron3(const Tetrahedron3& tetrahedron0, const Tetrahedron3& tetrahedron1, const Real epsilon)
    : ParentType{ epsilon }, impl{  tetrahedron0, tetrahedron1  }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid()  )
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Tetrahedron3<Real> Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::GetTetrahedron0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetTetrahedron0();
}

template <typename Real>
const Mathematics::Tetrahedron3<Real> Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::GetTetrahedron1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetTetrahedron1();
}

template <typename Real>
void Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::Find()
{
    // �����������ƽ�档
    auto tetrahedron0 = GetTetrahedron1();
    auto plane = tetrahedron0.GetPlanes();

    // Ҫ���еĳ�ʼ������tetrahedron1��
    IntersectionContainer intersection{};

    intersection.emplace_back(tetrahedron0);

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
        impl->SetIntersectionContainer(intersection);
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
typename const Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::IntersectionContainer Mathematics::StaticFindIntersectorTetrahedron3Tetrahedron3<Real>::GetIntersection() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetIntersection();
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    for (auto i = 0; i < 4; ++i)
    {
        distance[i] = plane.DistanceTo(tetraCopy.GetVertex(i));
        if (Math::GetValue(0) < distance[i])
        {
            positiveIndex[positive++] = i;
        }
        else if (distance[i] < Math::GetValue(0))
        {
            negativeIndex[negative++] = i;
        }
        else
        {
            zeroIndex[zero++] = i;
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
    std::array<Vector3D, 4> intp{};

    if (positive == 3)
    {
        // +++-
        for (auto i = 0; i < positive; ++i)
        {
            auto w0 = -distance[negativeIndex[0]] / (distance[positiveIndex[i]] - distance[negativeIndex[0]]);
            auto w1 = +distance[positiveIndex[i]] / (distance[positiveIndex[i]] - distance[negativeIndex[0]]);
            tetraCopy.SetVertex(positiveIndex[i], w0 * tetraCopy.GetVertex(positiveIndex[i]) + w1 * tetraCopy.GetVertex(negativeIndex[0]));
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
                auto w0 = -distance[negativeIndex[0]] / (distance[positiveIndex[i]] - distance[negativeIndex[0]]);
                auto w1 = +distance[positiveIndex[i]] / (distance[positiveIndex[i]] - distance[negativeIndex[0]]);
                intp[i] = w0 * tetraCopy.GetVertex(positiveIndex[i]) + w1 * tetraCopy.GetVertex(negativeIndex[0]);
            }
            for (auto i = 0; i < negative; ++i)
            {
                auto w0 = -distance[negativeIndex[1]] / (distance[positiveIndex[i]] - distance[negativeIndex[1]]);
                auto w1 = +distance[positiveIndex[i]] / (distance[positiveIndex[i]] - distance[negativeIndex[1]]);
                const auto nextIndex = i + 2;
                intp[nextIndex] = w0 * tetraCopy.GetVertex(positiveIndex[i]) + w1 * tetraCopy.GetVertex(negativeIndex[1]);
            }

            tetraCopy.SetVertex(positiveIndex[0], intp[2]);
            tetraCopy.SetVertex(positiveIndex[1], intp[1]);

            result.emplace_back(tetraCopy);
            result.emplace_back(Tetrahedron3{ tetraCopy.GetVertex(negativeIndex[1]), intp[3], intp[2], intp[1] });
            result.emplace_back(Tetrahedron3{ tetraCopy.GetVertex(negativeIndex[0]), intp[0], intp[1], intp[2] });
        }
        else
        {
            // ++-0
            for (auto i = 0; i < positive; ++i)
            {
                auto w0 = -distance[negativeIndex[0]] / (distance[positiveIndex[i]] - distance[negativeIndex[0]]);
                auto w1 = +distance[positiveIndex[i]] / (distance[positiveIndex[i]] - distance[negativeIndex[0]]);
                tetraCopy.SetVertex(positiveIndex[i], w0 * tetraCopy.GetVertex(positiveIndex[i]) + w1 * tetraCopy.GetVertex(negativeIndex[0]));
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
                auto w0 = -distance[negativeIndex[i]] / (distance[positiveIndex[0]] - distance[negativeIndex[i]]);
                auto w1 = +distance[positiveIndex[0]] / (distance[positiveIndex[0]] - distance[negativeIndex[i]]);
                intp[i] = w0 * tetraCopy.GetVertex(positiveIndex[0]) + w1 * tetraCopy.GetVertex(negativeIndex[i]);
            }

            tetraCopy.SetVertex(positiveIndex[0], intp[0]);

            result.emplace_back(tetraCopy);
            result.emplace_back(Tetrahedron3{ intp[0], tetraCopy.GetVertex(negativeIndex[1]), tetraCopy.GetVertex(negativeIndex[2]), intp[1] });
            result.emplace_back(Tetrahedron3{ tetraCopy.GetVertex(negativeIndex[2]), intp[1], intp[2], intp[0] });
        }
        else if (negative == 2)
        {
            // +--0
            for (auto i = 0; i < negative; ++i)
            {
                auto w0 = -distance[negativeIndex[i]] / (distance[positiveIndex[0]] - distance[negativeIndex[i]]);
                auto w1 = +distance[positiveIndex[0]] / (distance[positiveIndex[0]] - distance[negativeIndex[i]]);
                intp[i] = w0 * tetraCopy.GetVertex(positiveIndex[0]) + w1 * tetraCopy.GetVertex(negativeIndex[i]);
            }

            tetraCopy.SetVertex(positiveIndex[0], intp[0]);

            result.emplace_back(tetraCopy);
            result.emplace_back(Tetrahedron3{ intp[1], tetraCopy.GetVertex(zeroIndex[0]), tetraCopy.GetVertex(negativeIndex[1]), intp[0] });
        }
        else
        {
            // +-00

            auto w0 = -distance[negativeIndex[0]] / (distance[positiveIndex[0]] - distance[negativeIndex[0]]);
            auto w1 = +distance[positiveIndex[0]] / (distance[positiveIndex[0]] - distance[negativeIndex[0]]);
            tetraCopy.SetVertex(positiveIndex[0], w0 * tetraCopy.GetVertex(positiveIndex[0]) + w1 * tetraCopy.GetVertex(negativeIndex[0]));
            result.emplace_back(tetraCopy);
        }
    }

    return result;

#include STSTEM_WARNING_POP
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_ACHIEVE_H