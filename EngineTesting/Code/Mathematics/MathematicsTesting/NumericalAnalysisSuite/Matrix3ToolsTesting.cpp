// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:02)

#include "Matrix3ToolsTesting.h"
#include "Mathematics/NumericalAnalysis/Matrix3ToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Matrix3Tools<float>;
	template class Matrix3Tools<double>;	
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Matrix3ToolsTesting) 

void Mathematics::Matrix3ToolsTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SingularValueTest);
	ASSERT_NOT_THROW_EXCEPTION_0(PolarDecompositionValueTest);
	ASSERT_NOT_THROW_EXCEPTION_0(QDUDecompositionValueTest);
}

void Mathematics::Matrix3ToolsTesting
	::SingularValueTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5); 
	
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleMatrix3 matrix;

		for (int m = 0; m < 3;++m)
		{
			for (int j = 0; j < 3;++j)
			{
				matrix(m, j) = firstRandomDistribution(generator);
			}
		}

		DoubleMatrix3Tools matrix3Tools(matrix);

		DoubleSingularValue singularValueDecomposition = matrix3Tools.SingularValueDecomposition();

		DoubleMatrix3 leftMatrix = singularValueDecomposition.GetLeftMatrix();
		DoubleMatrix3 diagonalMatrix = singularValueDecomposition.GetDiagonalMatrix();
		DoubleMatrix3 rightTransposeMatrix = singularValueDecomposition.GetRightTransposeMatrix();

		DoubleMatrix3 result = leftMatrix * diagonalMatrix;
		result *= rightTransposeMatrix;

		typedef bool(*VariableMatrixdApproximate)(const DoubleMatrix3& lhs,const DoubleMatrix3& rhs,const double epsilon);

		VariableMatrixdApproximate function = Approximate<double>;

		ASSERT_APPROXIMATE_USE_FUNCTION(function,matrix, result, 1e-6);
	}
}

void Mathematics::Matrix3ToolsTesting
	::PolarDecompositionValueTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);  

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleMatrix3 matrix;

		for (int m = 0; m < 3;++m)
		{
			for (int j = 0; j < 3;++j)
			{
				matrix(m, j) = firstRandomDistribution(generator);
			}
		}

		DoubleMatrix3Tools matrix3Tools(matrix);

		DoublePolarDecompositionValue polarDecompositionValue = matrix3Tools.PolarDecomposition();

		DoubleMatrix3 orthogonalMatrix = polarDecompositionValue.GeOrthogonalMatrix();
		DoubleMatrix3 symmetryMatrix = polarDecompositionValue.GetSymmetryMatrix();
	 
		DoubleMatrix3 result = orthogonalMatrix * symmetryMatrix;	 

		typedef bool(*VariableMatrixdApproximate)(const DoubleMatrix3& lhs,const DoubleMatrix3& rhs,const double epsilon);

		VariableMatrixdApproximate function = Approximate<double>;

		ASSERT_APPROXIMATE_USE_FUNCTION(function,matrix, result, 1e-6);
	}
}



void Mathematics::Matrix3ToolsTesting
	::QDUDecompositionValueTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleMatrix3 matrix;

		for (int m = 0; m < 3;++m)
		{
			for (int j = 0; j < 3;++j)
			{
				matrix(m, j) = firstRandomDistribution(generator);
			}
		}
		DoubleMatrix3Tools matrix3Tools(matrix);

		DoubleQDUDecompositionValue qDUDecompositionValue(matrix3Tools.QDUDecomposition());

		DoubleMatrix3 orthogonalMatrix = qDUDecompositionValue.GeOrthogonalMatrix();
		DoubleMatrix3 diagonalMatrix = qDUDecompositionValue.GetDiagonalMatrix();
		DoubleMatrix3 upperTriangularMatrix = qDUDecompositionValue.GetUpperTriangularMatrix();

		DoubleMatrix3 result = orthogonalMatrix * diagonalMatrix;
		result *= upperTriangularMatrix;

		typedef bool(*VariableMatrixdApproximate)(const DoubleMatrix3& lhs, const DoubleMatrix3& rhs,const double epsilon);

		VariableMatrixdApproximate function = Approximate<double>;

		ASSERT_APPROXIMATE_USE_FUNCTION(function,matrix, result, 1e-5);
	}
}
