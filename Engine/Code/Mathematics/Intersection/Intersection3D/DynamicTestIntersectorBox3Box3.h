///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/24 17:50)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicTestIntersectorBox3Box3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicTestIntersectorBox3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Box3 GetBox0() const noexcept;
        [[nodiscard]] const Box3 GetBox1() const noexcept;

    private:
        using Separated = std::pair<bool, Real>;

    private:
        /// ��̬�����ཻ��ѯ�� �����һ���ཻʱ�䣨����У������������й��ཻ�����κ���Ϣ��
        void Test();

        /// ֧�ֶ�̬��ѯ�� �������Ǳ�ڷָ����ϵ�ͶӰ��������������ٶ��Լ���ѯ�����ʱ�䡣
        /// ����ǵ�һ�η���ʧ�ܣ����һ�������Ÿ����ٴο�ʼ���롣
        /// ��ĳ��������˵������ǡ����¡�������Ǳ�ڵķ����ᣬ�ú������ظ����á�
        /// ���������һ�δ��������һ��ʱ�Ÿ��¡� �����ϴ����С���ϴ�����ʱ�Ÿ��¡�
        ///
        /// ע�⣺����ʹ��BoxBoxAxisTest����������box-box��������Ż�box�ڸ������ϵ�ͶӰ��
        /// �ú�����Ч����BoxBoxAxisTest������û���᷽����ٶȵĵ���Ի���ٶȡ� �Ż���ͨ�����ٵĲ����������ٶȡ�
        [[nodiscard]] Separated IsSeparated(Real min0, Real max0, Real min1, Real max1, Real speed, Real tmax, Real tlast) noexcept;

    private:
        Box3 m_Box0;
        Box3 m_Box1;
    };

    using FloatDynamicTestIntersectorBox3Box3 = DynamicTestIntersectorBox3Box3<float>;
    using DoubleDynamicTestIntersectorBox3Box3 = DynamicTestIntersectorBox3Box3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H
