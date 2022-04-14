// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/03 15:29)

#include "UtilityTesting.h"
#include "Rendering/DataTypes/Utility.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, UtilityTesting) 
 #include SYSTEM_WARNING_DISABLE(26440)
void Rendering::UtilityTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ReflectXTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ReflectYTest);
}
 
void Rendering::UtilityTesting
	::ReflectXTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 	std::uniform_int<> sizeRandomDistribution(1,20); 
// 	std::uniform_int<> pixelRandomDistribution(1,10); 	
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		int xSize = sizeRandomDistribution(generator);
// 		int ySize = sizeRandomDistribution(generator);
// 		int numBytesPerPixel = pixelRandomDistribution(generator);
// 
// 		vector<char> firstPixels;
// 
// 		int pixelsSize = xSize * ySize * numBytesPerPixel;
// 
// 		for(int i = 0;i < pixelsSize;++i)
// 		{
// 			firstPixels.push_back(integerRandomDistribution(generator));
// 		}		
// 		
// 		vector<char> secondPixels(firstPixels);
// 
// 		Utility::ReflectX(xSize,ySize,numBytesPerPixel,&firstPixels[0]);
// 		Utility::ReflectX(xSize,ySize,numBytesPerPixel,&firstPixels[0]);
// 
// 		ASSERT_EQUAL(firstPixels,secondPixels);
// 
// 		Utility::ReflectX(xSize,ySize,numBytesPerPixel,&firstPixels[0]);
// 
// 		// 判断值是否正确
// 		for(int yIndex = 0;yIndex < ySize;++yIndex)
// 		{
// 			for(int xIndex = 0;xIndex < xSize * numBytesPerPixel;++xIndex)
// 			{
// 				int reflectX = (xSize - (xIndex / numBytesPerPixel) - 1) *
// 					            numBytesPerPixel + (xIndex % numBytesPerPixel);
// 				int firstIndex = yIndex * xSize * numBytesPerPixel + xIndex;
// 				int secondIndex = yIndex * xSize * numBytesPerPixel + reflectX;
// 			 
// 				ASSERT_EQUAL(firstPixels[firstIndex],secondPixels[secondIndex]);
// 			}
// 		}
// 	}
}

void Rendering::UtilityTesting
	::ReflectYTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_int<char> integerRandomDistribution(-128,127); 
// 	std::uniform_int<> sizeRandomDistribution(1,20); 
// 	std::uniform_int<> pixelRandomDistribution(1,10); 	
// 
// 	for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		int xSize = sizeRandomDistribution(generator);
// 		int ySize = sizeRandomDistribution(generator);
// 		int numBytesPerPixel = pixelRandomDistribution(generator);
// 
// 		vector<char> firstPixels;
// 
// 		int pixelsSize = xSize * ySize * numBytesPerPixel;
// 
// 		for(int i = 0;i < pixelsSize;++i)
// 		{
// 			firstPixels.push_back(integerRandomDistribution(generator));
// 		}		
// 
// 		vector<char> secondPixels(firstPixels);
// 
// 		Utility::ReflectY(xSize,ySize,numBytesPerPixel,&firstPixels[0]);
// 		Utility::ReflectY(xSize,ySize,numBytesPerPixel,&firstPixels[0]);
// 
// 		ASSERT_EQUAL(firstPixels,secondPixels);		
// 
// 		Utility::ReflectY(xSize,ySize,numBytesPerPixel,&firstPixels[0]);
// 
// 		// 判断值是否正确
// 		for(int xIndex = 0;xIndex < xSize * numBytesPerPixel;++xIndex)
// 		{
// 			for(int yIndex = 0;yIndex < ySize;++yIndex)
// 			{
// 				int reflectY = ySize - yIndex - 1;
// 				int firstIndex = yIndex * xSize * numBytesPerPixel + xIndex;
// 				int secondIndex = reflectY * xSize * numBytesPerPixel + xIndex;
// 
// 				ASSERT_EQUAL(firstPixels[firstIndex], secondPixels[secondIndex]);
// 			}
// 		}		
// 	}
}

