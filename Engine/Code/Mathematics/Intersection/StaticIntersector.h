///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/16 11:09)

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
        StaticIntersector& operator=(const StaticIntersector& rhs) noexcept = default;
        StaticIntersector(StaticIntersector&& rhs) noexcept = default;
        StaticIntersector& operator=(StaticIntersector&& rhs) noexcept = default;
#include STSTEM_WARNING_POP

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };

    using FloatStaticIntersector2D = StaticIntersector<float, Vector2D>;
    using FloatStaticIntersector3D = StaticIntersector<float, Vector3D>;
    using DoubleStaticIntersector2D = StaticIntersector<double, Vector2D>;
    using DoubleStaticIntersector3D = StaticIntersector<double, Vector3D>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H
