/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/02/18 13:19)

/// ��ν�Ĵ�״���󼴣��ھ���A�У�
/// ���еķ���Ԫ�ض������������Խ���Ϊ���ĵĴ�״�����С�
/// �� a11 a12 0   0   0   0
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

        // ��Ա����
        NODISCARD int GetSize() const;
        NODISCARD int GetLowerBandsNumber() const;
        NODISCARD int GetUpperBandsNumber() const;
        NODISCARD int GetStreamSize() const;

        /// �����С�����ԭ�����ݡ�
        void ResetSize(int size, int lowerBandsNumber, int upperBandsNumber);

        /// �Խ���
        NODISCARD ContainerType GetDiagonalBand() const;
        void SetDiagonalBand(const ContainerType& diagonalBand);

        /// ������
        /// GetLowerBand(index):  0 <= index < LowerBandMax
        NODISCARD int GetLowerBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD ContainerType GetLowerBand(int index) const;
        void SetLowerBand(int index, const ContainerType& lowerBand);
        void SetLowerBandZero();

        /// ������
        /// GetUpperBand(index):  0 <= index < UpperBandMax
        NODISCARD int GetUpperBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD ContainerType GetUpperBand(int index) const;
        void SetUpperBand(int index, const ContainerType& upperBand);
        void SetUpperBandZero();

        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        // �����������ڳ�ʼ������
        void SetZero();
        void SetIdentity();

        NODISCARD VariableMatrixType ToVariableMatrix() const;

        /// �����״������档
        /// ���������ʱ������ֵΪ�����
        /// �����󲻿���ʱ�������׳��쳣��
        /// RowMajor���������ģ�����ָ���Ĵ洢˳��
        template <bool RowMajor>
        NODISCARD VariableMatrixType ComputeInverse(Real epsilon = MathType::GetZeroTolerance()) const;

    private:
        ContainerType diagonalBandContainer;  // �Խ���
        BandedMatrixData lowerBandData;  // ������
        BandedMatrixData upperBandData;  // ������
    };

    using BandedMatrixF = BandedMatrix<float>;
    using BandedMatrixD = BandedMatrix<double>;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_H
