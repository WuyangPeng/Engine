// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 13:22)

#ifndef MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_DETAIL_H

#include "ParaboloidFit3.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"

template <typename Real>
Mathematics::ParaboloidFit3<Real>
	::ParaboloidFit3(const std::vector<Vector3D>& points)
	:m_Coeff{}
{
	Calculate(points);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ParaboloidFit3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::ParaboloidFit3<Real>::VariableLengthVector Mathematics::ParaboloidFit3<Real>
	::GetCoeff() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (m_IsFitSuccess)
	{
		return m_Coeff;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("抛物面拟合失败。"));
	}
}


template <typename Real>
bool Mathematics::ParaboloidFit3<Real>
	::GetIsFitSuccess() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_IsFitSuccess;
}


template <typename Real>
void Mathematics::ParaboloidFit3<Real>
	::Calculate(const std::vector<Vector3D>& points)
{
	// 分配线性系统（矩阵最初是零）。
	try
	{
		VariableMatrix<Real> matrix{ sm_VariableMatrixSize, sm_VariableMatrixSize };
		std::vector<Real> rhs(sm_VariableMatrixSize);
		
		auto numPoints = points.size();
		
		for (auto i = 0u; i < numPoints; i++)
		{
			auto x2 = points[i][0] * points[i][0];
			auto xy = points[i][0] * points[i][1];
			auto y2 = points[i][1] * points[i][1];
			auto zx = points[i][2] * points[i][0];
			auto zy = points[i][2] * points[i][1];
			auto x3 = points[i][0] * x2;
			auto x2y = x2 * points[i][1];
			auto xy2 = points[i][0] * y2;
			auto y3 = points[i][1] * y2;
			auto zx2 = points[i][2] * x2;
			auto zxy = points[i][2] * xy;
			auto zy2 = points[i][2] * y2;
			auto x4 = x2 * x2;
			auto x3y = x3 * points[i][1];
			auto x2y2 = x2 * y2;
			auto xy3 = points[i][0] * y3;
			auto y4 = y2 * y2;
			
			matrix[0][0] += x4;
			matrix[0][1] += x3y;
			matrix[0][2] += x2y2;
			matrix[0][3] += x3;
			matrix[0][4] += x2y;
			matrix[0][5] += x2;
			matrix[1][2] += xy3;
			matrix[1][4] += xy2;
			matrix[1][5] += xy;
			matrix[2][2] += y4;
			matrix[2][4] += y3;
			matrix[2][5] += y2;
			matrix[3][3] += x2;
			matrix[3][5] += points[i][0];
			matrix[4][5] += points[i][1];
			
			rhs[0] += zx2;
			rhs[1] += zxy;
			rhs[2] += zy2;
			rhs[3] += zx;
			rhs[4] += zy;
			rhs[5] += points[i][2];
		}
		
		matrix[1][0] = matrix[0][1];
		matrix[1][1] = matrix[0][2];
		matrix[1][3] = matrix[0][4];
		matrix[2][0] = matrix[0][2];
		matrix[2][1] = matrix[1][2];
		matrix[2][3] = matrix[1][4];
		matrix[3][0] = matrix[0][3];
		matrix[3][1] = matrix[1][3];
		matrix[3][2] = matrix[2][3];
		matrix[3][4] = matrix[1][5];
		matrix[4][0] = matrix[0][4];
		matrix[4][1] = matrix[1][4];
		matrix[4][2] = matrix[2][4];
		matrix[4][3] = matrix[3][4];
		matrix[4][4] = matrix[2][5];
		matrix[5][0] = matrix[0][5];
		matrix[5][1] = matrix[1][5];
		matrix[5][2] = matrix[2][5];
		matrix[5][3] = matrix[3][5];
		matrix[5][4] = matrix[4][5];
		matrix[5][5] = static_cast<Real>(numPoints);	

		std::vector<Real> coeff(sm_VariableMatrixSize);

		LinearSystem<Real> linearSystem;

		linearSystem.Solve(matrix, &rhs[0], &coeff[0]);

		m_Coeff = VariableLengthVector{ coeff };
		m_IsFitSuccess = true;
	}
	catch (CoreTools::Error&)
	{
		m_IsFitSuccess = false;
	}
}


#endif // MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_DETAIL_H
 