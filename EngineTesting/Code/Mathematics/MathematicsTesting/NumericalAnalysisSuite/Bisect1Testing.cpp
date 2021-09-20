// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 14:35)

#include "Bisect1Testing.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect1Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

namespace Mathematics
{
	template class Bisect1<float>;
	template class Bisect1<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Bisect1Testing) 

void Mathematics::Bisect1Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::Bisect1Testing
	::HaveSolutionTest()
{
    DoubleBisect1 bisect1(FirstEquation,200);
    
    DoubleBisect1Root root = bisect1.Bisect(0.0,1.0);
    
    ASSERT_APPROXIMATE(FirstEquation(root.GetRoot()),0.0,1e-8);
    
    ASSERT_ENUM_EQUAL(root.GetBisect1RootType(),BisectRootType::HaveSolution);
}

void Mathematics::Bisect1Testing
	::NoSolutionTest()
{
    FloatBisect1 bisect1(SecondEquation,20);
    
    FloatBisect1Root root = bisect1.Bisect(-1.0,0.0);
    
	ASSERT_ENUM_EQUAL(root.GetBisect1RootType(), BisectRootType::NoSolution);
}

void Mathematics::Bisect1Testing
	::UnknownTest()
{
    DoubleBisect1 bisect1(FirstEquation,20);
    
    DoubleBisect1Root root = bisect1.Bisect(0.0,1.0);
    
    ASSERT_TRUE(0.0 <= root.GetRoot());
    ASSERT_TRUE(root.GetRoot() <= 1.0);
    
	ASSERT_ENUM_EQUAL(root.GetBisect1RootType(), BisectRootType::Unknown);
}

// static
double Mathematics::Bisect1Testing
	::FirstEquation(double value)
{
    return 5.0 * value * value + 4.0 * value - 3.0;
}

// static
float Mathematics::Bisect1Testing
	::SecondEquation(float value)
{
    return 2.0f * value * value + 2.0f * value - 1.0f;
}