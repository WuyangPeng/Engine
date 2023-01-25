///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/08 13:42)

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
