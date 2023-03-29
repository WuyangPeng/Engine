///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/08 16:26)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_RELATIONSHIP_ITEM_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_RELATIONSHIP_ITEM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RelationshipItemTesting final : public UnitTest
    {
    public:
        using ClassType = RelationshipItemTesting;
        using ParentType = UnitTest;

    public:
        explicit RelationshipItemTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RelationshipItemTest();
        void TypeStringTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_RELATIONSHIP_ITEM_TESTING_H