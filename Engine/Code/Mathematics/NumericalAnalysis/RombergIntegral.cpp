///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 11:03)

#include "Mathematics/MathematicsExport.h"

#include "RombergIntegralDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class RombergIntegral<float, int>;
    template class RombergIntegral<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
