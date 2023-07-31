///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:20)

#ifndef GLUT_MAIN_ENTRY_POINT1_H
#define GLUT_MAIN_ENTRY_POINT1_H

#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuild.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcess.h"

namespace Framework
{
    using BaseType = OpenGLGlutMainFunctionHelper<OpenGLGlutFrameBuild, OpenGLGlutProcessInterface>;

    class GlutMainEntryPoint1 final : public BaseType
    {
    public:
        using ClassType = GlutMainEntryPoint1;
        using ParentType = BaseType;

    public:
        GlutMainEntryPoint1(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // GLUT_MAIN_ENTRY_POINT1_H
