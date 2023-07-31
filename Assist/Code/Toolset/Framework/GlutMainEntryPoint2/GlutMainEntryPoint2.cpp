///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:18)

#include "GlutMainEntryPoint2.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"

Framework::GlutMainEntryPoint2::GlutMainEntryPoint2(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ argc, argv, information, environmentDirectory }
{
    // 构造未完成
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, GlutMainEntryPoint2)
