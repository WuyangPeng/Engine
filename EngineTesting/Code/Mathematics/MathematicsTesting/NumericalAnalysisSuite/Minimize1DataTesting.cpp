///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:03)

#include "Minimize1DataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/Minimize1DataDetail.h"

namespace Mathematics
{
    template class Minimize1Data<float>;
    template class Minimize1Data<double>;
}

Mathematics::Minimize1DataTesting::Minimize1DataTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Minimize1DataTesting)

void Mathematics::Minimize1DataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
