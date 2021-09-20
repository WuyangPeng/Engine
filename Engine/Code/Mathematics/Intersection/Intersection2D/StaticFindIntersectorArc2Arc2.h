///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/18 15:04)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects2D/Arc2.h"
#include "Mathematics/Objects2D/Objects2DFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorArc2Arc2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersectorArc2Arc2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersectorArc2Arc2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersectorArc2Arc2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorArc2Arc2 : public StaticIntersector<Real, Vector2D>
    {
    public:
        using StaticFindIntersectorArc2Arc2Impl = StaticFindIntersectorArc2Arc2Impl<Real>;
 

        TYPE_DECLARE(StaticFindIntersectorArc2Arc2);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using ParentType = StaticIntersector<Real, Vector2D>;
        using Vector2D = Vector2D<Real>;
        using Circle2 = Circle2<Real>;
        using Arc2 = Arc2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorArc2Arc2(const Arc2& lhsArc, const Arc2& rhsArc, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Arc2 GetLhsArc() const noexcept;
        [[nodiscard]] const Arc2 GetRhsArc() const noexcept;

        // �ཻ��Ϊ��̬�����ཻ��ѯ��
        // m_Point�Ĵ�СΪ0,1��2��
        // ��0 < m_Point.size()ʱ������ȡ�����ཻ���͡�
        //   IntersectionType::Point:  ��ͬ���ཻ��
        //   IntersectionType::Other:  Բ���ص��㳬��һ�㡣
        // �ཻ����GetIntersectionArc()�� m_Point����Ч�ġ�
        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector2D GetPoint(int index) const;
        [[nodiscard]] const Arc2 GetIntersectionArc() const;

    private:
        // ��̬�����ཻ��ѯ��
        void Find();

    private:
        PackageType impl;
    };

    using FloatStaticFindIntersectorArc2Arc2 = StaticFindIntersectorArc2Arc2<float>;
    using DoubleStaticFindIntersectorArc2Arc2 = StaticFindIntersectorArc2Arc2<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_H
