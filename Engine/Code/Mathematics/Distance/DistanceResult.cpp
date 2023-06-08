///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:42)

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
