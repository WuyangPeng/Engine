///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/24 14:09)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_NONITERATIVE_EIGEN3X3_ACHIEVE
        #define MATHEMATICS_INCLUDED_NONITERATIVE_EIGEN3X3_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_NONITERATIVE_EIGEN3X3_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "NoniterativeEigen3x3Detail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class NoniterativeEigen3x3<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class NoniterativeEigen3x3<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
