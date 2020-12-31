///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/19 14:34)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ACHIEVE_H

#include "Bisect1.h"
#include "Math.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect1<Real>::Bisect1(Function function, int maxLevel, Real tolerance) noexcept
    : m_Function{ function }, m_MaxLevel{ maxLevel }, m_Tolerance{ tolerance }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect1<Real>::IsValid() const noexcept
{
    if (m_Function != nullptr && 0 < m_MaxLevel && Math::GetValue(0) <= m_Tolerance)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Bisect1<Real>::Bisect1Root Mathematics::Bisect1<Real>::Bisect(Real beginPoint, Real endPoint)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    // m_Function���ÿ����׳��쳣��
    CoreTools::DisableNoexcept();

    // ���������˵㡣
    auto beginPointFunctionValue = m_Function(beginPoint);
    if (Math::FAbs(beginPointFunctionValue) <= m_Tolerance)
    {
        return Bisect1Root{ beginPoint, BisectRootType::HaveSolution };
    }

    auto endPointFunctionValue = m_Function(endPoint);
    if (Math::FAbs(endPointFunctionValue) <= m_Tolerance)
    {
        return Bisect1Root{ endPoint, BisectRootType::HaveSolution };
    }

    // �����޽�
    if (Math::GetValue(0) < beginPointFunctionValue * endPointFunctionValue)
    {
        return Bisect1Root{};
    }

    auto middlePoints = Math::GetRational(1, 2) * (beginPoint + endPoint);

    for (auto level = 0; level < m_MaxLevel; ++level)
    {
        auto middlePointFunctionValue = m_Function(middlePoints);
        if (Math::FAbs(middlePointFunctionValue) <= m_Tolerance)
        {
            return Bisect1Root{ middlePoints, BisectRootType::HaveSolution };
        }

        if (beginPointFunctionValue * middlePointFunctionValue < Math::GetValue(0))
        {
            endPoint = middlePoints;
            endPointFunctionValue = middlePointFunctionValue;
        }
        else if (endPointFunctionValue * middlePointFunctionValue < Math::GetValue(0))
        {
            beginPoint = middlePoints;
            beginPointFunctionValue = middlePointFunctionValue;
        }

        middlePoints = Math::GetRational(1, 2) * (beginPoint + endPoint);
    }

    // ѭ�������˴���������һ���м�ֵ��
    return Bisect1Root{ middlePoints, BisectRootType::Unknown };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ACHIEVE_H
