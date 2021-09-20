// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 17:02)

#include "PrincipalCurvatureInfoTesting.h"
#include "Rendering/CurvesSurfaces/PrincipalCurvatureInfo.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
 
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PrincipalCurvatureInfoTesting) 

void Rendering::PrincipalCurvatureInfoTesting
	::MainTest()
{ 
	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);	
}
 
void Rendering::PrincipalCurvatureInfoTesting
	::InitTest()
{
// 	PrincipalCurvatureInfo firstPrincipalCurvatureInfo(0.2f,0.7f,Mathematics::AVectorf::sm_UnitZ,Mathematics::AVectorf::sm_UnitY);
// 
// 	typedef bool(*VectorFunction)(const Mathematics::AVectorf& lhs, const Mathematics::AVectorf& rhs,const float epsilon); 
// 
// 	VectorFunction vectorFunction = Mathematics::Approximate<float>;
// 
// 	ASSERT_APPROXIMATE(0.2f, firstPrincipalCurvatureInfo.GetPrincipalCurvature0(),  1e-8f);
// 	ASSERT_APPROXIMATE(0.7f, firstPrincipalCurvatureInfo.GetPrincipalCurvature1(),  1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, firstPrincipalCurvatureInfo.GetPrincipalDirection0(), Mathematics::AVectorf::sm_UnitZ, 1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, firstPrincipalCurvatureInfo.GetPrincipalDirection1(), Mathematics::AVectorf::sm_UnitY, 1e-8f);
}
 