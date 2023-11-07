///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 13:46)

#include "Mathematics/MathematicsExport.h"

#include "LinearSystemInverseDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class LinearSystemInverse<float>;
    template class LinearSystemInverse<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
