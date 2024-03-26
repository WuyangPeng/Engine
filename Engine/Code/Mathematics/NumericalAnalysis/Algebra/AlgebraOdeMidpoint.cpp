/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/19 00:00)

#include "Mathematics/MathematicsExport.h"

#include "OdeMidpointDetail.h"
#include "Mathematics/Algebra/Vector/Vector2Detail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics::Algebra
{
    template class OdeMidpoint<float, Vector2<float>>;
    template class OdeMidpoint<double, Vector2<double>>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
