///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 18:35)

#ifndef MATHEMATICS_OBJECTS3D_FRUSTUM3_H
#define MATHEMATICS_OBJECTS3D_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
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
        using Vector3D = Vector3D<Real>;
        using VerticesType = std::vector<Vector3D>;

    public:
        // 正交视锥体。
        // 设E是原点，D为方向向量，U是向上向量，而Real是右方向向量。
        // 设u > 0 且 r > 0分别是在U和Real方向的长度。
        // 设n和f是D的方向上的范围0 < n < f。
        // 四个角，在近的平面截锥是E + n * D + s0 * u * U + s1 * r * Real，
        // 其中|s0| =|s1| = 1（四个选项）。
        // 四个角的远平面的截锥是 E + f * D + (f / n) * (s0 * u * U + s1 * r * Real)，
        // 其中|s0| = |s1| = 1（四项选择）
        Frustum3(const Vector3D& origin, const Vector3D& directionVector, const Vector3D& upVector, const Vector3D& rightVector, Real directionMin,
                 Real directionMax, Real upBound, Real rightBound, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetOrigin() const noexcept;
        [[nodiscard]] const Vector3D GetDirectionVector() const noexcept;
        [[nodiscard]] const Vector3D GetUpVector() const noexcept;
        [[nodiscard]] const Vector3D GetRightVector() const noexcept;
        [[nodiscard]] Real GetDirectionMin() const noexcept;
        [[nodiscard]] Real GetDirectionMax() const noexcept;
        [[nodiscard]] Real GetUpBound() const noexcept;
        [[nodiscard]] Real GetRightBound() const noexcept;

        [[nodiscard]] Real GetDirectionRatio() const noexcept;
        [[nodiscard]] Real GetMTwoUF() const noexcept;
        [[nodiscard]] Real GetMTwoRF() const noexcept;

        // 返回8个顶点
        [[nodiscard]] const VerticesType ComputeVertices() const;

        [[nodiscard]] const Frustum3 GetMove(Real t, const Vector3D& velocity) const;

    private:
        // Update()函数必须被调用在更改了m_DirectionMin，m_DirectionMax，m_UpBound或m_RightBound时。
        // 该值m_DirectionRatio，m_MTwoUF和m_MTwoRF都依赖于这些值的变化。
        void Update() noexcept;

    private:
        Vector3D m_Origin;
        Vector3D m_DirectionVector;
        Vector3D m_UpVector;
        Vector3D m_RightVector;
        Real m_DirectionMin;
        Real m_DirectionMax;
        Real m_UpBound;
        Real m_RightBound;

        // 数值从构造函数的输入得到的。
        Real m_DirectionRatio;
        Real m_MTwoUF;
        Real m_MTwoRF;

        Real m_Epsilon;
    };

    using FloatFrustum3 = Frustum3<float>;
    using DoubleFrustum3 = Frustum3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_FRUSTUM3_H
