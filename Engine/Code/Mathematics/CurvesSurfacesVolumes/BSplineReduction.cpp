///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/15 14:48)

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
