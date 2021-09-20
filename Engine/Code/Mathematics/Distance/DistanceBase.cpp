///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/07 15:17)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_DISTANCE_BASE_ACHIEVE
        #define MATHEMATICS_INCLUDED_DISTANCE_BASE_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_DISTANCE_BASE_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "DistanceBaseDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<float, Vector2D<float>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<double, Vector2D<double>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<float, Vector3D<float>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<double, Vector3D<double>>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE