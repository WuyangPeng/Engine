///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:36)

#include "Testing.h"
#include "TestingWindowsMessage.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "Framework/WindowProcess/WindowMessageUnitTestSuiteDetail.h"

System::TestingWindowsMessage::TestingWindowsMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, "��ϵͳ�⡿Window��Ԫ�����׼�", environmentDirectory }
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
    auto systemOutputSuite = GenerateSuite("ϵͳ���");

    systemOutputSuite.AddSuite(GetMessageBoxSelectionSuite());

    AddSuite(systemOutputSuite);
}

CoreTools::Suite System::TestingWindowsMessage::GetMessageBoxSelectionSuite()
{
    const auto hWnd = GetHWnd();

    auto messageBoxSelectionSuite = GenerateSuite("��Ϣ��ѡ��");

    ADD_TEST_USE_PARAMETER_1(messageBoxSelectionSuite, MessageBoxSelectionUseFlagsDataWindowsTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(messageBoxSelectionSuite, MessageBoxSelectionUseLanguageIdDataWindowsTesting, hWnd);

    return messageBoxSelectionSuite;
}

void System::TestingWindowsMessage::AddDynamicLinkSuite()
{
    auto dynamicLinkSuite = GenerateSuite("��̬���ӿ⹤��");

    dynamicLinkSuite.AddSuite(GetLoadResourceToolsSuite());
    dynamicLinkSuite.AddSuite(GetEnumResourceToolsSuite());

    AddSuite(dynamicLinkSuite);
}

CoreTools::Suite System::TestingWindowsMessage::GetLoadResourceToolsSuite()
{
    const auto instance = System::GetHInstance();

    auto loadResourceToolsSuite = GenerateSuite("������Դ����");

    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, FindResourceWindowsTesting, instance);
    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, LoadResourceWindowsTesting, instance);
    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, LoadStringWindowsTesting, instance);

    return loadResourceToolsSuite;
}

CoreTools::Suite System::TestingWindowsMessage::GetEnumResourceToolsSuite()
{
    const auto instance = System::GetHInstance();

    auto enumResourceToolsSuite = GenerateSuite("�о���Դ����");

    ADD_TEST_USE_PARAMETER_1(enumResourceToolsSuite, EnumResourceToolsWindowsTesting, instance);
    ADD_TEST_USE_PARAMETER_1(enumResourceToolsSuite, ResourceEnumWindowsTesting, instance);

    return enumResourceToolsSuite;
}

void System::TestingWindowsMessage::AddOpenGLSuite()
{
    const auto hWnd = GetHWnd();

    auto openGLSuite = GenerateSuite("OpenGL");

    ADD_TEST_USE_PARAMETER_1(openGLSuite, OpenGLWglSwapIntervalTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(openGLSuite, OpenGLGetCurrentWglContextTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(openGLSuite, OpenGLGetWglProcAddressTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(openGLSuite, OpenGLSwapDeviceBuffersTesting, hWnd);

    AddSuite(openGLSuite);
}

void System::TestingWindowsMessage::AddWindowsSuite()
{
    const auto hWnd = GetHWnd();

    auto windowsSuite = GenerateSuite("Windowsϵͳ");

    windowsSuite.AddSuite(GetWindowsCreateSuite());
    windowsSuite.AddSuite(GetWindowsProcessSuite());
    windowsSuite.AddSuite(GetWindowsRegisterSuite());
    ADD_TEST_USE_PARAMETER_1(windowsSuite, WindowsFontInformationTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(windowsSuite, WindowsUserTesting, hWnd);
    windowsSuite.AddSuite(GetWindowsSystemSuite());

    AddSuite(windowsSuite);
}

CoreTools::Suite System::TestingWindowsMessage::GetWindowsCreateSuite()
{
    const auto instance = System::GetHInstance();
    const auto hWnd = GetHWnd();

    auto windowsCreateSuite = GenerateSuite("Windows����");

    ADD_TEST_USE_PARAMETER_2(windowsCreateSuite, CreateSystemWindowTesting, instance, hWnd);
    ADD_TEST_USE_PARAMETER_1(windowsCreateSuite, GetHInstanceTesting, instance);
    ADD_TEST_USE_PARAMETER_2(windowsCreateSuite, WindowsCreateMenuTesting, instance, hWnd);

    return windowsCreateSuite;
}

CoreTools::Suite System::TestingWindowsMessage::GetWindowsProcessSuite()
{
    const auto hWnd = GetHWnd();

    auto windowsProcessSuite = GenerateSuite("Windows����");

    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, GetMessageTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, PeekMessageTesting, hWnd);
    ADD_TEST(windowsProcessSuite, PostQuitMessageTesting);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, ValidateRectTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, DefWindowProcTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, MessageBoxTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, DestroyWindowTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, SendMessageTesting, hWnd);
    ADD_TEST(windowsProcessSuite, GetCommandLineTesting);
    ADD_TEST_USE_PARAMETER_1(windowsProcessSuite, WindowPaintTesting, hWnd);

    return windowsProcessSuite;
}

CoreTools::Suite System::TestingWindowsMessage::GetWindowsRegisterSuite()
{
    const auto instance = System::GetHInstance();

    auto windowsRegisterSuite = GenerateSuite("Windowsע��");

    ADD_TEST(windowsRegisterSuite, GetStockObjectTesting);
    ADD_TEST_USE_PARAMETER_1(windowsRegisterSuite, LoadCursorTesting, instance);
    ADD_TEST_USE_PARAMETER_1(windowsRegisterSuite, LoadIconTesting, instance);
    ADD_TEST_USE_PARAMETER_1(windowsRegisterSuite, RegisterClassTesting, instance);
    ADD_TEST(windowsRegisterSuite, RegisterWindowMessageTesting);

    return windowsRegisterSuite;
}

CoreTools::Suite System::TestingWindowsMessage::GetWindowsSystemSuite()
{
    const auto hWnd = GetHWnd();

    auto windowsSystemSuite = GenerateSuite("Windowsϵͳ");

    ADD_TEST(windowsSystemSuite, GetActiveWindowTesting);
    ADD_TEST_USE_PARAMETER_1(windowsSystemSuite, GetSystemClientRectTesting, hWnd);

    return windowsSystemSuite;
}
