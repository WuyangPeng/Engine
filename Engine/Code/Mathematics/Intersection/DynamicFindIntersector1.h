///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 16:03)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector1.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersector1 final : public Intersector1<Real>
    {
    public:
        using ClassType = DynamicFindIntersector1<Real>;
        using ParentType = Intersector1<Real>;

        using Math = typename ParentType::Math;
        using IntersectionsType = std::vector<Real>;

    public:
        DynamicFindIntersector1(Real u0, Real u1, Real v0, Real v1, Real tMax, Real speedU, Real speedV, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool IsIntersection() const noexcept final;

        // ��̬�ཻ��ѯ���������䴦�ڵ�һ��/���һ�νӴ���ʱ�䡣
        NODISCARD Real GetFirstTime() const;
        NODISCARD Real GetLastTime() const;

        // �йؽ�������Ϣ��
        // �ཻ��Ϊ0�����䲻�ص�����
        // 1������߽��ཻ����2�������������ཻ����
        NODISCARD int GetNumIntersections() const;
        NODISCARD Real GetIntersection(int index) const;

    private:
        void Find(Real tMax, Real speedU, Real speedV);

    private:
        // �й��ཻ����Ϣ��
        Real firstTime;
        Real lastTime;

        IntersectionsType intersections;
    };

    using DynamicFindIntersector1F = DynamicFindIntersector1<float>;
    using DynamicFindIntersector1D = DynamicFindIntersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H
