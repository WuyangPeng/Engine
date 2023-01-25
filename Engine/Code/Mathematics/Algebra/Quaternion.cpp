///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/08 13:42)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_QUATERNION_ACHIEVE
        #define MATHEMATICS_INCLUDED_QUATERNION_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_QUATERNION_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "QuaternionDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

using System::operator>>;

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Quaternion<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Quaternion<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
