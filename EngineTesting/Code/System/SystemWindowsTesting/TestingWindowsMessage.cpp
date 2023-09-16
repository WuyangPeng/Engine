///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:36)

#include "Testing.h"
#include "TestingWindowsMessage.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "Framework/WindowProcess/WindowMessageUnitTestSuiteDetail.h"

System::TestingWindowsMessage::TestingWindowsMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, "【系统库】Window单元测试套件", environmentDirectory }
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
    auto systemOutputSuite = GenerateSuite("系统输出");

    systemOutputSuite.AddSuite(GetMessageBoxSelectionSuite());

    AddSuite(systemOutputSuite);
}

CoreTools::Suite System::TestingWindowsMessage::GetMessageBoxSelectionSuite()
{
    const auto hWnd = GetHWnd();

    auto messageBoxSelectionSuite = GenerateSuite("消息框选择");

    ADD_TEST_USE_PARAMETER_1(messageBoxSelectionSuite, MessageBoxSelectionUseFlagsDataWindowsTesting, hWnd);
    ADD_TEST_USE_PARAMETER_1(messageBoxSelectionSuite, MessageBoxSelectionUseLanguageIdDataWindowsTesting, hWnd);

    return messageBoxSelectionSuite;
}

void System::TestingWindowsMessage::AddDynamicLinkSuite()
{
    auto dynamicLinkSuite = GenerateSuite("动态链接库工具");

    dynamicLinkSuite.AddSuite(GetLoadResourceToolsSuite());
    dynamicLinkSuite.AddSuite(GetEnumResourceToolsSuite());

    AddSuite(dynamicLinkSuite);
}

CoreTools::Suite System::TestingWindowsMessage::GetLoadResourceToolsSuite()
{
    const auto instance = System::GetHInstance();

    auto loadResourceToolsSuite = GenerateSuite("加载资源工具");

    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, FindResourceWindowsTesting, instance);
    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, LoadResourceWindowsTesting, instance);
    ADD_TEST_USE_PARAMETER_1(loadResourceToolsSuite, LoadStringWindowsTesting, instance);

    return loadResourceToolsSuite;
}

CoreTools::Suite System::TestingWindowsMessage::GetEnumResourceToolsSuite()
{
    const auto instance = System::GetHInstance();

    auto enumResourceToolsSuite = GenerateSuite("列举资源工具");

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

    auto windowsSuite = GenerateSuite("Windows系统");

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

    auto windowsCreateSuite = GenerateSuite("Windows创建");

    ADD_TEST_USE_PARAMETER_2(windowsCreateSuite, CreateSystemWindowTesting, instance, hWnd);
    ADD_TEST_USE_PARAMETER_1(windowsCreateSuite, GetHInstanceTesting, instance);
    ADD_TEST_USE_PARAMETER_2(windowsCreateSuite, WindowsCreateMenuTesting, instance, hWnd);

    return windowsCreateSuite;
}

CoreTools::Suite System::TestingWindowsMessage::GetWindowsProcessSuite()
{
    const auto hWnd = GetHWnd();

    auto windowsProcessSuite = GenerateSuite("Windows进程");

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

    auto windowsRegisterSuite = GenerateSuite("Windows注册");

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

    auto windowsSystemSuite = GenerateSuite("Windows系统");

    ADD_TEST(windowsSystemSuite, GetActiveWindowTesting);
    ADD_TEST_USE_PARAMETER_1(windowsSystemSuite, GetSystemClientRectTesting, hWnd);

    return windowsSystemSuite;
}
