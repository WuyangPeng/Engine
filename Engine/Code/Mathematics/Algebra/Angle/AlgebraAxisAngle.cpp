/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/02 11:01)

#include "Mathematics/MathematicsExport.h"

#include "AxisAngleDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics::Algebra
{
    template class AxisAngle<3, float>;
    template class AxisAngle<4, float>;
    template class AxisAngle<3, double>;
    template class AxisAngle<4, double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
