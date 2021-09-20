// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 10:24)

#include "VariableMatrixTesting.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
	template class VariableMatrix<float>;
	template class VariableMatrix<double>;
}

#endif // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,VariableMatrixTesting) 

void Mathematics::VariableMatrixTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MatrixCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::VariableMatrixTesting
	::ConstructionTest()
{
	FloatVariableMatrix firstVariableMatrix;

	ASSERT_EQUAL(firstVariableMatrix.GetRowsNumber(),0);
	ASSERT_EQUAL(firstVariableMatrix.GetColumnsNumber(),0);
	ASSERT_EQUAL(firstVariableMatrix.GetElementsNumber(),0);

	DoubleVariableMatrix secondVariableMatrix(5,6);

	ASSERT_EQUAL(secondVariableMatrix.GetRowsNumber(),5);
	ASSERT_EQUAL(secondVariableMatrix.GetColumnsNumber(),6);
	ASSERT_EQUAL(secondVariableMatrix.GetElementsNumber(),30);

	for(int row = 0;row < secondVariableMatrix.GetRowsNumber();++row)
	{
		for(int column = 0;column < secondVariableMatrix.GetColumnsNumber();++column)
		{
			ASSERT_APPROXIMATE(secondVariableMatrix(row,column),0.0,1e-10);
		}
	}

	vector<double> firstEntry{ 3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };

	DoubleVariableMatrix thirdVariableMatrix(2,4,firstEntry);

	ASSERT_EQUAL(thirdVariableMatrix.GetRowsNumber(),2);
	ASSERT_EQUAL(thirdVariableMatrix.GetColumnsNumber(),4);
	ASSERT_EQUAL(thirdVariableMatrix.GetElementsNumber(),8);

	for(int row = 0;row < thirdVariableMatrix.GetRowsNumber();++row)
	{
		for(int column = 0;column < thirdVariableMatrix.GetColumnsNumber();++column)
		{
			auto temp = row * thirdVariableMatrix.GetColumnsNumber() ;
			auto temp2 =  temp + column;
			ASSERT_APPROXIMATE(thirdVariableMatrix(row,column),
				               firstEntry[temp2],
							   1e-10);		
		}
	}

	vector<double> secondEntry{ -3.0,-4.0,-5.0,-6.0,-7.0,-8.0,-9.0,-10.0 };

	vector<vector<double> > entryVector{ firstEntry,secondEntry };

// 	DoubleVariableMatrix fourthVariableMatrix(2,8,entryVector);
// 
// 	ASSERT_EQUAL(fourthVariableMatrix.GetRowsNumber(),2);
// 	ASSERT_EQUAL(fourthVariableMatrix.GetColumnsNumber(),8);
// 	ASSERT_EQUAL(fourthVariableMatrix.GetElementsNumber(),16);
// 
// 	for(int row = 0;row < fourthVariableMatrix.GetRowsNumber();++row)
// 	{
// 		for(int column = 0;column < fourthVariableMatrix.GetColumnsNumber();++column)
// 		{
// 			ASSERT_APPROXIMATE(fourthVariableMatrix(row,column),entryVector[row][column],1e-10);		
// 		}
// 	}
// 
// 	DoubleVariableMatrix fifthVariableMatrix(fourthVariableMatrix);
// 
// 	ASSERT_EQUAL(fifthVariableMatrix.GetRowsNumber(),2);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetColumnsNumber(),8);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetElementsNumber(),16);
// 
// 	ASSERT_TRUE(Approximate(fifthVariableMatrix,fourthVariableMatrix,1e-10)); 
// 
// 	thirdVariableMatrix = fifthVariableMatrix;
// 	
// 	ASSERT_EQUAL(thirdVariableMatrix.GetRowsNumber(),2);
// 	ASSERT_EQUAL(thirdVariableMatrix.GetColumnsNumber(),8);
// 	ASSERT_EQUAL(thirdVariableMatrix.GetElementsNumber(),16);
// 
// 	ASSERT_TRUE(Approximate(fifthVariableMatrix, thirdVariableMatrix,1e-10)); 
// 
// 	fifthVariableMatrix.ResetSize(10,10);
// 
// 	ASSERT_EQUAL(fifthVariableMatrix.GetRowsNumber(),10);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetColumnsNumber(),10);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetElementsNumber(),100);
// 
// 	for(int row = 0;row < fifthVariableMatrix.GetRowsNumber();++row)
// 	{
// 		for(int column = 0;column < fifthVariableMatrix.GetColumnsNumber();++column)
// 		{
// 			ASSERT_APPROXIMATE(fifthVariableMatrix(row,column),0.0,1e-10);		
// 		}
// 	}	
// 
// 	fifthVariableMatrix.ResetMatrix(4,2,firstEntry);
// 
// 	ASSERT_EQUAL(fifthVariableMatrix.GetRowsNumber(),4);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetColumnsNumber(),2);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetElementsNumber(),8);
// 
// 	for(int row = 0;row < fifthVariableMatrix.GetRowsNumber();++row)
// 	{
// 		for(int column = 0;column < fifthVariableMatrix.GetColumnsNumber();++column)
// 		{
// 			auto temp = row * fifthVariableMatrix.GetColumnsNumber();
// 			auto temp2 = temp + column;
// 			ASSERT_APPROXIMATE(fifthVariableMatrix(row,column),firstEntry[temp2],1e-10);
// 		}
// 	}
// 
// 	fifthVariableMatrix.ResetMatrix(2,8,entryVector);
// 
// 	ASSERT_EQUAL(fifthVariableMatrix.GetRowsNumber(),2);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetColumnsNumber(),8);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetElementsNumber(),16);
// 
// 	for(int row = 0;row < fifthVariableMatrix.GetRowsNumber();++row)
// 	{
// 		for(int column = 0;column < fifthVariableMatrix.GetColumnsNumber();++column)
// 		{
// 			ASSERT_APPROXIMATE(fifthVariableMatrix(row,column),entryVector[row][column],1e-10);		
// 		}
// 	}
// 
// 	fifthVariableMatrix.SwapRows(0,1);
// 
// 	ASSERT_EQUAL(fifthVariableMatrix.GetRowsNumber(),2);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetColumnsNumber(),8);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetElementsNumber(),16);
// 
// 	for(int row = 0;row < fifthVariableMatrix.GetRowsNumber();++row)
// 	{
// 		for(int column = 0;column < fifthVariableMatrix.GetColumnsNumber();++column)
// 		{
// 			int newRow = row;
// 
// 			if(row == 1)
// 				newRow = 0;
// 			else if(row == 0)
// 				newRow = 1;
// 
// 			ASSERT_APPROXIMATE(fifthVariableMatrix(row,column),entryVector[newRow][column],1e-10);		
// 		}
// 	}
// 	
// 	fifthVariableMatrix.SwapColumns(0,2);
// 
// 	ASSERT_EQUAL(fifthVariableMatrix.GetRowsNumber(),2);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetColumnsNumber(),8);
// 	ASSERT_EQUAL(fifthVariableMatrix.GetElementsNumber(),16);
// 
// 	for(int row = 0;row < fifthVariableMatrix.GetRowsNumber();++row)
// 	{
// 		for(int column = 0;column < fifthVariableMatrix.GetColumnsNumber();++column)
// 		{
// 			int newRow = row;
// 
// 			if(row == 1)
// 				newRow = 0;
// 			else if(row == 0)
// 				newRow = 1;
// 
// 			int newColumn = column;
// 
// 			if(column == 2)
// 				newColumn = 0;
// 			else if(column == 0)
// 				newColumn = 2;
// 
// 			ASSERT_APPROXIMATE(fifthVariableMatrix(row,column),entryVector[newRow][newColumn],1e-10);		
// 		}
// 	}
}

