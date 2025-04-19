/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.0 (2025/03/27 17:46)

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

        using Vector3Type = Vector3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = Math<Real>;

    public:
        explicit Vector3OrthonormalBasis(const Vector3Type& nonzeroVector, bool isUnit, Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3Type GetUVector() const noexcept;
        NODISCARD Vector3Type GetVVector() const noexcept;
        NODISCARD Vector3Type GetWVector() const noexcept;

    private:
        void Generate() noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void GenerateOnXOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3);
        void GenerateOnYOrZIsMax() noexcept(gAssert < 3 || gMathematicsAssert < 3);

    private:
        bool isUnit;
        Vector3Type uVector;
        Vector3Type vVector;
        Vector3Type wVector;
        Real epsilon;
    };

    using Vector3OrthonormalBasisF = Vector3OrthonormalBasis<float>;
    using Vector3OrthonormalBasisD = Vector3OrthonormalBasis<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMAL_BASIS_H
