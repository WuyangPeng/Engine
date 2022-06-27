///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 16:18)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

Framework::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "框架测试" }
{
    CoreTools::ObjectManager::Create();
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::TestingHelper::~TestingHelper() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    CoreTools::ObjectManager::Destroy();
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, TestingHelper)

void Framework::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddMainFunctionHelperSuite();
    AddWindowCreateSuite();
    AddWindowProcessSuite();
    AddWindowRegisterSuite();
    AddApplicationSuite();
    AddMiddleLayerSuite();
    AddWindowsAPIFrameSuite();
    AddOpenGLGlutFrameSuite();
    AddAndroidFrameSuite();
    AddLinuxFrameSuite();
    AddMacintoshFrameSuite();
    AddConsoleFrameSuite();
}

void Framework::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    ADD_TEST(helperSuite, UserMacroTesting);
    ADD_TEST(helperSuite, MainFunctionEntryPointTesting);
    ADD_TEST(helperSuite, MainFunctionTesting);
    ADD_TEST(helperSuite, MiddleLayerMacroTesting);

    AddSuite(helperSuite);
}

void Framework::TestingHelper::AddMainFunctionHelperSuite()
{
    auto mainFunctionHelperSuite = GenerateSuite("主函数帮助");

    ADD_TEST(mainFunctionHelperSuite, EnvironmentDirectoryTesting);
    ADD_TEST(mainFunctionHelperSuite, MainFunctionHelperBaseTesting);
    ADD_TEST(mainFunctionHelperSuite, ConsoleMainFunctionHelperBaseTesting);
    ADD_TEST(mainFunctionHelperSuite, ConsoleMainFunctionHelperTesting);
    ADD_TEST(mainFunctionHelperSuite, WindowMainFunctionHelperTesting);
    ADD_TEST(mainFunctionHelperSuite, OpenGLGlutMainFunctionHelperTesting);
    ADD_TEST(mainFunctionHelperSuite, AndroidMainFunctionHelperTesting);
    ADD_TEST(mainFunctionHelperSuite, MacintoshMainFunctionHelperTesting);

    AddSuite(mainFunctionHelperSuite);
}

void Framework::TestingHelper::AddWindowCreateSuite()
{
    auto windowCreateSuite = GenerateSuite("Window创建");

    ADD_TEST(windowCreateSuite, WindowSizeTesting);
    ADD_TEST(windowCreateSuite, WindowPointTesting);
    ADD_TEST(windowCreateSuite, WindowInstanceParameterTesting);
    ADD_TEST(windowCreateSuite, WindowCreateParameterTesting);
    ADD_TEST(windowCreateSuite, WindowCreateHandleTesting);

    AddSuite(windowCreateSuite);
}

void Framework::TestingHelper::AddWindowProcessSuite()
{
    auto windowProcessSuite = GenerateSuite("窗口进程");

    ADD_TEST(windowProcessSuite, VirtualKeysTypesTesting);
    ADD_TEST(windowProcessSuite, WindowMessageLoopTesting);
    ADD_TEST(windowProcessSuite, WindowMessageInterfaceTesting);
    ADD_TEST(windowProcessSuite, WindowMessageTesting);
    ADD_TEST(windowProcessSuite, WindowProcessManagerTesting);
    ADD_TEST(windowProcessSuite, WindowProcessHandleTesting);
    ADD_TEST(windowProcessSuite, WindowMessageUnitTestSuiteTesting);

    AddSuite(windowProcessSuite);
}

void Framework::TestingHelper::AddWindowRegisterSuite()
{
    auto windowRegisterSuite = GenerateSuite("Window注册");

    ADD_TEST(windowRegisterSuite, WindowRegisterParameterTesting);
    ADD_TEST(windowRegisterSuite, WindowHIconTesting);
    ADD_TEST(windowRegisterSuite, WindowHCursorTesting);
    ADD_TEST(windowRegisterSuite, WindowHBrushTesting);
    ADD_TEST(windowRegisterSuite, WindowPictorialTesting);
    ADD_TEST(windowRegisterSuite, WindowNameTesting);
    ADD_TEST(windowRegisterSuite, WindowRegisterTesting);

    AddSuite(windowRegisterSuite);
}

void Framework::TestingHelper::AddApplicationSuite()
{
    auto applicationSuite = GenerateSuite("应用");

    ADD_TEST(applicationSuite, ApplicationTraitTesting);
    ADD_TEST(applicationSuite, FontInformationTesting);
    ADD_TEST(applicationSuite, MousePositionTesting);
    ADD_TEST(applicationSuite, PerformanceMeasurementsTesting);
    ADD_TEST(applicationSuite, WindowApplicationInformationTesting);
    ADD_TEST(applicationSuite, GLUTApplicationInformationTesting);
    ADD_TEST(applicationSuite, PixelScreenTesting);
    ADD_TEST(applicationSuite, CameraMotionTesting);
    ADD_TEST(applicationSuite, ObjectMotionTesting);

    AddSuite(applicationSuite);
}

