///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/24 18:39)

#include "Mathematics/MathematicsExport.h"

#include "GaussianQuadratureDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class GaussianQuadrature<float, int>;
    template class GaussianQuadrature<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
