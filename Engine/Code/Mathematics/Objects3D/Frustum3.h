/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 10:26)

#ifndef MATHEMATICS_OBJECTS_3D_FRUSTUM3_H
#define MATHEMATICS_OBJECTS_3D_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector3.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    /// ������׶�塣
    /// ��E��ԭ�㣬DΪ����������U��������������R���ҷ���������
    /// ��u > 0 �� r > 0�ֱ�����U��R����ĳ��ȡ�
    /// ��n��f��D�ķ����ϵķ�Χ0 < n < f��
    /// �ĸ��ǣ��ڽ���ƽ���׶��E + n * D + s0 * u * U + s1 * r * R��
    /// ����|s0| =|s1| = 1���ĸ�ѡ���
    /// �ĸ��ǵ�Զƽ��Ľ�׶�� E + f * D + (f / n) * (s0 * u * U + s1 * r * R)��
    /// ����|s0| = |s1| = 1���ĸ�ѡ�
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
        /// Ĭ�Ϲ��캯����������ֵ��
        /// ԭ��(E)Ϊ(0,0,0)��
        /// dVector(D)Ϊ(0,0,1)��
        /// uVector(U)Ϊ(0,1,0)��
        /// rVector(R)Ϊ(1,0,0)��
        /// dMin(n)Ϊ1��
        /// dMax(f)Ϊ2��
        /// uBound(u)Ϊ1��rBound(r)Ϊ1��
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

        /// ����8������
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
        /// ÿ����directionMin��directionMax��upBound��rightBound���и���ʱ�����������Update()������
        /// ֵdirectionRatio��mTwoUF��mTwoRF����������Щֵ�ı仯��
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

        // ��ֵ�ӹ��캯��������õ��ġ�
        Real directionRatio;
        Real twoUpF;
        Real twoRightF;

        Real epsilon;
    };

    /// ��֧�����������ıȽ�
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
