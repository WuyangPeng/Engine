/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 16:45)

#ifndef SYSTEM_OPENGL_TESTING_TESTING_HELPER_H
#define SYSTEM_OPENGL_TESTING_TESTING_HELPER_H

#include "OpenGLGlutCallBack.h"
#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"

namespace System
{
    using TestingHelperBase = Framework::OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild, OpenGLGlutProcessSystemOpenGLTesting>;

    class TestingHelper final : public TestingHelperBase
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = TestingHelperBase;

        using EnvironmentDirectory = Framework::EnvironmentDirectory;
        using GLUTApplicationInformation = Framework::GLUTApplicationInformation;

    public:
        TestingHelper(int argc, char** argv, const GLUTApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_TESTING_HELPER_H