void Mathematics::VariableMatrixTesting
	::AccessTest()
{
	vector<double> firstEntry{ 3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };

	const DoubleVariableMatrix firstVariableMatrix(2,4,firstEntry);

	ASSERT_EQUAL(firstVariableMatrix.GetRowsNumber(),2);
	ASSERT_EQUAL(firstVariableMatrix.GetColumnsNumber(),4);
	ASSERT_EQUAL(firstVariableMatrix.GetElementsNumber(),8);

// 	const double* firstPtr = firstVariableMatrix.GetElements();
// 
// 	for(int row = 0;row < firstVariableMatrix.GetRowsNumber();++row)
// 	{
// 		for(int column = 0;column < firstVariableMatrix.GetColumnsNumber();++column)
// 		{
// 			auto temp = row * firstVariableMatrix.GetColumnsNumber() ;
// 			auto temp2 =  temp + column;
// 			ASSERT_APPROXIMATE(firstVariableMatrix(row,column),firstEntry[temp2],1e-10);
// 
// 			ASSERT_APPROXIMATE(firstVariableMatrix[row][column],firstEntry[temp2],1e-10);
// 
// 			ASSERT_APPROXIMATE(firstPtr[temp2],
// 				               firstEntry[temp2],
// 							   1e-10);
// 		}
// 	}
// 
// 	DoubleVariableMatrix secondVariableMatrix(5,4);
// 
// 	const double* secondPtr = secondVariableMatrix.GetElements();
// 
// 	for(int row = 0;row < secondVariableMatrix.GetRowsNumber();++row)
// 	{
// 		for(int column = 0;column < secondVariableMatrix.GetColumnsNumber();++column)
// 		{
// 			ASSERT_APPROXIMATE(secondVariableMatrix(row,column),0.0,1e-10);	
// 
// 			ASSERT_APPROXIMATE(secondVariableMatrix[row][column],0.0,1e-10);
// 
// 			ASSERT_APPROXIMATE(secondPtr[row * secondVariableMatrix.GetColumnsNumber() + column],0.0,1e-10);
// 		}
// 	}
// 
// 	for(int i = 0;i < secondVariableMatrix.GetColumnsNumber();++i)
// 	{		
// 		secondVariableMatrix[0][i] = i * 3.0;
// 	}
// 
// 	DoubleVariableLengthVector firstVector = secondVariableMatrix.GetRow(0);
// 
// 	ASSERT_EQUAL(firstVector.GetSize(),4);
// 
// 	for(int i = 0;i < firstVector.GetSize();++i)
// 	{
// 		ASSERT_APPROXIMATE(firstVector[i],i * 3.0,1e-10);
// 		firstVector[i] = i * 2.0;
// 	}
// 
// 	secondVariableMatrix.SetRow(1,firstVector);
// 
// 	for(int i = 0;i < firstVector.GetSize();++i)
// 	{
// 		ASSERT_APPROXIMATE(secondVariableMatrix[1][i],i * 2.0,1e-10);
// 	}
// 
// 	for(int i = 0;i < secondVariableMatrix.GetRowsNumber();++i)
// 	{		
// 		secondVariableMatrix[i][2] = i * 3.0;
// 	}
// 
// 	firstVector = secondVariableMatrix.GetColumn(2);
// 
// 	ASSERT_EQUAL(firstVector.GetSize(),5);
// 
// 	for(int i = 0;i < firstVector.GetSize();++i)
// 	{
// 		ASSERT_APPROXIMATE(firstVector[i],i * 3.0,1e-10);
// 		firstVector[i] = i * 2.0;
// 	}
// 
// 	secondVariableMatrix.SetColumn(0,firstVector);
// 
// 	for(int i = 0;i < firstVector.GetSize();++i)
// 	{
// 		ASSERT_APPROXIMATE(secondVariableMatrix[i][0],i * 2.0,1e-10);
// 	}
}

