///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 13:47)

#include "FrameworkTestingWindowMessage.h"
#include "Testing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

Framework::FrameworkTestingWindowMessage::FrameworkTestingWindowMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, "����ܿ⡿��Ԫ�����׼�"s }
{
    System::UnusedFunction(environmentDirectory);

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, FrameworkTestingWindowMessage)

void Framework::FrameworkTestingWindowMessage::InitSuite()
{
    AddWindowCreateSuite();
    AddWindowProcessSuite();
    AddWindowRegisterSuite();
    AddApplicationSuite();
}

void Framework::FrameworkTestingWindowMessage::AddWindowCreateSuite()
{
    auto hWnd = GetHWnd();
    auto instance = System::GetHInstance();
    auto windowCreateSuite = GenerateSuite("Window����"s);

    ADD_TEST_USE_PARAMETER_1(windowCreateSuite, WindowInstanceParameterTesting, instance);
    ADD_TEST_USE_PARAMETER_1(windowCreateSuite, WindowCreateParameterTesting, hWnd);
    ADD_TEST_USE_PARAMETER_2(windowCreateSuite, WindowCreateHandleTesting, instance, hWnd);

    AddSuite(windowCreateSuite);
}

void Framework::FrameworkTestingWindowMessage::AddWindowProcessSuite()
{
    auto hWnd = GetHWnd();
    auto windowProcessSuite = GenerateSuite("���ڽ���"s);

    ADD_TEST_USE_PARAMETER_1(windowProcessSuite, WindowMessageInterfaceTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(windowProcessSuite, WindowMessageTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(windowProcessSuite, WindowProcessManagerTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(windowProcessSuite, WindowProcessHandleTesting, hWnd);

    AddSuite(windowProcessSuite);
}

void Framework::FrameworkTestingWindowMessage::AddWindowRegisterSuite()
{
    auto instance = System::GetHInstance();
    auto windowRegisterSuite = GenerateSuite("Windowע��"s);

    ADD_TEST_USE_PARAMETER_1(windowRegisterSuite, WindowRegisterParameterTesting, instance);
    ADD_TEST_USE_PARAMETER_1(windowRegisterSuite, WindowHIconTesting, instance);
    ADD_TEST_USE_PARAMETER_1(windowRegisterSuite, WindowHCursorTesting, instance);
    ADD_TEST_USE_PARAMETER_1(windowRegisterSuite, WindowPictorialTesting, instance);
    ADD_TEST_USE_PARAMETER_1(windowRegisterSuite, WindowRegisterTesting, instance);

    AddSuite(windowRegisterSuite);
}

void Framework::FrameworkTestingWindowMessage::AddApplicationSuite()
{
    auto hWnd = GetHWnd();
    auto instance = System::GetHInstance();
    auto applicationSuite = GenerateSuite("Ӧ��"s);

    ADD_TEST_USE_PARAMETER_1(applicationSuite, FontInformationTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(applicationSuite, MousePositionTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(applicationSuite, WindowApplicationInformationTesting, instance);

    AddSuite(applicationSuite);
}
