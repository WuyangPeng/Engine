///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/30 0:09)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_YES_NO_CANCEL_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_YES_NO_CANCEL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MessageBoxSelectionUseYesNoCancelTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageBoxSelectionUseYesNoCancelTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageBoxSelectionUseYesNoCancelTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MessageBoxSelectionWithCharTest();
        void MessageBoxSelectionWithWCharTest();
        void MessageBoxSelectionWithTCharTest();
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_YES_NO_CANCEL_TESTING_H