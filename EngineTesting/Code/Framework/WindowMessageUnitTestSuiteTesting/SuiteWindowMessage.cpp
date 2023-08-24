///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 10:50)

#include "SuiteWindowMessage.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"

using namespace std::literals;

Framework::SuiteWindowMessage::SuiteWindowMessage(int64_t delta, MAYBE_UNUSED const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, "��Window Message Unit Test Suite Testing����Ԫ�����׼�"s }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SuiteWindowMessage)

void Framework::SuiteWindowMessage::InitSuite()
{
    auto windowProcessSuite = GenerateSuite("���ڽ���"s);

    ADD_TEST_USE_PARAMETER_1(windowProcessSuite, WindowMessageUnitTestSuiteTesting, shared_from_this());

    AddSuite(windowProcessSuite);
}
