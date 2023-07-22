///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/14 22:21)

#ifndef MATHEMATICS_CYLINDRICAL_COORDINATES_H
#define MATHEMATICS_CYLINDRICAL_COORDINATES_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/BaseFwd.h"

// Բ������ϵͳ
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
            : r{}, ��{}, y{}
        {
        }

        CylindricalCoordinates(Real r, Real ��, Real y);

        NODISCARD bool IsValid() const noexcept;

        void SetCartesian(Real xCoordinate, Real yCoordinate, Real zCoordinate) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD Vector3 GetCartesian() const noexcept;

        NODISCARD constexpr Real GetR() const noexcept
        {
            return r;
        }

        NODISCARD constexpr Real GetPhi() const noexcept
        {
            return ��;
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
        Real ��;
        Real y;
    };
}

#endif  // MATHEMATICS_CYLINDRICAL_COORDINATES_H