void Mathematics::VariableMatrixTesting
	::ArithmeticCalculateTest()
{
	default_random_engine generator{};

	uniform_real<float> floatRandomDistribution{ -100.0f, 100.0f };
	uniform_int<>  integerRandomDistribution(1,20);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVariableMatrix firstMatrix(integerRandomDistribution(generator), integerRandomDistribution(generator));

		for(int row = 0;row < firstMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < firstMatrix.GetColumnsNumber();
				++column)
			{
				firstMatrix[row][column] = floatRandomDistribution(generator);
			}

		}

		FloatVariableMatrix secondMatrix(firstMatrix.GetColumnsNumber(),integerRandomDistribution(generator));


		for(int row = 0;row < secondMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < secondMatrix.GetColumnsNumber();++column)
			{
				secondMatrix[row][column] = floatRandomDistribution(generator);
			}

		}

		FloatVariableMatrix thirdMatrix = firstMatrix * secondMatrix;

		ASSERT_EQUAL(thirdMatrix.GetRowsNumber(),firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(thirdMatrix.GetColumnsNumber(),secondMatrix.GetColumnsNumber());
		ASSERT_EQUAL(thirdMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * secondMatrix.GetColumnsNumber());

		for(int row = 0;row < thirdMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < thirdMatrix.GetColumnsNumber(); ++column)
			{
				float sum = 0;
				for(int index = 0;index < firstMatrix.GetColumnsNumber(); ++index)
				{
					sum += firstMatrix(row,index) * secondMatrix(index,column);				 
				}

				ASSERT_APPROXIMATE(sum,thirdMatrix(row,column),1e-10f);
			}

		}

		thirdMatrix = firstMatrix;

		thirdMatrix *= secondMatrix;

		ASSERT_EQUAL(thirdMatrix.GetRowsNumber(),firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(thirdMatrix.GetColumnsNumber(),secondMatrix.GetColumnsNumber());
		ASSERT_EQUAL(thirdMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * secondMatrix.GetColumnsNumber());

		for(int row = 0;row < thirdMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < thirdMatrix.GetColumnsNumber();++column)
			{
				float sum = 0;
				for(int index = 0;index < firstMatrix.GetColumnsNumber();++index)
				{
					sum += firstMatrix(row,index) * secondMatrix(index,column);				 
				}

				ASSERT_APPROXIMATE(sum,thirdMatrix(row,column),1e-10f);
			}

		}

		thirdMatrix = -firstMatrix;

		ASSERT_EQUAL(thirdMatrix.GetRowsNumber(),firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(thirdMatrix.GetColumnsNumber(),firstMatrix.GetColumnsNumber());
		ASSERT_EQUAL(thirdMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

		for(int row = 0;row < thirdMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < thirdMatrix.GetColumnsNumber();++column)
			{
				ASSERT_APPROXIMATE(firstMatrix(row,column),-thirdMatrix(row,column),1e-10f);
			}

		}

		FloatVariableMatrix fourthMatrix(firstMatrix.GetRowsNumber(),firstMatrix.GetColumnsNumber());

		FloatVariableMatrix fifthMatrix = firstMatrix + fourthMatrix;

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(),firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),firstMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

		for(int row = 0;row < fifthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fifthMatrix.GetColumnsNumber();++column)
			{
				ASSERT_APPROXIMATE(fifthMatrix(row,column),firstMatrix(row,column) + fourthMatrix(row,column),1e-10f);
			}

		}

		fifthMatrix = firstMatrix;

		fifthMatrix += fourthMatrix;

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(),firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),firstMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

		for(int row = 0;row < fifthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fifthMatrix.GetColumnsNumber();++column)
			{
				ASSERT_APPROXIMATE(fifthMatrix(row,column),firstMatrix(row,column) + fourthMatrix(row,column),1e-10f);
			}

		}

		fifthMatrix = firstMatrix - fourthMatrix;

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(),firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),firstMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

		for(int row = 0;row < fifthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fifthMatrix.GetColumnsNumber();++column)
			{
				ASSERT_APPROXIMATE(fifthMatrix(row,column),firstMatrix(row,column) - fourthMatrix(row,column), 1e-10f);
			}

		}

		fifthMatrix = firstMatrix;

		fifthMatrix -= fourthMatrix;

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(),firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),firstMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

		for(int row = 0;row < fifthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fifthMatrix.GetColumnsNumber();++column)
			{
				ASSERT_APPROXIMATE(fifthMatrix(row,column), firstMatrix(row,column) - fourthMatrix(row,column),1e-10f);
			}

		}

		fifthMatrix = firstMatrix * 3.0f;

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(),firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),firstMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

		for(int row = 0;row < fifthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fifthMatrix.GetColumnsNumber();++column)
			{
				ASSERT_APPROXIMATE(fifthMatrix(row,column),firstMatrix(row,column) * 3.0f,1e-10f);
			}

		}

		fifthMatrix = 2.5f * firstMatrix;

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(),firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),firstMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

		for(int row = 0;row < fifthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fifthMatrix.GetColumnsNumber();++column)
			{
				ASSERT_APPROXIMATE(fifthMatrix(row,column),firstMatrix(row,column) * 2.5f,1e-10f);
			}

		}

		fifthMatrix = firstMatrix;

		fifthMatrix *= 4.0f;

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(),firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),firstMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

		for(int row = 0;row < fifthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fifthMatrix.GetColumnsNumber();++column)
			{
				ASSERT_APPROXIMATE(fifthMatrix(row,column),firstMatrix(row,column) * 4.0f,1e-10f);
			}

		}

		fifthMatrix = firstMatrix / 3.0f;

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(), firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),firstMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

		for(int row = 0;row < fifthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fifthMatrix.GetColumnsNumber();++column)
			{
				ASSERT_APPROXIMATE(fifthMatrix(row,column),firstMatrix(row,column) / 3.0f,1e-10f);
			}

		}

		fifthMatrix = firstMatrix;

		fifthMatrix /= 4.0f;

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(),firstMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),firstMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),firstMatrix.GetRowsNumber() * firstMatrix.GetColumnsNumber());

		for(int row = 0;row < fifthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fifthMatrix.GetColumnsNumber();++column)
			{
				ASSERT_APPROXIMATE(fifthMatrix(row,column),firstMatrix(row,column) / 4.0f,1e-10f);
			}

		}		
	}
}

