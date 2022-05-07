// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/27 16:10)

#include "MinimizeNDataTesting.h"
#include "Mathematics/NumericalAnalysis/MinimizeNDataDetail.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"

using std::vector;
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
namespace Mathematics
{
	template class MinimizeNData<float>;
	template class MinimizeNData<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, MinimizeNDataTesting) 

void Mathematics::MinimizeNDataTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DataTest);
}

void Mathematics::MinimizeNDataTesting
	::DataTest() 
{
	vector<double> minLocation{ 6.0,5.0,4.0,3.0,2.0 };

	MinimizeNDataD firstMinimize1Data(minLocation,50.0);

	ASSERT_APPROXIMATE(firstMinimize1Data.GetMinValue(), 50.0, 1e-10);

	int index = 0;
	for (MinimizeNDataD::ConstIter iter = firstMinimize1Data.GetMinLocationBegin(),
		 end = firstMinimize1Data.GetMinLocationEnd();iter != end;++iter)
	{
		ASSERT_APPROXIMATE(minLocation[index], *iter, 1e-10);
		++index;
	}
}
