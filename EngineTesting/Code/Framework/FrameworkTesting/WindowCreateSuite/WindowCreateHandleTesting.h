///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/24 17:01)

#ifndef FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
#define FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H

#include "System/Windows/Flags/WindowsFlags.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
    class WindowCreateHandleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowCreateHandleTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowCreateHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest() noexcept;
    };
}

#endif  // FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
