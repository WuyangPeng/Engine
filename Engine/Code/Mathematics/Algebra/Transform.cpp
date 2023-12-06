/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/29 15:45)

#include "Mathematics/MathematicsExport.h"

#include "Mathematics/Algebra/TransformDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class Transform<float>;
    template class Transform<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST