///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:12)

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
        void DoRunUnitTest() override;
        void MainTest();

        void MessageBoxSelectionWithCharTest();
        void MessageBoxSelectionWithWCharTest();
        void MessageBoxSelectionWithTCharTest();
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_YES_NO_CANCEL_TESTING_H