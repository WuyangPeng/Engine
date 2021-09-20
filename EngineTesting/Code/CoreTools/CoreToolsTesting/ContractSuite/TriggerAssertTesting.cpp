///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/25 21:05)

#include "TriggerAssertTesting.h"
#include "CoreTools/Contract/Flags/CheckInvariantFlags.h"
#include "CoreTools/Contract/TriggerAssert.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;
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

#ifdef OPEN_IMPORTANT_EXCPTION_ASSERT

    ASSERT_THROW_EXCEPTION_0(TriggerAssertionTest);

#else  // !OPEN_IMPORTANT_EXCPTION_ASSERT

    ASSERT_NOT_THROW_EXCEPTION_0(TriggerAssertionTest);

#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT
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
