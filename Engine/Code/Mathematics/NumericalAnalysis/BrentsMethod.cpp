/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:28)

#include "Mathematics/MathematicsExport.h"

#include "BrentsMethodDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class BrentsMethod<float, int>;
    template class BrentsMethod<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
