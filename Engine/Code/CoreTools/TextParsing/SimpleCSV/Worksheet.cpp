///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:29)

#include "CoreTools/CoreToolsExport.h"

#include "CellReference.h"
#include "Document.h"
#include "RowRange.h"
#include "Worksheet.h"
#include "XmlFile.h"
#include "XmlParser.h"
#include "Detail/Utilities.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySharedStrings.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

using std::string;
using std::vector;

CoreTools::SimpleCSV::Worksheet::Worksheet(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    Init();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, Worksheet)

CoreTools::SimpleCSV::Worksheet::CellSharedPtr CoreTools::SimpleCSV::Worksheet::GetCell(const string& ref) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetCell(CellReference{ ref });
}

CoreTools::SimpleCSV::Worksheet::CellSharedPtr CoreTools::SimpleCSV::Worksheet::GetCell(const CellReference& ref) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetCell(ref.GetRow(), ref.GetColumn());
}

CoreTools::SimpleCSV::Worksheet::CellSharedPtr CoreTools::SimpleCSV::Worksheet::GetCell(int rowNumber, int columnNumber) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDocument = GetXmlDocument();
    const auto cellNode = GetCellNode(rowNumber, columnNumber);

    auto sharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

    return Cell::CreateCell(xmlDocument, cellNode, sharedStrings);
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::Worksheet::GetCellNode(int rowNumber, int columnNumber) const
{
    auto rowNode = GetRowNode(GetSheetData(), rowNumber);
    const auto rowNodeColumnNumber = GetColumnNumber(rowNode);

    if (rowNodeColumnNumber == 0 || rowNodeColumnNumber < columnNumber)
    {
        CellReference cellRef{ rowNumber, columnNumber };

        auto cellNode = rowNode.append_child(TextParsing::g_ChildC.data());
        cellNode.append_attribute(TextParsing::g_AttributeR.data()).set_value(cellRef.GetAddress().c_str());

        return rowNode.last_child();
    }
    else if (rowNodeColumnNumber - columnNumber < columnNumber)
    {
        auto cellNode = rowNode.last_child();
        while (columnNumber < CellReference::GetColumn(GetAttributeR(cellNode)))
        {
            cellNode = cellNode.previous_sibling();
        }

        if (CellReference::GetColumn(GetAttributeR(cellNode)) < columnNumber)
        {
            CellReference cellRef{ rowNumber, columnNumber };

            cellNode = rowNode.insert_child_after(TextParsing::g_ChildC.data(), cellNode);
            cellNode.append_attribute(TextParsing::g_AttributeR.data()).set_value(cellRef.GetAddress().c_str());
        }

        return cellNode;
    }
    else
    {
        auto cellNode = rowNode.first_child();
        while (CellReference::GetColumn(GetAttributeR(cellNode)) < columnNumber)
        {
            cellNode = cellNode.next_sibling();
        }

        if (columnNumber < CellReference::GetColumn(GetAttributeR(cellNode)))
        {
            CellReference cellRef{ rowNumber, columnNumber };

            cellNode = rowNode.insert_child_before(TextParsing::g_ChildC.data(), cellNode);
            cellNode.append_attribute(TextParsing::g_AttributeR.data()).set_value(cellRef.GetAddress().c_str());
        }

        return cellNode;
    }
}

CoreTools::SimpleCSV::CellRange CoreTools::SimpleCSV::Worksheet::GetRange() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetRange(CellReference{ TextParsing::g_DefaultCellAddress.data() }, GetLastCell());
}

CoreTools::SimpleCSV::CellRange CoreTools::SimpleCSV::Worksheet::GetRange(const CellReference& topLeft, const CellReference& bottomRight) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDocument = GetXmlDocument();

    auto querySharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

    return CellRange{ xmlDocument,
                      xmlDocument->first_child().child(TextParsing::g_SheetData.data()),
                      topLeft,
                      bottomRight,
                      querySharedStrings };
}

