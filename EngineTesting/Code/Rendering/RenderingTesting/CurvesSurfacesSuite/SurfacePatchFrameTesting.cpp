// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 17:02)

#include "SurfacePatchFrameTesting.h"
#include "Rendering/CurvesSurfaces/SurfacePatchFrame.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
 
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SurfacePatchFrameTesting) 

void Rendering::SurfacePatchFrameTesting
	::MainTest()
{ 
	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);	
}
 #include SYSTEM_WARNING_DISABLE(26440)
void Rendering::SurfacePatchFrameTesting
	::InitTest()
{
// 	SurfacePatchFrame firstSurfacePatchFrame(Mathematics::APointf::sm_Origin,Mathematics::AVectorf::sm_UnitX,Mathematics::AVectorf::sm_UnitZ,Mathematics::AVectorf::sm_UnitY);
// 
// 	typedef bool(*VectorFunction)(const Mathematics::AVectorf& lhs, const Mathematics::AVectorf& rhs,const float epsilon);
// 	typedef bool(*PointFunction)(const Mathematics::APointf& lhs, const Mathematics::APointf& rhs,const float epsilon);
// 
// 	PointFunction pointFunction = Mathematics::Approximate<float>;
// 	VectorFunction vectorFunction = Mathematics::Approximate<float>;
// 
// 	ASSERT_APPROXIMATE_USE_FUNCTION(pointFunction, firstSurfacePatchFrame.GetPosition(), Mathematics::APointf::sm_Origin, 1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, firstSurfacePatchFrame.GetTangent0(), Mathematics::AVectorf::sm_UnitX, 1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, firstSurfacePatchFrame.GetTangent1(), Mathematics::AVectorf::sm_UnitZ, 1e-8f);
// 	ASSERT_APPROXIMATE_USE_FUNCTION(vectorFunction, firstSurfacePatchFrame.GetNormal(), Mathematics::AVectorf::sm_UnitY, 1e-8f);
}
 