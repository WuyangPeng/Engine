///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/09 11:40)

#include "Mathematics/MathematicsExport.h"

#include "GaussianEliminationDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class GaussianElimination<float>;
    template class GaussianElimination<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
