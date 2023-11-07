///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 13:49)

#include "Mathematics/MathematicsExport.h"

#include "GaussianQuadratureDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class GaussianQuadrature<float, int>;
    template class GaussianQuadrature<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
