// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:09)

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

void Mathematics::Minimize1DataTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DataTest);
}

void Mathematics::Minimize1DataTesting ::DataTest()
{
    const Minimize1DataD firstMinimize1Data(3.0, 50.0);

    ASSERT_APPROXIMATE(firstMinimize1Data.GetMinLocation(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(firstMinimize1Data.GetMinValue(), 50.0, 1e-10);
}
