// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/29 10:42)

#include "GreatArcFit3Testing.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include "Mathematics/Approximation/GreatArcFit3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/Approximation/GreatCircleFit3.h" 

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class GreatArcFit3<float>;
	template class GreatArcFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, GreatArcFit3Testing) 

void Mathematics::GreatArcFit3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::GreatArcFit3Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(0.0, 100.0);
	uniform_int<> secondRandomDistribution(5, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector3D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(DoubleVector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleGreatArcFit3 greatArcFit(vertices);

		DoubleGreatCircleFit3 greatCircleFit(vertices);

		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, greatArcFit.GetNormal(), greatCircleFit.GetNormal(), 1e-10);

		DoubleVector3DOrthonormalBasis basis = DoubleVector3DTools::GenerateComplementBasis(greatCircleFit.GetNormal());
//  
// 		std::vector<GreatArcFit3Item<double> > items;	 
// 
// 		for (int i = 0; i < size; ++i)
// 		{
// 			GreatArcFit3Item<double> item(basis.GetUVector(), basis.GetVVector(), vertices[i]);
// 
// 			items.push_back(item);
// 		}
// 
// 		std::sort(items.begin(), items.end());

		// 连续定位的角度是一个最大的差值。
		// 实际上, 我们构建一个圆锥包含最小角的单位长度向量。
// 		int numPointsMinus1 = size - 1;
// 		double maxDiff = DoubleMath::GetTwoPI() + items[0].GetAngle() - items[numPointsMinus1].GetAngle();
// 		int end0 = 0;
// 		int end1 = numPointsMinus1;
// 		for (int index = 0; index < numPointsMinus1; ++index)
// 		{
// 			auto temp = index + 1;
// 			double diff = items[temp].GetAngle() - items[index].GetAngle();
// 			if (maxDiff < diff)
// 			{
// 				maxDiff = diff;
// 				end0 = index + 1;
// 				end1 = index;
// 			}
// 		}
// 
// 		DoubleVector3D arcEnd0 = items[end0].GetUDot() * basis.GetUVector() + items[end0].GetVDot() * basis.GetVVector();
// 		DoubleVector3D arcEnd1 = items[end1].GetUDot() * basis.GetUVector() + items[end1].GetVDot() * basis.GetVVector();
// 		arcEnd0.Normalize();
// 		arcEnd1.Normalize();
// 
// 		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, greatArcFit.GetArcEnd0(), arcEnd0, 1e-10);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, greatArcFit.GetArcEnd1(), arcEnd1, 1e-10);
	}
}

