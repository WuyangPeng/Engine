/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:53)

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
        using Relationships = SimpleCSV::Relationships;
        using RelationshipItem = SimpleCSV::RelationshipItem;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RelationshipItemTest();
        void TypeStringTest();

        void DoRelationshipItemTest(const Relationships& relationships, const RelationshipItem& relationshipItem);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_RELATIONSHIP_ITEM_TESTING_H