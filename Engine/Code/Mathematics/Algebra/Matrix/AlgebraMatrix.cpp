/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/01 13:26)

#include "Mathematics/MathematicsExport.h"

#include "Matrix2x2Detail.h"
#include "Matrix3x3Detail.h"
#include "Matrix4x4Detail.h"
#include "MatrixDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics::Algebra
{
    template class Matrix<1, 1, float>;
    template class Matrix<1, 1, double>;
    template class Matrix<2, 2, float>;
    template class Matrix<2, 2, double>;
    template class Matrix<3, 3, float>;
    template class Matrix<3, 3, double>;
    template class Matrix<4, 4, float>;
    template class Matrix<4, 4, double>;

    template class Matrix<1, 2, float>;
    template class Matrix<3, 1, double>;
    template class Matrix<1, 4, float>;
    template class Matrix<2, 3, double>;
    template class Matrix<4, 2, float>;
    template class Matrix<3, 4, double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
