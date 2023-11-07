///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 15:16)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMAL_BASIS_H
#define MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMAL_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3OrthonormalBasis final
    {
    public:
        using ClassType = Vector3OrthonormalBasis<Real>;

        using Vector3 = Vector3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = Math<Real>;

    public:
        explicit Vector3OrthonormalBasis(const Vector3& nonzeroVector, bool isUnit, Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetUVector() const noexcept;
        NODISCARD Vector3 GetVVector() const noexcept;
        NODISCARD Vector3 GetWVector() const noexcept;

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

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMAL_BASIS_H
