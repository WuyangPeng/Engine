///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 14:18)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DETAIL_H

#include "Minimize1Detail.h"
#include "MinimizeN.h"
#include "MinimizeNDataDetail.h"
#include "MinimizeNGetMinimumDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real, typename UserDataType>
Mathematics::MinimizeN<Real, UserDataType>::MinimizeN(int dimensions, Function function, int maxLevel, int maxBracket, int maxIterations, const UserDataType* userData) noexcept
    : m_Dimensions{ dimensions },
      m_Function{ function },
      m_MaxLevel{ maxLevel },
      m_MaxBracket{ maxBracket },
      m_MaxIterations{ maxIterations },
      m_UserData{ userData }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::MinimizeN<Real, UserDataType>::IsValid() const noexcept
{
    if (1 <= m_Dimensions && m_Function != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
typename const Mathematics::MinimizeN<Real, UserDataType>::MinimizeNData Mathematics::MinimizeN<Real, UserDataType>::GetMinimum(const Container& begin, const Container& end, const Container& initial) const
{
    MATHEMATICS_CLASS_IS_VALID_1;

    // 初始猜测。
    MinimizeNGetMinimum minimizeNGetMinimum{ m_Dimensions, initial, m_Function, m_UserData, begin, end };

    for (auto iter = 0; iter < m_MaxIterations; ++iter)
    {
        // 查找在每个方向最小值并更新当前位置。
        for (auto index = 0; index < m_Dimensions; ++index)
        {
            minimizeNGetMinimum.FindEachDirection(index, m_MaxLevel, m_MaxBracket);
        }

        // 估计一个单位长度的共轭方向。
        auto length = minimizeNGetMinimum.EstimateUnitLengthConjugateDirection();
        if (length < Math::sm_Epsilon)
        {
            // 新的位置并没有从旧的位置有显著改变。在这里是否有更好的收敛准则？
            break;
        }

        minimizeNGetMinimum.MinimizeConjugateDirection(length, m_MaxLevel, m_MaxBracket);
    }

    return minimizeNGetMinimum.GetMinimizeNData();
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DETAIL_H
