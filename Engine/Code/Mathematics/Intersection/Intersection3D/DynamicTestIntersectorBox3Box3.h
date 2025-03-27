///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:01)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicTestIntersectorBox3Box3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicTestIntersectorBox3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Box3 = Box3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::MathType;

    public:
        DynamicTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Box3 GetBox0() const noexcept;
        NODISCARD Box3 GetBox1() const noexcept;

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
        NODISCARD Separated IsSeparated(Real min0, Real max0, Real min1, Real max1, Real speed, Real tmax, Real tlast) noexcept;

    private:
        Box3 box0;
        Box3 box1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H
