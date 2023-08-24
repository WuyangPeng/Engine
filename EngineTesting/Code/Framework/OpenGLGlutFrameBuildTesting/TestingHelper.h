///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 11:21)

#ifndef OPENGL_GLUT_FRAME_BUILD_TESTING_TESTING_HELPER_H
#define OPENGL_GLUT_FRAME_BUILD_TESTING_TESTING_HELPER_H

#include "System/Helper/GLExtensionsMacro.h"
#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcess.h"

namespace OpenGLGlutFrameBuildTesting
{
    class TestingHelper final : public Framework::OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild, Framework::OpenGLGlutProcessInterface>
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild, Framework::OpenGLGlutProcessInterface>;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using GLUTApplicationInformation = Framework::GLUTApplicationInformation;

    public:
        TestingHelper(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // OPENGL_GLUT_FRAME_BUILD_TESTING_TESTING_HELPER_H