///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/05 11:08)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics//Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE BandedMatrixData final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BandedMatrixData<Real>;
        using Math = Math<Real>;
        using ContainerType = std::vector<Real>;

    public:
        BandedMatrixData(int size, int bandsNumber);

        CLASS_INVARIANT_DECLARE;

        // ��Ա����
        [[nodiscard]] int GetSize() const noexcept;
        [[nodiscard]] int GetBandsNumber() const;
        [[nodiscard]] int GetStreamSize() const;

        // �����С�����ԭ�����ݡ�
        void ResetSize(int size, int bandsNumber);

        // ������
        // GetBand(index):  0 <= index < bandMax
        [[nodiscard]] int GetBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        ContainerType GetBand(int index) const;
        void SetBand(int index, const ContainerType& band);

        [[nodiscard]] Real& operator()(int row, int column);
        [[nodiscard]] const Real& operator()(int row, int column) const;

        // �����������ڳ�ʼ������
        void SetZero();

    private:
        using DataType = std::vector<ContainerType>;

    private:
        void Allocate(int bandsNumber);

    private:
        int m_Size;
        DataType m_Bands;
    };
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_H
