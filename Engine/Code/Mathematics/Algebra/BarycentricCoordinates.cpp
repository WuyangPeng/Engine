///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:07)

#include "Mathematics/MathematicsExport.h"

#include "BarycentricCoordinatesDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class BarycentricCoordinates<float, 3>;
    template class BarycentricCoordinates<double, 3>;
    template class BarycentricCoordinates<float, 4>;
    template class BarycentricCoordinates<double, 4>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
