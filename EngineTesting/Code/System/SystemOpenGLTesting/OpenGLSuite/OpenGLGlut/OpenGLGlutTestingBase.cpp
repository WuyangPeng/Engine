/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/15 14:15)

#include "OpenGLGlutTestingBase.h"
#include "System/OpenGL/Flags/GlutFlags.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLGlutTestingBase::OpenGLGlutTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGlutTestingBase)

void System::OpenGLGlutTestingBase::GlutInit(bool multiSample) const noexcept
{
    GlutInitWindowSize(width, height);
    GlutInitContextVersion(4, 6);
    GlutInitWindowPosition(0, 0);
    GlutInitDisplayMode(multiSample);
}

void System::OpenGLGlutTestingBase::DoCreateWindowTest(int window, int mainWindow) const noexcept
{
    GlutSetWindow(window);
    GlutSetWindow(mainWindow);

    GlutPostWindowRedisplay(window);

    GlutSetOption(GlutOption::WindowClose, GlutExtension::GlutMainLoopReturns);
}
