///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/23 11:06)

#include "Mathematics/MathematicsExport.h"

#include "DynamicIntersectorDetail.h"

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class DynamicIntersector<float, Vector2>;
    template class DynamicIntersector<double, Vector2>;
    template class DynamicIntersector<float, Vector3>;
    template class DynamicIntersector<double, Vector3>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST
