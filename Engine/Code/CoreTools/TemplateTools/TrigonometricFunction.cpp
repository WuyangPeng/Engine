///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 15:39)

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
