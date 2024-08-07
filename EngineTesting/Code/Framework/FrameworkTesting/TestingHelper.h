/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/07 10:41)

#ifndef FRAMEWORK_TESTING_TESTING_HELPER_H
#define FRAMEWORK_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace Framework
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddHelperSuite();
        void AddMainFunctionHelperSuite();
        void AddWindowCreateSuite();
        void AddWindowProcessSuite();
        void AddWindowRegisterSuite();
        void AddApplicationSuite();
        void AddMiddleLayerSuite();
        void AddWindowsAPIFrameSuite();
        void AddOpenGLGlutFrameSuite();
        void AddAndroidFrameSuite();
        void AddLinuxFrameSuite();
        void AddMacintoshFrameSuite();
        void AddConsoleFrameSuite();
        void AddProjectSuite();
    };
}

#endif  // FRAMEWORK_TESTING_TESTING_HELPER_H
