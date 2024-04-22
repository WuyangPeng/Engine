/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 14:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SORT_EIGENSTUFF_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SORT_EIGENSTUFF_DETAIL_H

#include "SortEigenstuff.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::SortEigenstuff<Real>::SortEigenstuff() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::SortEigenstuff<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::SortEigenstuff<Real>::operator()(int sortType, bool isRotation, std::array<Real, 3>& eval, std::array<std::array<Real, 3>, 3>& evec)
{
    if (sortType != 0)
    {
        /// 将特征值排序为 eval.at(0) <= eval.at(1) <= eval.at(2)。
        std::array<int, 3> index{};
        if (eval.at(0) < eval.at(1))
        {
            if (eval.at(2) < eval.at(0))
            {
                /// 偶排列
                index.at(0) = 2;
                index.at(1) = 0;
                index.at(2) = 1;
            }
            else if (eval.at(2) < eval.at(1))
            {
                /// 奇数排列
                index.at(0) = 0;
                index.at(1) = 2;
                index.at(2) = 1;
                isRotation = !isRotation;
            }
            else
            {
                /// 偶排列
                index.at(0) = 0;
                index.at(1) = 1;
                index.at(2) = 2;
            }
        }
        else
        {
            if (eval.at(2) < eval.at(1))
            {
                /// 奇数排列
                index.at(0) = 2;
                index.at(1) = 1;
                index.at(2) = 0;
                isRotation = !isRotation;
            }
            else if (eval.at(2) < eval.at(0))
            {
                /// 偶排列
                index.at(0) = 1;
                index.at(1) = 2;
                index.at(2) = 0;
            }
            else
            {
                /// 奇数排列
                index.at(0) = 1;
                index.at(1) = 0;
                index.at(2) = 2;
                isRotation = !isRotation;
            }
        }

        if (sortType == -1)
        {
            /// 请求是eval.at(0) >= eval.at(1) >= eval.at(2)。
            /// 这需要一个奇数置换，(i0,i1,i2) -> (i2,i1,i0)。
            std::swap(index.at(0), index.at(2));
            isRotation = !isRotation;
        }

        auto unorderedEVal = eval;
        auto unorderedEVec = evec;
        for (auto j = 0; j < 3; ++j)
        {
            auto i = index.at(j);
            eval.at(j) = unorderedEVal.at(i);
            evec.at(j) = unorderedEVec.at(i);
        }
    }

    /// 确保有序的特征向量形成右手基。
    if (!isRotation)
    {
        for (auto j = 0; j < 3; ++j)
        {
            evec.at(2).at(j) = -evec.at(2).at(j);
        }
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SORT_EIGENSTUFF_DETAIL_H
