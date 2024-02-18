/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/30 20:00)

#include "Mathematics/MathematicsExport.h"

#include "MatrixTableDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics::Algebra
{
    template class MatrixTable<1, 1, float>;
    template class MatrixTable<1, 1, double>;
    template class MatrixTable<2, 2, float>;
    template class MatrixTable<2, 2, double>;
    template class MatrixTable<3, 3, float>;
    template class MatrixTable<3, 3, double>;
    template class MatrixTable<4, 4, float>;
    template class MatrixTable<4, 4, double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
