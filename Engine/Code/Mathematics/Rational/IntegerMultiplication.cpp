///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/11 15:36)

#include "Mathematics/MathematicsExport.h"

#include "IntegerMultiplicationDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class IntegerMultiplication<1>;
    template class IntegerMultiplication<2>;
    template class IntegerMultiplication<3>;
    template class IntegerMultiplication<4>;
    template class IntegerMultiplication<5>;
    template class IntegerMultiplication<6>;
    template class IntegerMultiplication<7>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST