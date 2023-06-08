///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:36)

#include "Mathematics/MathematicsExport.h"

#include "GaussianQuadratureDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class GaussianQuadrature<float, int>;
    template class GaussianQuadrature<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
