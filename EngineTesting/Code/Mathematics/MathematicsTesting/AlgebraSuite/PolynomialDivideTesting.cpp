// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 09:31)

#include "PolynomialDivideTesting.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Algebra/PolynomialDivideDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <vector> 
#include <random> 

using std::vector;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class PolynomialDivide<float>;
	template class PolynomialDivide<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,PolynomialDivideTesting) 

void Mathematics::PolynomialDivideTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
}

void Mathematics::PolynomialDivideTesting
	::ConstructionTest()
{
	default_random_engine generator{};
	uniform_real<double> randomDistribution{ -100.0,100.0 };
    
	vector<double> firstDoubleVector{ randomDistribution(generator),randomDistribution(generator),randomDistribution(generator),
									  randomDistribution(generator),randomDistribution(generator) };

    
    PolynomialD firstPolynomial(firstDoubleVector);
    
	vector<double> secondDoubleVector{ randomDistribution(generator),randomDistribution(generator),randomDistribution(generator),randomDistribution(generator) };
    
    PolynomialD secondPolynomial(secondDoubleVector);
    
    PolynomialDivideD polynomialDivide(firstPolynomial,secondPolynomial);
    
    ASSERT_TRUE(Approximate(polynomialDivide.GetQuotient(),firstPolynomial));
    ASSERT_TRUE(Approximate(polynomialDivide.GetRemainder(),secondPolynomial));
}

