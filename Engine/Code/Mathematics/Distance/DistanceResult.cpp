///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/20 14:07)

#include "Mathematics/MathematicsExport.h"

#include "DistanceResultDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class DistanceResult<float, Vector2<float>>;
    template class DistanceResult<double, Vector2<double>>;
    template class DistanceResult<float, Vector3<float>>;
    template class DistanceResult<double, Vector3<double>>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
