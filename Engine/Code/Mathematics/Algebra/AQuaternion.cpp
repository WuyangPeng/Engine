///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/03 14:39)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_AQUATERNION_ACHIEVE
        #define MATHEMATICS_INCLUDED_AQUATERNION_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_AQUATERNION_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "AQuaternionDetail.h"
#include "AVectorDetail.h"
#include "MatrixDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class AQuaternion<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class AQuaternion<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE