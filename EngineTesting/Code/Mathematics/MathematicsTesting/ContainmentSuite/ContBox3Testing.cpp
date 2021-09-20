// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 19:03)

#include "ContBox3Testing.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Containment/ContBox3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

namespace Mathematics
{
	template class ContBox3<float>;
	template class ContBox3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, ContBox3Testing) 

void Mathematics::ContBox3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ContAlignedBoxTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ContOrientedBoxTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MergeBoxesTest);
}

void Mathematics::ContBox3Testing
	::ContAlignedBoxTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	std::uniform_int<> secondRandomDistribution(10, 50);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector3D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(DoubleVector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleBox3 box = ContBox3d::ContAlignedBox(vertices);
		
		for (int i = 0; i < size; ++i)
		{
			 ASSERT_TRUE(ContBox3d::InBox(vertices[i],box));
		}
	}
}

void Mathematics::ContBox3Testing
	::ContOrientedBoxTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	std::uniform_int<> secondRandomDistribution(10, 50);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector3D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(DoubleVector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleBox3 box = ContBox3d::ContOrientedBox(vertices);

		for (int i = 0; i < size; ++i)
		{
			ASSERT_TRUE(ContBox3d::InBox(vertices[i],box));
		}
	}
}

void Mathematics::ContBox3Testing
	::MergeBoxesTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	std::uniform_int<> secondRandomDistribution(10, 50);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector3D> firstVertices;
		int firstSize = secondRandomDistribution(generator);

		for (int i = 0; i < firstSize; ++i)
		{
			firstVertices.push_back(DoubleVector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleBox3 firstBox = ContBox3d::ContAlignedBox(firstVertices);

		std::vector<DoubleVector3D> secondVertices;
		int secondSize = secondRandomDistribution(generator);

		for (int i = 0; i < secondSize; ++i)
		{
			secondVertices.push_back(DoubleVector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleBox3 secondBox = ContBox3d::ContOrientedBox(secondVertices);

		DoubleBox3 thirdBox = ContBox3d::MergeBoxes(firstBox,secondBox);

		for (int i = 0; i < firstSize; ++i)
		{
			ASSERT_TRUE(ContBox3d::InBox(firstVertices[i],thirdBox));
		}

		for (int i = 0; i < secondSize; ++i)
		{
			ASSERT_TRUE(ContBox3d::InBox(secondVertices[i],thirdBox));
		}
	}
}

