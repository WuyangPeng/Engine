/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 10:36)

#ifndef MATHEMATICS_ESTIMATE_ASIN_ESTIMATE_DETAIL_H
#define MATHEMATICS_ESTIMATE_ASIN_ESTIMATE_DETAIL_H

#include "ACosEstimateDetail.h"
#include "ASinEstimate.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int Degree>
requires(1 <= Degree && Degree <= 8)
T Mathematics::ASinEstimate(T x)
{
    return Math<T>::GetHalfPI() - ACosEstimate<T, Degree>(x);
}

#endif  // MATHEMATICS_ESTIMATE_ASIN_ESTIMATE_DETAIL_H
