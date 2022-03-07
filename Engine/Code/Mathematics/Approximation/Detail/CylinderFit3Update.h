///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/18 18:22)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_H

#include "Mathematics/MathematicsDll.h"

#include "CylinderFit3UpdateData.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE CylinderFit3Update final
    {
    public:
        using ClassType = CylinderFit3Update<Real>;
        using Vector3 = Vector3<Real>;
        using Math = Math<Real>;
        using Points = std::vector<Vector3>;
        using CylinderFit3UpdateData = CylinderFit3UpdateData<Real>;
        using UpdateData = std::vector<CylinderFit3UpdateData>;

    public:
        CylinderFit3Update(const Points& points, const Vector3& guessCenter, const Vector3& guessAxis, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        void Update(int maxLoopTime);

        // 返回准确度
        NODISCARD Real GetExactly() const noexcept;

        NODISCARD Real GetInverseRadiusSqrare() const noexcept;
        NODISCARD Vector3 GetAxis() const noexcept;
        NODISCARD Vector3 GetCenter() const noexcept;

    private:
        void CalculateUpdateData();
        void UpdateInverseRadiusSqrare() noexcept(g_Assert < 2 || g_MathematicsAssert < 2);
        void UpdateDirection();
        void UpdateCenter();

    private:
        Points points;
        Real inverseRadiusSqrare;
        Vector3 axis;
        Vector3 center;
        Real exactly;
        Real epsilon;
        UpdateData updateData;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_H
