/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:45)

#include "OpenGLGlutDestroyTesting.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

int System::OpenGLGlutDestroyTesting::destroyWindowId{ 0 };

System::OpenGLGlutDestroyTesting::OpenGLGlutDestroyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGlutDestroyTesting)

void System::OpenGLGlutDestroyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGlutDestroyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DestroyWindowTest);
}

void System::OpenGLGlutDestroyTesting::DestroyWindowTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(GlutInit, false);

    const auto mainWindow = GlutGetWindow();

    destroyWindowId = GlutCreateWindow("Not Displayed Window");
    ASSERT_LESS(0, destroyWindowId);

    GlutSetWindow(destroyWindowId);
    GlutDisplayFunc(RenderSceneCallback);

    GlutSetWindow(mainWindow);
}

void System::OpenGLGlutDestroyTesting::RenderSceneCallback() noexcept
{
    GlutSwapBuffers();

    GlutDestroyWindow(destroyWindowId);
}
