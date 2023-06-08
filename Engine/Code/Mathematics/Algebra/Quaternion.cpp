///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/31 09:33)

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
