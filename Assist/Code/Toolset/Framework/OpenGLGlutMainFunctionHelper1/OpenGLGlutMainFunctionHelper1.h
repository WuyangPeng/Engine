///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 13:39)

#ifndef OPENGL_GLUT_MAIN_FUNCTION_HELPER1_H
#define OPENGL_GLUT_MAIN_FUNCTION_HELPER1_H

#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuild.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcess.h"

namespace Framework
{
    using BaseType = OpenGLGlutMainFunctionHelper<OpenGLGlutFrameBuild, OpenGLGlutProcessInterface>;

    class OpenGLGlutMainFunctionHelper1 final : public BaseType
    {
    public:
        using ClassType = OpenGLGlutMainFunctionHelper1;
        using ParentType = BaseType;

    public:
        OpenGLGlutMainFunctionHelper1(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // OPENGL_GLUT_MAIN_FUNCTION_HELPER1_H