CoreTools::SimpleCSV::RowRange CoreTools::SimpleCSV::Worksheet::GetRows() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDocument = GetXmlDocument();

    auto querySharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

    const auto sheetData = GetSheetData();

    return RowRange{ xmlDocument,
                     sheetData,
                     1,
                     (sheetData.last_child() ? sheetData.last_child().attribute(TextParsing::g_AttributeR.data()).as_int() : 1),
                     querySharedStrings };
}

CoreTools::SimpleCSV::RowRange CoreTools::SimpleCSV::Worksheet::GetRows(int rowCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDocument = GetXmlDocument();

    auto querySharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

    const auto sheetData = GetSheetData();

    return RowRange{ xmlDocument,
                     sheetData,
                     1,
                     rowCount,
                     querySharedStrings };
}

CoreTools::SimpleCSV::RowRange CoreTools::SimpleCSV::Worksheet::GetRows(int firstRow, int lastRow) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDocument = GetXmlDocument();

    const auto sheetData = GetSheetData();
    auto querySharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

    return RowRange{ xmlDocument,
                     sheetData,
                     firstRow,
                     lastRow,
                     querySharedStrings };
}

CoreTools::SimpleCSV::Worksheet::RowSharedPtr CoreTools::SimpleCSV::Worksheet::GetRow(int rowNumber) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDocument = GetXmlDocument();
    auto querySharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

    return Row::CreateRow(xmlDocument,
                          GetRowNode(GetSheetData(), rowNumber),
                          querySharedStrings);
}

CoreTools::SimpleCSV::Column CoreTools::SimpleCSV::Worksheet::GetColumn(int columnNumber) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDocument = GetXmlDocument();

    if (!GetFirstChildColumns())
    {
        xmlDocument->root().insert_child_before(TextParsing::g_Columns.data(), GetSheetData());
    }

    auto column = GetFirstChildColumns();

    auto columnNode = column.find_child([&](const auto& node) {
        return columnNumber <= GetAttributeMin(node);
    });

    const auto attributeMin = GetAttributeMin(columnNode);

    if (attributeMin < 0 || columnNumber < attributeMin)
    {
        if (columnNumber < attributeMin)
        {
            columnNode = column.insert_child_before(TextParsing::g_Column.data(), columnNode);
        }
        else
        {
            columnNode = column.append_child(TextParsing::g_Column.data());
        }

        columnNode.append_attribute(TextParsing::g_Min.data()) = columnNumber;
        columnNode.append_attribute(TextParsing::g_Max.data()) = columnNumber;
        columnNode.append_attribute(TextParsing::g_Width.data()) = 10;
        columnNode.append_attribute(TextParsing::g_CustomWidth.data()) = 1;
    }

    return Column{ xmlDocument, columnNode };
}

CoreTools::SimpleCSV::CellReference CoreTools::SimpleCSV::Worksheet::GetLastCell() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return { GetRowCount(), GetColumnCount() };
}

int CoreTools::SimpleCSV::Worksheet::GetColumnCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    vector<int> counts{};
    for (const auto& row : GetRows())
    {
        counts.emplace_back(row.GetCellCount());
    }

    auto iter = std::max_element(counts.cbegin(), counts.cend());
    if (iter != counts.cend())
    {
        return *iter;
    }
    else
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("Worksheet GetColumnCount 错误。"s));
    }
}

int CoreTools::SimpleCSV::Worksheet::GetRowCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument()->document_element().child(TextParsing::g_SheetData.data()).last_child().attribute(TextParsing::g_AttributeR.data()).as_int();
}

bool CoreTools::SimpleCSV::Worksheet::IsSelected() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return TabIsSelected(*GetXmlDocument());
}

void CoreTools::SimpleCSV::Worksheet::SetSelected(bool selected)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    SetTabSelected(*GetXmlDocument(), selected);
}

void CoreTools::SimpleCSV::Worksheet::SetColor(const Color& color)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    SetTabColor(*GetXmlDocument(), color);
}

