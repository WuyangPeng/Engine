///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 15:58)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_QUATERNION_ACHIEVE
        #define MATHEMATICS_INCLUDED_QUATERNION_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_QUATERNION_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "QuaternionDetail.h"
#include "QuaternionFactorDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Quaternion<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Quaternion<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
