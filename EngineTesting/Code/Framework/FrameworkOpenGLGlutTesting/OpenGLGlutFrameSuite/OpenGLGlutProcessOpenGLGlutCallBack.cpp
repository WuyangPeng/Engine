///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 18:09)

#include "OpenGLGlutProcessOpenGLGlutCallBack.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/OpenGLGlutFrame/Flags/FrameParameter.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"

Framework::OpenGLGlutProcessOpenGLGlutCallBack::OpenGLGlutProcessOpenGLGlutCallBack() noexcept
    : ParentType{ System::gMicroseconds / 60 }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, OpenGLGlutProcessOpenGLGlutCallBack);

namespace Framework
{
    template <>
    OpenGLGlutProcess<OpenGLGlutProcessOpenGLGlutCallBack>::OpenGLGlutProcess(int64_t delta)
    {
        CoreTools::DisableNoexcept();

        System::UnusedFunction(delta);

        FRAMEWORK_SELF_CLASS_IS_VALID_9;
    }
}