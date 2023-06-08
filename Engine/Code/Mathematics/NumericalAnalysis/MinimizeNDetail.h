///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:49)

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
    : dimensions{ dimensions },
      function{ function },
      maxLevel{ maxLevel },
      maxBracket{ maxBracket },
      maxIterations{ maxIterations },
      userData{ userData }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
bool Mathematics::MinimizeN<Real, UserDataType>::IsValid() const noexcept
{
    if (1 <= dimensions && function != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
typename Mathematics::MinimizeN<Real, UserDataType>::MinimizeNData Mathematics::MinimizeN<Real, UserDataType>::GetMinimum(const Container& begin, const Container& end, const Container& initial) const
{
    MATHEMATICS_CLASS_IS_VALID_1;

    // ��ʼ�²⡣
    MinimizeNGetMinimum minimizeNGetMinimum{ dimensions, initial, function, userData, begin, end };

    for (auto iter = 0; iter < maxIterations; ++iter)
    {
        // ������ÿ��������Сֵ�����µ�ǰλ�á�
        for (auto index = 0; index < dimensions; ++index)
        {
            minimizeNGetMinimum.FindEachDirection(index, maxLevel, maxBracket);
        }

        // ����һ����λ���ȵĹ����
        const auto length = minimizeNGetMinimum.EstimateUnitLengthConjugateDirection();
        if (length < Math::epsilon)
        {
            // �µ�λ�ò�û�дӾɵ�λ���������ı䡣�������Ƿ��и��õ�����׼��
            break;
        }

        minimizeNGetMinimum.MinimizeConjugateDirection(length, maxLevel, maxBracket);
    }

    return minimizeNGetMinimum.GetMinimizeNData();
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_DETAIL_H
