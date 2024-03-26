/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 12:27)

#ifndef SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_LANGUAGE_ID_DATA_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_LANGUAGE_ID_DATA_WINDOWS_TESTING_H

#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    /// @brief 消息框选择模块使用语言id的测试。
    /// 这里只测试hWnd参数不为空的情况。
    /// SystemTesting有hWnd参数为空时的测试。
    class MessageBoxSelectionUseLanguageIdDataWindowsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageBoxSelectionUseLanguageIdDataWindowsTesting;
        using ParentType = UnitTest;

    public:
        MessageBoxSelectionUseLanguageIdDataWindowsTesting(const OStreamShared& stream, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void MessageBoxTest();

        void DoMessageBoxTest(size_t index);

    private:
        using PrimaryLanguageContainer = std::vector<PrimaryLanguage>;
        using SubLanguageContainer = std::vector<SubLanguage>;

    private:
        WindowsHWnd hWnd;
        PrimaryLanguageContainer primaryLanguageFlags;
        SubLanguageContainer subLanguageFlags;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_LANGUAGE_ID_DATA_WINDOWS_TESTING_H