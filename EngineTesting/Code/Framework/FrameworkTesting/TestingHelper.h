///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 16:19)

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
        ~TestingHelper() noexcept;
        TestingHelper(const TestingHelper& rhs) = delete;
        TestingHelper& operator=(const TestingHelper& rhs) = delete;
        TestingHelper(TestingHelper&& rhs) noexcept = delete;
        TestingHelper& operator=(TestingHelper&& rhs) noexcept = delete;

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
    };
}

#endif  // FRAMEWORK_TESTING_TESTING_HELPER_H
