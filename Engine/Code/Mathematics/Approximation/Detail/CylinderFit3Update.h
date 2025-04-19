///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:23)

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

        using Vector3Type = Vector3<Real>;
        using MathType = Math<Real>;
        using Points = std::vector<Vector3Type>;
        using CylinderFit3UpdateDataType = CylinderFit3UpdateData<Real>;
        using UpdateData = std::vector<CylinderFit3UpdateDataType>;

    public:
        CylinderFit3Update(Points points, const Vector3Type& guessCenter, const Vector3Type& guessAxis, const Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Update(int maxLoopTime);

        // 返回准确度
        NODISCARD Real GetExactly() const noexcept;

        NODISCARD Real GetInverseRadiusSquare() const noexcept;
        NODISCARD Vector3Type GetAxis() const noexcept;
        NODISCARD Vector3Type GetCenter() const noexcept;

    private:
        void CalculateUpdateData();
        void UpdateInverseRadiusSquare() noexcept(gAssert < 2 || gMathematicsAssert < 2);
        void UpdateDirection();
        void UpdateCenter();

    private:
        Points points;
        Real inverseRadiusSquare;
        Vector3Type axis;
        Vector3Type center;
        Real exactly;
        Real epsilon;
        UpdateData updateData;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_H
