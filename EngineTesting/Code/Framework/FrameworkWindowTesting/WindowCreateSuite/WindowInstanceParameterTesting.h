// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 15:35)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_INSTANCE_PARAMETER_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_INSTANCE_PARAMETER_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowInstanceParameterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowInstanceParameterTesting;
        using ParentType = UnitTest;
        using HInstance = System::WindowsHInstance;

    public:
        WindowInstanceParameterTesting(const OStreamShared& osPtr, HInstance instance);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ValueTest();

        void DoRunUnitTest() final;

    private:
        HInstance m_Instance;
    };
}

#endif  // FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_INSTANCE_PARAMETER_TESTING_H
