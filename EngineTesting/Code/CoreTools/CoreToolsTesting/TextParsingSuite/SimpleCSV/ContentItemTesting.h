/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 16:47)

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