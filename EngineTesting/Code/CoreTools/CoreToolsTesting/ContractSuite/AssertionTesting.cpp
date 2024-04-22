/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 10:09)

#include "AssertionTesting.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Contract/Assertion.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::AssertionTesting::AssertionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertionTesting)

void CoreTools::AssertionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertionFailTest);
}

void CoreTools::AssertionTesting::AssertionFailTest()
{
    const auto promptMessage = "���ζ��Դ���ֻ�ǲ��ԣ���û�д��������"s;
    const auto cancelMessage = "��������ȡ����"s;

    const Assertion assertion{ false, CORE_TOOLS_FUNCTION_DESCRIBED, "%s%s\n", promptMessage, cancelMessage };
}

void CoreTools::AssertionTesting::PrintTipsMessage()
{
    GetStream() << "������Իᴥ��ʧ�ܶ��ԣ��밴��ȡ����\n";

    System::SystemPause();
}