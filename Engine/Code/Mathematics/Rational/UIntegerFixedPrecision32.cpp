/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 20:06)

#include "Mathematics/MathematicsExport.h"

#include "UIntegerFixedPrecision32Detail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class UIntegerFixedPrecision32<1>;
    template class UIntegerFixedPrecision32<2>;
    template class UIntegerFixedPrecision32<4>;
    template class UIntegerFixedPrecision32<8>;
    template class UIntegerFixedPrecision32<16>;
    template class UIntegerFixedPrecision32<24>;
    template class UIntegerFixedPrecision32<32>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
