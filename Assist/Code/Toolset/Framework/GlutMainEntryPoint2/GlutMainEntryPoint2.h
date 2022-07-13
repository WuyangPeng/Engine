///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 10:20)

#ifndef GLUT_MAIN_ENTRY_POINT2_H
#define GLUT_MAIN_ENTRY_POINT2_H

#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuild.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcess.h"

namespace Framework
{
    using BaseType = OpenGLGlutMainFunctionHelper<OpenGLGlutFrameBuild, OpenGLGlutProcessInterface>;

    class GlutMainEntryPoint2 : public BaseType
    {
    public:
        using ClassType = GlutMainEntryPoint2;
        using ParentType = BaseType;

    public:
        GlutMainEntryPoint2(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // GLUT_MAIN_ENTRY_POINT1_H
