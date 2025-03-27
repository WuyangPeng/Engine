///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Classify : public StaticIntersector<Real, Vector2>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Classify<Real>;
        using ParentType = StaticIntersector<Real, Vector2>;

        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Math = typename ParentType::MathType;

    public:
        // ���Է����ķ��ࡣ
        // ����P0 + s * D0��P1 + s * D1��
        // ���߲��ཻʱ������ֵΪIntersectionType::Empty��
        // ����ֻ��Ψһ�Ľ���ʱ������ֵΪIntersectionType::Point��
        // �����ص�ʱ������ֵΪIntersectionType::Line��
        // ��ֻ��Ψһ�Ľ���ʱ����ΪP0 + s[0] * D0 = P1 + s[1] * D1��
        // 'epsilon'���������ڲ���ƽ�л�ֱ�����ķǸ�����
        // ��Test() �� Find() ������ʹ�õ�ֵ��m_Epsilon��
        // �������֪��s[]ֵ������isCalculateParameterΪ'true'��
        // ������������-���ߣ�ֱ��-ֱ�ߺ��߶�-�߶ε��ཻ���Թ���
        StaticTestIntersectorLine2Classify(const Vector2& lhsOrigin,
                                           const Vector2& lhsDirection,
                                           const Vector2& rhsOrigin,
                                           const Vector2& rhsDirection,
                                           bool isCalculateParameter = true,
                                           const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Real GetParameter0() const noexcept;
        NODISCARD Real GetParameter1() const noexcept;

    private:
        void Test(const Vector2& lhsOrigin, const Vector2& lhsDirection, const Vector2& rhsOrigin, const Vector2& rhsDirection, bool isCalculateParameter);

    private:
        Real parameter0;
        Real parameter1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H
