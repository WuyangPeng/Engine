/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 00:00)

#include "Mathematics/MathematicsExport.h"

#include "OdeRungeKutta4Detail.h"
#include "Mathematics/Algebra/Vector/Vector2.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics::Algebra
{
    template class OdeRungeKutta4<float, Vector2<float>>;
    template class OdeRungeKutta4<double, Vector2<double>>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
