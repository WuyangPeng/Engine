/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/23 09:20)

#ifndef MATHEMATICS_PRIMITIVES_FWD_H
#define MATHEMATICS_PRIMITIVES_FWD_H

#include <type_traits>

namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class AlignedBox;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class AlignedBoxCentered;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Line;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Rectangle;

    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    class Hyperplane;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class CanonicalBox;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Segment;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Capsule;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Ray;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Cone;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class HyperEllipsoid;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class HyperSphere;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class OrientedBox;

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Triangle;

    enum class TopologyType;
}

#endif  // MATHEMATICS_PRIMITIVES_FWD_H