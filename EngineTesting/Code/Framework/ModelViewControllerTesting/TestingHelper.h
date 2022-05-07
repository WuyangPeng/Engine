// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/17 09:26)

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
