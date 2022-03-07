///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 14:05)

#include "Mathematics/MathematicsExport.h"

#include "SolveSymmetricConjugateGradientDetail.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"

// private
template <>
void Mathematics::SolveSymmetricConjugateGradient<float, Mathematics::SparseMatrix>::Multiply()
{
    product.assign(size, 0.0f);

    for (auto iter = matrix.GetBegin(); iter != matrix.GetEnd(); ++iter)
    {
        const auto row = iter.GetKey().GetRow();
        const auto column = iter.GetKey().GetColumn();
        auto value = iter.GetMapped();

        product.at(row) += value * inputAmend2.at(column);
        if (row != column)
        {
            product.at(column) += value * inputAmend2.at(row);
        }
    }
}

// private
template <>
void Mathematics::SolveSymmetricConjugateGradient<double, Mathematics::SparseMatrix>::Multiply()
{
    product.assign(size, 0.0);

    for (auto iter = matrix.GetBegin(); iter != matrix.GetEnd(); ++iter)
    {
        const auto row = iter.GetKey().GetRow();
        const auto column = iter.GetKey().GetColumn();
        auto value = iter.GetMapped();

        product.at(row) += value * inputAmend2.at(column);
        if (row != column)
        {
            product.at(column) += value * inputAmend2.at(row);
        }
    }
}

#ifdef MATHEMATICS_TEMPLATE_TEST

namespace Mathematics
{
    template class SolveSymmetricConjugateGradient<float, Mathematics::SparseMatrix>;
    template class SolveSymmetricConjugateGradient<double, Mathematics::SparseMatrix>;
}

#endif  // MATHEMATICS_TEMPLATE_TEST