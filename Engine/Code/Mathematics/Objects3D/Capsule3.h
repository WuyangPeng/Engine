/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 10:26)

#ifndef MATHEMATICS_OBJECTS_3D_CAPSULE3_H
#define MATHEMATICS_OBJECTS_3D_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Segment3.h"
#include "Mathematics/Algebra/Vector3.h"

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

#endif  // MATHEMATICS_OBJECTS_3D_CAPSULE3_H
