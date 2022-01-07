///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/18 13:53)

#include "MemoryMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

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

void CoreTools::MemoryMacroTesting::MainTest() noexcept
{
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
