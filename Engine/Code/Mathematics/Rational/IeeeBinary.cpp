/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 13:48)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_IEEE_BINARY_ACHIEVE

        #define MATHEMATICS_INCLUDED_IEEE_BINARY_ACHIEVE

    #endif  // MATHEMATICS_INCLUDED_IEEE_BINARY_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "IeeeBinaryDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE IeeeBinary<int16_t, uint16_t, 16, 11>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE IeeeBinary<float, uint32_t, 32, 24>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE IeeeBinary<double, uint64_t, 64, 53>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
