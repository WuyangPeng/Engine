///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:40)

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

        using MathType = Math<Real>;
        using AVectorType = AVector<Real>;

    public:
        explicit AVectorOrthonormalBasis(const AVectorType& nonzeroVector, bool isUnit, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD AVectorType GetUVector() const noexcept;
        NODISCARD AVectorType GetVVector() const noexcept;
        NODISCARD AVectorType GetWVector() const noexcept;

    private:
        void Generate();
        void GenerateOnXOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3);
        void GenerateOnYOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3);

    private:
        bool isUnit;
        AVectorType uVector;
        AVectorType vVector;
        AVectorType wVector;
        Real epsilon;
    };

    using AVectorOrthonormalBasisF = AVectorOrthonormalBasis<float>;
    using AVectorOrthonormalBasisD = AVectorOrthonormalBasis<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMAL_BASIS_H
