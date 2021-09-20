// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 12:18)

#ifndef CLOSE_USE_MEMORY
	#define CLOSE_USE_MEMORY
#endif // CLOSE_USE_MEMORY

#include "DefaultMemoryTesting.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <string>

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, DefaultMemoryTesting)

void CoreTools::DefaultMemoryTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SingleTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Array1DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Array2DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Array3DTest);
	ASSERT_NOT_THROW_EXCEPTION_0(Array4DTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26403)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
void CoreTools::DefaultMemoryTesting
	::SingleTest()
{
	auto single = NEW0 int;
	ASSERT_UNEQUAL_NULL_PTR(single);
	DELETE0(single);
}

void CoreTools::DefaultMemoryTesting
	::Array1DTest()
{
	auto array1D = NEW1<double>(5);
	ASSERT_UNEQUAL_NULL_PTR(array1D);
	DELETE1(array1D);
}

void CoreTools::DefaultMemoryTesting
	::Array2DTest()
{
	auto array2D = NEW2<float>(5, 8);
	ASSERT_UNEQUAL_NULL_PTR(array2D);
	ASSERT_UNEQUAL_NULL_PTR(array2D[0]);
	DELETE2(array2D);
}

void CoreTools::DefaultMemoryTesting
	::Array3DTest()
{
	auto array3D = NEW3<string>(5, 8, 9);
	ASSERT_UNEQUAL_NULL_PTR(array3D);
	ASSERT_UNEQUAL_NULL_PTR(array3D[0]);
	ASSERT_UNEQUAL_NULL_PTR(array3D[0][0]);
	DELETE3(array3D);
}

void CoreTools::DefaultMemoryTesting
	::Array4DTest()
{
	auto array4D = NEW4<char>(5, 8, 9, 8);
	ASSERT_UNEQUAL_NULL_PTR(array4D);
	ASSERT_UNEQUAL_NULL_PTR(array4D[0]);
	ASSERT_UNEQUAL_NULL_PTR(array4D[0][0]);
	ASSERT_UNEQUAL_NULL_PTR(array4D[0][0][0]);
	DELETE4(array4D);
}



#include STSTEM_WARNING_POP