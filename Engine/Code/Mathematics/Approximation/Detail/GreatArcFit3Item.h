///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 18:35)

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

    // ֧������
    template <typename Real>
    NODISCARD bool operator<(const GreatArcFit3Item<Real>& lhs, const GreatArcFit3Item<Real>& rhs) noexcept;
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_H
