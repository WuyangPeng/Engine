///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:24)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE GreatArcFit3Item final
    {
    public:
        using ClassType = GreatArcFit3Item<Real>;

        using Vector3 = Vector3<Real>;

    public:
        explicit GreatArcFit3Item(const Vector3& uVector, const Vector3& vVector, const Vector3& point) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetUDot() const noexcept;
        NODISCARD Real GetVDot() const noexcept;
        NODISCARD Real GetAngle() const noexcept;

    private:
        Real uDot;
        Real vDot;
        Real angle;
    };

    // 支持排序。
    template <typename Real>
    NODISCARD bool operator<(const GreatArcFit3Item<Real>& lhs, const GreatArcFit3Item<Real>& rhs) noexcept;
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_H
