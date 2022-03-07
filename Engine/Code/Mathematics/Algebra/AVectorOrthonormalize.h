///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 11:17)

#ifndef MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AVector.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalize final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AVectorOrthonormalize<Real>;
        using Math = Math<Real>;
        using AVector = AVector<Real>;

    public:
        // Gram-Schmidt正交化。
        // 以线性无关的向量U、V和W，来计算一个正交组（单位长度，相互垂直）。
        AVectorOrthonormalize(const AVector& uVector, const AVector& vVector, const AVector& wVector, const Real epsilon = Math::GetZeroTolerance());

        explicit AVectorOrthonormalize(const std::vector<AVector> vectors, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD AVector GetUVector() const noexcept;
        NODISCARD AVector GetVVector() const noexcept;
        NODISCARD AVector GetWVector() const noexcept;

    private:
        void Generate();

    private:
        AVector uVector;
        AVector vVector;
        AVector wVector;
        Real epsilon;
    };

    using AVectorOrthonormalizeF = AVectorOrthonormalize<float>;
    using AVectorOrthonormalizeD = AVectorOrthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H
