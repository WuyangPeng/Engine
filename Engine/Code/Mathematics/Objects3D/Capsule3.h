///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/10 14:58)

#ifndef MATHEMATICS_OBJECTS3D_CAPSULE3_H
#define MATHEMATICS_OBJECTS3D_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Segment3.h"
#include "Mathematics/Algebra/Vector3.h"

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

        NODISCARD Segment3 GetSegment() const noexcept;
        NODISCARD Real GetRadius() const noexcept;

    private:
        Segment3 segment;
        Real radius;
    };

    using Capsule3F = Capsule3<float>;
    using Capsule3D = Capsule3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_CAPSULE3_H