void Mathematics::VariableMatrixTesting
	::MatrixCalculateTest()
{
	default_random_engine generator{};

	uniform_real<float> floatRandomDistribution{ -100.0f, 100.0f };
	uniform_int<>  integerRandomDistribution(1, 20);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop) 
	{
		FloatVariableMatrix firstMatrix(integerRandomDistribution(generator),integerRandomDistribution(generator));


		for(int row = 0;row < firstMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < firstMatrix.GetColumnsNumber();++column)
			{
				firstMatrix[row][column] = floatRandomDistribution(generator);
			}

		}

		FloatVariableLengthVector firstVector(firstMatrix.GetRowsNumber());

		for(int index = 0;index < firstVector.GetSize();++index)
		{
			firstVector[index] = floatRandomDistribution(generator);
		}

		FloatVariableLengthVector secondVector(firstMatrix.GetColumnsNumber());

		for(int index = 0;index < secondVector.GetSize();++index)
		{
			secondVector[index] = floatRandomDistribution(generator);
		}

		float quadraticForm = Dot(firstVector,firstMatrix * secondVector);

		ASSERT_APPROXIMATE(quadraticForm,firstMatrix.QuadraticForm(firstVector,secondVector),1e-10f);

		FloatVariableMatrix secondMatrix = firstMatrix.Transpose();

		ASSERT_EQUAL(firstMatrix.GetRowsNumber(),secondMatrix.GetColumnsNumber());
		ASSERT_EQUAL(firstMatrix.GetColumnsNumber(),secondMatrix.GetRowsNumber());
		ASSERT_EQUAL(firstMatrix.GetElementsNumber(), secondMatrix.GetElementsNumber());

		for(int row = 0;row < firstMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < firstMatrix.GetColumnsNumber();++column)
			{
				ASSERT_APPROXIMATE(firstMatrix[row][column],secondMatrix[column][row],1e-10f);
			}

		}

		FloatVariableLengthVector thirdVector = firstMatrix * secondVector;

		ASSERT_EQUAL(thirdVector.GetSize(),firstMatrix.GetRowsNumber());

		FloatVariableLengthVector fourthVector(firstMatrix.GetRowsNumber());

		for (int rows = 0; rows < firstMatrix.GetRowsNumber(); ++rows)
		{
			for (int columns = 0; columns < firstMatrix.GetColumnsNumber();++columns)
			{
				fourthVector[rows] += firstMatrix[rows][columns] * secondVector[columns];
			}
		}

		ASSERT_TRUE(Approximate(thirdVector, fourthVector,1e-10f)); 

		secondVector.ResetSize(firstMatrix.GetRowsNumber());

		for (int index = 0; index < secondVector.GetSize(); ++index)
		{
			secondVector[index] = floatRandomDistribution(generator);
		}

		thirdVector = secondVector * firstMatrix;

		ASSERT_EQUAL(thirdVector.GetSize(),firstMatrix.GetColumnsNumber());

		fourthVector.ResetSize(firstMatrix.GetColumnsNumber());

		for (int rows = 0; rows < firstMatrix.GetRowsNumber(); ++rows)
		{
			for (int columns = 0; columns < firstMatrix.GetColumnsNumber();++columns)
			{
				fourthVector[columns] += firstMatrix[rows][columns] * secondVector[rows];
			}
		}

		ASSERT_TRUE(Approximate(thirdVector, fourthVector,1e-10f)); 

		DoubleVariableMatrix thirdMatrix(integerRandomDistribution(generator),integerRandomDistribution(generator));

		for(int row = 0;row < thirdMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < thirdMatrix.GetColumnsNumber();++column)
			{
				thirdMatrix[row][column] = floatRandomDistribution(generator);
			}
		}

		DoubleVariableMatrix fourthMatrix(thirdMatrix.GetRowsNumber(),integerRandomDistribution(generator));

		for(int row = 0;row < fourthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fourthMatrix.GetColumnsNumber();++column)
			{
				fourthMatrix[row][column] = floatRandomDistribution(generator);
			}
		}

		DoubleVariableMatrix fifthMatrix = TransposeTimes(thirdMatrix,fourthMatrix);
		DoubleVariableMatrix sixthMatrix = thirdMatrix.Transpose() * fourthMatrix;

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(),sixthMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),sixthMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),sixthMatrix.GetElementsNumber());

		ASSERT_TRUE(Approximate(fifthMatrix, sixthMatrix,1e-10));

		fourthMatrix.ResetSize(integerRandomDistribution(generator),thirdMatrix.GetColumnsNumber());

		for(int row = 0;row < fourthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fourthMatrix.GetColumnsNumber();++column)
			{
				fourthMatrix[row][column] = floatRandomDistribution(generator);
			}
		}

		fifthMatrix = TimesTranspose(thirdMatrix,fourthMatrix);
		sixthMatrix = thirdMatrix * fourthMatrix.Transpose();

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(),sixthMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),sixthMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),sixthMatrix.GetElementsNumber());

		ASSERT_TRUE(Approximate(fifthMatrix, sixthMatrix,1e-10));

		fourthMatrix.ResetSize(integerRandomDistribution(generator),thirdMatrix.GetRowsNumber());

		for(int row = 0;row < fourthMatrix.GetRowsNumber();++row)
		{
			for(int column = 0;column < fourthMatrix.GetColumnsNumber();++column)
			{
				fourthMatrix[row][column] = floatRandomDistribution(generator);
			}
		}

		fifthMatrix = TransposeTimesTranspose(thirdMatrix,fourthMatrix);
		sixthMatrix = thirdMatrix.Transpose() * fourthMatrix.Transpose();

		ASSERT_EQUAL(fifthMatrix.GetRowsNumber(),sixthMatrix.GetRowsNumber());
		ASSERT_EQUAL(fifthMatrix.GetColumnsNumber(),sixthMatrix.GetColumnsNumber());
		ASSERT_EQUAL(fifthMatrix.GetElementsNumber(),sixthMatrix.GetElementsNumber());

		ASSERT_TRUE(Approximate(fifthMatrix, sixthMatrix,1e-10));
	}
}

