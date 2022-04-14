// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/07 17:03)

#include "SurfacePatchTesting.h"
#include "Detail/TestSurfacePatch.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
 
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SurfacePatchTesting) 

void Rendering::SurfacePatchTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(ParameterTest);	
	ASSERT_NOT_THROW_EXCEPTION_0(DerivativesTest);

	CoreTools::InitTerm::ExecuteTerminators();
}
 #include SYSTEM_WARNING_DISABLE(26440)
void Rendering::SurfacePatchTesting
	::ParameterTest()
{
// 	TestSurfacePatch patch(1.0f,3.0f,2.0f,6.0f,true);
// 
// 	ASSERT_APPROXIMATE(patch.GetUMin(), 1.0f, 1e-8f);
// 	ASSERT_APPROXIMATE(patch.GetUMax(), 3.0f, 1e-8f);
// 	ASSERT_APPROXIMATE(patch.GetVMin(), 2.0f, 1e-8f);
// 	ASSERT_APPROXIMATE(patch.GetVMax(), 6.0f, 1e-8f);
// 	ASSERT_TRUE(patch.IsRectangular());
}

void Rendering::SurfacePatchTesting
	::DerivativesTest()
{
// 	TestSurfacePatch patch(1.0f,3.0f,2.0f,6.0f,false);
// 
// 	Mathematics::AVectorf tangent0 = patch.GetTangent0(2.0f, 4.0f); 
// 	Mathematics::AVectorf tangent1 = patch.GetTangent1(2.0f, 4.0f);
// 	Mathematics::AVectorf normal = patch.GetNormal(2.0f, 4.0f);
// 
// 	SurfacePatchFrame frame = patch.GetFrame(2.0f, 4.0f);
// 
// 	typedef bool(*VectorFunction)(const Mathematics::AVectorf& lhs, const Mathematics::AVectorf& rhs,const float epsilon);
// 	typedef bool(*PointFunction)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,const float epsilon);
// 
// 	PointFunction pointFunction = Mathematics::Approximate<float>;
// 	VectorFunction vectorFunction = Mathematics::Approximate<float>;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, tangent0, frame.GetTangent0(), 1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, tangent1, frame.GetTangent1(), 1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, normal, frame.GetNormal(), 1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, frame.GetPosition(), patch.GetPosition(2.0f, 4.0f),1e-8f);
// 
// 	Mathematics::AVectorf uVector = patch.GetDerivativesU(2.0f, 4.0f);
// 	uVector.Normalize();
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, tangent0, uVector, 1e-8f);
// 
// 	Mathematics::AVectorf vVector = patch.GetDerivativesV(2.0f, 4.0f);
// 
// 	Mathematics::AVectorf testNormal = UnitCross(tangent0, vVector);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, normal, testNormal, 1e-8f);
// 
// 	vVector = Cross(normal, uVector);
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, tangent1, vVector, 1e-8f);
// 
// 	PrincipalCurvatureInfo info = patch.ComputePrincipalCurvatureInfo(2.0f, 4.0f);
// 
// 	Mathematics::AVectorf  derivativesU = patch.GetDerivativesU(2.0f, 4.0f);
// 	Mathematics::AVectorf  derivativesV = patch.GetDerivativesV(2.0f, 4.0f);
// 	Mathematics::AVectorf  derivativesUU = patch.GetDerivativesUU(2.0f, 4.0f);
// 	Mathematics::AVectorf  derivativesUV = patch.GetDerivativesUV(2.0f, 4.0f);
// 	Mathematics::AVectorf  derivativesVV = patch.GetDerivativesVV(2.0f, 4.0f);
// 
// 	Mathematics::Matrix2f metricTensor;
// 	metricTensor(0, 0) = Dot(derivativesU, derivativesU);
// 	metricTensor(0, 1) = Dot(derivativesU, derivativesV);
// 	metricTensor(1, 0) = metricTensor(0, 1);
// 	metricTensor(1, 1) = Dot(derivativesV, derivativesV);
// 
// 	normal = UnitCross(derivativesU, derivativesV);
// 	Mathematics::Matrix2f curvatureTensor;
// 	curvatureTensor(0, 0) = -Dot(normal, derivativesUU);
// 	curvatureTensor(0, 1) = -Dot(normal, derivativesUV);
// 	curvatureTensor(1, 0) = curvatureTensor(0, 1);
// 	curvatureTensor(1, 1) = -Dot(normal, derivativesVV);
// 	 
// 	float constant = curvatureTensor(0, 0) * curvatureTensor(1, 1) - curvatureTensor(0, 1) * curvatureTensor(1, 0);
// 	float once = 2.0f * curvatureTensor(0, 1) * metricTensor(0, 1) - curvatureTensor(0, 0) * metricTensor(1, 1) - curvatureTensor(1, 1) * metricTensor(0, 0);
// 	float twice = metricTensor(0, 0) * metricTensor(1, 1) - metricTensor(0, 1) * metricTensor(1, 0);
// 	 
// 	float discriminant = Mathematics::MathF::Sqrt(Mathematics::MathF::FAbs(once * once - 4.0f * constant * twice));
// 	float principalCurvature0 = -0.5f * (once + discriminant);
// 	float principalCurvature1 = 0.5f * (-once + discriminant);
// 
// 	ASSERT_APPROXIMATE(principalCurvature0, info.GetPrincipalCurvature0(), 1e-8f);
// 	ASSERT_APPROXIMATE(principalCurvature1, info.GetPrincipalCurvature1(), 1e-8f);
// 	 
// 	float a0 = curvatureTensor(0, 1) - principalCurvature0 * metricTensor(0, 1);
// 	float a1 = principalCurvature0 * metricTensor(0, 0) - curvatureTensor(0, 0);
// 	float length = Mathematics::MathF::Sqrt(a0 * a0 + a1 * a1);
// 	Mathematics::AVectorf principalDirection0;
// 	if (Mathematics::MathF::sm_ZeroTolerance <= length)
// 	{
// 		principalDirection0 = a0 * derivativesU + a1 * derivativesV;
// 	}
// 	else
// 	{
// 		a0 = curvatureTensor(1, 1) - principalCurvature0 * metricTensor(1, 1);
// 		a1 = principalCurvature0*metricTensor(0, 1) - curvatureTensor(0, 1);
// 		length = Mathematics::MathF::Sqrt(a0 * a0 + a1 * a1);
// 		if (Mathematics::MathF::sm_ZeroTolerance <= length)
// 		{
// 			principalDirection0 = a0 * derivativesU + a1 * derivativesV;
// 		}
// 		else
// 		{
// 			 
// 			principalDirection0 = derivativesU;
// 		}
// 	}
// 	principalDirection0.Normalize();
// 
// 	// 第二切线是第一切线和法线的叉乘 
// 	Mathematics::AVectorf principalDirection1 = Cross(principalDirection0, normal);
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, principalDirection0,info.GetPrincipalDirection0(), 1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, principalDirection1, info.GetPrincipalDirection1(), 1e-8f);
}

