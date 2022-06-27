///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/17 22:48)

#ifndef RENDERING_OPENGL_TESTING_TESTING_HELPER_H
#define RENDERING_OPENGL_TESTING_TESTING_HELPER_H

#include "RenderingOpenGLTestingOpenGLGlutCallBack.h"
#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"

namespace Rendering
{
    using TestingHelperBase = Framework::OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild, OpenGLGlutProcessSystemOpenGLTesting>;

    class TestingHelper : public TestingHelperBase
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = TestingHelperBase;
        using GLUTApplicationInformation = Framework::GLUTApplicationInformation;

    public:
        TestingHelper(int argc, char** argv, const GLUTApplicationInformation& information, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // RENDERING_OPENGL_TESTING_TESTING_HELPER_H