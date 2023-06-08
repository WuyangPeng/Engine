///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:42)

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
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<float, Vector2<float>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<double, Vector2<double>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<float, Vector3<float>>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class DistanceBase<double, Vector3<double>>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
