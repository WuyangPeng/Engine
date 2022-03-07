///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/08 14:40)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real, bool Robust = false>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3Orthonormalize final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector3Orthonormalize<Real, Robust>;
        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using ContainerType = std::vector<Vector3>;

    public:
        // Gram-Schmidt正交化.
        // 以线性无关的向量U、V和W，来计算一个正交组（单位长度，相互垂直）。
        Vector3Orthonormalize(const Vector3& uVector, const Vector3& vVector, const Vector3& wVector, const Real epsilon = Math::GetZeroTolerance());

        explicit Vector3Orthonormalize(const ContainerType& vectors, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD const Vector3 GetUVector() const noexcept;
        NODISCARD const Vector3 GetVVector() const noexcept;
        NODISCARD const Vector3 GetWVector() const noexcept;

    private:
        void Generate();

    private:
        Vector3 uVector;
        Vector3 vVector;
        Vector3 wVector;
        Real epsilon;
    };

    using Vector3OrthonormalizeF = Vector3Orthonormalize<float>;
    using Vector3OrthonormalizeD = Vector3Orthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_H
