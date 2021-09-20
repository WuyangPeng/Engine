// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 14:44)

#include "Bisect2Testing.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect2Detail.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Bisect2Testing) 

void Mathematics::Bisect2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::Bisect2Testing
	::HaveSolutionTest()
{
     
}

void Mathematics::Bisect2Testing
	::NoSolutionTest()
{
     
}

void Mathematics::Bisect2Testing
	::UnknownTest()
{
    
}

// static
double Mathematics::Bisect2Testing
	::FirstEquation(double x,double y)
{
    return 2.0 * x - 1.0 + 1.0 * y;
}

// static
double Mathematics::Bisect2Testing
	::SecondEquation(double x,double y)
{
    return 3.0 * x - 2.0 + 3.0 * y;
}