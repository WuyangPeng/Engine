///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 13:54)

#include "Mathematics/MathematicsExport.h"

#include "BarycentricCoordinatesDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class BarycentricCoordinates<float, 3>;
    template class BarycentricCoordinates<double, 3>;
    template class BarycentricCoordinates<float, 4>;
    template class BarycentricCoordinates<double, 4>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
