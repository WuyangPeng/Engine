// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 19:03)

#include "ContBox3Testing.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::ContBox3Testing
	::ContAlignedBoxTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	std::uniform_int<> secondRandomDistribution(10, 50);

	const auto testLoopCount = GetTestLoopCount();
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<Vector3D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		Box3D box = ContBox3D::ContAlignedBox(vertices);
		
		for (int i = 0; i < size; ++i)
		{
			 ASSERT_TRUE(ContBox3D::InBox(vertices[i],box));
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
		std::vector<Vector3D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		Box3D box = ContBox3D::ContOrientedBox(vertices);

		for (int i = 0; i < size; ++i)
		{
			ASSERT_TRUE(ContBox3D::InBox(vertices[i],box));
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
		std::vector<Vector3D> firstVertices;
		int firstSize = secondRandomDistribution(generator);

		for (int i = 0; i < firstSize; ++i)
		{
			firstVertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		Box3D firstBox = ContBox3D::ContAlignedBox(firstVertices);

		std::vector<Vector3D> secondVertices;
		int secondSize = secondRandomDistribution(generator);

		for (int i = 0; i < secondSize; ++i)
		{
			secondVertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		Box3D secondBox = ContBox3D::ContOrientedBox(secondVertices);

		Box3D thirdBox = ContBox3D::MergeBoxes(firstBox,secondBox);

		for (int i = 0; i < firstSize; ++i)
		{
			ASSERT_TRUE(ContBox3D::InBox(firstVertices[i],thirdBox));
		}

		for (int i = 0; i < secondSize; ++i)
		{
			ASSERT_TRUE(ContBox3D::InBox(secondVertices[i],thirdBox));
		}
	}
}

