// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 12:20)

#include "MemoryTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"

#include <map>
#include <string>
#include <vector>

using std::map;
using std::pair;
using std::string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, MemoryTesting)

void CoreTools::MemoryTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array1DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array2DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array3DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array4DTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26403)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
void CoreTools::MemoryTesting ::SingleTest()
{
    auto intSingle = NEW0 int;
    ASSERT_UNEQUAL_NULL_PTR(intSingle);
    DELETE0(intSingle);

    auto stringVectorSingle = NEW0 vector<string>;
    ASSERT_UNEQUAL_NULL_PTR(stringVectorSingle);
    DELETE0(stringVectorSingle);
}

void CoreTools::MemoryTesting ::Array1DTest()
{
    auto doubleArray1D = NEW1<double>(5);
    ASSERT_UNEQUAL_NULL_PTR(doubleArray1D);
    DELETE1(doubleArray1D);

    auto intMapArray1D = NEW1<map<int, string>>(2);
    ASSERT_UNEQUAL_NULL_PTR(intMapArray1D);
    DELETE1(intMapArray1D);
}

void CoreTools::MemoryTesting ::Array2DTest()
{
    auto floatArray2D = NEW2<float>(5, 8);
    ASSERT_UNEQUAL_NULL_PTR(floatArray2D);
    ASSERT_UNEQUAL_NULL_PTR(floatArray2D[0]);
    DELETE2(floatArray2D);

    auto pairArray2D = NEW2<pair<int, int>>(1, 2);
    ASSERT_UNEQUAL_NULL_PTR(pairArray2D);
    ASSERT_UNEQUAL_NULL_PTR(pairArray2D[0]);
    DELETE2(pairArray2D);
}

void CoreTools::MemoryTesting ::Array3DTest()
{
    auto array3D = NEW3<string>(5, 8, 9);
    ASSERT_UNEQUAL_NULL_PTR(array3D);
    ASSERT_UNEQUAL_NULL_PTR(array3D[0]);
    ASSERT_UNEQUAL_NULL_PTR(array3D[0][0]);
    DELETE3(array3D);
}

void CoreTools::MemoryTesting ::Array4DTest()
{
    auto array4D = NEW4<char>(5, 8, 9, 8);
    ASSERT_UNEQUAL_NULL_PTR(array4D);
    ASSERT_UNEQUAL_NULL_PTR(array4D[0]);
    ASSERT_UNEQUAL_NULL_PTR(array4D[0][0]);
    ASSERT_UNEQUAL_NULL_PTR(array4D[0][0][0]);
    DELETE4(array4D);

    auto mapArray4D = NEW4<map<string, vector<int>>>(3, 1, 19, 18);
    ASSERT_UNEQUAL_NULL_PTR(mapArray4D);
    ASSERT_UNEQUAL_NULL_PTR(mapArray4D[0]);
    ASSERT_UNEQUAL_NULL_PTR(mapArray4D[0][0]);
    ASSERT_UNEQUAL_NULL_PTR(mapArray4D[0][0][0]);
    DELETE4(mapArray4D);
}

#include STSTEM_WARNING_POP