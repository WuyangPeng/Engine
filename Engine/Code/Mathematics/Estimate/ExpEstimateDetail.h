/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 09:58)

#ifndef MATHEMATICS_ESTIMATE_EXP_ESTIMATE_DETAIL_H
#define MATHEMATICS_ESTIMATE_EXP_ESTIMATE_DETAIL_H

#include "ExpEstimate.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int Degree>
requires(1 <= Degree && Degree <= 7)
T Mathematics::ExpEstimate(T x)
{
    return Exp2Estimate<T, Degree>(x * Math<T>::GetInverseLN2());
}

template <typename T, int Degree>
requires(1 <= Degree && Degree <= 7)
T Mathematics::ExpEstimateReal(T x)
{
    return Exp2EstimateReal<T, Degree>(x * Math<T>::GetInverseLN2());
}

#endif  // MATHEMATICS_ESTIMATE_EXP_ESTIMATE_DETAIL_H
