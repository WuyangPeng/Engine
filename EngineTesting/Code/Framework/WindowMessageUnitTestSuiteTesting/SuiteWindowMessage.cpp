///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 17:22)

#include "SuiteWindowMessage.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using namespace std::literals;

Framework::SuiteWindowMessage::SuiteWindowMessage(int64_t delta, MAYBE_UNUSED const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, "【Window Message Unit Test Suite Testing】单元测试套件"s }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, SuiteWindowMessage)

void Framework::SuiteWindowMessage::InitSuite()
{
    auto windowProcessSuite = GenerateSuite("窗口进程"s);

    ADD_TEST_USE_PARAMETER_1(windowProcessSuite, WindowMessageUnitTestSuiteTesting, shared_from_this());

    AddSuite(windowProcessSuite);
}
