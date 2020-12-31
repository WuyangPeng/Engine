///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 14:36)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE GreatArcFit3Item final
    {
    public:
        using ClassType = GreatArcFit3Item<Real>;
        using Vector3D = Vector3D<Real>;

    public:
        explicit GreatArcFit3Item(const Vector3D& uVector, const Vector3D& vVector, const Vector3D& point);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetUDot() const;
        [[nodiscard]] Real GetVDot() const;
        [[nodiscard]] Real GetAngle() const;

    private:
        Real m_UDot;
        Real m_VDot;
        Real m_Angle;
    };

    // 支持排序。
    template <typename Real>
    bool operator<(const GreatArcFit3Item<Real>& lhs, const GreatArcFit3Item<Real>& rhs);
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ITEM_H
