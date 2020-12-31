///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/02 16:18)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_H

#include "Mathematics/MathematicsDll.h"

#include "CylinderFit3UpdateData.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE CylinderFit3Update final
    {
    public:
        using ClassType = CylinderFit3Update<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Points = std::vector<Vector3D>;
        using CylinderFit3UpdateData = CylinderFit3UpdateData<Real>;
        using UpdateData = std::vector<CylinderFit3UpdateData>;

    public:
        CylinderFit3Update(const Points& points, const Vector3D& guessCenter, const Vector3D& guessAxis, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        void Update(int maxLoopTime);

        // 返回准确度
        [[nodiscard]] Real GetExactly() const noexcept;

        [[nodiscard]] Real GetInverseRadiusSqrare() const noexcept;
        [[nodiscard]] const Vector3D GetAxis() const noexcept;
        [[nodiscard]] const Vector3D GetCenter() const noexcept;

    private:
        void CalculateUpdateData();
        void UpdateInverseRadiusSqrare() noexcept(g_Assert < 2 || g_MathematicsAssert < 2);
        void UpdateDirection();
        void UpdateCenter();

    private:
        Points m_Points;
        Real m_InverseRadiusSqrare;
        Vector3D m_Axis;
        Vector3D m_Center;
        Real m_Exactly;
        Real m_Epsilon;
        UpdateData m_UpdateData;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_H
