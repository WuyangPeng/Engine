// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/28 16:28)

#include "CylinderFit3Testing.h"
#include "Mathematics/Approximation/CylinderFit3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/Algebra/Vector3DTools.h"

using std::vector;
using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class CylinderFit3<float>;
	template class CylinderFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, CylinderFit3Testing) 

void Mathematics::CylinderFit3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::CylinderFit3Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(10, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		vector<DoubleVector3D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(DoubleVector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleCylinderFit3 fit(vertices);

		double exactly = fit.GetExactly();

		ASSERT_TRUE(exactly <= 1.0);

		DoubleVector3D center = fit.GetCenter();
		DoubleVector3D axis = fit.GetAxis();
		double radius = fit.GetRadius();
		double height = fit.GetHeight();	 

		double maxDistance = DoubleMath::Sqrt(radius * radius + height * height);
		maxDistance = DoubleMath::Sqrt(radius * radius + maxDistance * maxDistance);

		for (int i = 0; i < size; ++i)
		{
			 // 计算点到原点的距离
			double distance = DoubleVector3DTools::Distance(vertices[i], center);
			 
			ASSERT_TRUE(distance <= maxDistance); 
		}
	}
}

