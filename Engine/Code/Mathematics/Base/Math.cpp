//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.0 (2020/08/26 12:56)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_MATH_ACHIEVE
        #define MATHEMATICS_INCLUDED_MATH_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_MATH_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "MathDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Math<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Math<double>; 
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
