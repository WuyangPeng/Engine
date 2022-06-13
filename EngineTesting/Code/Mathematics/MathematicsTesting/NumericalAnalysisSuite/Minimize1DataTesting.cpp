///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/02 21:57)

#include "Minimize1DataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Minimize1DataDetail.h"

namespace Mathematics
{
    template class Minimize1Data<float>;
    template class Minimize1Data<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Minimize1DataTesting)

void Mathematics::Minimize1DataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DataTest);
}

void Mathematics::Minimize1DataTesting::DataTest()
{
    const Minimize1DataD firstMinimize1Data(3.0, 50.0);

    ASSERT_APPROXIMATE(firstMinimize1Data.GetMinLocation(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(firstMinimize1Data.GetMinValue(), 50.0, 1e-10);
}
