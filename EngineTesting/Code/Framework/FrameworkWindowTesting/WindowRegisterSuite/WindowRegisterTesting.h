// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/11 0:10)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_TESTING_H

#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowRegisterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowRegisterTesting;
        using ParentType = UnitTest;
        using HInstance = System::WindowsHInstance;

    public:
        explicit WindowRegisterTesting(const OStreamShared& stream, HInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void RegisterTest();

    private:
        HInstance m_Instance;
        int m_Count;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_REGISTER_TESTING_H
