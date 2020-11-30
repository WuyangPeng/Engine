///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/23 18:44)

#include "Mathematics/MathematicsExport.h"

#include "BrentsMethodCalculateDetail.h"
#include "BrentsMethodDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class BrentsMethod<float, int>;
    template class BrentsMethod<double, int>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
