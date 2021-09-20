// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/21 14:16)

#include "BandedMatrixSolveTesting.h"
#include "Mathematics/Algebra/BandedMatrixSolveDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/Algebra/Flags/MatrixFlags.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class BandedMatrixSolve<float>;
	template class BandedMatrixSolve<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,BandedMatrixSolveTesting) 

void Mathematics::BandedMatrixSolveTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SolveTest);
}

void Mathematics::BandedMatrixSolveTesting
	::ConstructionTest()
{
	default_random_engine generator{};
	uniform_int<> firstIntegerRandomDistribution{ 2,20 }; 

	int size = firstIntegerRandomDistribution(generator);

	uniform_int<> secondIntegerRandomDistribution{ 1,size };

	int lowerBoundNumber = secondIntegerRandomDistribution(generator);
	int upperBoundNumber = secondIntegerRandomDistribution(generator);

	DoubleBandedMatrixSolve firstBandedMatrix(size,lowerBoundNumber,upperBoundNumber);

	ASSERT_EQUAL(firstBandedMatrix.GetSize (),size);
	ASSERT_EQUAL(firstBandedMatrix.GetLowerBandsNumber () ,lowerBoundNumber);
	ASSERT_EQUAL(firstBandedMatrix.GetUpperBandsNumber () ,upperBoundNumber);

	// 对角线
	for(int i = 0;i < firstBandedMatrix.GetSize();++i)
	{
		firstBandedMatrix(i,i) = i * 1.0;
	}
	
	auto firstPtr = firstBandedMatrix.GetDiagonalBand();

	for(int i = 0;i < firstBandedMatrix.GetSize();++i)
	{
		ASSERT_APPROXIMATE(firstBandedMatrix(i,i),firstPtr[i],1e-10);
	}

	// 下三角
	for(int row = 0;row < firstBandedMatrix.GetSize();++row)
	{
		for(int column = 0;column < firstBandedMatrix.GetSize();++column)
		{
			int band = column - row;
			if(band < 0 && -band - 1 < firstBandedMatrix.GetLowerBandsNumber())
			{
				firstBandedMatrix(row,column) = row * 1.0 - column * 0.1;
			}
		}
	}

	for(int i = 0;i < firstBandedMatrix.GetLowerBandsNumber();++i)
	{
		ASSERT_EQUAL(firstBandedMatrix.GetLowerBandMax(i),firstBandedMatrix.GetSize() - 1 - i);

		auto secondPtr = firstBandedMatrix.GetLowerBand(i);

		for(int j = 0;j < firstBandedMatrix.GetLowerBandMax(i);++j)
		{
			ASSERT_APPROXIMATE(firstBandedMatrix(i + 1 + j,j),secondPtr[j],1e-10);
		}
	}
	
	// 上三角
	for(int row = 0;row < firstBandedMatrix.GetSize();++row)
	{
		for(int column = 0;column < firstBandedMatrix.GetSize();++column)
		{
			int band = column - row;
			if(0 < band && band - 1 < firstBandedMatrix.GetUpperBandsNumber())
			{
				firstBandedMatrix(row,column) = row * 2.0 - column * 0.3;
			}
		}
	}

	for(int i = 0;i < firstBandedMatrix.GetUpperBandsNumber();++i)
	{
		ASSERT_EQUAL(firstBandedMatrix.GetUpperBandMax(i),firstBandedMatrix.GetSize() - 1 - i);

		auto secondPtr = firstBandedMatrix.GetUpperBand(i);

		for(int j = 0;j < firstBandedMatrix.GetUpperBandMax(i);++j)
		{
			ASSERT_APPROXIMATE(firstBandedMatrix(j,i + 1 + j),secondPtr[j],1e-10);
		}
	}

	// 其他元素为零
	for(int row = 0;row < firstBandedMatrix.GetSize();++row)
	{
		for(int column = 0;column < firstBandedMatrix.GetSize();++column)
		{
			int band = column - row;

			if (0 < band && firstBandedMatrix.GetUpperBandsNumber() <= band - 1)
			{				
				ASSERT_APPROXIMATE(firstBandedMatrix(row,column),0.0,1e-10);								
			}
			else if (band < 0 && firstBandedMatrix.GetUpperBandsNumber() <=  -band - 1)
			{			
				ASSERT_APPROXIMATE(firstBandedMatrix(row,column),0.0,1e-10);								
			}
		}
	}

	const DoubleBandedMatrixSolve secondBandedMatrix(firstBandedMatrix);

	ASSERT_EQUAL(secondBandedMatrix.GetSize (),firstBandedMatrix.GetSize());
	ASSERT_EQUAL(secondBandedMatrix.GetLowerBandsNumber () ,firstBandedMatrix.GetLowerBandsNumber());
	ASSERT_EQUAL(secondBandedMatrix.GetUpperBandsNumber () ,firstBandedMatrix.GetUpperBandsNumber());

	for(int row = 0;row < firstBandedMatrix.GetSize();++row)
	{
		for(int column = 0;column < firstBandedMatrix.GetSize();++column)
		{
			ASSERT_APPROXIMATE(firstBandedMatrix(row,column),secondBandedMatrix(row,column),1e-10);
		}
	}

	// 对角线	
	const auto thirdPtr = secondBandedMatrix.GetDiagonalBand();

	for(int i = 0;i < secondBandedMatrix.GetSize();++i)
	{
		ASSERT_APPROXIMATE(secondBandedMatrix(i,i),thirdPtr[i],1e-10);
	}

	// 下三角

	for(int i = 0;i < secondBandedMatrix.GetLowerBandsNumber();++i)
	{
		ASSERT_EQUAL(secondBandedMatrix.GetLowerBandMax(i),secondBandedMatrix.GetSize() - 1 - i);

		const auto fourthPtr = secondBandedMatrix.GetLowerBand(i);

		for(int j = 0;j < secondBandedMatrix.GetLowerBandMax(i);++j)
		{
			ASSERT_APPROXIMATE(secondBandedMatrix(i + 1 + j,j),fourthPtr[j],1e-10);
		}
	}
	
	// 上三角

	for(int i = 0;i < secondBandedMatrix.GetUpperBandsNumber();++i)
	{
		ASSERT_EQUAL(secondBandedMatrix.GetUpperBandMax(i),secondBandedMatrix.GetSize() - 1 - i);

		const auto fifthPtr = secondBandedMatrix.GetUpperBand(i);

		for(int j = 0;j < secondBandedMatrix.GetUpperBandMax(i);++j)
		{
			ASSERT_APPROXIMATE(secondBandedMatrix(j,i + 1 + j),fifthPtr[j],1e-10);
		}
	}

	// 其他元素为零
	for(int row = 0;row < secondBandedMatrix.GetSize();++row)
	{
		for(int column = 0;column < secondBandedMatrix.GetSize();++column)
		{
			int band = column - row;

			if (0 < band && secondBandedMatrix.GetUpperBandsNumber() <= band - 1)
			{				
				ASSERT_APPROXIMATE(secondBandedMatrix(row,column),0.0,1e-10);								
			}
			else if (band < 0 && secondBandedMatrix.GetUpperBandsNumber() <=  -band - 1)
			{			
				ASSERT_APPROXIMATE(secondBandedMatrix(row,column),0.0,1e-10);								
			}
		}
	}

	DoubleBandedMatrixSolve thirdBandedMatrix(5,1,1);

	for(int i = 0;i < thirdBandedMatrix.GetSize();++i)
	{
		thirdBandedMatrix(i,i) = i * 1.0;
	}

	for(int row = 0;row < thirdBandedMatrix.GetSize();++row)
	{
		for(int column = 0;column < thirdBandedMatrix.GetSize();++column)
		{
			int band = column - row;
			if(band < 0 && -band - 1 < thirdBandedMatrix.GetLowerBandsNumber())
			{
				thirdBandedMatrix(row,column) = row * 1.0 - column * 0.1;
			}
		}
	}

	for(int row = 0;row < thirdBandedMatrix.GetSize();++row)
	{
		for(int column = 0;column < thirdBandedMatrix.GetSize();++column)
		{
			int band = column - row;
			if(0 < band && band - 1 < thirdBandedMatrix.GetUpperBandsNumber())
			{
				thirdBandedMatrix(row,column) = row * 2.0 - column * 0.2;
			}
		}
	}

	firstBandedMatrix = thirdBandedMatrix;

	ASSERT_EQUAL(thirdBandedMatrix.GetSize (),firstBandedMatrix.GetSize());
	ASSERT_EQUAL(thirdBandedMatrix.GetLowerBandsNumber () ,firstBandedMatrix.GetLowerBandsNumber());
	ASSERT_EQUAL(thirdBandedMatrix.GetUpperBandsNumber () ,firstBandedMatrix.GetUpperBandsNumber());

	for(int row = 0;row < firstBandedMatrix.GetSize();++row)
	{
		for(int column = 0;column < firstBandedMatrix.GetSize();++column)
		{
			ASSERT_APPROXIMATE(firstBandedMatrix(row,column),thirdBandedMatrix(row,column),1e-10);
		}
	}

	DoubleBandedMatrixSolve fourthBandedMatrix(secondBandedMatrix);

	fourthBandedMatrix.SetZero();

	for(int row = 0;row < fourthBandedMatrix.GetSize();++row)
	{
		for(int column = 0;column < fourthBandedMatrix.GetSize();++column)
		{
			ASSERT_APPROXIMATE(fourthBandedMatrix(row,column),0.0,1e-10);
		}
	}

	fourthBandedMatrix.SetIdentity();

	for(int row = 0;row < fourthBandedMatrix.GetSize();++row)
	{
		for(int column = 0;column < fourthBandedMatrix.GetSize();++column)
		{
			if(row == column)
			{
				ASSERT_APPROXIMATE(fourthBandedMatrix(row,column),1.0, 1e-10);
			}
			else
			{
				ASSERT_APPROXIMATE(fourthBandedMatrix(row,column),0.0, 1e-10);
			}
			
		}
	}

	fourthBandedMatrix.SetEpsilon(1e-11);
	ASSERT_APPROXIMATE(fourthBandedMatrix.GetEpsilon(),1e-11, 1e-10);
}

