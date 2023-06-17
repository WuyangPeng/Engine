///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:23)

#ifndef MODEL_VIEW_CONTROLLER_TESTING_TESTING_HELPER_H
#define MODEL_VIEW_CONTROLLER_TESTING_TESTING_HELPER_H

#include "ModelViewControllerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

namespace ModelViewController
{
    using TestingHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, ModelViewControllerTesting>;

    class TestingHelper : public TestingHelperBase
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = TestingHelperBase;
        using WindowApplicationInformation = Framework::WindowApplicationInformation;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        TestingHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // MODEL_VIEW_CONTROLLER_TESTING_TESTING_HELPER_H
