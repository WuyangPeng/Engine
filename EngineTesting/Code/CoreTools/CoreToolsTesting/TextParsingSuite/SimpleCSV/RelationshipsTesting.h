/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 16:54)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_RELATIONSHIPS_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_RELATIONSHIPS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RelationshipsTesting final : public UnitTest
    {
    public:
        using ClassType = RelationshipsTesting;
        using ParentType = UnitTest;

    public:
        explicit RelationshipsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Relationships = SimpleCSV::Relationships;
        using RelationshipItem = SimpleCSV::RelationshipItem;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RelationshipsTest();

        void GetRelationshipByIdTest(const Relationships& relationships, const RelationshipItem& relationshipItem);
        void RelationshipsOperationTest(Relationships& relationships);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_RELATIONSHIPS_TESTING_H