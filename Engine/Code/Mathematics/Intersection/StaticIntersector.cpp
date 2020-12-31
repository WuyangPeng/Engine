///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/16 10:14)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_STATIC_INTERSECTOR_ACHIEVE
        #define MATHEMATICS_INCLUDED_STATIC_INTERSECTOR_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_STATIC_INTERSECTOR_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "StaticIntersectorDetail.h" 

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class StaticIntersector<float, Vector2D>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class StaticIntersector<double, Vector2D>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class StaticIntersector<float, Vector3D>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class StaticIntersector<double, Vector3D>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
