///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 18:35)

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
        // ������׶�塣
        // ��E��ԭ�㣬DΪ����������U��������������Real���ҷ���������
        // ��u > 0 �� r > 0�ֱ�����U��Real����ĳ��ȡ�
        // ��n��f��D�ķ����ϵķ�Χ0 < n < f��
        // �ĸ��ǣ��ڽ���ƽ���׶��E + n * D + s0 * u * U + s1 * r * Real��
        // ����|s0| =|s1| = 1���ĸ�ѡ���
        // �ĸ��ǵ�Զƽ��Ľ�׶�� E + f * D + (f / n) * (s0 * u * U + s1 * r * Real)��
        // ����|s0| = |s1| = 1������ѡ��
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

        // ����8������
        [[nodiscard]] const VerticesType ComputeVertices() const;

        [[nodiscard]] const Frustum3 GetMove(Real t, const Vector3D& velocity) const;

    private:
        // Update()�������뱻�����ڸ�����m_DirectionMin��m_DirectionMax��m_UpBound��m_RightBoundʱ��
        // ��ֵm_DirectionRatio��m_MTwoUF��m_MTwoRF����������Щֵ�ı仯��
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

        // ��ֵ�ӹ��캯��������õ��ġ�
        Real m_DirectionRatio;
        Real m_MTwoUF;
        Real m_MTwoRF;

        Real m_Epsilon;
    };

    using FloatFrustum3 = Frustum3<float>;
    using DoubleFrustum3 = Frustum3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_FRUSTUM3_H
