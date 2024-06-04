/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 16:48)

#include "RelationshipItemTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/PropertyFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/RelationshipFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using System::operator++;

CoreTools::RelationshipItemTesting::RelationshipItemTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RelationshipItemTesting)

void CoreTools::RelationshipItemTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RelationshipItemTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RelationshipItemTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TypeStringTest);
}

void CoreTools::RelationshipItemTesting::RelationshipItemTest()
{
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx");

    const auto data = make_shared<SimpleCSV::XmlData>(document, "xl/_rels/workbook.xml.rels");

    for (const SimpleCSV::Relationships relationships{ data };
         const auto& relationshipItem : relationships.GetRelationships())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoRelationshipItemTest, relationships, relationshipItem);
    }
}

void CoreTools::RelationshipItemTesting::DoRelationshipItemTest(const Relationships& relationships, const RelationshipItem& relationshipItem)
{
    ASSERT_EQUAL(relationshipItem.GetId(), relationships.GetRelationshipById(relationshipItem.GetId()).GetId());
    ASSERT_EQUAL(relationshipItem.GetTarget(), relationships.GetRelationshipByTarget(relationshipItem.GetTarget()).GetTarget());

    ASSERT_EQUAL(SimpleCSV::RelationshipItem::GetTypeFromString(SimpleCSV::RelationshipItem::GetStringFromType(relationshipItem.GetType())), relationshipItem.GetType());
}

void CoreTools::RelationshipItemTesting::TypeStringTest()
{
    for (auto relationshipType = SimpleCSV::RelationshipType::CoreProperties; relationshipType <= SimpleCSV::RelationshipType::ControlProperties; ++relationshipType)
    {
        ASSERT_EQUAL(SimpleCSV::RelationshipItem::GetTypeFromString(SimpleCSV::RelationshipItem::GetStringFromType(relationshipType)), relationshipType);
    }
}
