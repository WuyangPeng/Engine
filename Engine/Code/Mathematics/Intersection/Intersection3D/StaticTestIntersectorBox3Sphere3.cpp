///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/31 16:14)

#include "Mathematics/MathematicsExport.h"

#include "StaticTestIntersectorBox3Sphere3Detail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class StaticTestIntersectorBox3Sphere3<float>;
    template class StaticTestIntersectorBox3Sphere3<double>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
