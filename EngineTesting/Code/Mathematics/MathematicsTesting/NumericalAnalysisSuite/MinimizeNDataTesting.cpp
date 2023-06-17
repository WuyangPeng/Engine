///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:04)

#include "MinimizeNDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/MinimizeNDataDetail.h"

namespace Mathematics
{
    template class MinimizeNData<float>;
    template class MinimizeNData<double>;
}

Mathematics::MinimizeNDataTesting::MinimizeNDataTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, MinimizeNDataTesting)

void Mathematics::MinimizeNDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::MinimizeNDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DataTest);
}

void Mathematics::MinimizeNDataTesting::DataTest()
{
    std::vector<double> minLocation{ 6.0, 5.0, 4.0, 3.0, 2.0 };

    MinimizeNDataD firstMinimize1Data(minLocation, 50.0);

    ASSERT_APPROXIMATE(firstMinimize1Data.GetMinValue(), 50.0, 1e-10);

    auto index = 0;
    for (auto iter = firstMinimize1Data.GetMinLocationBegin(); iter != firstMinimize1Data.GetMinLocationEnd(); ++iter)
    {
        ASSERT_APPROXIMATE(minLocation.at(index), *iter, 1e-10);
        ++index;
    }
}
