///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/10 16:07)

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
        // ������׶�塣
        // ��E��ԭ�㣬DΪ����������U��������������Real���ҷ���������
        // ��u > 0 �� r > 0�ֱ�����U��Real����ĳ��ȡ�
        // ��n��f��D�ķ����ϵķ�Χ0 < n < f��
        // �ĸ��ǣ��ڽ���ƽ���׶��E + n * D + s0 * u * U + s1 * r * Real��
        // ����|s0| =|s1| = 1���ĸ�ѡ���
        // �ĸ��ǵ�Զƽ��Ľ�׶�� E + f * D + (f / n) * (s0 * u * U + s1 * r * Real)��
        // ����|s0| = |s1| = 1������ѡ��
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

        // ����8������
        NODISCARD VerticesType ComputeVertices() const;

        NODISCARD Frustum3 GetMove(Real t, const Vector3& velocity) const;

    private:
        // Update()�������뱻�����ڸ�����m_DirectionMin��m_DirectionMax��m_UpBound��m_RightBoundʱ��
        // ��ֵm_DirectionRatio��m_MTwoUF��m_MTwoRF����������Щֵ�ı仯��
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
        Real mTwoUF;
        Real mTwoRF;

        Real epsilon;
    };

    using Frustum3F = Frustum3<float>;
    using Frustum3D = Frustum3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_FRUSTUM3_H
