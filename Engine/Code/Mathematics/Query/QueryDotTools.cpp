///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 16:11)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_QUERY_DOT_TOOLS_ACHIEVE
        #define MATHEMATICS_INCLUDED_QUERY_DOT_TOOLS_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_QUERY_DOT_TOOLS_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "QueryDotToolsDetail.h"

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