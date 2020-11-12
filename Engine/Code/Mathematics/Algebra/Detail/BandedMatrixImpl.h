///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 13:14)

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

        // 成员访问
        [[nodiscard]] int GetSize() const;
        [[nodiscard]] int GetLowerBandsNumber() const;
        [[nodiscard]] int GetUpperBandsNumber() const;
        [[nodiscard]] int GetStreamSize() const;

        // 重设大小会清空原有数据。
        void ResetSize(int size, int lowerBandsNumber, int upperBandsNumber);

        // 对角线
        [[nodiscard]] ContainerType GetDiagonalBand() const;
        void SetDiagonalBand(const ContainerType& diagonalBand);

        // 下三角
        // GetLowerBand(index):  0 <= index < LowerBandMax
        [[nodiscard]] int GetLowerBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] ContainerType GetLowerBand(int index) const;
        void SetLowerBand(int index, const ContainerType& lowerBand);
        void SetLowerBandZero();

        // 上三角
        // GetUupperBand(index):  0 <= index < UpperBandMax
        [[nodiscard]] int GetUpperBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1); 
        [[nodiscard]] ContainerType GetUpperBand(int index) const;
        void SetUpperBand(int index, const ContainerType& upperBand);
        void SetUpperBandZero();

        [[nodiscard]] Real& operator()(int row, int column);
        [[nodiscard]] const Real& operator()(int row, int column) const;

        // 便利函数用于初始化矩阵
        void SetZero();
        void SetIdentity();

        [[nodiscard]] const VariableMatrix ToVariableMatrix() const;

    private:
        ContainerType m_DiagonalBand;  // 对角线
        BandedMatrixData m_LowerBand;  // 下三角
        BandedMatrixData m_UpperBand;  // 上三角
    };   
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_IMPL_H
