/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 00:00)

#include "Mathematics/MathematicsExport.h"

#include "OdeEulerDetail.h"
#include "Mathematics/Algebra/Vector2.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics::Algebra
{
    template class OdeEuler<float, Vector2<float>>;
    template class OdeEuler<double, Vector2<double>>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
