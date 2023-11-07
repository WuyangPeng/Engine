///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 17:17)

#include "Mathematics/MathematicsExport.h"

#include "DistanceResultDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class DistanceResult<float, Vector2<float>>;
    template class DistanceResult<double, Vector2<double>>;
    template class DistanceResult<float, Vector3<float>>;
    template class DistanceResult<double, Vector3<double>>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
