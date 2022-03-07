// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 14:53)

#include "Bisect3StorageTesting.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect3Detail.h" 
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
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Bisect3StorageTesting) 

void Mathematics::Bisect3StorageTesting
	::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TestValuesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetStorageValueTest);
}

void Mathematics::Bisect3StorageTesting
	::TestValuesTest()
{
	 
	 

	 
	
}

void Mathematics::Bisect3StorageTesting
	::SetStorageValueTest()
{
	 

}

// static
double Mathematics::Bisect3StorageTesting
	::FirstEquation(double x,double y,double z)
{
    return 1.0 * x + 1.0 * y - 2.0 * z + 1.0;
}

// static
double Mathematics::Bisect3StorageTesting
	::SecondEquation(double x,double y,double z)
{
    return 2.0 * x + 3.0 * y - 1.0 * z - 1.0;
}

double Mathematics::Bisect3StorageTesting
	::ThirdEquation( double x,double y,double z )
{
	return 3.0 * x + 1.0 * y - 2.0 * z - 1.0;
}
