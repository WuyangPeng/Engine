///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/11/30 15:28)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_QUERY_DOT_TOOLS_ACHIEVE
        #define MATHEMATICS_INCLUDED_QUERY_DOT_TOOLS_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_QUERY_DOT_TOOLS_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "QueryDotToolsDetail.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class QueryDotTools<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class QueryDotTools<double>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class QueryDotTools<int64_t>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class QueryDotTools<Integer<2>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class QueryDotTools<Integer<4>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class QueryDotTools<Integer<6>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class QueryDotTools<SignRational<16>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class QueryDotTools<SignRational<32>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class QueryDotTools<SignRational<64>>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE