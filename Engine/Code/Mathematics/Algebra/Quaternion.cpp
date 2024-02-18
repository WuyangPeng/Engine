/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/02/03 18:20)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_QUATERNION_ACHIEVE

        #define MATHEMATICS_INCLUDED_QUATERNION_ACHIEVE

    #endif  // MATHEMATICS_INCLUDED_QUATERNION_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "QuaternionDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Quaternion<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Quaternion<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
