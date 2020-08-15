// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 13:03)

#include "Mathematics/MathematicsExport.h"

#include "SolveSymmetricConjugateGradientDetail.h"
#include "SparseMatrixDetail.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
// private
template <>
void Mathematics::SolveSymmetricConjugateGradient<float, Mathematics::SparseMatrix>
	::Multiply()
{
	m_Product.assign(m_Size, 0.0f);
const auto end = m_Matrix.GetEnd();
	for (auto iter = m_Matrix.GetBegin() ; iter != end; ++iter)
	{
		const auto row = iter.GetKey().GetRow();
		const auto column = iter.GetKey().GetColumn();
		auto value = iter.GetMapped();
		m_Product[row] += value * m_InputSecondAmend[column];
		if (row != column)
		{
			m_Product[column] += value * m_InputSecondAmend[row];
		}
	}
}

// private
template <>
void Mathematics::SolveSymmetricConjugateGradient<double, Mathematics::SparseMatrix>
	::Multiply()
{
	m_Product.assign(m_Size, 0.0);
const auto end = m_Matrix.GetEnd();
	for (auto iter = m_Matrix.GetBegin() ; iter != end; ++iter)
	{
		const auto row = iter.GetKey().GetRow();
		const auto column = iter.GetKey().GetColumn();
		auto value = iter.GetMapped();
		m_Product[row] += value * m_InputSecondAmend[column];
		if (row != column)
		{
			m_Product[column] += value * m_InputSecondAmend[row];
		}
	}
}
#include STSTEM_WARNING_POP