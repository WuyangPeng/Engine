///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 11:16)

#ifndef FRAMEWORK_APPLICATION_SUITE_APPLICATION_TRAIT_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_APPLICATION_TRAIT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class ApplicationTraitTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ApplicationTraitTesting;
        using ParentType = UnitTest;

    public:
        explicit ApplicationTraitTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void KeyIdentifiersTest();
        void KeyboardModifiersTest();
        void MouseButtonsTest();
        void MouseStateTest();
        void MouseModifiersTest();

        void WindowKeyIdentifiersTest() noexcept;
        void WindowKeyboardModifiersTest() noexcept;
        void WindowMouseButtonsTest() noexcept;
        void WindowMouseStateTest() noexcept;
        void WindowMouseModifiersTest() noexcept;

        void GlutKeyIdentifiersTest() noexcept;
        void GlutKeyboardModifiersTest() noexcept;
        void GlutMouseButtonsTest() noexcept;
        void GlutMouseStateTest() noexcept;
        void GlutMouseModifiersTest() noexcept;

        void AndroidKeyIdentifiersTest() noexcept;
        void AndroidKeyboardModifiersTest() noexcept;
        void AndroidMouseButtonsTest() noexcept;
        void AndroidMouseStateTest() noexcept;
        void AndroidMouseModifiersTest() noexcept;

        void LinuxKeyIdentifiersTest() noexcept;
        void LinuxKeyboardModifiersTest() noexcept;
        void LinuxMouseButtonsTest() noexcept;
        void LinuxMouseStateTest() noexcept;
        void LinuxMouseModifiersTest() noexcept;

        void MacintoshKeyIdentifiersTest() noexcept;
        void MacintoshKeyboardModifiersTest() noexcept;
        void MacintoshMouseButtonsTest() noexcept;
        void MacintoshMouseStateTest() noexcept;
        void MacintoshMouseModifiersTest() noexcept;
    };
}

#endif  // FRAMEWORK_APPLICATION_SUITE_APPLICATION_TRAIT_TESTING_H