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

        using Suite = CoreTools::Suite;

    public:
        TestingHelper(int argc, char** argv);
        virtual ~TestingHelper() noexcept;
        TestingHelper(const TestingHelper& rhs) = delete;
        TestingHelper& operator=(const TestingHelper& rhs) = delete;
        TestingHelper(TestingHelper&& rhs) noexcept = default;
        TestingHelper& operator=(TestingHelper&& rhs) noexcept = default;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();
        void Destroy();

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

        NODISCARD Suite GetEnvironmentDirectorySuite();
    };
}

#endif  // FRAMEWORK_TESTING_TESTING_HELPER_H
