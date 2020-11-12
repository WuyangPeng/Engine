///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/05 13:14)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_IMPL_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "BandedMatrixData.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE BandedMatrixImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BandedMatrixImpl<Real>;
        using Math = Math<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using BandedMatrixData = BandedMatrixData<Real>;
        using ContainerType = std::vector<Real>;

    public:
        BandedMatrixImpl(int size, int lowerBandsNumber, int upperBandsNumber);

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
        ContainerType m_DiagonalBand;  // �Խ���
        BandedMatrixData m_LowerBand;  // ������
        BandedMatrixData m_UpperBand;  // ������
    };   
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_IMPL_H
