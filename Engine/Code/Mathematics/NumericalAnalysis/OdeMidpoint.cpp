/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:25)

#include "Mathematics/MathematicsExport.h"

#include "OdeMidpointDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class OdeMidpoint<float, int>;
    template class OdeMidpoint<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
