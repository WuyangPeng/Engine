///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/05 14:27)

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
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <memory>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class BandedMatrixImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<BandedMatrixImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<BandedMatrixImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<BandedMatrixImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BandedMatrix final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using BandedMatrixImpl = BandedMatrixImpl<Real>;
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(BandedMatrix, DESTRUCTOR_DEFAULT);

        using Math = Math<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using ContainerType = std::vector<Real>;

    public:
        BandedMatrix(int size, int lowerBandsNumber, int upperBandsNumber);

        CLASS_INVARIANT_DECLARE;

        // ��Ա����
        [[nodiscard]] int GetSize() const;
        [[nodiscard]] int GetLowerBandsNumber() const;
        [[nodiscard]] int GetUpperBandsNumber() const;
        [[nodiscard]] int GetStreamSize() const;

        // �����С�����ԭ�����ݡ�
        void ResetSize(int size, int lowerBandsNumber, int upperBandsNumber);

        // �Խ���
        [[nodiscard]] ContainerType GetDiagonalBand() const;
        void SetDiagonalBand(const ContainerType& diagonalBand);

        // ������
        // GetLowerBand(index):  0 <= index < LowerBandMax
        [[nodiscard]] int GetLowerBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] ContainerType GetLowerBand(int index) const;
        void SetLowerBand(int index, const ContainerType& lowerBand);
        void SetLowerBandZero();

        // ������
        // GetUupperBand(index):  0 <= index < UpperBandMax
        [[nodiscard]] int GetUpperBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] ContainerType GetUpperBand(int index) const;
        void SetUpperBand(int index, const ContainerType& upperBand);
        void SetUpperBandZero();

        [[nodiscard]] Real& operator()(int row, int column);
        [[nodiscard]] const Real& operator()(int row, int column) const;

        // �����������ڳ�ʼ������
        void SetZero();
        void SetIdentity();

        [[nodiscard]] const VariableMatrix ToVariableMatrix() const;

    private:
        IMPL_TYPE_DECLARE(BandedMatrix);
    };

    using FloatBandedMatrix = BandedMatrix<float>;
    using DoubleBandedMatrix = BandedMatrix<double>;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_H
