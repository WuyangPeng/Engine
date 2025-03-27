/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:26)

#ifndef MATHEMATICS_OBJECTS_3D_FRUSTUM3_H
#define MATHEMATICS_OBJECTS_3D_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector3.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    /// 正交视锥体。
    /// 设E是原点，D为方向向量，U是向上向量，而R是右方向向量。
    /// 设u > 0 且 r > 0分别是在U和R方向的长度。
    /// 设n和f是D的方向上的范围0 < n < f。
    /// 四个角，在近的平面截锥是E + n * D + s0 * u * U + s1 * r * R，
    /// 其中|s0| =|s1| = 1（四个选项）。
    /// 四个角的远平面的截锥是 E + f * D + (f / n) * (s0 * u * U + s1 * r * R)，
    /// 其中|s0| = |s1| = 1（四个选项）
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Frustum3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Frustum3<Real>;

        using MathType = Math<Real>;
        using Vector3 = Vector3<Real>;
        using AlgebraVector3 = Algebra::Vector3<Real>;
        using VerticesType = std::vector<Vector3>;

        static constexpr auto vertexSize = 8;

        using ArrayType = std::array<Vector3, vertexSize>;

    public:
        /// 默认构造函数设置以下值：
        /// 原点(E)为(0,0,0)，
        /// dVector(D)为(0,0,1)，
        /// uVector(U)为(0,1,0)，
        /// rVector(R)为(1,0,0)，
        /// dMin(n)为1，
        /// dMax(f)为2，
        /// uBound(u)为1和rBound(r)为1。
        Frustum3() noexcept;

        Frustum3(const Vector3& origin,
                 const Vector3& directionVector,
                 const Vector3& upVector,
                 const Vector3& rightVector,
                 Real directionMin,
                 Real directionMax,
                 Real upBound,
                 Real rightBound,
                 Real epsilon = MathType::GetZeroTolerance()) noexcept;

        Frustum3(const AlgebraVector3& origin,
                 const AlgebraVector3& directionVector,
                 const AlgebraVector3& upVector,
                 const AlgebraVector3& rightVector,
                 Real directionMin,
                 Real directionMax,
                 Real upBound,
                 Real rightBound,
                 Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetOrigin() const noexcept;
        NODISCARD Vector3 GetDirectionVector() const noexcept;
        NODISCARD Vector3 GetUpVector() const noexcept;
        NODISCARD Vector3 GetRightVector() const noexcept;
        NODISCARD Real GetDirectionMin() const noexcept;
        NODISCARD Real GetDirectionMax() const noexcept;
        NODISCARD Real GetUpBound() const noexcept;
        NODISCARD Real GetRightBound() const noexcept;

        NODISCARD AlgebraVector3 GetAlgebraOrigin() const noexcept;
        NODISCARD AlgebraVector3 GetAlgebraDirectionVector() const noexcept;
        NODISCARD AlgebraVector3 GetAlgebraUpVector() const noexcept;
        NODISCARD AlgebraVector3 GetAlgebraRightVector() const noexcept;

        NODISCARD Real GetDirectionRatio() const noexcept;
        NODISCARD Real GetMTwoUpF() const noexcept;
        NODISCARD Real GetMTwoRightF() const noexcept;

        /// 返回8个顶点
        NODISCARD VerticesType ComputeVertices() const;
        NODISCARD ArrayType ComputeVerticesToArray() const;

        NODISCARD Frustum3 GetMove(Real t, const Vector3& velocity) const;

        void SetOrigin(const Vector3& aOrigin) noexcept;
        void SetDirectionVector(const Vector3& aDirectionVector) noexcept;
        void SetUpVector(const Vector3& aUpVector) noexcept;
        void SetRightVector(const Vector3& aRightVector) noexcept;
        void SetDirectionMin(Real aDirectionMin) noexcept;
        void SetDirectionMax(Real aDirectionMax) noexcept;
        void SetUpBound(Real aUpBound) noexcept;
        void SetRightBound(Real aRightBound) noexcept;

        void SetOrigin(const AlgebraVector3& aOrigin);
        void SetDirectionVector(const AlgebraVector3& aDirectionVector);
        void SetUpVector(const AlgebraVector3& aUpVector);
        void SetRightVector(const AlgebraVector3& aRightVector);

    private:
        /// 每当对directionMin，directionMax，upBound或rightBound进行更改时，都必须调用Update()函数。
        /// 值directionRatio，mTwoUF和mTwoRF都依赖于这些值的变化。
        void Update() noexcept;

    private:
        Vector3 origin;
        Vector3 directionVector;
        Vector3 upVector;
        Vector3 rightVector;
        Real directionMin;
        Real directionMax;
        Real upBound;
        Real rightBound;

        // 数值从构造函数的输入得到的。
        Real directionRatio;
        Real twoUpF;
        Real twoRightF;

        Real epsilon;
    };

    /// 与支持排序容器的比较
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Frustum3<Real>& lhs, const Frustum3<Real>& rhs);

    using Frustum3F = Frustum3<float>;
    using Frustum3D = Frustum3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_FRUSTUM3_H
