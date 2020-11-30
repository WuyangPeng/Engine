///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 17:19)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_BISECT3_ACHIEVE
        #define MATHEMATICS_INCLUDED_BISECT3_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_BISECT3_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "Bisect3Detail.h"
#include "Bisect3RootDetail.h"
#include "Detail/Bisect3CalculateDetail.h"
#include "Detail/Bisect3NodeDetail.h"
#include "Detail/Bisect3StorageDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Bisect3<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Bisect3<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
