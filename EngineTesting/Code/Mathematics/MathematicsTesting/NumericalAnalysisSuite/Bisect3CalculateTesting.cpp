// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 14:47)

#include "Bisect3CalculateTesting.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect3Detail.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Bisect3CalculateTesting) 

void Mathematics::Bisect3CalculateTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::Bisect3CalculateTesting
	::HaveSolutionTest()
{
	 
}

void Mathematics::Bisect3CalculateTesting
	::NoSolutionTest()
{
	 
}

void Mathematics::Bisect3CalculateTesting
	::UnknownTest()
{
   
}

// static
float Mathematics::Bisect3CalculateTesting
	::FirstEquation(float x,float y,float z)
{
     return 1.0f * x + 1.0f * y - 2.0f * z + 1.0f;
}

// static
float Mathematics::Bisect3CalculateTesting
	::SecondEquation(float x,float y,float z)
{
    return 2.0f * x + 3.0f * y - 1.0f * z - 1.0f;
}

float Mathematics::Bisect3CalculateTesting
	::ThirdEquation( float x,float y,float z )
{
	return 3.0f * x + 1.0f * y - 2.0f * z - 1.0f;
}
