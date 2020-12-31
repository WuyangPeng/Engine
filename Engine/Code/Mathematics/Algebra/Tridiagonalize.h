///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 19:10)

#ifndef MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H
#define MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix3.h"
#include "Vector2D.h"
#include "Vector3D.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Tridiagonalize final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Tridiagonalize<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;

    public:
        explicit Tridiagonalize(const Matrix3& matrix);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool IsReflection() const noexcept;
        [[nodiscard]] const Matrix3 GetRotation() const noexcept;
        [[nodiscard]] const Vector3D GetDiagonal() const noexcept;

    private:
        // 支持特征分解。该Tridiagonalize函数可将Householder变换矩阵。
        // 如果这种转变是identity（矩阵已经是tridiagonal），则返回值是'false'。
        // 否则，转换是一个反射和返回值是'true'。
        // QLAlgorithm返回“true”当且仅当QL迭代方案收敛。
        void Init();
        bool QLAlgorithm();
        static bool IsValueNear(Real subdiagonal, Real lhsDiagonal, Real rhsDiagonal) noexcept;
        void UpdateDiagonal(int lhsIndex, int rhsIndex);
        void GivensRotation(int lhsIndex, int rhsIndex, Real cosValue, Real sinValue);

    private:
        Matrix3 m_InputMatrix;
        Matrix3 m_OutputMatrix;
        Vector3D m_Diagonal;
        Vector2D m_Subdiagonal;
        bool m_Reflection;
    };
}

#endif  // MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_H
