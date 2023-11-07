///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 13:49)

#include "Mathematics/MathematicsExport.h"

#include "GaussianEliminationDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class GaussianElimination<float>;
    template class GaussianElimination<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
