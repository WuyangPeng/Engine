///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/15 10:49)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_SURFACE_DETAIL
        #define MATHEMATICS_INCLUDED_SURFACE_DETAIL
    #endif  // MATHEMATICS_INCLUDED_SURFACE_DETAIL

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "SurfaceDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Surface<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Surface<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE