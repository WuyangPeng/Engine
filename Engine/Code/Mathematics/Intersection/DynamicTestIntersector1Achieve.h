///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 17:08)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_ACHIEVE_H

#include "DynamicTestIntersector1.h"
#include "Intersector1Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersector1<Real>::DynamicTestIntersector1(Real u0, Real u1, Real v0, Real v1, Real tMax, Real speedU, Real speedV, const Real epsilon)
    : ParentType{ u0, u1, v0, v1, epsilon }, m_FirstTime{}, m_LastTime{}, m_Intersection{ false }
{
    Test(tMax, speedU, speedV);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::DynamicTestIntersector1<Real>::Test(Real tMax, Real speedU, Real speedV)
{
    auto u0 = this->GetU(0);
    auto u1 = this->GetU(1);
    auto v0 = this->GetV(0);
    auto v1 = this->GetV(1);
    auto epsilon = this->GetEpsilon();

    if (u1 + epsilon < v0)
    {
        // [u0,u1]最初在[v0,v1]的左边。
        auto differenceSpeed = speedU - speedV;
        if (Math::GetValue(0) < differenceSpeed)
        {
            // 区间必须朝向彼此移动。
            auto differencePosition = v0 - u1;
            if (differencePosition <= tMax * differenceSpeed)
            {
                // 区间在指定时间内相交。
                m_FirstTime = differencePosition / differenceSpeed;
                m_LastTime = (v1 - u0) / differenceSpeed;

                m_Intersection = true;
            }
        }
    }
    else if (v1 + epsilon < u0)
    {
        // [u0,u1]最初在[v0,v1]的右边。
        auto differenceSpeed = speedV - speedU;
        if (Math::GetValue(0) < differenceSpeed)
        {
            // 区间必须朝向彼此移动。
            auto differencePosition = u0 - v1;
            if (differencePosition <= tMax * differenceSpeed)
            {
                // 区间在指定时间内相交。
                m_FirstTime = differencePosition / differenceSpeed;
                m_LastTime = (u1 - v0) / differenceSpeed;
                m_Intersection = true;
            }
        }
    }
    else
    {
        // 区间本来就相交。
        m_FirstTime = Math::GetValue(0);
        if (speedU + epsilon < speedV)
        {
            m_LastTime = (u1 - v0) / (speedV - speedU);
        }
        else if (speedV + epsilon < speedU)
        {
            m_LastTime = (v1 - u0) / (speedU - speedV);
        }
        else
        {
            m_LastTime = Math::sm_MaxReal;
        }

        m_Intersection = true;
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicTestIntersector1<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && Math::GetValue(0) <= m_FirstTime && m_FirstTime <= m_LastTime)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicTestIntersector1<Real>::IsIntersection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Intersection;
}

template <typename Real>
Real Mathematics::DynamicTestIntersector1<Real>::GetFirstTime() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (m_Intersection)
    {
        return m_FirstTime;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("区间不相交\n"s));
    }
}

template <typename Real>
Real Mathematics::DynamicTestIntersector1<Real>::GetLastTime() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (m_Intersection)
    {
        return m_LastTime;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("区间不相交\n"s));
    }
}
#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_ACHIEVE_H
