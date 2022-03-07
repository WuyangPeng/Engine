// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 14:42)

#include "Bisect2StorageTesting.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect2Detail.h"
 
 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

 #include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26497)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Bisect2StorageTesting) 

void Mathematics::Bisect2StorageTesting
	::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TestValuesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetStorageValueTest);
}

void Mathematics::Bisect2StorageTesting
	::TestValuesTest()
{
    
}

void Mathematics::Bisect2StorageTesting
	::SetStorageValueTest()
{ 
}

// static
double Mathematics::Bisect2StorageTesting
	::FirstEquation(double x,double y)
{
    return 2.0 * x - 1.0 + 1.0 * y;
}

// static
float Mathematics::Bisect2StorageTesting
	::SecondEquation(float x,float y)
{
    return 2.0f * x - 1.0f * x + 1.0f  * y;
}

double Mathematics::Bisect2StorageTesting
	::ThirdEquation( double x,double y )
{
	return 3.0 * x - 2.0 + 1.0 * y;
}

float Mathematics::Bisect2StorageTesting
	::FourthEquation( float x,float y )
{
	 return 3.0f * x - 2.0f * x + 1.0f * y;
}
