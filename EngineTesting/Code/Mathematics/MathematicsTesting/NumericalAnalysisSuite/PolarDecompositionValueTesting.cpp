// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:19)

#include "PolarDecompositionValueTesting.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/PolarDecompositionValueDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::swap;
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class PolarDecompositionValue<float>;
	template class PolarDecompositionValue<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26429)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolarDecompositionValueTesting) 

void Mathematics::PolarDecompositionValueTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(PolarDecompositionValueTest);
}

void Mathematics::PolarDecompositionValueTesting
	::PolarDecompositionValueTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);  

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Matrix3D matrix;

		for (int m = 0; m < 3;++m)
		{
			for (int j = 0; j < 3;++j)
			{
				matrix(m, j) = firstRandomDistribution(generator);
			}
		}

		PolarDecompositionValueD polarDecompositionValue(matrix);

		Matrix3D orthogonalMatrix = polarDecompositionValue.GeOrthogonalMatrix();
		Matrix3D symmetryMatrix = polarDecompositionValue.GetSymmetryMatrix();
	 
		Matrix3D result = orthogonalMatrix * symmetryMatrix;	 

		typedef bool(*VariableMatrixdApproximate)(const Matrix3D& lhs,const Matrix3D& rhs,const double epsilon);

		VariableMatrixdApproximate function = Approximate<double>;

		ASSERT_APPROXIMATE_USE_FUNCTION(function,matrix, result, 1e-6);
	}
}

