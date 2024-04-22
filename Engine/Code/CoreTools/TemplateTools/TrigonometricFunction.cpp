/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:02)

#include "CoreTools/CoreToolsExport.h"

#include "TrigonometricFunction.h"

double CoreTools::TrigonometricFunction::SineSeries(double radian, int index, int maxTerms) noexcept
{
    if (maxTerms < index)
    {
        return 1.0;
    }

    return 1.0 - (radian * radian / (2.0 * index + 2.0) / (2.0 * index + 3.0) * SineSeries(radian, index + 1, maxTerms));
}

double CoreTools::TrigonometricFunction::RecursiveSine(double radian) noexcept
{
    constexpr auto maxTerms = 10;

    return radian * SineSeries(radian, 0, maxTerms);
}
