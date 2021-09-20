///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/18 13:53)

#include "MemoryMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <map>
#include <vector>

using std::map;
using std::pair;
using std::string;
using std::vector;

CoreTools::MemoryMacroTesting::MemoryMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, MemoryMacroTesting)

void CoreTools::MemoryMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::MemoryMacroTesting::MainTest()
{
    MEMORY_DESTROY;
    MEMORY_CREATE_WITH_ALLOCATOR_AND_DEALLOCATOR(ClassType::Allocator, ClassType::Deallocator);

    ASSERT_NOT_THROW_EXCEPTION_0(SingleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array1DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array2DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array3DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array4DTest);

    MEMORY_DESTROY;
    MEMORY_CREATE;

    ASSERT_NOT_THROW_EXCEPTION_0(SingleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array1DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array2DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array3DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Array4DTest);
}

void CoreTools::MemoryMacroTesting::SingleTest()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26403)
#include SYSTEM_WARNING_DISABLE(26409)

    auto intSingle = NEW0 int{};

#include STSTEM_WARNING_POP

    ASSERT_UNEQUAL_NULL_PTR(intSingle);
    DELETE0(intSingle);

    auto stringVectorSingle = New0<vector<string>>();
    ASSERT_UNEQUAL_NULL_PTR(stringVectorSingle);
    DELETE0(stringVectorSingle);
}

void CoreTools::MemoryMacroTesting::Array1DTest()
{
    auto doubleArray1D = NEW1<double>(5);
    ASSERT_UNEQUAL_NULL_PTR(doubleArray1D);
    DELETE1(doubleArray1D);

    auto intMapArray1D = NEW1<map<int, string>>(2);
    ASSERT_UNEQUAL_NULL_PTR(intMapArray1D);
    DELETE1(intMapArray1D);
}

void CoreTools::MemoryMacroTesting::Array2DTest()
{
    auto floatArray2D = NEW2<float>(5, 8);
    if (floatArray2D != nullptr)
    {
        ASSERT_UNEQUAL_NULL_PTR(floatArray2D);
        ASSERT_UNEQUAL_NULL_PTR(floatArray2D[0]);
        DELETE2(floatArray2D);
    }

    auto pairArray2D = NEW2<pair<int, int>>(1, 2);
    if (pairArray2D != nullptr)
    {
        ASSERT_UNEQUAL_NULL_PTR(pairArray2D);
        ASSERT_UNEQUAL_NULL_PTR(pairArray2D[0]);
        DELETE2(pairArray2D);
    }
}

void CoreTools::MemoryMacroTesting::Array3DTest()
{
    auto array3D = NEW3<string>(5, 8, 9);
    if (array3D != nullptr)
    {
        ASSERT_UNEQUAL_NULL_PTR(array3D);
        ASSERT_UNEQUAL_NULL_PTR(array3D[0]);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_UNEQUAL_NULL_PTR(array3D[0][0]);

#include STSTEM_WARNING_POP

        DELETE3(array3D);
    }
}

void CoreTools::MemoryMacroTesting::Array4DTest()
{
    auto array4D = NEW4<char>(5, 8, 9, 8);
    if (array4D != nullptr)
    {
        ASSERT_UNEQUAL_NULL_PTR(array4D);
        ASSERT_UNEQUAL_NULL_PTR(array4D[0]);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_UNEQUAL_NULL_PTR(array4D[0][0]);
        ASSERT_UNEQUAL_NULL_PTR(array4D[0][0][0]);

#include STSTEM_WARNING_POP

        DELETE4(array4D);
    }

    auto mapArray4D = NEW4<map<string, vector<int>>>(3, 1, 19, 18);
    if (mapArray4D != nullptr)
    {
        ASSERT_UNEQUAL_NULL_PTR(mapArray4D);
        ASSERT_UNEQUAL_NULL_PTR(mapArray4D[0]);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        ASSERT_UNEQUAL_NULL_PTR(mapArray4D[0][0]);
        ASSERT_UNEQUAL_NULL_PTR(mapArray4D[0][0][0]);

#include STSTEM_WARNING_POP

        DELETE4(mapArray4D);
    }
}

void* CoreTools::MemoryMacroTesting::Allocator(size_t bytesNumber, MAYBE_UNUSED const FunctionDescribed& functionDescribed)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    return new char[bytesNumber];

#include STSTEM_WARNING_POP
}

void CoreTools::MemoryMacroTesting::Deallocator(const void* memBlock, MAYBE_UNUSED const FunctionDescribed& functionDescribed) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

    delete[] memBlock;

#include STSTEM_WARNING_POP
}
