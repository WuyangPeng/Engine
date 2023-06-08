///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 17:56)

#ifndef MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H
#define MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix3.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Tridiagonalize final
    {
    public:
        using ClassType = Tridiagonalize<Real>;
        using Math = Math<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector2 = Vector2<Real>;
        using Vector3 = Vector3<Real>;

    public:
        explicit Tridiagonalize(const Matrix3& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsReflection() const noexcept;
        NODISCARD Matrix3 GetRotation() const noexcept;
        NODISCARD Vector3 GetDiagonal() const noexcept;

    private:
        // 支持特征分解。该Tridiagonalize函数可将Householder变换矩阵。
        // 如果这种转变是identity（矩阵已经是tridiagonal），则返回值是'false'。
        // 否则，转换是一个反射和返回值是'true'。
        // QLAlgorithm返回“true”当且仅当QL迭代方案收敛。
        void Init();
        NODISCARD bool QLAlgorithm();
        NODISCARD static bool IsValueNear(Real subDiagonal, Real lhsDiagonal, Real rhsDiagonal) noexcept;
        void UpdateDiagonal(int lhsIndex, int rhsIndex);
        void GivensRotation(int lhsIndex, int rhsIndex, Real cosValue, Real sinValue);

    private:
        Matrix3 inputMatrix;
        Matrix3 outputMatrix;
        Vector3 diagonal;
        Vector2 subDiagonal;
        bool reflection;
    };
}

#endif  // MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H
