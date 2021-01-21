///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 17:00)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H

#include "StaticFindIntersectorPlane3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Plane3<Real>::StaticFindIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, const Real epsilon)
    : ParentType{ epsilon }, m_Plane0{ plane0 }, m_Plane1{ plane1 }, m_IntrLine{ Vector3D::GetZero(), Vector3D::GetZero() }, m_IntrPlane{}
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
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetPlane0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane0;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetPlane1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Plane3<Real>::Find()
{
    /// 如果N0和N1平行，则两个平面平行且分开或在同一平面上。
    /// 在这两种情况下，均返回“ false”。 否则，交线为 L(t) = t * Cross(N0,N1) / |Cross(N0,N1)| + c0 * N0 + c1 * N1
    /// 对于某些系数c0和c1，对于t任意实数（行参数）。
    /// 与法线一起取点积，
    ///   d0 = Dot(N0,L) = c0 * Dot(N0,N0) + c1 * Dot(N0,N1) = c0 + c1 * d
    ///   d1 = Dot(N1,L) = c0 * Dot(N0,N1) + c1 * Dot(N1,N1) = c0 * d + c1
    /// 其中d = Dot(N0,N1)。 这是两个未知数中的两个方程。 解决方法是
    ///   c0 = (d0 - d * d1) / det
    ///   c1 = (d1 - d * d0) / det
    /// 其中det = 1 - d^2。

    auto dot = Vector3DTools::DotProduct(m_Plane0.GetNormal(), m_Plane1.GetNormal());
    if (Math::GetValue(1) - Math::GetZeroTolerance() <= Math::FAbs(dot))
    {
        // 这些平面是平行的。 检查它们是否共面。
        auto diff = Math::GetValue(0);
        if (Math::GetValue(0) <= dot)
        {
            // 法线方向相同，需要查看c0 - c1。
            diff = m_Plane0.GetConstant() - m_Plane1.GetConstant();
        }
        else
        {
            // 法线方向相反，需要查看c0 + c1。
            diff = m_Plane0.GetConstant() + m_Plane1.GetConstant();
        }

        if (Math::FAbs(diff) < Math::GetZeroTolerance())
        {
            // 平面共面。
            this->SetIntersectionType(IntersectionType::Plane);
            m_IntrPlane = m_Plane0;
            return;
        }

        // 平面是平行的，但截然不同。
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto invDet = (Math::GetValue(1)) / (Math::GetValue(1) - dot * dot);
    auto c0 = (m_Plane0.GetConstant() - dot * m_Plane1.GetConstant()) * invDet;
    auto c1 = (m_Plane1.GetConstant() - dot * m_Plane0.GetConstant()) * invDet;
    this->SetIntersectionType(IntersectionType::Line);
    m_IntrLine = Line3{ c0 * m_Plane0.GetNormal() + c1 * m_Plane1.GetNormal(), Vector3DTools::UnitCrossProduct(m_Plane0.GetNormal(), m_Plane1.GetNormal()) };
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetIntersectionLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntrLine;
}

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Plane3<Real>::GetIntersectionPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_IntrPlane;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_ACHIEVE_H