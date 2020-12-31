///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 14:33)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_BISECT2_ACHIEVE
        #define MATHEMATICS_INCLUDED_BISECT2_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_BISECT2_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "Bisect2Detail.h"
#include "Bisect2RootDetail.h"
#include "Detail/Bisect2NodeDetail.h"
#include "Detail/Bisect2StorageDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Bisect2<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Bisect2<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
