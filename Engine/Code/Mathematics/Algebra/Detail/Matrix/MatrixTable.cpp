/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/30 20:00)

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
