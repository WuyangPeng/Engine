///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 13:49)

#include "Mathematics/MathematicsExport.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

    #ifndef MATHEMATICS_INCLUDED_MATRIX3_TOOLS_ACHIEVE

        #define MATHEMATICS_INCLUDED_MATRIX3_TOOLS_ACHIEVE

    #endif  // MATHEMATICS_INCLUDED_MATRIX3_TOOLS_ACHIEVE

#endif  // MATHEMATICS_EXPORT_TEMPLATE

#include "Matrix3ToolsDetail.h"

#ifdef MATHEMATICS_EXPORT_TEMPLATE

namespace Mathematics
{
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Matrix3Tools<float>;
    template MATHEMATICS_TEMPLATE_DEFAULT_DECLARE class Matrix3Tools<double>;
}

#endif  // MATHEMATICS_EXPORT_TEMPLATE
