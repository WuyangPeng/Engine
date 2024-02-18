/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/18 13:35)

#include "Mathematics/MathematicsExport.h"

#include "BandedMatrixSolveDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class BandedMatrixSolve<float>;
    template class BandedMatrixSolve<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST