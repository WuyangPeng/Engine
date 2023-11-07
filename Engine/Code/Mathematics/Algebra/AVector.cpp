///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:06)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_A_VECTOR_ACHIEVE

        #define MATHEMATICS_INCLUDED_A_VECTOR_ACHIEVE

    #endif  // MATHEMATICS_INCLUDED_A_VECTOR_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "AVectorDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class AVector<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class AVector<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
