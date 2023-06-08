///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 19:14)

#ifndef MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H

#include "Intersector.h"

namespace Mathematics
{
    // ��̬�ཻ��ѯ��Ĭ��ʵ�ַ��ء�false����Find��ѯ����һ���ཻ���ϡ�
    // �����ฺ���ṩ����,��Ϊ���ϵ����������ڶ������͡�
    template <typename Real, template <typename> class Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticIntersector : public Intersector<Real, Vector>
    {
    public:
        using ClassType = StaticIntersector<Real, Vector>;
        using ParentType = Intersector<Real, Vector>;
        using Math = typename ParentType::Math;

    public:
        explicit StaticIntersector(const Real epsilon = Math::GetZeroTolerance()) noexcept;
        ~StaticIntersector() noexcept = 0;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

        StaticIntersector(const StaticIntersector& rhs) noexcept = default;
        StaticIntersector(StaticIntersector&& rhs) noexcept = default;

#include STSTEM_WARNING_POP

        StaticIntersector& operator=(const StaticIntersector& rhs) noexcept = default;
        StaticIntersector& operator=(StaticIntersector&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };

    using StaticIntersector2F = StaticIntersector<float, Vector2>;
    using StaticIntersector3F = StaticIntersector<float, Vector3>;
    using StaticIntersector2D = StaticIntersector<double, Vector2>;
    using StaticIntersector3D = StaticIntersector<double, Vector3>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H
