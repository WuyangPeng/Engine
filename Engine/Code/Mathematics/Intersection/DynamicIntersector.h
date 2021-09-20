///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/16 11:32)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector.h"

namespace Mathematics
{
    template <typename Real, template <typename> class Vector>
    class DynamicIntersectorImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicIntersectorImpl<float, Vector2D>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicIntersectorImpl<double, Vector2D>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicIntersectorImpl<float, Vector3D>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicIntersectorImpl<double, Vector3D>>;

    template <typename Real, template <typename> class Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicIntersectorImpl<Real, Vector>>;

    // ��̬�ཻ��ѯ��Ĭ��ʵ�ַ��ء�false����
    // Find��ѯ����һ����һ�νӴ����ཻ���ϡ�
    // �����ฺ���ṩ����,��Ϊ���ϵ����������ڶ������͡�
    template <typename Real, template <typename> class Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicIntersector : public Intersector<Real, Vector>
    {
    public:
        using DynamicIntersectorImpl = DynamicIntersectorImpl<Real, Vector>;

    public:
        void Swap(DynamicIntersector& rhs) noexcept;

    public:
        TYPE_DECLARE(DynamicIntersector);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~DynamicIntersector() noexcept = default;
        DynamicIntersector(const DynamicIntersector& rhs);
        DynamicIntersector& operator=(const DynamicIntersector& rhs);
        DynamicIntersector(DynamicIntersector&& rhs) noexcept;
        DynamicIntersector& operator=(DynamicIntersector&& rhs) noexcept;

        using ClassType = DynamicIntersector<Real, Vector>;
        using ParentType = Intersector<Real, Vector>;
        using Math = typename ParentType::Math;
        using VectorType = typename ParentType::VectorType;

    public:
        explicit DynamicIntersector(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ���������ڵ�һ�νӴ�ʱ��̬�ཻ��ѯ��ʱ�䡣
        [[nodiscard]] Real GetContactTime() const noexcept;
        [[nodiscard]] Real GetTMax() const noexcept;
        [[nodiscard]] const VectorType GetLhsVelocity() const noexcept;
        [[nodiscard]] const VectorType GetRhsVelocity() const noexcept;

    protected:
        void SetContactTime(Real contactTime) noexcept;

    private:
        using ImplPtr = std::shared_ptr<ImplType>;
    private:
        ImplPtr impl;
    };

    using FloatDynamicIntersector2D = DynamicIntersector<float, Vector2D>;
    using FloatDynamicIntersector3D = DynamicIntersector<float, Vector3D>;
    using DoubleDynamicIntersector2D = DynamicIntersector<double, Vector2D>;
    using DoubleDynamicIntersector3D = DynamicIntersector<double, Vector3D>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H
