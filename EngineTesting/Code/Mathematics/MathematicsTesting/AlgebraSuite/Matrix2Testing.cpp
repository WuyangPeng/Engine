// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 15:37)

#include "Matrix2Testing.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

#include <random> 
#include "Mathematics/Algebra/Vector2DTools.h"

using std::vector;
using std::uniform_real;
using std::default_random_engine; 

namespace Mathematics
{
	template class Matrix2<float>;
	template class Matrix2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Matrix2Testing) 

void Mathematics::Matrix2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OperatorCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
}

void Mathematics::Matrix2Testing
	::ConstructionTest()
{
	FloatMatrix2 firstMatrix(MatrixInitType::Zero);

	ASSERT_APPROXIMATE(firstMatrix(0,0),0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(0,1),0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(1,0),0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(1,1),0.0f,1e-8f);

	FloatMatrix2 secondMatrix(MatrixInitType::Identity);

	ASSERT_APPROXIMATE(secondMatrix(0,0),1.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(0,1),0.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(1,0),0.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(1,1),1.0f,1e-8f);

	DoubleMatrix2 thirdMatrix(3.0,6.0,1.0,2.0);

	ASSERT_APPROXIMATE(thirdMatrix(0,0),3.0,1e-10);
	ASSERT_APPROXIMATE(thirdMatrix(0,1),6.0,1e-10);
	ASSERT_APPROXIMATE(thirdMatrix(1,0),1.0,1e-10);
	ASSERT_APPROXIMATE(thirdMatrix(1,1),2.0,1e-10);

	vector<double> doubleVector{ 6.0,6.2,9.0,2.0 }; 

	DoubleMatrix2 fourthMatrix(doubleVector,MatrixMajorFlags::Row);

	ASSERT_APPROXIMATE(fourthMatrix(0,0),6.0,1e-10);
	ASSERT_APPROXIMATE(fourthMatrix(0,1),6.2,1e-10);
	ASSERT_APPROXIMATE(fourthMatrix(1,0),9.0,1e-10);
	ASSERT_APPROXIMATE(fourthMatrix(1,1),2.0,1e-10);

	DoubleMatrix2 fifthMatrix(doubleVector,MatrixMajorFlags::Column);

	ASSERT_APPROXIMATE(fifthMatrix(0,0),6.0,1e-10);
	ASSERT_APPROXIMATE(fifthMatrix(0,1),9.0,1e-10);
	ASSERT_APPROXIMATE(fifthMatrix(1,0),6.2,1e-10);
	ASSERT_APPROXIMATE(fifthMatrix(1,1),2.0,1e-10);

	FloatVector2D firstVector(6.0f,3.0f);
	FloatVector2D secondVector(8.0f,3.1f);

	FloatMatrix2 sixthMatrix(firstVector,secondVector,MatrixMajorFlags::Row);

	ASSERT_APPROXIMATE(sixthMatrix(0,0),6.0f,1e-8f);
	ASSERT_APPROXIMATE(sixthMatrix(0,1),3.0f,1e-8f);
	ASSERT_APPROXIMATE(sixthMatrix(1,0),8.0f,1e-8f);
	ASSERT_APPROXIMATE(sixthMatrix(1,1),3.1f,1e-8f);

	FloatMatrix2 seventhMatrix(firstVector,secondVector,MatrixMajorFlags::Column);

	ASSERT_APPROXIMATE(seventhMatrix(0,0),6.0f,1e-8f);
	ASSERT_APPROXIMATE(seventhMatrix(0,1),8.0f,1e-8f);
	ASSERT_APPROXIMATE(seventhMatrix(1,0),3.0f,1e-8f);
	ASSERT_APPROXIMATE(seventhMatrix(1,1),3.1f,1e-8f);

	vector<FloatVector2D> vector2DVector{ firstVector,secondVector }; 

	FloatMatrix2 eighthMatrix(vector2DVector,MatrixMajorFlags::Row);

	ASSERT_APPROXIMATE(eighthMatrix(0,0),6.0f,1e-8f);
	ASSERT_APPROXIMATE(eighthMatrix(0,1),3.0f,1e-8f);
	ASSERT_APPROXIMATE(eighthMatrix(1,0),8.0f,1e-8f);
	ASSERT_APPROXIMATE(eighthMatrix(1,1),3.1f,1e-8f);

	FloatMatrix2 ninthMatrix(vector2DVector,MatrixMajorFlags::Column);

	ASSERT_APPROXIMATE(ninthMatrix(0,0),6.0f,1e-8f);
	ASSERT_APPROXIMATE(ninthMatrix(0,1),8.0f,1e-8f);
	ASSERT_APPROXIMATE(ninthMatrix(1,0),3.0f,1e-8f);
	ASSERT_APPROXIMATE(ninthMatrix(1,1),3.1f,1e-8f);

	DoubleMatrix2 tenthMatrix(6.0,89.0);

	ASSERT_APPROXIMATE(tenthMatrix(0,0),6.0,1e-10);
	ASSERT_APPROXIMATE(tenthMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(tenthMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(tenthMatrix(1,1),89.0,1e-10);

	DoubleMatrix2 eleventhMatrix(DoubleMath::GetHalfPI() / 3.0);

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),cos(DoubleMath::GetHalfPI() / 3.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),-sin(DoubleMath::GetHalfPI() / 3.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),sin(DoubleMath::GetHalfPI() / 3.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),cos(DoubleMath::GetHalfPI() / 3.0),1e-10);

	FloatMatrix2 twelfthMatrix(firstVector,secondVector);

	ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetX(),twelfthMatrix(0,0),1e-8f);
	ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetY(),twelfthMatrix(0,1),1e-8f);
	ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetX(),twelfthMatrix(1,0),1e-8f);
	ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetY(),twelfthMatrix(1,1),1e-8f);

	eleventhMatrix.MakeZero();

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),0.0,1e-10);

	eleventhMatrix.MakeIdentity();

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),1.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),1.0,1e-10);

	eleventhMatrix.MakeDiagonal(6.0,9.0);

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),6.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),9.0,1e-10);

	eleventhMatrix.MakeRotation(DoubleMath::GetHalfPI() / 6.0);

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),cos(DoubleMath::GetHalfPI() / 6.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),-sin(DoubleMath::GetHalfPI() / 6.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),sin(DoubleMath::GetHalfPI() / 6.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),cos(DoubleMath::GetHalfPI() / 6.0),1e-10);

	ninthMatrix.MakeTensorProduct(firstVector,secondVector);

	ASSERT_APPROXIMATE(twelfthMatrix(0,0),ninthMatrix(0,0),1e-8f);
	ASSERT_APPROXIMATE(twelfthMatrix(0,1),ninthMatrix(0,1),1e-8f);
	ASSERT_APPROXIMATE(twelfthMatrix(1,0),ninthMatrix(1,0),1e-8f);
	ASSERT_APPROXIMATE(twelfthMatrix(1,1),ninthMatrix(1,1),1e-8f);

	eleventhMatrix = tenthMatrix;

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),6.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),89.0,1e-10);

	DoubleMatrix2 thirteenthMatrix(eleventhMatrix);

	ASSERT_APPROXIMATE(thirteenthMatrix(0,0),6.0,1e-10);
	ASSERT_APPROXIMATE(thirteenthMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(thirteenthMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(thirteenthMatrix(1,1),89.0,1e-10);
}

void Mathematics::Matrix2Testing
	::AccessTest()
{
	const FloatMatrix2 firstMatrix(3.0f,4.0f,8.1f,3.2f);

	ASSERT_APPROXIMATE(firstMatrix(0,0),3.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(0,1),4.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(1,0),8.1f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(1,1),3.2f,1e-8f);

	DoubleMatrix2 secondMatrix(9.2,1.0,4.2,5.2);

	ASSERT_APPROXIMATE(secondMatrix(0,0),9.2,1e-10);
	ASSERT_APPROXIMATE(secondMatrix(0,1),1.0,1e-10);
	ASSERT_APPROXIMATE(secondMatrix(1,0),4.2,1e-10);
	ASSERT_APPROXIMATE(secondMatrix(1,1),5.2,1e-10);
}

void Mathematics::Matrix2Testing
	::OperatorCalculateTest()
{
	FloatMatrix2 firstMatrix(3.0f,4.0f,8.1f,3.2f);

	FloatMatrix2 secondMatrix = -firstMatrix;

	ASSERT_APPROXIMATE(secondMatrix(0,0),-3.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(0,1),-4.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(1,0),-8.1f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(1,1),-3.2f,1e-8f);

	FloatMatrix2 thirdMatrix(9.2f,3.0f,2.0f,9.0f);

	thirdMatrix += secondMatrix;

	ASSERT_APPROXIMATE(thirdMatrix(0,0),6.2f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(0,1),-1.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(1,0),-6.1f,1e6f);
	ASSERT_APPROXIMATE(thirdMatrix(1,1),5.8f,1e-8f);

	thirdMatrix -= firstMatrix;

	ASSERT_APPROXIMATE(thirdMatrix(0,0),3.2f,1e-6f);
	ASSERT_APPROXIMATE(thirdMatrix(0,1),-5.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(1,0),-14.2f,1e-6f);
	ASSERT_APPROXIMATE(thirdMatrix(1,1),2.6f,1e-6f);

	thirdMatrix *= 6.0f;

	ASSERT_APPROXIMATE(thirdMatrix(0,0),19.2f,1e-5f);
	ASSERT_APPROXIMATE(thirdMatrix(0,1),-30.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(1,0),-85.2f,1e-5f);
	ASSERT_APPROXIMATE(thirdMatrix(1,1),15.6f,1e-8f);

	thirdMatrix /= 2.0f;

	ASSERT_APPROXIMATE(thirdMatrix(0,0),9.6f,1e-6f);
	ASSERT_APPROXIMATE(thirdMatrix(0,1),-15.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(1,0),-42.6f,1e-5f);
	ASSERT_APPROXIMATE(thirdMatrix(1,1),7.8f,1e-8f);

	FloatMatrix2 fourthMatrix1 = firstMatrix + thirdMatrix;

	ASSERT_APPROXIMATE(fourthMatrix1(0,0),12.6f,1e-6f);
	ASSERT_APPROXIMATE(fourthMatrix1(0,1),-11.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix1(1,0),-34.5f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix1(1,1),11.0f,1e-8f);

	fourthMatrix1 = firstMatrix - thirdMatrix;

	ASSERT_APPROXIMATE(fourthMatrix1(0,0),-6.6f,1e-6f);
	ASSERT_APPROXIMATE(fourthMatrix1(0,1),19.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix1(1,0),50.7f,1e-5f);
	ASSERT_APPROXIMATE(fourthMatrix1(1,1),-4.6f,1e-6f);

	fourthMatrix1 = firstMatrix * 5.0f;

	ASSERT_APPROXIMATE(fourthMatrix1(0,0),15.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix1(0,1),20.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix1(1,0),40.5f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix1(1,1),16.0f,1e-8f);

	fourthMatrix1 = 3.0f * firstMatrix;

	ASSERT_APPROXIMATE(fourthMatrix1(0,0),9.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix1(0,1),12.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix1(1,0),24.3f,1e-5f);
	ASSERT_APPROXIMATE(fourthMatrix1(1,1),9.6f,1e-8f);

	fourthMatrix1 =  firstMatrix / 2.0f;

	ASSERT_APPROXIMATE(fourthMatrix1(0,0),1.5f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix1(0,1),2.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix1(1,0),4.05f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix1(1,1),1.6f,1e-8f);

	default_random_engine generator{};
	uniform_real<float> randomDistribution{ -100.0f,100.0f }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatMatrix2 fifthMatrix{ randomDistribution(generator),randomDistribution(generator),randomDistribution(generator),randomDistribution(generator) };

		FloatMatrix2 sixthMatrix{ randomDistribution(generator),randomDistribution(generator),randomDistribution(generator),randomDistribution(generator) };

		FloatMatrix2 seventhMatrix(sixthMatrix);

		seventhMatrix *= fifthMatrix;

		FloatMatrix2 fourthMatrix(sixthMatrix(0,0) * fifthMatrix(0,0) +
			                  sixthMatrix(0,1) * fifthMatrix(1,0),
							  sixthMatrix(0,0) * fifthMatrix(0,1) +
							  sixthMatrix(0,1) * fifthMatrix(1,1),
							  sixthMatrix(1,0) * fifthMatrix(0,0) +
							  sixthMatrix(1,1) * fifthMatrix(1,0),
							  sixthMatrix(1,0) * fifthMatrix(0,1) +
							  sixthMatrix(1,1) * fifthMatrix(1,1));

		ASSERT_TRUE(Approximate(fourthMatrix,seventhMatrix,1e-8f)); 

		seventhMatrix = sixthMatrix * fifthMatrix;

		ASSERT_TRUE(Approximate(fourthMatrix,seventhMatrix,1e-8f)); 

		FloatMatrix2::Vector2D firstVector(randomDistribution(generator),
			                           randomDistribution(generator));

		FloatMatrix2::Vector2D secondVector = seventhMatrix * firstVector;
		FloatMatrix2::Vector2D thirdVector = firstVector * seventhMatrix;

		FloatMatrix2::Vector2D fourthVector(seventhMatrix(0,0) * firstVector[0] + 
			                            seventhMatrix(0,1) * firstVector[1],
										seventhMatrix(1,0) * firstVector[0] + 
										seventhMatrix(1,1) * firstVector[1]);

		ASSERT_TRUE(FloatVector2DTools::Approximate(secondVector, fourthVector,1e-8f));  

		fourthVector[0] = seventhMatrix(0,0) * firstVector[0] + seventhMatrix(1,0) * firstVector[1];

		fourthVector[1] = seventhMatrix(0,1) * firstVector[0] + seventhMatrix(1,1) * firstVector[1];

		ASSERT_TRUE(FloatVector2DTools::Approximate(thirdVector, fourthVector,1e-8f));

		FloatMatrix2 eighthMatrix = TransposeTimes(fifthMatrix,sixthMatrix);
		FloatMatrix2 ninthMatrix = fifthMatrix.Transpose() * sixthMatrix;

		ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix,1e-8f));  

		eighthMatrix = TimesTranspose(fifthMatrix,sixthMatrix);
		ninthMatrix = fifthMatrix * sixthMatrix.Transpose();

		ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix,1e-8f));  

		eighthMatrix = TransposeTimesTranspose(fifthMatrix,sixthMatrix);
		ninthMatrix = fifthMatrix.Transpose() * sixthMatrix.Transpose();

		ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix,1e-8f)); 
	}
}

