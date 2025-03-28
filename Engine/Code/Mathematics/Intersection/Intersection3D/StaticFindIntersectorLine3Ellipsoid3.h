///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:06)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Ellipsoid3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorLine3Ellipsoid3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Ellipsoid3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Line3Type = Line3<Real>;
        using Ellipsoid3Type = Ellipsoid3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorLine3Ellipsoid3(const Line3Type& line, const Ellipsoid3Type& ellipsoid, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3Type GetLine() const noexcept;
        NODISCARD Ellipsoid3Type GetEllipsoid() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3Type GetPoint(int index) const;

        /// С��ֵ���ڲ���������йصĶ��η��̵��б�ʽ��Q(t) = a2 * t^2 + 2 * a1 * t + a0��
        /// �б�ʽΪD = a1 * a1 - a0 * a2��
        ///  Q(t)��D < 0ʱû��ʵֵ������D = 0ʱ��һ��ʵֵ������D > 0ʱ������ʵֵ����
        /// �����߼��漰�û��������ֵ��if(D < negThreshold){ �޸����޽�����}��
        /// else if (D > posThreshold) { ����������������}
        ///  else { һ������һ��������}��ֵ��Ĭ��ֵΪ�㣬�������Խ�������Ϊ���� ��negThreshold <= 0 �� posThreshold >= 0����
        /// ��ǰ������ֵ��Ӳ����Ϊ�㡣 ����ֵ��Ӳ����ΪMath<Real>::GetZeroTolerance()��
        /// ����ֵ��������ĳЩ���ݼ�����������Բ��Χ�ܴ�ʱ��������Ĭ��ֵΪ�㡣
        void SetNegativeThreshold(Real negThreshold);
        NODISCARD Real GetNegativeThreshold() const noexcept;
        void SetPositiveThreshold(Real posThreshold);
        NODISCARD Real GetPositiveThreshold() const noexcept;

    private:
        void Find();

    private:
        Line3Type line;
        Ellipsoid3Type ellipsoid;

        int quantity;
        Vector3Type point0;
        Vector3Type point1;

        /// ���ڲ����б�ʽ�� Ĭ��ֵΪ�㡣 �����Խ�����ֵ����Ϊ��С��������������ֵ����Ϊ��С��������
        Real negativeThreshold;
        Real positiveThreshold;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_H
