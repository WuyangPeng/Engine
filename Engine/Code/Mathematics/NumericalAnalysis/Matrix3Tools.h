/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MATRIX3_TOOLS_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MATRIX3_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "PolarDecompositionValue.h"
#include "QDUDecompositionValue.h"
#include "SingularValue.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/MathematicsFwd.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3Tools final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix3Tools<Real>;

        using Matrix3Type = Matrix3<Real>;
        using QDUDecompositionValueType = QDUDecompositionValue<Real>;
        using SingularValueType = SingularValue<Real>;
        using PolarDecompositionValueType = PolarDecompositionValue<Real>;

    public:
        explicit Matrix3Tools(const Matrix3Type& matrix) noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        // 奇异值分解，M = L * D * Transpose(Real)，其中L和Real是正交的，
        // D是对角矩阵，其对角元素是非负的。
        // 返回值第一部分为left, 第二部分为diag,第三部分为rightTranspose
        NODISCARD SingularValueType SingularValueDecomposition() const;

        // 极分解，M = Q * S，其中Q是正交的，S是对称的。
        // 这里使用奇异值分解：
        // M = L * D * Transpose(Real) = (L * Transpose(Real)) * (Real * D * Transpose(Real)) = Q * S
        // 其中Q = L * Transpose(Real)和S = Real * D * Transpose(Real)。
        // 返回值第一部分为Q，第二部分为S
        NODISCARD PolarDecompositionValueType PolarDecomposition() const;

        // 系数M = Q * D * U使用正交矩阵Q，对角矩阵D，上三角矩阵U。
        // 返回值第一部分为Q，第二部分为D，第三部分为U
        NODISCARD QDUDecompositionValueType QDUDecomposition() const;

    private:
        Matrix3Type matrix;
    };

    using Matrix3ToolsF = Matrix3Tools<float>;
    using Matrix3ToolsD = Matrix3Tools<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_TOOLS_H
