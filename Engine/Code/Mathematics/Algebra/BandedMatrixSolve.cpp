///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/31 09:32)

#include "Mathematics/MathematicsExport.h"

#include "BandedMatrixSolveDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class BandedMatrixSolve<float>;
    template class BandedMatrixSolve<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST