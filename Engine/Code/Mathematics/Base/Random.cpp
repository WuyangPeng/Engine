///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/30 15:00)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_RANDOM_DETAIL

        #define MATHEMATICS_INCLUDED_RANDOM_DETAIL

    #endif  // MATHEMATICS_INCLUDED_RANDOM_DETAIL

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "RandomDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Random<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Random<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
