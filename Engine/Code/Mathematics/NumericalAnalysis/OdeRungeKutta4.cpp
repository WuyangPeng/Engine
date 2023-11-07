///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 13:50)

#include "Mathematics/MathematicsExport.h"

#include "OdeRungeKutta4Detail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class OdeRungeKutta4<float, int>;
    template class OdeRungeKutta4<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
