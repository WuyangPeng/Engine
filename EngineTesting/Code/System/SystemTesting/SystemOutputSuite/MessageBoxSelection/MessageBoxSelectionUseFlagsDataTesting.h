///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/30 0:08)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_FLAGS_DATA_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_FLAGS_DATA_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class MessageBoxSelectionUseFlagsDataTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageBoxSelectionUseFlagsDataTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageBoxSelectionUseFlagsDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void YesNoTest();
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_FLAGS_DATA_TESTING_H