void Mathematics::BandedMatrixSolveTesting
	::SolveTest()
{
	default_random_engine generator{};
	uniform_int<> firstIntegerRandomDistribution{ 2,20 };
	uniform_real<> doubleRandomDistribution{ 1.0,3.0 }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		int size = firstIntegerRandomDistribution(generator);		

		uniform_int<> secondIntegerRandomDistribution(1,size - 1);

		int boundNumber = secondIntegerRandomDistribution(generator);

		DoubleBandedMatrixSolve firstBandedMatrix(size,boundNumber,boundNumber,1e-5);		

		// 下三角
		for(int row = 0;row < firstBandedMatrix.GetSize();++row)
		{
			for(int column = 0;column < firstBandedMatrix.GetSize();++column)
			{
				int band = column - row;
				if(band < 0 && -band - 1 < firstBandedMatrix.GetLowerBandsNumber())
				{
					firstBandedMatrix(row,column) =  doubleRandomDistribution(generator);
				}
			}
		}	

		// 上三角
		for(int row = 0;row < firstBandedMatrix.GetSize();++row)
		{
			for(int column = 0;column < firstBandedMatrix.GetSize();++column)
			{
				int band = column - row;
				if(0 < band && band - 1 < firstBandedMatrix.GetUpperBandsNumber())
				{
					firstBandedMatrix(row,column) = firstBandedMatrix(column,row);
				}
			}
		}	

		// 对角线	
		firstBandedMatrix(0,0) = doubleRandomDistribution(generator);
			
		for(int index = 1;index < firstBandedMatrix.GetSize();++index)
		{
			firstBandedMatrix(index,index) =  firstBandedMatrix(index - 1,index - 1) * firstBandedMatrix(index,index - 1) + doubleRandomDistribution(generator);
		}

	    ASSERT_ENUM_EQUAL(firstBandedMatrix.GetSolve(),BandedMatrixSolveFlags::Unsolved);
		 
		if(!firstBandedMatrix.CholeskyFactor())
		{
			 ASSERT_ENUM_EQUAL(firstBandedMatrix.GetSolve(), BandedMatrixSolveFlags::Failure);
		     continue;  
		}

		ASSERT_ENUM_EQUAL(firstBandedMatrix.GetSolve(), BandedMatrixSolveFlags::Succeed);

		DoubleVariableLengthVector firstVector(firstBandedMatrix.GetSize());

		for(int index = 0;index < firstVector.GetSize();++index)
		{
			firstVector[index] = doubleRandomDistribution(generator);
		}

		DoubleVariableLengthVector secondVector =  firstBandedMatrix.SolveSystem(firstVector);

		ASSERT_TRUE(Approximate(firstBandedMatrix.ToInputVariableMatrix() * secondVector, firstVector,1e-10));
 
		DoubleVariableMatrix firstVariableMatrix(firstBandedMatrix.GetSize(), firstBandedMatrix.GetSize());

		for(int row = 0;row < firstBandedMatrix.GetSize();++row)
		{
			for(int column = 0;column < firstBandedMatrix.GetSize();++column)
			{
				firstVariableMatrix[row][column] = doubleRandomDistribution(generator);
			}
		}

		DoubleVariableMatrix secondVariableMatrix = firstBandedMatrix.SolveSystem(firstVariableMatrix);

		ASSERT_TRUE(Approximate(firstBandedMatrix.ToInputVariableMatrix() * secondVariableMatrix,firstVariableMatrix,1e-10));		 
	}	

	DoubleBandedMatrixSolve fifthBandedMatrix(3,2,2);

	fifthBandedMatrix(0,0) = 6;
	fifthBandedMatrix(0,1) = 7;
	fifthBandedMatrix(0,2) = 5;
	fifthBandedMatrix(1,0) = 7;
	fifthBandedMatrix(1,1) = 13;
	fifthBandedMatrix(1,2) = 8;
	fifthBandedMatrix(2,0) = 5;
	fifthBandedMatrix(2,1) = 8;
	fifthBandedMatrix(2,2) = 6;	 

	ASSERT_ENUM_EQUAL(fifthBandedMatrix.GetSolve(),BandedMatrixSolveFlags::Unsolved);
		 
	if(!fifthBandedMatrix.CholeskyFactor())
	{
	    ASSERT_ENUM_EQUAL(fifthBandedMatrix.GetSolve(),BandedMatrixSolveFlags::Failure);	   
	}
	else
	{
		ASSERT_ENUM_EQUAL(fifthBandedMatrix.GetSolve(), BandedMatrixSolveFlags::Succeed);
	}
}


