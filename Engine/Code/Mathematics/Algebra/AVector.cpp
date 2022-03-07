///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/07 11:19)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_AVECTOR_ACHIEVE
        #define MATHEMATICS_INCLUDED_AVECTOR_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_AVECTOR_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "AVectorDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class AVector<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class AVector<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
