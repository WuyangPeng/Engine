///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/31 09:23)

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
    requires std::is_arithmetic_v<Real>
    class BandedMatrixData final
    {
    public:
        using ClassType = BandedMatrixData<Real>;
        using Math = Math<Real>;
        using ContainerType = std::vector<Real>;

    public:
        BandedMatrixData(int size, int bandsNumber);

        CLASS_INVARIANT_DECLARE;

        // ��Ա����
        NODISCARD int GetSize() const noexcept;
        NODISCARD int GetBandsNumber() const;
        NODISCARD int GetStreamSize() const;

        // �����С�����ԭ�����ݡ�
        void ResetSize(int newSize, int bandsNumber);

        // ������
        // GetBand(index):  0 <= index < bandMax
        NODISCARD int GetBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD ContainerType GetBand(int index) const;
        void SetBand(int index, const ContainerType& band);

        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        // �����������ڳ�ʼ������
        void SetZero();

    private:
        using DataType = std::vector<ContainerType>;

    private:
        void Allocate(int bandsNumber);

    private:
        int size;
        DataType bands;
    };
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_H
