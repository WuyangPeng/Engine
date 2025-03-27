///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 15:01)

#ifndef MATHEMATICS_SPHERE_COORDINATES_H
#define MATHEMATICS_SPHERE_COORDINATES_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/BaseFwd.h"

// 球体坐标系统
namespace Mathematics
{
    template <typename Real>
    requires std::is_floating_point_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SphereCoordinates final
    {
    public:
        using ClassType = SphereCoordinates<Real>;

        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;

    public:
        constexpr SphereCoordinates() noexcept
            : r{}, theta{}, phi{}
        {
        }

        SphereCoordinates(Real r, Real theta, Real phi);

        NODISCARD bool IsValid() const noexcept;

        void SetCartesian(Real xCoordinate, Real yCoordinate, Real zCoordinate) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD Vector3 GetCartesian() const noexcept;

        NODISCARD constexpr Real GetR() const noexcept
        {
            return r;
        }

        NODISCARD constexpr Real GetTheta() const noexcept
        {
            return theta;
        }

        NODISCARD constexpr Real GetPhi() const noexcept
        {
            return phi;
        }

        void SetR(Real radius);

        void SetTheta(Real aTheta);

        void SetPhi(Real aPhi);

    private:
        Real r;
        Real theta;
        Real phi;
    };
}

#endif  // MATHEMATICS_SPHERE_COORDINATES_H