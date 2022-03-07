///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 16:07)

#ifndef MATHEMATICS_OBJECTS3D_FRUSTUM3_H
#define MATHEMATICS_OBJECTS3D_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Frustum3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Frustum3<Real>;
        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using VerticesType = std::vector<Vector3>;

    public:
        // 正交视锥体。
        // 设E是原点，D为方向向量，U是向上向量，而Real是右方向向量。
        // 设u > 0 且 r > 0分别是在U和Real方向的长度。
        // 设n和f是D的方向上的范围0 < n < f。
        // 四个角，在近的平面截锥是E + n * D + s0 * u * U + s1 * r * Real，
        // 其中|s0| =|s1| = 1（四个选项）。
        // 四个角的远平面的截锥是 E + f * D + (f / n) * (s0 * u * U + s1 * r * Real)，
        // 其中|s0| = |s1| = 1（四项选择）
        Frustum3(const Vector3& origin,
                 const Vector3& directionVector,
                 const Vector3& upVector,
                 const Vector3& rightVector,
                 Real directionMin,
                 Real directionMax,
                 Real upBound,
                 Real rightBound,
                 const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetOrigin() const noexcept;
        NODISCARD Vector3 GetDirectionVector() const noexcept;
        NODISCARD Vector3 GetUpVector() const noexcept;
        NODISCARD Vector3 GetRightVector() const noexcept;
        NODISCARD Real GetDirectionMin() const noexcept;
        NODISCARD Real GetDirectionMax() const noexcept;
        NODISCARD Real GetUpBound() const noexcept;
        NODISCARD Real GetRightBound() const noexcept;

        NODISCARD Real GetDirectionRatio() const noexcept;
        NODISCARD Real GetMTwoUF() const noexcept;
        NODISCARD Real GetMTwoRF() const noexcept;

        // 返回8个顶点
        NODISCARD VerticesType ComputeVertices() const;

        NODISCARD Frustum3 GetMove(Real t, const Vector3& velocity) const;

    private:
        // Update()函数必须被调用在更改了m_DirectionMin，m_DirectionMax，m_UpBound或m_RightBound时。
        // 该值m_DirectionRatio，m_MTwoUF和m_MTwoRF都依赖于这些值的变化。
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
        Real mTwoUF;
        Real mTwoRF;

        Real epsilon;
    };

    using Frustum3F = Frustum3<float>;
    using Frustum3D = Frustum3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_FRUSTUM3_H
