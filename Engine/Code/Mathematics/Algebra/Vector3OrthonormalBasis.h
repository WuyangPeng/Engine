///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/02 1:11)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMA_BASIS_H
#define MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMA_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3OrthonormalBasis final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector3OrthonormalBasis<Real>;
        using Vector3 = Vector3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = Math<Real>;

    public:
        explicit Vector3OrthonormalBasis(const Vector3& nonzeroVector, bool isUnit, const Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const Vector3 GetUVector() const noexcept;
        NODISCARD const Vector3 GetVVector() const noexcept;
        NODISCARD const Vector3 GetWVector() const noexcept;

    private:
        void Generate() noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void GenerateOnXOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3);
        void GenerateOnYOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3);

    private:
        bool isUnit;
        Vector3 uVector;
        Vector3 vVector;
        Vector3 wVector;
        Real epsilon;
    };

    using Vector3OrthonormalBasisF = Vector3OrthonormalBasis<float>;
    using Vector3OrthonormalBasisD = Vector3OrthonormalBasis<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMA_BASIS_H
