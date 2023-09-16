///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 09:48)

#include "UnusedFunctionTesting.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::UnusedFunctionTesting::UnusedFunctionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, UnusedFunctionTesting)

void System::UnusedFunctionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::UnusedFunctionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UnusedFunctionTest);
}

void System::UnusedFunctionTesting::UnusedFunctionTest()
{
    UnusedFunction();
    UnusedFunction(0);
    UnusedFunction(0, 1);
    UnusedFunction(0, 1, 2);
    UnusedFunction(0, 1, 2, "3"s);
}
