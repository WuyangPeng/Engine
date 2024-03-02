///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/20 16:26)

#include "Mathematics/MathematicsExport.h"

#include "Mathematics/Algebra/ConvertCoordinatesDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class ConvertCoordinates<1, float>;
    template class ConvertCoordinates<1, double>;
    template class ConvertCoordinates<2, float>;
    template class ConvertCoordinates<2, double>;
    template class ConvertCoordinates<3, float>;
    template class ConvertCoordinates<3, double>;
    template class ConvertCoordinates<4, float>;
    template class ConvertCoordinates<4, double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST