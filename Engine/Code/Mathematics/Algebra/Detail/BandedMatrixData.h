///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/08 11:58)

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
    class BandedMatrixData final
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
