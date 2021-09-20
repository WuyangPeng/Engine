// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 16:37)

#ifndef MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_AGGREGATE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_AGGREGATE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class AlgebraAggregateTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AlgebraAggregateTesting); 

	private:
		void MainTest();
		void HomogeneousPointTest();
		void Vector2DTest();
		void Vector3DTest();
		void Vector4DTest();
		void AVectorTest();
		void APointTest();
		void VariableLengthVectorTest();
		void PlaneTest();
		void PolynomialTest();
		void Matrix2Test();
		void Matrix3Test();
		void Matrix4Test();
		void MatrixTest();
		void VariableMatrixTest();
		void BandedMatrixTest();
		void BandedMatrixSolveTest();
		void QuaternionTest();
		void AQuaternionTest();
		void Float1Test();
		void Float2Test();
		void Float3Test();
		void Float4Test();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_QUATERN_SWING_TWIST_TESTING_H