void Framework::TestingHelper::AddMiddleLayerSuite()
{
    auto middleLayerSuite = GenerateSuite("中间层");

    ADD_TEST(middleLayerSuite, MiddleLayerInterfaceTesting);
    ADD_TEST(middleLayerSuite, ModelViewControllerMiddleLayerTesting);
    ADD_TEST(middleLayerSuite, ModelViewControllerMiddleLayerContainerTesting);
    ADD_TEST(middleLayerSuite, ModelMiddleLayerTesting);
    ADD_TEST(middleLayerSuite, ViewMiddleLayerTesting);
    ADD_TEST(middleLayerSuite, ControllerMiddleLayerTesting);
    ADD_TEST(middleLayerSuite, PixelViewMiddleLayerTesting);
    ADD_TEST(middleLayerSuite, CameraModelMiddleLayerTesting);
    ADD_TEST(middleLayerSuite, CameraViewMiddleLayerTesting);
    ADD_TEST(middleLayerSuite, CameraControllerMiddleLayerTesting);
    ADD_TEST(middleLayerSuite, EngineMiddleLayerInterfaceTesting);
    ADD_TEST(middleLayerSuite, NetworkManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, ObjectLogicManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, ObjectLogicManagerTesting);
    ADD_TEST(middleLayerSuite, ArtificialIntellegenceInterfaceTesting);
    ADD_TEST(middleLayerSuite, ObjectLogicInterfaceTesting);
    ADD_TEST(middleLayerSuite, InputManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, InputManagerTesting);
    ADD_TEST(middleLayerSuite, PhysicalModellingManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, MessageManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, EventManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, SystemManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, ResourceManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, AudioManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, CameraSystemsManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, RenderingManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, GUIManagerInterfaceTesting);
    ADD_TEST(middleLayerSuite, EngineMiddleLayerContainerTesting);

    AddSuite(middleLayerSuite);
}

void Framework::TestingHelper::AddWindowsAPIFrameSuite()
{
    auto windowsAPIFrameSuite = GenerateSuite("Windows API 框架创建");

    ADD_TEST(windowsAPIFrameSuite, WindowsAPIFrameBuildTesting);

    AddSuite(windowsAPIFrameSuite);
}

void Framework::TestingHelper::AddOpenGLGlutFrameSuite()
{
    auto openGLGlutFrameSuite = GenerateSuite("OpenGL GLUT 框架创建");

    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutProcessManagerTesting);
    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutProcessTesting);
    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutCallBackInterfaceTesting);
    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutCallBackTesting);
    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutCallBackUnitTestSuiteTesting);
    ADD_TEST(openGLGlutFrameSuite, OpenGLGlutFrameBuildTesting);

    AddSuite(openGLGlutFrameSuite);
}

void Framework::TestingHelper::AddAndroidFrameSuite()
{
    auto androidFrameSuite = GenerateSuite("安卓框架");

    ADD_TEST(androidFrameSuite, AndroidProcessManagerTesting);
    ADD_TEST(androidFrameSuite, AndroidProcessTesting);
    ADD_TEST(androidFrameSuite, AndroidCallBackInterfaceTesting);
    ADD_TEST(androidFrameSuite, AndroidCallBackTesting);
    ADD_TEST(androidFrameSuite, AndroidCallBackUnitTestSuiteTesting);
    ADD_TEST(androidFrameSuite, AndroidMessageLoopTesting);
    ADD_TEST(androidFrameSuite, AndroidFrameBuildTesting);

    AddSuite(androidFrameSuite);
}

void Framework::TestingHelper::AddLinuxFrameSuite()
{
    auto linuxFrameSuite = GenerateSuite("Linux框架");

    ADD_TEST(linuxFrameSuite, LinuxProcessTesting);
    ADD_TEST(linuxFrameSuite, LinuxCallBackInterfaceTesting);
    ADD_TEST(linuxFrameSuite, LinuxFrameBuildTesting);

    AddSuite(linuxFrameSuite);
}

void Framework::TestingHelper::AddMacintoshFrameSuite()
{
    auto macintoshFrameSuite = GenerateSuite("Macintosh框架");

    ADD_TEST(macintoshFrameSuite, MacintoshProcessTesting);
    ADD_TEST(macintoshFrameSuite, MacintoshCallBackInterfaceTesting);
    ADD_TEST(macintoshFrameSuite, MacintoshFrameBuildTesting);

    AddSuite(macintoshFrameSuite);
}

void Framework::TestingHelper::AddConsoleFrameSuite()
{
    auto consoleFrameSuite = GenerateSuite("Console框架");

    ADD_TEST(consoleFrameSuite, ConsoleProcessTesting);
    ADD_TEST(consoleFrameSuite, ConsoleCallBackInterfaceTesting);
    ADD_TEST(consoleFrameSuite, ConsoleFrameBuildTesting);

    AddSuite(consoleFrameSuite);
}