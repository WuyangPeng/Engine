///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/18 19:38)

#ifndef MATHEMATICS_ESTIMATE_LOG_ESTIMATE_DETAIL_H
#define MATHEMATICS_ESTIMATE_LOG_ESTIMATE_DETAIL_H

#include "LogEstimate.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int Degree>
requires(1 <= Degree && Degree <= 8)
T Mathematics::LogEstimate(T x)
{
    return Log2Estimate<T, Degree>(x) * Math<T>::GetLN2();
}

template <typename T, int Degree>
requires(1 <= Degree && Degree <= 8)
T Mathematics::LogEstimateReal(T x)
{
    return Log2EstimateRR<T, Degree>(x) * Math<T>::GetLN2();
}

#endif  // MATHEMATICS_ESTIMATE_LOG_ESTIMATE_DETAIL_H