void Mathematics::Matrix2Testing
	::ArithmeticCalculateTest()
{
	default_random_engine generator{};
	uniform_real<float> randomDistribution{ -100.0f,100.0f };
	uniform_real<float> angleRandomDistribution(0.0f, FloatMath::GetHalfPI());

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatMatrix2::Vector2D firstVector(randomDistribution(generator),
			                           randomDistribution(generator));

		FloatMatrix2::Vector2D secondVector(randomDistribution(generator),
			                            randomDistribution(generator));

		FloatMatrix2 firstMatrix(randomDistribution(generator),
			                 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator));

		float qForm = firstMatrix.QuadraticForm(firstVector,secondVector);

		float testQFormValue = FloatVector2DTools::DotProduct(firstVector,firstMatrix * secondVector);

		ASSERT_APPROXIMATE(qForm,testQFormValue,1e-8f);

		FloatMatrix2 secondMatrix = firstMatrix.Transpose();

		ASSERT_APPROXIMATE(firstMatrix(0,0),secondMatrix(0,0),1e-8f);
		ASSERT_APPROXIMATE(firstMatrix(0,1),secondMatrix(1,0),1e-8f);
		ASSERT_APPROXIMATE(firstMatrix(1,0),secondMatrix(0,1),1e-8f);
		ASSERT_APPROXIMATE(firstMatrix(1,1),secondMatrix(1,1),1e-8f); 

		float determinant = secondMatrix(0,0) * secondMatrix(1,1) - secondMatrix(0,1) * secondMatrix(1,0);

		ASSERT_APPROXIMATE(determinant,secondMatrix.Determinant(),1e-8f);

		if(FloatMath::GetZeroTolerance() < FloatMath::FAbs(determinant))
		{
			FloatMatrix2 thirdMatrix = secondMatrix.Inverse();

			FloatMatrix2 fourthMatrix = secondMatrix * thirdMatrix;

			ASSERT_APPROXIMATE(fourthMatrix(0,0),1.0f,1e-5f);
			ASSERT_APPROXIMATE(fourthMatrix(0,1),0.0f,1e-5f);
			ASSERT_APPROXIMATE(fourthMatrix(1,0),0.0f,1e-5f);
			ASSERT_APPROXIMATE(fourthMatrix(1,1),1.0f,1e-5f);

			FloatMatrix2 fifthMatrix = secondMatrix.Adjoint();
			fifthMatrix /= determinant;

			fourthMatrix = fifthMatrix * secondMatrix;

			ASSERT_TRUE(Approximate(fourthMatrix, FloatMatrix2::GetIdentity(),1e-5f));
		}
		
		float angle = angleRandomDistribution(generator);
		
		FloatMatrix2 sixthMatrix(angle);
		
		ASSERT_APPROXIMATE(angle,sixthMatrix.ExtractAngle(),1e-7f);
		
		FloatMatrix2 seventhMatrix(sixthMatrix);
		
		seventhMatrix.Orthonormalize();

		FloatVector2D thirdVector(sixthMatrix(0,0),sixthMatrix(1,0));
		FloatVector2D fourthVector(seventhMatrix(0,0),seventhMatrix(1,0));

		thirdVector.Normalize();

		ASSERT_TRUE(FloatVector2DTools::Approximate(thirdVector, fourthVector,1e-7f)); 

		FloatVector2D fifthVector(sixthMatrix(0,1),sixthMatrix(1,1));
		FloatVector2D sixthVector(seventhMatrix(0,1),seventhMatrix(1,1));

		fifthVector -= (FloatVector2DTools::DotProduct(fourthVector , fifthVector)) * fourthVector;

		fifthVector.Normalize();

		ASSERT_TRUE(FloatVector2DTools::Approximate(fifthVector, sixthVector,1e-7f)); 

		DoubleMatrix2 eighthMatrix(randomDistribution(generator),angle,angle,randomDistribution(generator));
		
		DoubleMatrix2::Matrix2EigenDecomposition eigenDecomposition = eighthMatrix.EigenDecomposition(1e-10);

		DoubleMatrix2 rotation = eigenDecomposition.GetRotation();
		DoubleMatrix2 diagonal = eigenDecomposition.GetDiagonal();

		DoubleMatrix2 ninthMatrix = rotation * diagonal * rotation.Transpose();

		ASSERT_TRUE(Approximate(ninthMatrix, eighthMatrix,1e-10)); 	
	}
}
