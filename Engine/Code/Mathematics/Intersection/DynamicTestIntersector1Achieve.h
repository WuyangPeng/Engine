///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:31)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_ACHIEVE_H

#include "DynamicTestIntersector1.h"
#include "Intersector1Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersector1<Real>::DynamicTestIntersector1(Real u0, Real u1, Real v0, Real v1, Real tMax, Real speedU, Real speedV, const Real epsilon)
    : ParentType{ u0, u1, v0, v1, epsilon }, firstTime{}, lastTime{}, intersection{ false }
{
    Test(tMax, speedU, speedV);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

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
        // [u0,u1]�����[v0,v1]����ߡ�
        auto differenceSpeed = speedU - speedV;
        if (MathType::GetValue(0) < differenceSpeed)
        {
            // ������볯��˴��ƶ���
            auto differencePosition = v0 - u1;
            if (differencePosition <= tMax * differenceSpeed)
            {
                // ������ָ��ʱ�����ཻ��
                firstTime = differencePosition / differenceSpeed;
                lastTime = (v1 - u0) / differenceSpeed;

                intersection = true;
            }
        }
    }
    else if (v1 + epsilon < u0)
    {
        // [u0,u1]�����[v0,v1]���ұߡ�
        auto differenceSpeed = speedV - speedU;
        if (MathType::GetValue(0) < differenceSpeed)
        {
            // ������볯��˴��ƶ���
            auto differencePosition = u0 - v1;
            if (differencePosition <= tMax * differenceSpeed)
            {
                // ������ָ��ʱ�����ཻ��
                firstTime = differencePosition / differenceSpeed;
                lastTime = (u1 - v0) / differenceSpeed;
                intersection = true;
            }
        }
    }
    else
    {
        // ���䱾�����ཻ��
        firstTime = MathType::GetValue(0);
        if (speedU + epsilon < speedV)
        {
            lastTime = (u1 - v0) / (speedV - speedU);
        }
        else if (speedV + epsilon < speedU)
        {
            lastTime = (v1 - u0) / (speedU - speedV);
        }
        else
        {
            lastTime = MathType::maxReal;
        }

        intersection = true;
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicTestIntersector1<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && MathType::GetValue(0) <= firstTime && firstTime <= lastTime)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicTestIntersector1<Real>::IsIntersection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intersection;
}

template <typename Real>
Real Mathematics::DynamicTestIntersector1<Real>::GetFirstTime() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (intersection)
    {
        return firstTime;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���䲻�ཻ\n"s));
    }
}

template <typename Real>
Real Mathematics::DynamicTestIntersector1<Real>::GetLastTime() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (intersection)
    {
        return lastTime;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���䲻�ཻ\n"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_ACHIEVE_H
