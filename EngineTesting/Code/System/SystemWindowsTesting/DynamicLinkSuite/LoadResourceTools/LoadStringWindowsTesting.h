/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:38)

#ifndef SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_LOAD_STRING_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_LOAD_STRING_WINDOWS_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief 加载字符串模块的测试。
    /// 这里只测试dllModule参数为instance的情况。
    /// SystemWindowsTesting有dllModule不为instance时的测试。
    class LoadStringWindowsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LoadStringWindowsTesting;
        using ParentType = UnitTest;

    public:
        explicit LoadStringWindowsTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LoadStringTest();

    private:
        WindowsHInstance instance;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_LOAD_STRING_WINDOWS_TESTING_H