/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 20:03)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_U_INTEGER_ARITHMETIC_LOGIC_UNIT_32_ACHIEVE

        #define MATHEMATICS_INCLUDED_U_INTEGER_ARITHMETIC_LOGIC_UNIT_32_ACHIEVE

    #endif  // MATHEMATICS_INCLUDED_U_INTEGER_ARITHMETIC_LOGIC_UNIT_32_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "UIntegerArbitraryPrecision32.h"
#include "UIntegerArithmeticLogicUnit32Detail.h"
#include "UIntegerFixedPrecision32.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE UIntegerArithmeticLogicUnit32<UIntegerArbitraryPrecision32>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE UIntegerArithmeticLogicUnit32<UIntegerFixedPrecision32<1>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE UIntegerArithmeticLogicUnit32<UIntegerFixedPrecision32<2>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE UIntegerArithmeticLogicUnit32<UIntegerFixedPrecision32<4>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE UIntegerArithmeticLogicUnit32<UIntegerFixedPrecision32<8>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE UIntegerArithmeticLogicUnit32<UIntegerFixedPrecision32<16>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE UIntegerArithmeticLogicUnit32<UIntegerFixedPrecision32<24>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE UIntegerArithmeticLogicUnit32<UIntegerFixedPrecision32<32>>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
