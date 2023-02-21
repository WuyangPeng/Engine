///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/08 13:56)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_H
#define MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Quaternion.h"
#include "Flags/QuaternionFlags.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QuaternionFactor final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = QuaternionFactor<Real>;
        using Quaternion = Quaternion<Real>;
        using Math = Math<Real>;

    public:
        QuaternionFactor(const Quaternion& quaternion, QuaternionFactorFlags flag) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetSinX() const noexcept;
        NODISCARD Real GetSinY() const noexcept;
        NODISCARD Real GetSinZ() const noexcept;
        NODISCARD Real GetCosX() const noexcept;
        NODISCARD Real GetCosY() const noexcept;
        NODISCARD Real GetCosZ() const noexcept;

    private:
        // 系数为 (cx + sx * i) * (cy + sy * j) * (cz + sz * k).
        void FactorXYZ() noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 系数为 (cx + sx * i) * (cz + sz * k) * (cy + sy * j).
        void FactorXZY() noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 系数为 (cy + sy * j) * (cz + sz * k) * (cx + sx * i).
        void FactorYZX() noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 系数为 (cy + sy * j) * (cx + sx * i) * (cz + sz * k).
        void FactorYXZ() noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 系数为 (cz + sz * k) * (cx + sx * i) * (cy + sy * j).
        void FactorZXY() noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 系数为 (cz + sz * k) * (cy + sy * j) * (cx + sx * i).
        void FactorZYX() noexcept(gAssert < 3 || gMathematicsAssert < 3);

    private:
        Quaternion quaternion;
        Real sinX;
        Real cosX;
        Real sinY;
        Real cosY;
        Real sinZ;
        Real cosZ;
    };

    using QuaternionFactorF = QuaternionFactor<float>;
    using QuaternionFactorD = QuaternionFactor<double>;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_H
