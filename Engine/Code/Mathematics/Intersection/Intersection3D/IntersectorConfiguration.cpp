///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 14:29)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_INTERSECTOR_CONFIGURATION_ACHIEVE
        #define MATHEMATICS_INCLUDED_INTERSECTOR_CONFIGURATION_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_INTERSECTOR_CONFIGURATION_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "IntersectorConfigurationDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class IntersectorConfiguration<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class IntersectorConfiguration<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE