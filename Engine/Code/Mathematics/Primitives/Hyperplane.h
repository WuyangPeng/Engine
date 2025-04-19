///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/27 09:24)

#ifndef MATHEMATICS_PRIMITIVES_HYPERPLANE_H
#define MATHEMATICS_PRIMITIVES_HYPERPLANE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector.h"

/// 超平面表示为Dot(U, X - P) = 0，
/// 其中U是单位长度法向量，
/// P是超平面原点，
/// X是超平面上的任何点。
/// 用户必须确保法向量为单位长度。
/// 超平面常数为c = Dot(U, P)，因此Dot(U, X) = c。
/// 如果在构造超平面时没有指定P，
/// 则将其选择为最靠近原点的平面上的点，P = c * U。
///
/// 注意：不能单独设置'origin'和 'constant'。请改用构造函数。
///
/// // 由法线N和常数c构造。
/// Plane3<T> plane(N, c);  // plane.origin = c * N
///
/// // 由法线N和原点P构造。
/// Plane3<T> plane(N, P);  // plane.constant = Dot(N, P)
///
/// Plane3<T> plane{};  // N = (0,0,0), P = (0,0,0), c = 0 [无效的]
/// plane.normal = (0,0,1);
/// plane.constant = 3;
/// // 如果现在使用平面，原点和常数不一致，因为P = (0,0,0)但Dot(N,P) = 0 != 3 = c改为使用
/// plane = Plane3<T>({ 0, 0, 1 }, 3);
namespace Mathematics
{
    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    class Hyperplane
    {
    public:
        using ClassType = Hyperplane<N, Real>;

        using MathType = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;
        using PointType = std::array<Vector, N>;

    public:
        /// 默认构造函数将法线设置为(0,...,0,1)，
        /// 原点设置为(0,...,0)，
        /// 常量设置为零。
        Hyperplane() noexcept requires(N == 3);
        Hyperplane() noexcept requires(N == 4);

        Hyperplane(const Vector& normal, Real constant);
        Hyperplane(const Vector& normal, const Vector& origin);

        /// U是集合{p[1]-p[0],...,p[n-1]-p[0]}和 c = Dot(U,p[0])的正交补中的单位长度向量，
        /// 其中p[i]是超平面上的点。
        explicit Hyperplane(const PointType& p);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetNormal() const noexcept;
        void SetNormal(const Vector& aNormal) noexcept;
        NODISCARD Vector GetOrigin() const noexcept;
        void SetOrigin(const Vector& aOrigin) noexcept;
        NODISCARD Real GetConstant() const noexcept;
        void SetConstant(Real aConstant) noexcept;

    private:
        /// 用于N > 3时在Hyperplane(std::array<*>)构造函数中使用
        void ComputeFromPoints(const PointType& p) requires(N != 3);

        /// 用于N == 3时在Hyperplane(std::array<*>)构造函数中使用
        void ComputeFromPoints(const PointType& p) requires(N == 3);

    private:
        Vector normal;
        Vector origin;
        Real constant;
    };

    /// 与支持排序容器的比较。
    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs);

    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs);

    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs);

    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs);

    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs);

    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const Hyperplane<N, Real>& lhs, const Hyperplane<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，模板别名。
        template <typename T>
        using Plane3 = Hyperplane<3, T>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_HYPERPLANE_H
