///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/21 21:37)

#include "Testing.h"
#include "TestingWindowsMessage.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "Framework/WindowProcess/WindowMessageUnitTestSuiteDetail.h"

using namespace std::literals;

System::TestingWindowsMessage::TestingWindowsMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, "��ϵͳ�⡿Window��Ԫ�����׼�"s, environmentDirectory }
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
    auto systemOutputSuite = GenerateSuite("ϵͳ���"s);

    systemOutputSuite.AddSuite(GetMessageBoxSelectionSuite());

    AddSuite(systemOutputSuite);
}

CoreTools::Suite System::TestingWindowsMessage::GetMessageBoxSelectionSuite()
{
    const auto hwnd = GetHwnd();

    auto messageBoxSelectionSuite = GenerateSuite("��Ϣ��ѡ��"s);

    ADD_TEST_USE_PARAMETER_1(messageBoxSelectionSuite, MessageBoxSelectionUseFlagsDataWindowsTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(messageBoxSelectionSuite, MessageBoxSelectionUseLanguageIDDataWindowsTesting, hwnd);

    return messageBoxSelectionSuite;
}

void System::TestingWindowsMessage::AddDynamicLinkSuite()
{
    auto dynamicLinkSuite = GenerateSuite("��̬���ӿ⹤��"s);

    dynamicLinkSuite.AddSuite(GetLoadResourceToolsSuite());
    dynamicLinkSuite.AddSuite(GetEnumResourceToolsSuite());

    AddSuite(dynamicLinkSuite);
}

CoreTools::Suite System::TestingWindowsMessage::GetLoadResourceToolsSuite()
{
    const auto instance = System::GetHInstance();

    auto loadResourceToolsSuite = GenerateSuite("������Դ����"s);

    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, FindResourceWindowsTesting, instance);
    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, LoadResourceWindowsTesting, instance);
    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, LoadStringWindowsTesting, instance);

    return loadResourceToolsSuite;
}

CoreTools::Suite System::TestingWindowsMessage::GetEnumResourceToolsSuite()
{
    const auto instance = System::GetHInstance();

    auto enumResourceToolsSuite = GenerateSuite("�о���Դ����"s);

    ADD_TEST_USE_PARAMETER_1(enumResourceToolsSuite, EnumResourceToolsWindowsTesting, instance);
    ADD_TEST_USE_PARAMETER_1(enumResourceToolsSuite, ResourceEnumWindowsTesting, instance);

    return enumResourceToolsSuite;
}

void System::TestingWindowsMessage::AddOpenGLSuite()
{
    const auto hwnd = GetHwnd();

    auto openGLSuite = GenerateSuite("OpenGL"s);

    ADD_TEST_USE_PARAMETER_1(openGLSuite, OpenGLWglSwapIntervalTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(openGLSuite, OpenGLGetCurrentWglContextTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(openGLSuite, OpenGLGetWglProcAddressTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(openGLSuite, OpenGLSwapDeviceBuffersTesting, hwnd);

    AddSuite(openGLSuite);
}

void System::TestingWindowsMessage::AddWindowsSuite()
{
    const auto hwnd = GetHwnd();

    auto windowsSuite = GenerateSuite("Windowsϵͳ"s);

    windowsSuite.AddSuite(GetWindowsCreateSuite());
    windowsSuite.AddSuite(GetWindowsProcessSuite());
    windowsSuite.AddSuite(GetWindowsRegisterSuite());
    ADD_TEST_USE_PARAMETER_1(windowsSuite, WindowsFontInformationTesting, hwnd);
    ADD_TEST_USE_PARAMETER_1(windowsSuite, WindowsUserTesting, hwnd);
    windowsSuite.AddSuite(GetWindowsSystemSuite());

    AddSuite(windowsSuite);
}

CoreTools::Suite System::TestingWindowsMessage::GetWindowsCreateSuite()
{
    const auto instance = System::GetHInstance();
    const auto hwnd = GetHwnd();

    auto windowsCreateSuite = GenerateSuite("Windows����"s);

    ADD_TEST_USE_PARAMETER_2(windowsCreateSuite, CreateSystemWindowTesting, instance, hwnd);
    ADD_TEST_USE_PARAMETER_1(windowsCreateSuite, GetHInstanceTesting, instance);
    ADD_TEST_USE_PARAMETER_2(windowsCreateSuite, WindowsCreateMenuTesting, instance, hwnd);

    return windowsCreateSuite;
}

CoreTools::Suite System::TestingWindowsMessage::GetWindowsProcessSuite()
{
    const auto hwnd = GetHwnd();

    auto windowsProcessSuite = GenerateSuite("Windows����"s);

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
    const auto instance = System::GetHInstance();

    auto windowsRegisterSuite = GenerateSuite("Windowsע��"s);

    ADD_TEST(windowsRegisterSuite, GetStockObjectTesting);
    ADD_TEST_USE_PARAMETER_1(windowsRegisterSuite, LoadCursorTesting, instance);
    ADD_TEST_USE_PARAMETER_1(windowsRegisterSuite, LoadIconTesting, instance);
    ADD_TEST_USE_PARAMETER_1(windowsRegisterSuite, RegisterClassTesting, instance);
    ADD_TEST(windowsRegisterSuite, RegisterWindowMessageTesting);

    return windowsRegisterSuite;
}

CoreTools::Suite System::TestingWindowsMessage::GetWindowsSystemSuite()
{
    const auto hwnd = GetHwnd();

    auto windowsSystemSuite = GenerateSuite("Windowsϵͳ"s);

    ADD_TEST(windowsSystemSuite, GetActiveWindowTesting);
    ADD_TEST_USE_PARAMETER_1(windowsSystemSuite, GetSystemClientRectTesting, hwnd);

    return windowsSystemSuite;
}
