///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/18 16:13)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Circle2.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorArc2Circle2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorArc2Circle2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorArc2Circle2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorArc2Circle2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorArc2Circle2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using StaticFindIntersectorArc2Circle2Impl = StaticFindIntersectorArc2Circle2Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(StaticFindIntersectorArc2Circle2);

        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Circle2 = Circle2<Real>;
        using Arc2 = Arc2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorArc2Circle2(const Arc2& arc, const Circle2& circle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Arc2 GetArc() const noexcept;
        [[nodiscard]] const Circle2 GetCircle() const noexcept;

        // �ཻ��Ϊ��̬�����ཻ��ѯ��
        // m_Point.size()Ϊ0,1��2��
        // ��0 < m_Point.size()ʱ������ȡ�����ཻ���͡�
        //   IntersectionType::Point:  m_Point ��ͬ���ཻ��
        //   IntersectionType::Other:  Բ����Բ�ϡ��ཻ����GetIntersectionArc()���ء�
        //   m_Point����Ч�ġ�
        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;
        [[nodiscard]] const Arc2 GetIntersectionArc() const;

    private:
        // ��̬�����ཻ��ѯ��
        void Find();

    private:
        IMPL_TYPE_DECLARE(StaticFindIntersectorArc2Circle2);
    };

    using FloatStaticFindIntersectorArc2Circle2 = StaticFindIntersectorArc2Circle2<float>;
    using DoubleStaticFindIntersectorArc2Circle2 = StaticFindIntersectorArc2Circle2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_H
