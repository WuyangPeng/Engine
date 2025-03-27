///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 16:50)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Circle3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceLine3Circle3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;

        using Line3 = Line3<Real>;
        using Circle3 = Circle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine3Circle3(const Line3& line, const Circle3& circle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ������ʡ�
        NODISCARD Line3 GetLine() const noexcept;
        NODISCARD Circle3 GetCircle() const noexcept;

        /// ��̬�����ѯ�� ����ӵ�P��Բ�ľ��롣
        /// ��P�ڷ���C + t * N�ϣ�����C��Բ�Ĳ���N�ǰ�����Բ��ƽ��ķ���ʱ��������Բ�㶼��P�Ⱦࡣ
        /// ����������£����ص�ΪC + r * U ������U�Ǵ�ֱ��N��������
        NODISCARD DistanceResult GetSquared() const override;

        // ��̬�����ѯ�ĺ������㡣
        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        struct DistanceInfo
        {
            Real sqrDistance;
            int numClosestCircle;
            Vector3 closestCircle;

            DistanceInfo(Real sqrDistance, int numClosestCircle, const Vector3& closestCircle) noexcept;
        };

        /// mClosestLine[i]�����롣 mClosestCircle[i]�������
        /// ��������֮���ƽ�����롣 mNumClosest��ֵ����Ϊ1��INT_MAX�� ����Ǻ��ߣ�������Բ�㶼��mClosestLine[i]�Ⱦࡣ
        NODISCARD DistanceInfo SqrDistancePointCircle(const Vector3& closestLine) const;

        // ������F(s) = s + m2b2 - r * m0sqr * s / sqrt(m0sqr * s * s + b1sqr)�ֳ�ָ�����[smin��smax]��
        NODISCARD static Real BisectF(Real lineDotDiff, Real radiusMultiplyDot, Real dot, Real diffCrossNormalDot, Real smin, Real smax);

    private:
        Line3 line;
        Circle3 circle;
    };

    using DistanceLine3Circle3F = DistanceLine3Circle3<float>;
    using DistanceLine3Circle3D = DistanceLine3Circle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_H
