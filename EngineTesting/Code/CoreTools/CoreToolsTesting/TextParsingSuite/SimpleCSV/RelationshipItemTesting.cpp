///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/13 21:07)

#include "RelationshipItemTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/ContentItem.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/PropertyFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/SheetFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Worksheet.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

using namespace std::literals;
using std::make_shared;
using std::string;
using std::vector;

namespace CoreTools
{
    namespace SimpleCSV
    {
        ENUM_INCREMENTABLE_OPERATOR_DEFINE(RelationshipType)
    }
}

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
    auto document = SimpleCSV::Document::Open("Resource/CSVTesting/ExcelConversionCSVTesting.xlsx"s);

    auto data = make_shared<SimpleCSV::XmlData>(document, "xl/_rels/workbook.xml.rels");

    SimpleCSV::Relationships relationships{ data };

    for (const auto& relationshipItem : relationships.GetRelationships())
    {
        ASSERT_EQUAL(relationshipItem.GetID(), relationships.GetRelationshipByID(relationshipItem.GetID()).GetID());
        ASSERT_EQUAL(relationshipItem.GetTarget(), relationships.GetRelationshipByTarget(relationshipItem.GetTarget()).GetTarget());

        ASSERT_ENUM_EQUAL(SimpleCSV::RelationshipItem::GetTypeFromString(SimpleCSV::RelationshipItem::GetStringFromType(relationshipItem.GetType())), relationshipItem.GetType());
    }
}

void CoreTools::RelationshipItemTesting::TypeStringTest()
{
    for (auto relationshipType = SimpleCSV::RelationshipType::CoreProperties; relationshipType <= SimpleCSV::RelationshipType::ControlProperties; ++relationshipType)
    {
        ASSERT_ENUM_EQUAL(SimpleCSV::RelationshipItem::GetTypeFromString(SimpleCSV::RelationshipItem::GetStringFromType(relationshipType)), relationshipType);
    }
}
