///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 10:55)

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