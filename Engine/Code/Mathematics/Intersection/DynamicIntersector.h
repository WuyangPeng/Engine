///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/23 11:05)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector.h"

namespace Mathematics
{
    // ��̬�ཻ��ѯ��Ĭ��ʵ�ַ��ء�false����
    // Find��ѯ����һ����һ�νӴ����ཻ���ϡ�
    // �����ฺ���ṩ����,��Ϊ���ϵ����������ڶ������͡�
    template <typename Real, template <typename> class Vector>
    class DynamicIntersector : public Intersector<Real, Vector>
    {
    public:
        using ClassType = DynamicIntersector<Real, Vector>;
        using ParentType = Intersector<Real, Vector>;
        using Math = typename ParentType::Math;
        using VectorType = typename ParentType::VectorType;

    public:
        explicit DynamicIntersector(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ���������ڵ�һ�νӴ�ʱ��̬�ཻ��ѯ��ʱ�䡣
        NODISCARD Real GetContactTime() const noexcept;
        NODISCARD Real GetTMax() const noexcept;
        NODISCARD VectorType GetLhsVelocity() const noexcept;
        NODISCARD VectorType GetRhsVelocity() const noexcept;

    protected:
        void SetContactTime(Real newContactTime) noexcept;

    private:
        Real contactTime;
        Real tMax;
        VectorType lhsVelocity;
        VectorType rhsVelocity;
    };

    using DynamicIntersector2F = DynamicIntersector<float, Vector2>;
    using DynamicIntersector3F = DynamicIntersector<float, Vector3>;
    using DynamicIntersector2D = DynamicIntersector<double, Vector2>;
    using DynamicIntersector3D = DynamicIntersector<double, Vector3>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H
