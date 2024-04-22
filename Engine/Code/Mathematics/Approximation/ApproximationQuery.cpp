﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 00:00)

#include "Mathematics/MathematicsExport.h"

#include "ApproximationQueryDetail.h"
#include "Mathematics/Algebra/Vector/Vector2Detail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class ApproximationQuery<float, Algebra::Vector2<float>>;
    template class ApproximationQuery<double, Algebra::Vector2<double>>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
