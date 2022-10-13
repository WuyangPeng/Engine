///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/04 20:40)

#include "Testing.h"
#include "TestingWindowsMessage.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "Framework/WindowProcess/WindowMessageUnitTestSuiteDetail.h"

using std::string;
using namespace std::literals;

System::TestingWindowsMessage::TestingWindowsMessage(int64_t delta, MAYBE_UNUSED const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, "【系统库】Window单元测试套件"s }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, TestingWindowsMessage)

void System::TestingWindowsMessage::InitSuite()
{
    AddSystemOutputSuite();
    AddDynamicLinkSuite();
    AddOpenGLSuite();
    AddWindowsSuite();
}

void System::TestingWindowsMessage::AddSystemOutputSuite()
{
    auto systemOutputSuite = GenerateSuite("系统输出"s);

    systemOutputSuite.AddSuite(GetMessageBoxSelectionSuite());

    AddSuite(systemOutputSuite);
}

CoreTools::Suite System::TestingWindowsMessage::GetMessageBoxSelectionSuite()
{
    auto hwnd = GetHwnd();

    auto messageBoxSelectionSuite = GenerateSuite("消息框选择"s);

    ADD_TEST_USE_PARAMETER_1(messageBoxSelectionSuite, MessageBoxSelectionUseFlagsDataWindowsTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(messageBoxSelectionSuite, MessageBoxSelectionUseLanguageIDDataWindowsTesting, hwnd);

    return messageBoxSelectionSuite;
}

void System::TestingWindowsMessage::AddDynamicLinkSuite()
{
    auto dynamicLinkSuite = GenerateSuite("动态链接库工具"s);

    dynamicLinkSuite.AddSuite(GetLoadResourceToolsSuite());
    dynamicLinkSuite.AddSuite(GetEnumResourceToolsSuite());

    AddSuite(dynamicLinkSuite);
}

CoreTools::Suite System::TestingWindowsMessage::GetLoadResourceToolsSuite()
{
    auto instance = System::GetHInstance();

    auto loadResourceToolsSuite = GenerateSuite("加载资源工具"s);

    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, FindResourceWindowsTesting, instance);
    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, LoadResourceWindowsTesting, instance);
    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, LoadStringWindowsTesting, instance);

    return loadResourceToolsSuite;
}

CoreTools::Suite System::TestingWindowsMessage::GetEnumResourceToolsSuite()
{
    auto instance = System::GetHInstance();

    auto enumResourceToolsSuite = GenerateSuite("列举资源工具"s);

    ADD_TEST_USE_PARAMETER_1(enumResourceToolsSuite, EnumResourceToolsWindowsTesting, instance);
    ADD_TEST_USE_PARAMETER_1(enumResourceToolsSuite, ResourceEnumWindowsTesting, instance);

    return enumResourceToolsSuite;
}

void System::TestingWindowsMessage::AddOpenGLSuite()
{
    auto hwnd = GetHwnd();

    auto openGLSuite = GenerateSuite("OpenGL"s);

    ADD_TEST_USE_PARAMETER_1(openGLSuite, OpenGLWglPrototypesTesting, hwnd);

    AddSuite(openGLSuite);
}

void System::TestingWindowsMessage::AddWindowsSuite()
{
    auto instance = System::GetHInstance();
    auto hwnd = GetHwnd();

    auto windowsSuite = GenerateSuite("Windows系统"s);

    ADD_TEST_USE_PARAMETER_2(windowsSuite, WindowsCreateTesting, instance, hwnd);
    windowsSuite.AddSuite(GetWindowsProcessSuite());
    windowsSuite.AddSuite(GetWindowsRegisterSuite());
    ADD_TEST_USE_PARAMETER_1(windowsSuite, WindowsFontInformationTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(windowsSuite, WindowsUserTesting, hwnd);

    AddSuite(windowsSuite);
}

CoreTools::Suite System::TestingWindowsMessage::GetWindowsProcessSuite()
{
    auto hwnd = GetHwnd();

    auto windowsProcessSuite = GenerateSuite("Windows进程"s);

    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, GetMessageTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, PeekMessageTesting, hwnd);
    ADD_TEST(windowsProcessSuite, PostQuitMessageTesting);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, ValidateRectTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, DefWindowProcTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, MessageBoxTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, DestroyWindowTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, SendMessageTesting, hwnd);
    ADD_TEST(windowsProcessSuite, GetCommandLineTesting);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, WindowPaintTesting, hwnd);

    return windowsProcessSuite;
}

CoreTools::Suite System::TestingWindowsMessage::GetWindowsRegisterSuite()
{
    auto instance = System::GetHInstance();

    auto windowsRegisterSuite = GenerateSuite("Windows注册"s);

    ADD_TEST(windowsRegisterSuite, GetStockObjectTesting);
    ADD_TEST_USE_PARAMETER_1(windowsRegisterSuite, LoadCursorTesting, instance);
    ADD_TEST_USE_PARAMETER_1(windowsRegisterSuite, LoadIconTesting, instance);
    ADD_TEST_USE_PARAMETER_1(windowsRegisterSuite, RegisterClassTesting, instance);
    ADD_TEST(windowsRegisterSuite, RegisterWindowMessageTesting);

    return windowsRegisterSuite;
}
