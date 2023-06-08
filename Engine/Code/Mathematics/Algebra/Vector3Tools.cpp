///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 09:35)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_VECTOR3_TOOLS_ACHIEVE

        #define MATHEMATICS_INCLUDED_VECTOR3_TOOLS_ACHIEVE

    #endif  // MATHEMATICS_INCLUDED_VECTOR3_TOOLS_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "Vector3ToolsDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector3Tools<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Vector3Tools<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
