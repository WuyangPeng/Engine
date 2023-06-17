///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 10:04)

#include "Mathematics/MathematicsExport.h"

#include "BSplineReductionDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class BSplineReduction<float, Vector2F>;
    template class BSplineReduction<double, Vector2D>;
    template class BSplineReduction<float, Vector3F>;
    template class BSplineReduction<double, Vector3D>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
