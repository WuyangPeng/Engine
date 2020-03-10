// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/09 11:33)

#include "Mathematics/MathematicsExport.h"

#include "SolveSymmetricConjugateGradientDetail.h"
#include "SparseMatrixDetail.h"

// private
template <>
void Mathematics::SolveSymmetricConjugateGradient<float, Mathematics::SparseMatrix>
	::Multiply()
{
	m_Product.assign(m_Size, 0.0f);

	for (auto iter = m_Matrix.GetBegin(),  end = m_Matrix.GetEnd(); iter != end;++iter)
	{
		auto row = iter.GetKey().GetRow();
		auto column = iter.GetKey().GetColumn();
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
	
	for (auto iter = m_Matrix.GetBegin(),  end = m_Matrix.GetEnd(); iter != end;++iter)
	{
		auto row = iter.GetKey().GetRow();
		auto column = iter.GetKey().GetColumn();
		auto value = iter.GetMapped();
		m_Product[row] += value * m_InputSecondAmend[column];
		if (row != column)
		{
			m_Product[column] += value * m_InputSecondAmend[row];
		}
	}
}
