///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 11:15)

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

        NODISCARD AVector GetUVector() const noexcept;
        NODISCARD AVector GetVVector() const noexcept;
        NODISCARD AVector GetWVector() const noexcept;

    private:
        void Generate();
        void GenerateOnXOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3);
        void GenerateOnYOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3);

    private:
        bool isUnit;
        AVector uVector;
        AVector vVector;
        AVector wVector;
        Real epsilon;
    };

    using AVectorOrthonormalBasisF = AVectorOrthonormalBasis<float>;
    using AVectorOrthonormalBasisD = AVectorOrthonormalBasis<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_H
