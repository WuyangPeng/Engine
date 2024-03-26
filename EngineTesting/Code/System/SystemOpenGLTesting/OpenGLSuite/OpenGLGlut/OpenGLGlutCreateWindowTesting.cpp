/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:44)

#include "OpenGLGlutCreateWindowTesting.h"
#include "System/OpenGL/Flags/GlutFlags.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessManager.h"

System::OpenGLGlutCreateWindowTesting::OpenGLGlutCreateWindowTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGlutCreateWindowTesting)

void System::OpenGLGlutCreateWindowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGlutCreateWindowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateWindowTest);
}

void System::OpenGLGlutCreateWindowTesting::CreateWindowTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(GlutInit, true);

    const auto window = GlutCreateWindow("OpenGL Glut Testing");
    ASSERT_LESS(0, window);

    const auto mainWindow = GlutGetWindow();

    GlutDisplayFunc(Framework::OpenGLGlutProcessManager::GetRenderSceneCallback());
    ASSERT_NOT_THROW_EXCEPTION_2(DoCreateWindowTest, window, mainWindow);
}
