///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/02 1:11)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_VECTOR3_ORTHONORMALIZE_ACHIEVE
        #define MATHEMATICS_INCLUDED_VECTOR3_ORTHONORMALIZE_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_VECTOR3_ORTHONORMALIZE_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "Vector3OrthonormalizeDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector3Orthonormalize<float, false>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector3Orthonormalize<double, false>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector3Orthonormalize<float, true>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector3Orthonormalize<double, true>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
