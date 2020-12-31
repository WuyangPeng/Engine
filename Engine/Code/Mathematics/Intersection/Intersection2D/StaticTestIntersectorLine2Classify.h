///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/23 15:06)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Classify : public StaticIntersector<Real, Vector2D>
    {
    public:
        using ClassType = StaticTestIntersectorLine2Classify<Real>;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

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
        StaticTestIntersectorLine2Classify(const Vector2D& lhsOrigin, const Vector2D& lhsDirection, const Vector2D& rhsOrigin,
                                           const Vector2D& rhsDirection, bool isCalculateParameter = true, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] Real GetParameter0() const noexcept;
        [[nodiscard]] Real GetParameter1() const noexcept;

    private:
        void Test(const Vector2D& lhsOrigin, const Vector2D& lhsDirection, const Vector2D& rhsOrigin, const Vector2D& rhsDirection, bool isCalculateParameter);

    private:
        Real m_Parameter0;
        Real m_Parameter1;
    };

    using FloatStaticTestIntersectorLine2Classify = StaticTestIntersectorLine2Classify<float>;
    using DoubleStaticTestIntersectorLine2Classify = StaticTestIntersectorLine2Classify<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_CLASSIFY_H
