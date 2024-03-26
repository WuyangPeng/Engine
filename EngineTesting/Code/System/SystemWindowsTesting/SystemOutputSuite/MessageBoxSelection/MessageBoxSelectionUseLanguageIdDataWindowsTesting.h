/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 12:27)

#ifndef SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_LANGUAGE_ID_DATA_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_LANGUAGE_ID_DATA_WINDOWS_TESTING_H

#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    /// @brief ��Ϣ��ѡ��ģ��ʹ������id�Ĳ��ԡ�
    /// ����ֻ����hWnd������Ϊ�յ������
    /// SystemTesting��hWnd����Ϊ��ʱ�Ĳ��ԡ�
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