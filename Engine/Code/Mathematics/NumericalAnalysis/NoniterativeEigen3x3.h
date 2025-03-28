/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/BaseFwd.h"

namespace Mathematics
{
    template <typename Real>
    class NoniterativeEigen3x3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = NoniterativeEigen3x3<Real>;

        using MathType = Math<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector3 = Vector3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;

    public:
        // 输入矩阵必须是对称的。
        explicit NoniterativeEigen3x3(const Matrix3& matrix);

        CLASS_INVARIANT_DECLARE;

        // 得到特征向量。特征值以递增的顺序存储。
        NODISCARD Real GetEigenvalue(int index) const;
        NODISCARD Vector3 GetEigenvector(int index) const;

    private:
        NODISCARD Real GetMaxValue(const Matrix3& matrix) const;
        void Compute(const Matrix3& matrix);
        void RescaleBack(Real maxValue) noexcept;

        // 计算三次多项式的根。双精度运算被使用在由于最小化的影响减消除。根按递增顺序返回。
        void ComputeRoots(const Matrix3& matrix);

        // 确定matrix是否有的正的列。返回matrix的最大量值项目。
        // 它包含的列也被返回。
        NODISCARD bool PositiveRank(Matrix3& matrix, Real& maxEntry, Vector3& maxRow) const;

        // 计算特征向量。
        void ComputeVectors(const Matrix3& matrix, const Vector3& vector, int index0, int index1, int index2);

    private:
        static constexpr auto eigenMax = 3;

        using EigenValueType = std::array<Real, eigenMax>;
        using EigenVectorType = std::array<Vector3, eigenMax>;
        using Container = std::vector<Real>;

        EigenValueType eigenvalue;
        EigenVectorType eigenvector;
    };

    using NoniterativeEigen3x3F = NoniterativeEigen3x3<float>;
    using NoniterativeEigen3x3D = NoniterativeEigen3x3<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_H
