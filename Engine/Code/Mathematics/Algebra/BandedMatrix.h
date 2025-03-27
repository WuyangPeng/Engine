/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/18 13:19)

/// 所谓的带状矩阵即：在矩阵A中，
/// 所有的非零元素都集中在以主对角线为中心的带状区域中。
/// 如 a11 a12 0   0   0   0
///    a21 a22 a23 0   0   0
///    a31 a32 a33 a34 0   0
///    0   a42 a43 a44 a45 0
///    0   0   a53 a54 a55 a56
///    0   0   0   a64 a65 a66
#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Detail/BandedMatrixData.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/Math.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class BandedMatrix final
    {
    public:
        using ClassType = BandedMatrix<Real>;

        using MathType = Math<Real>;
        using ContainerType = std::vector<Real>;
        using VariableMatrixType = VariableMatrix<Real>;
        using BandedMatrixData = BandedMatrixData<Real>;

    public:
        BandedMatrix(int size, int lowerBandsNumber, int upperBandsNumber);

        CLASS_INVARIANT_DECLARE;

        // 成员访问
        NODISCARD int GetSize() const;
        NODISCARD int GetLowerBandsNumber() const;
        NODISCARD int GetUpperBandsNumber() const;
        NODISCARD int GetStreamSize() const;

        /// 重设大小会清空原有数据。
        void ResetSize(int size, int lowerBandsNumber, int upperBandsNumber);

        /// 对角线
        NODISCARD ContainerType GetDiagonalBand() const;
        void SetDiagonalBand(const ContainerType& diagonalBand);

        /// 下三角
        /// GetLowerBand(index):  0 <= index < LowerBandMax
        NODISCARD int GetLowerBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD ContainerType GetLowerBand(int index) const;
        void SetLowerBand(int index, const ContainerType& lowerBand);
        void SetLowerBandZero();

        /// 上三角
        /// GetUpperBand(index):  0 <= index < UpperBandMax
        NODISCARD int GetUpperBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD ContainerType GetUpperBand(int index) const;
        void SetUpperBand(int index, const ContainerType& upperBand);
        void SetUpperBandZero();

        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        // 便利函数用于初始化矩阵
        void SetZero();
        void SetIdentity();

        NODISCARD VariableMatrixType ToVariableMatrix() const;

        /// 计算带状矩阵的逆。
        /// 当矩阵可逆时，返回值为逆矩阵。
        /// 当矩阵不可逆时，函数抛出异常。
        /// RowMajor必须具有由模板参数指定的存储顺序。
        template <bool RowMajor>
        NODISCARD VariableMatrixType ComputeInverse(Real epsilon = MathType::GetZeroTolerance()) const;

    private:
        ContainerType diagonalBandContainer;  // 对角线
        BandedMatrixData lowerBandData;  // 下三角
        BandedMatrixData upperBandData;  // 上三角
    };

    using BandedMatrixF = BandedMatrix<float>;
    using BandedMatrixD = BandedMatrix<double>;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_H
