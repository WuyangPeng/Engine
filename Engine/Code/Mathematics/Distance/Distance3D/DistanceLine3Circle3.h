///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/10 15:00)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Circle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceLine3Circle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Line3 = Line3<Real>;
        using Circle3 = Circle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine3Circle3(const Line3& line, const Circle3& circle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ������ʡ�
        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Circle3 GetCircle() const noexcept;

        /// ��̬�����ѯ�� ����ӵ�P��Բ�ľ��롣
        /// ��P�ڷ���C + t * N�ϣ�����C��Բ�Ĳ���N�ǰ�����Բ��ƽ��ķ���ʱ��������Բ�㶼��P�Ⱦࡣ
        /// ����������£����ص�ΪC + r * U ������U�Ǵ�ֱ��N��������
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // ��̬�����ѯ�ĺ������㡣
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        struct DistanceInfo
        {
            Real m_SqrDistance;
            int m_NumClosestCircle;
            Vector3D m_ClosestCircle;

            DistanceInfo(Real sqrDistance, int numClosestCircle, const Vector3D& closestCircle) noexcept;
        };

        /// mClosestLine[i]�����롣 mClosestCircle[i]�������
        /// ��������֮���ƽ�����롣 mNumClosest��ֵ����Ϊ1��INT_MAX�� ����Ǻ��ߣ�������Բ�㶼��mClosestLine[i]�Ⱦࡣ
        DistanceInfo SqrDistancePointCircle(const Vector3D& closestLine) const;

        // ������F(s) = s + m2b2 - r * m0sqr * s / sqrt(m0sqr * s * s + b1sqr)�ֳ�ָ�����[smin��smax]��
        static Real BisectF(Real lineDotDiff, Real radiusMultiplyDot, Real dot, Real diffCrossNormalDot, Real smin, Real smax);

        Line3 m_Line;
        Circle3 m_Circle;       
    };

    using FloatDistanceLine3Circle3 = DistanceLine3Circle3<float>;
    using DoubleDistanceLine3Circle3 = DistanceLine3Circle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_H
