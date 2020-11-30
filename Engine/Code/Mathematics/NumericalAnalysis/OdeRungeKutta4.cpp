///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/27 11:05)

#include "Mathematics/MathematicsExport.h"

#include "OdeRungeKutta4Detail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class OdeRungeKutta4<float, int>;
    template class OdeRungeKutta4<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
