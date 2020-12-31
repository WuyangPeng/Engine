///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 18:42)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_H
#define MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
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
        QuaternionFactor(const Quaternion& quaternion, QuaternionFactorFlags flag) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetSinX() const noexcept;
        [[nodiscard]] Real GetSinY() const noexcept;
        [[nodiscard]] Real GetSinZ() const noexcept;
        [[nodiscard]] Real GetCosX() const noexcept;
        [[nodiscard]] Real GetCosY() const noexcept;
        [[nodiscard]] Real GetCosZ() const noexcept;

    private:
        // 系数为 (cx + sx * i) * (cy + sy * j) * (cz + sz * k).
        void FactorXYZ() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 系数为 (cx + sx * i) * (cz + sz * k) * (cy + sy * j).
        void FactorXZY() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 系数为 (cy + sy * j) * (cz + sz * k) * (cx + sx * i).
        void FactorYZX() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 系数为 (cy + sy * j) * (cx + sx * i) * (cz + sz * k).
        void FactorYXZ() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 系数为 (cz + sz * k) * (cx + sx * i) * (cy + sy * j).
        void FactorZXY() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 系数为 (cz + sz * k) * (cy + sy * j) * (cx + sx * i).
        void FactorZYX() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

    private:
        Quaternion m_Quaternion;
        Real m_SinX;
        Real m_CosX;
        Real m_SinY;
        Real m_CosY;
        Real m_SinZ;
        Real m_CosZ;
    };

    using FloatQuaternionFactor = QuaternionFactor<float>;
    using DoubleQuaternionFactor = QuaternionFactor<double>;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_H
