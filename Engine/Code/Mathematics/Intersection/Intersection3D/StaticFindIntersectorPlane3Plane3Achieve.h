///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 13:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H

#include "StaticFindIntersectorPlane3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Plane3<Real>::StaticFindIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, const Real epsilon)
    : ParentType{ epsilon }, plane0{ plane0 }, plane1{ plane1 }, intrLine{ Vector3::GetZero(), Vector3::GetZero() }, intrPlane{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetPlane0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane0;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetPlane1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Plane3<Real>::Find()
{
    /// ���N0��N1ƽ�У�������ƽ��ƽ���ҷֿ�����ͬһƽ���ϡ�
    /// ������������£������ء� false���� ���򣬽���Ϊ L(t) = t * Cross(N0,N1) / |Cross(N0,N1)| + c0 * N0 + c1 * N1
    /// ����ĳЩϵ��c0��c1������t����ʵ�����в�������
    /// �뷨��һ��ȡ�����
    ///   d0 = Dot(N0,L) = c0 * Dot(N0,N0) + c1 * Dot(N0,N1) = c0 + c1 * d
    ///   d1 = Dot(N1,L) = c0 * Dot(N0,N1) + c1 * Dot(N1,N1) = c0 * d + c1
    /// ����d = Dot(N0,N1)�� ��������δ֪���е��������̡� ���������
    ///   c0 = (d0 - d * d1) / det
    ///   c1 = (d1 - d * d0) / det
    /// ����det = 1 - d^2��

    auto dot = Vector3ToolsType::DotProduct(plane0.GetNormal(), plane1.GetNormal());
    if (MathType::GetValue(1) - MathType::GetZeroTolerance() <= MathType::FAbs(dot))
    {
        // ��Щƽ����ƽ�еġ� ��������Ƿ��档
        auto diff = MathType::GetValue(0);
        if (MathType::GetValue(0) <= dot)
        {
            // ���߷�����ͬ����Ҫ�鿴c0 - c1��
            diff = plane0.GetConstant() - plane1.GetConstant();
        }
        else
        {
            // ���߷����෴����Ҫ�鿴c0 + c1��
            diff = plane0.GetConstant() + plane1.GetConstant();
        }

        if (MathType::FAbs(diff) < MathType::GetZeroTolerance())
        {
            // ƽ�湲�档
            this->SetIntersectionType(IntersectionType::Plane);
            intrPlane = plane0;
            return;
        }

        // ƽ����ƽ�еģ�����Ȼ��ͬ��
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto invDet = (MathType::GetValue(1)) / (MathType::GetValue(1) - dot * dot);
    auto c0 = (plane0.GetConstant() - dot * plane1.GetConstant()) * invDet;
    auto c1 = (plane1.GetConstant() - dot * plane0.GetConstant()) * invDet;
    this->SetIntersectionType(IntersectionType::Line);
    intrLine = Line3{ c0 * plane0.GetNormal() + c1 * plane1.GetNormal(), Vector3ToolsType::UnitCrossProduct(plane0.GetNormal(), plane1.GetNormal()) };
}

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetIntersectionLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intrLine;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetIntersectionPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intrPlane;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H