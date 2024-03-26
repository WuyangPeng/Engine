/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:25)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_HANDLE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_HANDLE_TESTING_H

#include "System/FileManager/FileManagerFwd.h"
#include "System/Console/Fwd/ConsoleFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    /// @brief 控制台句柄测试。
    /// 测试资源在ConsoleHandleTesting目录下。
    class ConsoleHandleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleHandleTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using StandardHandleContainer = std::vector<StandardHandle>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void HandleTest();
        void DoHandleTest(StandardHandle standardHandle);
        void InputHandleTest(StandardHandle standardHandle);
        void OutputHandleTest(StandardHandle standardHandle);
        void SetStandardHandleTest(StandardHandle standardHandle, WindowsHandle windowsHandle);

        void PreviousHandleTest(StandardHandle standardHandle, WindowsHandle defaultHandle, WindowsHandle windowsHandle);

        void StandardHandleTest(StandardHandle standardHandle, const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode);

    private:
        StandardHandleContainer standardHandles;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_HANDLE_TESTING_H