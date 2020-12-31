///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/25 18:47)

#include "Mathematics/MathematicsExport.h"

#include "SolveSymmetricConjugateGradientDetail.h"
#include "Mathematics/NumericalAnalysis/SparseMatrixDetail.h"

// private
template <>
void Mathematics::SolveSymmetricConjugateGradient<float, Mathematics::SparseMatrix>::Multiply()
{
    m_Product.assign(m_Size, 0.0f);

    for (auto iter = m_Matrix.GetBegin(); iter != m_Matrix.GetEnd(); ++iter)
    {
        const auto row = iter.GetKey().GetRow();
        const auto column = iter.GetKey().GetColumn();
        auto value = iter.GetMapped();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Product[row] += value * m_InputAmend2[column];
        if (row != column)
        {
            m_Product[column] += value * m_InputAmend2[row];
        }
#include STSTEM_WARNING_POP
    }
}

// private
template <>
void Mathematics::SolveSymmetricConjugateGradient<double, Mathematics::SparseMatrix>::Multiply()
{
    m_Product.assign(m_Size, 0.0);

    for (auto iter = m_Matrix.GetBegin(); iter != m_Matrix.GetEnd(); ++iter)
    {
        const auto row = iter.GetKey().GetRow();
        const auto column = iter.GetKey().GetColumn();
        auto value = iter.GetMapped();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Product[row] += value * m_InputAmend2[column];
        if (row != column)
        {
            m_Product[column] += value * m_InputAmend2[row];
        }
#include STSTEM_WARNING_POP
    }
}