void Mathematics::VariableMatrixTesting
	::CompareTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0, 100.0 };

	vector<double> firstDoubleVector;
	for(int i = 0;i < 15;++i)
	{
		firstDoubleVector.push_back(randomDistribution(generator));
	}

	vector<double> secondDoubleVector;
	for(int i = 0;i < 15;++i)
	{
		secondDoubleVector.push_back(randomDistribution(generator));
	}

	DoubleVariableMatrix firstMatrix(3,5,firstDoubleVector);
	DoubleVariableMatrix secondMatrix(3,5,secondDoubleVector);	

	firstMatrix[0][0]  = 0.0;
	secondMatrix[0][0]  = 1.0;

	ASSERT_TRUE(firstMatrix == firstMatrix);
	ASSERT_FALSE(firstMatrix != firstMatrix);
	ASSERT_FALSE(firstMatrix == secondMatrix);
	ASSERT_TRUE(firstMatrix != secondMatrix);
	ASSERT_TRUE(firstMatrix < secondMatrix);
	ASSERT_TRUE(firstMatrix <= secondMatrix);
	ASSERT_FALSE(firstMatrix > secondMatrix);
	ASSERT_FALSE(firstMatrix >= secondMatrix);

	ASSERT_TRUE(Approximate(firstMatrix, firstMatrix,1e-10));
	ASSERT_TRUE(Approximate(secondMatrix, secondMatrix));
	ASSERT_FALSE(Approximate(secondMatrix, firstMatrix));
}


