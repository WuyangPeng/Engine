///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 16:41)

#ifndef FRAMEWORK_WINDOW_PROCESS_SUITE_VIRTUAL_KEYS_TYPES_TESTING_H
#define FRAMEWORK_WINDOW_PROCESS_SUITE_VIRTUAL_KEYS_TYPES_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class VirtualKeysTypesTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = VirtualKeysTypesTesting;
        using ParentType = UnitTest;

    public:
        explicit VirtualKeysTypesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void WindowKeysTest();
        void GlutKeysTest();
        void SetModifiersTest();

        NODISCARD static System::WindowsWParam RandomParam(System::WindowsWParam wParam, int mouseModifiers, bool isDown) noexcept;

        NODISCARD constexpr static bool IsKeyDown(int key, int mouseModifiers) noexcept
        {
            return key == mouseModifiers;
        }

        NODISCARD constexpr static bool IsButtonDown(int button, int mouseModifiers) noexcept
        {
            return button == mouseModifiers;
        }

        NODISCARD static int GetModifiers(int keyDown) noexcept;
        NODISCARD static int GetButton(int mouseDown) noexcept;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_SUITE_VIRTUAL_KEYS_TYPES_TESTING_H