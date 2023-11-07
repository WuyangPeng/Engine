///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 16:43)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_H
#define MATHEMATICS_DISTANCE_DISTANCE_H

#include "Mathematics/MathematicsDll.h"

#include "DistanceResult.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector3.h"
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

        DistanceBase(const DistanceBase& rhs) noexcept = default;
        DistanceBase& operator=(const DistanceBase& rhs) noexcept = default;
        DistanceBase(DistanceBase&& rhs) noexcept = default;
        DistanceBase& operator=(DistanceBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // ���ڵ����ƽ���
        void SetDifferenceStep(Real newDifferenceStep) noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD Real GetDifferenceStep() const noexcept;

        void SetMaximumIterations(int newMaximumIterations) noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD int GetMaximumIterations() const noexcept;

        void SetZeroThreshold(Real newZeroThreshold) noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD Real GetZeroThreshold() const noexcept;

        // ��̬�����ѯ��
        // ���루Ĭ��ʵ��Ϊ����GetSquared����DistanceResult�еľ���ֵ���п�����
        NODISCARD virtual DistanceResult Get() const;
        // ����ƽ��
        NODISCARD virtual DistanceResult GetSquared() const = 0;

        // �������㶯̬�����ѯ��
        // ��Ĭ��ʵ��Ϊ����GetSquared����DistanceResult�еľ���ֵ���п�����
        NODISCARD virtual DistanceResult Get(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        NODISCARD virtual DistanceResult GetSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const = 0;

        // ΢�ּ��㶯̬�����ѯ��Ĭ��ʹ�����޲�ֹ���f'(t) = (f(t + h) - f(t - h)) / (2 * h)������h = m_DifferenceStep��
        // ��������Ը�����Щ�����ṩ��Ҫ��h�ľ�ȷ��ʽ��ʵ�֡�
        NODISCARD virtual Real GetDerivative(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        NODISCARD virtual Real GetDerivativeSquared(Real t, const Vector& lhsVelocity, const Vector& rhsVelocity) const;

        // ��̬�����ѯ������������ʱ����[tmin,tmax]��������֮�����С���롣
        // Ĭ��ʵ�ּ����ǣ�����f(t)��һ��͹������
        NODISCARD virtual DistanceResult GetInterval(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const;
        NODISCARD virtual DistanceResult GetIntervalSquared(Real tMin, Real tMax, const Vector& lhsVelocity, const Vector& rhsVelocity) const;

    private:
        static constexpr auto defaultMaximumIterations = 8;
        static constexpr Real defaultZeroThreshold = Math::GetZeroTolerance();
        static constexpr Real defaultDifferenceStep = Math::GetRational(1, 1000);

    private:
        // ����ţ�ٷ����������߲�ֵ��
        // Ĭ�� = 8
        int maximumIterations;
        // Ĭ�� = Math<Real>::GetZeroTolerance()
        Real zeroThreshold;

        // Ĭ�� = 1e-03
        Real differenceStep;
        Real inverseTwoDifferenceStep;
    };

    using Distance2F = DistanceBase<float, Vector2F>;
    using Distance3F = DistanceBase<float, Vector3F>;
    using Distance2D = DistanceBase<double, Vector2D>;
    using Distance3D = DistanceBase<double, Vector3D>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_H
