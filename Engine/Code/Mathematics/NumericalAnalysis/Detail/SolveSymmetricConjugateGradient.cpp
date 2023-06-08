///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:33)

#include "Mathematics/MathematicsExport.h"

#include "SolveSymmetricConjugateGradientDetail.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"

template <>
void Mathematics::SolveSymmetricConjugateGradient<float, Mathematics::SparseMatrix>::Multiply()
{
    product.assign(size, 0.0f);

    for (auto iter = matrix.GetBegin(); iter != matrix.GetEnd(); ++iter)
    {
        const auto row = iter.GetKey().GetRow();
        const auto column = iter.GetKey().GetColumn();
        const auto value = iter.GetMapped();

        product.at(row) += value * inputAmend2.at(column);
        if (row != column)
        {
            product.at(column) += value * inputAmend2.at(row);
        }
    }
}

template <>
void Mathematics::SolveSymmetricConjugateGradient<double, Mathematics::SparseMatrix>::Multiply()
{
    product.assign(size, 0.0);

    for (auto iter = matrix.GetBegin(); iter != matrix.GetEnd(); ++iter)
    {
        const auto row = iter.GetKey().GetRow();
        const auto column = iter.GetKey().GetColumn();
        const auto value = iter.GetMapped();

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