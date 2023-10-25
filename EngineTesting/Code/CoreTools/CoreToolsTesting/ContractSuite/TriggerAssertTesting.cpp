///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 16:56)

#include "TriggerAssertTesting.h"
#include "CoreTools/Contract/Flags/CheckInvariantFlags.h"
#include "CoreTools/Contract/TriggerAssert.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::TriggerAssertTesting::TriggerAssertTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TriggerAssertTesting)

void CoreTools::TriggerAssertTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TriggerAssertTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TriggerInvariantTest);

#ifdef OPEN_IMPORTANT_EXCEPTION_ASSERT

    ASSERT_THROW_EXCEPTION_0(TriggerAssertionTest);

#else  // !OPEN_IMPORTANT_EXCEPTION_ASSERT

    ASSERT_NOT_THROW_EXCEPTION_0(TriggerAssertionTest);

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT
}

void CoreTools::TriggerAssertTesting::TriggerInvariantTest()
{
    const auto promptMessage = "�����಻��ʽʧ��ֻ�ǲ��ԣ���û�д��������"s;
    const auto cancelMessage = "��������ȡ����"s;

    const TriggerAssert triggerAssert{ TriggerAssertCheck::Invariant, CORE_TOOLS_FUNCTION_DESCRIBED, "%s%s\n"s, promptMessage, cancelMessage };
}

void CoreTools::TriggerAssertTesting::TriggerAssertionTest()
{
    const auto promptMessage = "���ζ��Դ���ֻ�ǲ��ԣ���û�д��������"s;
    const auto cancelMessage = "��������ȡ����"s;

    const TriggerAssert triggerAssert{ TriggerAssertCheck::Assertion, CORE_TOOLS_FUNCTION_DESCRIBED, "%s%s\n"s, promptMessage, cancelMessage };
}
