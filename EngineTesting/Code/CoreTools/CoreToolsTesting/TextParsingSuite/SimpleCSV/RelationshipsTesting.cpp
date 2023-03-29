///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/08 16:27)

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

using namespace std::literals;

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
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    const auto data = make_shared<SimpleCSV::XmlData>(document, "xl/_rels/workbook.xml.rels");

    SimpleCSV::Relationships relationships{ data };

    const auto size = relationships.GetRelationships().size();

    for (const auto& relationshipItem : relationships.GetRelationships())
    {
        ASSERT_EQUAL(relationshipItem.GetId(), relationships.GetRelationshipByID(relationshipItem.GetId()).GetId());
        ASSERT_EQUAL(relationshipItem.GetTarget(), relationships.GetRelationshipByTarget(relationshipItem.GetTarget()).GetTarget());

        ASSERT_TRUE(relationships.IsIdExists(relationshipItem.GetId()));
        ASSERT_TRUE(relationships.IsTargetExists(relationshipItem.GetTarget()));
    }

    relationships.AddRelationship(SimpleCSV::RelationshipType::ChartSheet, "/xl/"s);

    ASSERT_EQUAL(relationships.GetRelationships().size(), size + 1);

    relationships.DeleteRelationship("rId4");

    ASSERT_EQUAL(relationships.GetRelationships().size(), size);

    relationships.AddRelationship(SimpleCSV::RelationshipType::ChartSheet, "/xl/"s);

    ASSERT_EQUAL(relationships.GetRelationships().size(), size + 1);

    relationships.DeleteRelationship(relationships.GetRelationshipByID("rId5"));

    ASSERT_EQUAL(relationships.GetRelationships().size(), size);
}
