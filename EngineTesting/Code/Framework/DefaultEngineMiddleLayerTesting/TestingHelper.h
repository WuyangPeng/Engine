// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.4 (2019/09/10 19:24)

#ifndef DEFAULT_ENGINE_MIDDLE_LAYER_TESTING_TESTING_HELPER_H
#define DEFAULT_ENGINE_MIDDLE_LAYER_TESTING_TESTING_HELPER_H

#include "DefaultEngineMiddleLayerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

namespace DefaultEngineMiddleLayer
{
    using TestingHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, DefaultEngineMiddleLayerTesting>;

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

#endif  // DEFAULT_ENGINE_MIDDLE_LAYER_TESTING_TESTING_HELPER_H
