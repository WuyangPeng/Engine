///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:42)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Query/QueryBase.h"

namespace Mathematics
{
    template <typename Real>
    class ContMinBox3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContMinBox3<Real>;

    public:
        ContMinBox3(const std::vector<Vector3<Real>>& points, Real epsilon, QueryType queryType);

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator Box3<Real>() const noexcept;

    private:
        Box3<Real> minBox;
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_MIN_BOX3_H
