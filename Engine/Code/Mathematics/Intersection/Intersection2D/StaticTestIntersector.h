///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/22 13:44)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    template <typename Type0, typename Type1>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersector
    {
    public:
        using ClassType = StaticTestIntersector;

    public:
        StaticTestIntersector(const Type0& lhs, const Type1& rhs);
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_H
