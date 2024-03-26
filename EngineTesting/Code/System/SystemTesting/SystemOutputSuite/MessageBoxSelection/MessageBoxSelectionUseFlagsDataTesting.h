/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 12:19)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_FLAGS_DATA_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_FLAGS_DATA_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// @brief 消息框选择模块使用标志数据的测试。
    /// 这里只测试hWnd参数为空的情况。
    /// SystemWindowsTesting有hWnd参数不为空时的测试。
    class MessageBoxSelectionUseFlagsDataTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageBoxSelectionUseFlagsDataTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageBoxSelectionUseFlagsDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void YesNoTest();
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_MESSAGE_BOX_SELECTION_USE_FLAGS_DATA_TESTING_H