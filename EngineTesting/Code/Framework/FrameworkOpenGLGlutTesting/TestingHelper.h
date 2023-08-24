///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 14:46)

#ifndef FRAMEWORK_TESTING_TESTING_HELPER_H
#define FRAMEWORK_TESTING_TESTING_HELPER_H

#include "FrameworkTestingOpenGLGlutCallBack.h"
#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"

namespace Framework
{
    class TestingHelper final : public OpenGLGlutMainFunctionHelper<OpenGLGlutFrameBuild, OpenGLGlutProcessFrameworkTesting>
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild, OpenGLGlutProcessFrameworkTesting>;

        using GLUTApplicationInformation = GLUTApplicationInformation;

    public:
        TestingHelper(int argc, char* argv[], const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // FRAMEWORK_TESTING_TESTING_HELPER_H
