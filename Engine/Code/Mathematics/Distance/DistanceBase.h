///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/07 14:40)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_H
#define MATHEMATICS_DISTANCE_DISTANCE_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceResult.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceBase
    {
    public:
        using ClassType = DistanceBase<Real, Vector>;
        using DistanceResult = DistanceResult<Real, Vector>;
        using Math = Math<Real>;

    public:
        DistanceBase() noexcept;
        virtual ~DistanceBase() noexcept = default;

        DistanceBase(const DistanceBase& rhs) = default;
        DistanceBase& operator=(const DistanceBase& rhs) = default;
        DistanceBase(DistanceBase&& rhs) noexcept = default;
        DistanceBase& operator=(DistanceBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // ���ڵ����ƽ���
        void SetDifferenceStep(Real differenceStep) noexcept(g_Assert < 2 || g_MathematicsAssert < 2);
        [[nodiscard]] Real GetDifferenceStep() const noexcept;

        void SetMaximumIterations(int maximumIterations) noexcept(g_Assert < 2 || g_MathematicsAssert < 2);
        [[nodiscard]] int GetMaximumIterations() const noexcept;

        void SetZeroThreshold(Real zeroThreshold) noexcept(g_Assert < 2 || g_MathematicsAssert < 2);
        [[nodiscard]] Real GetZeroThreshold() const noexcept;

        // ��̬�����ѯ��
        // ���루Ĭ��ʵ��Ϊ����GetSquared����DistanceResult�еľ���ֵ���п�����
        [[nodiscard]] virtual const DistanceResult Get() const;
        // ����ƽ��
        [[nodiscard]] virtual const DistanceResult GetSquared() const = 0;

        // �������㶯̬�����ѯ��
        // ��Ĭ��ʵ��Ϊ����GetSquared����DistanceResult�еľ���ֵ���п�����
        [[nodiscard]] virtual const DistanceResult Get(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        [[nodiscard]] virtual const DistanceResult GetSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const = 0;

        // ΢�ּ��㶯̬�����ѯ��Ĭ��ʹ�����޲�ֹ���f'(t) = (f(t + h) - f(t - h)) / (2 * h)������h = m_DifferenceStep��
        // ��������Ը�����Щ�����ṩ��Ҫ��h�ľ�ȷ��ʽ��ʵ�֡�
        [[nodiscard]] virtual Real GetDerivative(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        [[nodiscard]] virtual Real GetDerivativeSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;

        // ��̬�����ѯ������������ʱ����[tmin,tmax]��������֮�����С���롣
        // Ĭ��ʵ�ּ����ǣ�����f(t)��һ��͹������
        [[nodiscard]] virtual const DistanceResult GetInterval(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        [[nodiscard]] virtual const DistanceResult GetIntervalSquared(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const;

    private:
        static constexpr auto sm_DefaultMaximumIterations = 8;
        static constexpr Real sm_DefaultZeroThreshold = Math::GetZeroTolerance();
        static constexpr Real sm_DefaultDifferenceStep = Math::GetRational(1, 1000);
    
    private:
        // ����ţ�ٷ����������߲�ֵ��
        // Ĭ�� = 8
        int m_MaximumIterations;
        // Ĭ�� = Math<Real>::GetZeroTolerance()
        Real m_ZeroThreshold;

        // Ĭ�� = 1e-03
        Real m_DifferenceStep;
        Real m_InverseTwoDifferenceStep;
    };

    using Distance2f = DistanceBase<float, FloatVector2D>;
    using Distance3f = DistanceBase<float, FloatVector3D>;
    using Distance2d = DistanceBase<double, DoubleVector2D>;
    using Distance3d = DistanceBase<double, DoubleVector3D>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_H
