///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 09:23)

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

        // 成员访问
        NODISCARD int GetSize() const noexcept;
        NODISCARD int GetBandsNumber() const;
        NODISCARD int GetStreamSize() const;

        // 重设大小会清空原有数据。
        void ResetSize(int newSize, int bandsNumber);

        // 下三角
        // GetBand(index):  0 <= index < bandMax
        NODISCARD int GetBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD ContainerType GetBand(int index) const;
        void SetBand(int index, const ContainerType& band);

        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        // 便利函数用于初始化矩阵
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
