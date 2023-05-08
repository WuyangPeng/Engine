///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/26 15:14)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_ITEM_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_ITEM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ContentItemTesting final : public UnitTest
    {
    public:
        using ClassType = ContentItemTesting;
        using ParentType = UnitTest;

    public:
        explicit ContentItemTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ContentItemTest();
        void TypeStringTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_ITEM_TESTING_H