/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:17)

#ifndef MATHEMATICS_OBJECTS_2D_FWD_H
#define MATHEMATICS_OBJECTS_2D_FWD_H

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Arc2;

    template <typename Real>
    class Box2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Circle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Line2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ray2;

    template <typename Real>
    class Triangle2;

    template <typename Real>
    class Polygon2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Segment2;

    template <typename Real>
    class Ellipse2;

    template <typename Real>
    class Ellipse2Coefficients;

    template <typename Real>
    class ConvexPolygon2;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Sector2;

    namespace Algebra
    {
        template <typename Real>
        requires std::is_arithmetic_v<Real>
        class Polygon2;
    }
}

#endif  // MATHEMATICS_OBJECTS_2D_FWD_H