CoreTools::SimpleCSV::Color CoreTools::SimpleCSV::Worksheet::GetColor() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetTabColor(*GetXmlDocument());
}

void CoreTools::SimpleCSV::Worksheet::SetTabColor(const XMLDocument& xmlDocument, const Color& color)
{
    const auto sheetPr = CreateTabColor(xmlDocument);

    auto colorNode = sheetPr.child(TextParsing::g_TabColor.data());
    for (const auto attr : colorNode.attributes())
    {
        colorNode.remove_attribute(attr);
    }

    colorNode.prepend_attribute(TextParsing::g_RGB.data()).set_value(color.GetHex().c_str());
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::Worksheet::CreateTabColor(const XMLDocument& xmlDocument)
{
    auto documentElement = xmlDocument.document_element();
    if (!documentElement.child(TextParsing::g_SheetPr.data()))
    {
        documentElement.prepend_child(TextParsing::g_SheetPr.data());
    }

    auto sheetPr = documentElement.child(TextParsing::g_SheetPr.data());
    if (!sheetPr.child(TextParsing::g_TabColor.data()))
    {
        sheetPr.prepend_child(TextParsing::g_TabColor.data());
    }

    return sheetPr;
}

CoreTools::SimpleCSV::Color CoreTools::SimpleCSV::Worksheet::GetTabColor(const XMLDocument& xmlDocument)
{
    const auto sheetPr = CreateTabColor(xmlDocument);

    const auto colorNode = sheetPr.child(TextParsing::g_TabColor.data());

    return Color{ colorNode.attribute(TextParsing::g_RGB.data()).value() };
}

void CoreTools::SimpleCSV::Worksheet::SetTabSelected(const XMLDocument& xmlDocument, bool selected)
{
    const auto value = (selected ? 1u : 0u);
    xmlDocument.first_child().child(TextParsing::g_SheetViews.data()).first_child().attribute(TextParsing::g_TabSelected.data()).set_value(value);
}

bool CoreTools::SimpleCSV::Worksheet::TabIsSelected(const XMLDocument& xmlDocument)
{
    return xmlDocument.first_child().child(TextParsing::g_SheetViews.data()).first_child().attribute(TextParsing::g_TabSelected.data()).as_bool();
}

void CoreTools::SimpleCSV::Worksheet::Init()
{
    auto xmlDocument = GetXmlDocument();
    auto dimensionNode = xmlDocument->document_element().child(TextParsing::g_Dimension.data());

    string dimensions{ dimensionNode.attribute(TextParsing::g_Ref.data()).value() };

    const auto position = dimensions.find(TextParsing::g_Colon);

    if (position == std::string::npos)
    {
        dimensionNode.set_value(TextParsing::g_DefaultCellAddress.data());
    }
    else
    {
        dimensionNode.set_value(dimensions.substr(position + 1).c_str());
    }

    auto colsNode = xmlDocument->first_child().child(TextParsing::g_Columns.data());
    if (colsNode.type() != pugi::node_null)
    {
        auto currentNode = colsNode.first_child();
        while (currentNode != nullptr)
        {
            const auto min = GetAttributeMin(currentNode);
            const auto max = GetAttributeMax(currentNode);
            if (min != max)
            {
                currentNode.attribute(TextParsing::g_Min.data()).set_value(max);
                for (auto i = min; i < max; ++i)
                {
                    auto newNode = colsNode.insert_child_before(TextParsing::g_Column.data(), currentNode);
                    auto attr = currentNode.first_attribute();
                    while (attr != nullptr)
                    {
                        newNode.append_attribute(attr.name()) = attr.value();
                        attr = attr.next_attribute();
                    }
                    newNode.attribute(TextParsing::g_Min.data()) = i;
                    newNode.attribute(TextParsing::g_Max.data()) = i;
                }
            }
            currentNode = currentNode.next_sibling();
        }
    }
}
