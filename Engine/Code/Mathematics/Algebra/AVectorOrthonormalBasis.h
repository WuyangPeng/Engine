///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 14:49)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMAL_BASIS_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMAL_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "AVector.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalBasis final
    {
    public:
        using ClassType = AVectorOrthonormalBasis<Real>;
        using Math = Math<Real>;
        using AVector = AVector<Real>;

    public:
        explicit AVectorOrthonormalBasis(const AVector& nonzeroVector, bool isUnit, Real epsilon = Math::GetZeroTolerance());

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

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMAL_BASIS_H
