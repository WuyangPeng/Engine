///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/02 22:13)

#include "MinimizeNDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/MinimizeNDataDetail.h"

using std::vector;

namespace Mathematics
{
    template class MinimizeNData<float>;
    template class MinimizeNData<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, MinimizeNDataTesting)

void Mathematics::MinimizeNDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DataTest);
}

void Mathematics::MinimizeNDataTesting::DataTest()
{
    vector<double> minLocation{ 6.0, 5.0, 4.0, 3.0, 2.0 };

    MinimizeNDataD firstMinimize1Data(minLocation, 50.0);

    ASSERT_APPROXIMATE(firstMinimize1Data.GetMinValue(), 50.0, 1e-10);

    auto index = 0;
    for (auto iter = firstMinimize1Data.GetMinLocationBegin(); iter != firstMinimize1Data.GetMinLocationEnd(); ++iter)
    {
        ASSERT_APPROXIMATE(minLocation.at(index), *iter, 1e-10);
        ++index;
    }
}
