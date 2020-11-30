///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/30 10:49)

#include "Mathematics/MathematicsExport.h"

#include "TrapezoidRuleDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class TrapezoidRule<float, int>;
    template class TrapezoidRule<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
