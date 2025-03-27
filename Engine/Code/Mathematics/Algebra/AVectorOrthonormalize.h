///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:40)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AVector.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVectorOrthonormalize final
    {
    public:
        using ClassType = AVectorOrthonormalize<Real>;

        using MathType = Math<Real>;
        using AVectorType = AVector<Real>;

    public:
        // Gram-Schmidt正交化。
        // 以线性无关的向量U、V和W，来计算一个正交组（单位长度，相互垂直）。
        AVectorOrthonormalize(const AVectorType& uVector, const AVectorType& vVector, const AVectorType& wVector, Real epsilon = MathType::GetZeroTolerance());

        explicit AVectorOrthonormalize(const std::vector<AVectorType> vectors, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD AVectorType GetUVector() const noexcept;
        NODISCARD AVectorType GetVVector() const noexcept;
        NODISCARD AVectorType GetWVector() const noexcept;

    private:
        void Generate();

    private:
        AVectorType uVector;
        AVectorType vVector;
        AVectorType wVector;
        Real epsilon;
    };

    using AVectorOrthonormalizeF = AVectorOrthonormalize<float>;
    using AVectorOrthonormalizeD = AVectorOrthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_ORTHONORMALIZE_H
