///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/16 11:35)

#include "Mathematics/MathematicsExport.h"

#include "OdeEulerDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class OdeEuler<float, int>;
    template class OdeEuler<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
