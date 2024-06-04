/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:54)

#include "RelationshipsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/PropertyFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/RelationshipFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::RelationshipsTesting::RelationshipsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RelationshipsTesting)

void CoreTools::RelationshipsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RelationshipsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RelationshipsTest);
}

void CoreTools::RelationshipsTesting::RelationshipsTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    const auto data = make_shared<SimpleCSV::XmlData>(document, "xl/_rels/workbook.xml.rels");

    SimpleCSV::Relationships relationships{ data };

    for (const auto& relationshipItem : relationships.GetRelationships())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(GetRelationshipByIdTest, relationships, relationshipItem);
    }

    ASSERT_NOT_THROW_EXCEPTION_1(RelationshipsOperationTest, relationships);
}

void CoreTools::RelationshipsTesting::GetRelationshipByIdTest(const Relationships& relationships, const RelationshipItem& relationshipItem)
{
    ASSERT_EQUAL(relationshipItem.GetId(), relationships.GetRelationshipById(relationshipItem.GetId()).GetId());
    ASSERT_EQUAL(relationshipItem.GetTarget(), relationships.GetRelationshipByTarget(relationshipItem.GetTarget()).GetTarget());

    ASSERT_TRUE(relationships.IsIdExists(relationshipItem.GetId()));
    ASSERT_TRUE(relationships.IsTargetExists(relationshipItem.GetTarget()));
}

void CoreTools::RelationshipsTesting::RelationshipsOperationTest(Relationships& relationships)
{
    const auto size = relationships.GetRelationships().size();

    relationships.AddRelationship(SimpleCSV::RelationshipType::ChartSheet, "/xl/");

    ASSERT_EQUAL(relationships.GetRelationships().size(), size + 1);

    relationships.DeleteRelationship("rId4");

    ASSERT_EQUAL(relationships.GetRelationships().size(), size);

    relationships.AddRelationship(SimpleCSV::RelationshipType::ChartSheet, "/xl/");

    ASSERT_EQUAL(relationships.GetRelationships().size(), size + 1);

    relationships.DeleteRelationship(relationships.GetRelationshipById("rId5"));

    ASSERT_EQUAL(relationships.GetRelationships().size(), size);
}