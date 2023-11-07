///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 17:33)

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
        // 胶囊体是一组从线段中等距的点， 公共距离被称为半径。
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
