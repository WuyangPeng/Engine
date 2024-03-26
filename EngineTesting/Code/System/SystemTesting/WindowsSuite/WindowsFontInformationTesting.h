/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:19)

#ifndef SYSTEM_WINDOWS_SUITE_WINDOWS_FONT_INFORMATION_TESTING_H
#define SYSTEM_WINDOWS_SUITE_WINDOWS_FONT_INFORMATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// SystemWindowsTesting有windows函数的测试。
    class WindowsFontInformationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsFontInformationTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsFontInformationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() const noexcept;
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_WINDOWS_FONT_INFORMATION_TESTING_H