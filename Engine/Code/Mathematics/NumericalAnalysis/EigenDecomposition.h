///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/24 11:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include <memory>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class EigenDecompositionImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<EigenDecompositionImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<EigenDecompositionImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<EigenDecompositionImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE EigenDecomposition final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using EigenDecompositionImpl = EigenDecompositionImpl<Real>;

    public:
        void Swap(EigenDecomposition& rhs) noexcept;

    public:
        TYPE_DECLARE(EigenDecomposition);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~EigenDecomposition() noexcept = default;
        EigenDecomposition(const EigenDecomposition& rhs);
        EigenDecomposition& operator=(const EigenDecomposition& rhs);
        EigenDecomposition(EigenDecomposition&& rhs) noexcept;
        EigenDecomposition& operator=(EigenDecomposition&& rhs) noexcept;

        using Math = Math<Real>;
        using Matrix2 = Matrix2<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector3D = Vector3D<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

    public:
        // 一个特征系统的矩阵必须是对称的。
        explicit EigenDecomposition(int size);
        explicit EigenDecomposition(const Matrix2& rhs);
        explicit EigenDecomposition(const Matrix3& rhs);
        explicit EigenDecomposition(const VariableMatrix& rhs);

        EigenDecomposition& operator=(const Matrix2& rhs);
        EigenDecomposition& operator=(const Matrix3& rhs);
        EigenDecomposition& operator=(const VariableMatrix& rhs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetSize() const noexcept;

        // 设置特征系统的矩阵。
        [[nodiscard]] const Real& operator()(int row, int column) const;
        [[nodiscard]] Real& operator()(int row, int column);

        // 解这个特征系统。
        // 当你想要的特征值在递增顺序进行排序，
        // 设置“increasingSort'为'true'，
        // 否则，特征值以递减顺序进行排序。
        void Solve(bool increasingSort);

        // 得到结果。如果你知道特征系统的相应尺寸应该调用
        // GetEigenvector2和GetEigenvector3。
        [[nodiscard]] Real GetEigenvalue(int index) const;
        [[nodiscard]] const Vector2D GetEigenvector2(int index) const;
        [[nodiscard]] const Matrix2 GetEigenvectors2() const;
        [[nodiscard]] const Vector3D GetEigenvector3(int index) const;
        [[nodiscard]] const Matrix3 GetEigenvectors3() const;
        [[nodiscard]] const VariableLengthVector GetEigenvector(int index) const;
        [[nodiscard]] const VariableMatrix GetEigenvectors() const;

    private:
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };

    using FloatEigenDecomposition = EigenDecomposition<float>;
    using DoubleEigenDecomposition = EigenDecomposition<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_H
