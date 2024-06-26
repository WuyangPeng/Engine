///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 09:57)

#ifndef CAMERA_MODEL_VIEW_CONTROLLER_TESTING_TESTING_HELPER_H
#define CAMERA_MODEL_VIEW_CONTROLLER_TESTING_TESTING_HELPER_H

#include "CameraModelViewControllerMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

namespace CameraModelViewController
{
    using TestingHelperBase = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, CameraModelViewControllerTesting>;

    class TestingHelper final : public TestingHelperBase
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

#endif  // CAMERA_MODEL_VIEW_CONTROLLER_TESTING_TESTING_HELPER_H
