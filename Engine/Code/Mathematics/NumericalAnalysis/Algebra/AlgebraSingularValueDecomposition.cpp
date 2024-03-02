/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:23)

#include "Mathematics/MathematicsExport.h"

#include "SingularValueDecompositionDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics::Algebra
{
    template class SingularValueDecomposition<float>;
    template class SingularValueDecomposition<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
