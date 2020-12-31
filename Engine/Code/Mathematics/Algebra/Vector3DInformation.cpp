///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/12 18:36)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_VECTOR3D_INFORMATION_ACHIEVE
        #define MATHEMATICS_INCLUDED_VECTOR3D_INFORMATION_ACHIEVE
    #endif  // MATHEMATICS_INCLUDED_VECTOR3D_INFORMATION_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "Vector3DInformationDetail.h"
#include "Vector3DDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector3DInformation<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector3DInformation<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
