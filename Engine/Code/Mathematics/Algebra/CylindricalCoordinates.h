///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:43)

#ifndef MATHEMATICS_CYLINDRICAL_COORDINATES_H
#define MATHEMATICS_CYLINDRICAL_COORDINATES_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/BaseFwd.h"

// 圆柱坐标系统
namespace Mathematics
{
    template <typename Real>
    requires std::is_floating_point_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CylindricalCoordinates final
    {
    public:
        using ClassType = CylindricalCoordinates<Real>;

        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;

    public:
        constexpr CylindricalCoordinates() noexcept
            : r{}, phi{}, y{}
        {
        }

        CylindricalCoordinates(Real r, Real phi, Real y);

        NODISCARD bool IsValid() const noexcept;

        void SetCartesian(Real xCoordinate, Real yCoordinate, Real zCoordinate) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD Vector3 GetCartesian() const noexcept;

        NODISCARD constexpr Real GetR() const noexcept
        {
            return r;
        }

        NODISCARD constexpr Real GetPhi() const noexcept
        {
            return phi;
        }

        NODISCARD constexpr Real GetY() const noexcept
        {
            return y;
        }

        void SetR(Real radius);

        void SetPhi(Real phi);

        constexpr void SetY(Real yCoordinate) noexcept
        {
            y = yCoordinate;
        }

    private:
        Real r;
        Real phi;
        Real y;
    };
}

#endif  // MATHEMATICS_CYLINDRICAL_COORDINATES_H