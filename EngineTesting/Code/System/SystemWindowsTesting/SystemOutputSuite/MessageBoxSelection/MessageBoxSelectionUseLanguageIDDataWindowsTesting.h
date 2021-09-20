///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/23 20:16)

#ifndef SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_LANGUAGE_ID_DATA_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_LANGUAGE_ID_DATA_WINDOWS_TESTING_H

#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <random>
#include <vector>

namespace System
{
    class MessageBoxSelectionUseLanguageIDDataWindowsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageBoxSelectionUseLanguageIDDataWindowsTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageBoxSelectionUseLanguageIDDataWindowsTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void MessageBoxTest();

    private:
        using PrimaryLanguageCollection = std::vector<PrimaryLanguage>;
        using SubLanguageCollection = std::vector<SubLanguage>;

    private:
        WindowsHWnd hwnd;
        PrimaryLanguageCollection primaryLanguageFlags;
        SubLanguageCollection subLanguageFlags;
        size_t maxSize;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_LANGUAGE_ID_DATA_WINDOWS_TESTING_H