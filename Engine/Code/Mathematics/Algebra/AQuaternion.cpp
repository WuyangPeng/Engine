///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/31 09:31)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_A_QUATERNION_ACHIEVE

        #define MATHEMATICS_INCLUDED_A_QUATERNION_ACHIEVE

    #endif  // MATHEMATICS_INCLUDED_A_QUATERNION_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "AQuaternionDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class AQuaternion<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class AQuaternion<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE