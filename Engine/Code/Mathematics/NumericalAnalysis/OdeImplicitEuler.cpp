///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/27 10:46)

#include "Mathematics/MathematicsExport.h"

#include "OdeImplicitEulerDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class OdeImplicitEuler<float, int>;
    template class OdeImplicitEuler<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
