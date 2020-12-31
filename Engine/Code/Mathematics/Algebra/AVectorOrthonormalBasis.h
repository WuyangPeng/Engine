///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/02 17:21)

#ifndef MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_H
#define MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "AVector.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalBasis final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AVectorOrthonormalBasis<Real>;
        using Math = Math<Real>;
        using AVector = AVector<Real>;

    public:
        explicit AVectorOrthonormalBasis(const AVector& nonzeroVector, bool isUnit, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const AVector GetUVector() const noexcept;
        [[nodiscard]] const AVector GetVVector() const noexcept;
        [[nodiscard]] const AVector GetWVector() const noexcept;

    private:
        void Generate();
        void GenerateOnXOrZIsMax() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        void GenerateOnYOrZIsMax() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

    private:
        bool m_IsUnit;
        AVector m_UVector;
        AVector m_VVector;
        AVector m_WVector;
        Real m_Epsilon;
    };

    using FloatAVectorOrthonormalBasis = AVectorOrthonormalBasis<float>;
    using DoubleAVectorOrthonormalBasis = AVectorOrthonormalBasis<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_H
