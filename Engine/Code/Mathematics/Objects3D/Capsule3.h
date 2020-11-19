///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 15:38)

#ifndef MATHEMATICS_OBJECTS3D_CAPSULE3_H
#define MATHEMATICS_OBJECTS3D_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Segment3.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Capsule3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Capsule3<Real>;
        using Segment3 = Segment3<Real>;

    public:
        // ��������һ����߶��еȾ�ĵ㣬 �������뱻��Ϊ�뾶��
        Capsule3(const Segment3& segment, Real radius) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Segment3 GetSegment() const noexcept;
        [[nodiscard]] Real GetRadius() const noexcept;

    private:
        Segment3 m_Segment;
        Real m_Radius;
    };

    using FloatCapsule3 = Capsule3<float>;
    using DoubleCapsule3 = Capsule3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_CAPSULE3_H
