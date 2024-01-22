/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:00)

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

CoreTools::SimpleCSV::Worksheet::Worksheet(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    Init();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, Worksheet)

CoreTools::SimpleCSV::Worksheet::CellSharedPtr CoreTools::SimpleCSV::Worksheet::GetCell(const std::string& ref) const
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

    const auto xmlDocument = GetXmlDocument();
    const auto cellNode = GetCellNode(rowNumber, columnNumber);

    const auto sharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

    return Cell::CreateCell(xmlDocument, cellNode, sharedStrings);
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::Worksheet::GetCellNode(int rowNumber, int columnNumber) const
{
    const auto rowNode = GetRowNode(GetSheetData(), rowNumber);

    if (const auto rowNodeColumnNumber = GetColumnNumber(rowNode);
        rowNodeColumnNumber == 0 || rowNodeColumnNumber < columnNumber)
    {
        return GetCellNodeInColumnNumber(rowNumber, columnNumber, rowNode);
    }
    else if (rowNodeColumnNumber - columnNumber < columnNumber)
    {
        return GetCellNodeInTwoColumnNumber(rowNumber, columnNumber, rowNode);
    }
    else
    {
        return GetCellNodeGreaterTwoColumnNumber(rowNumber, columnNumber, rowNode);
    }
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::Worksheet::GetCellNodeInColumnNumber(int rowNumber, int columnNumber, XMLNode rowNode) const
{
    const CellReference cellRef{ rowNumber, columnNumber };

    auto cellNode = rowNode.append_child(TextParsing::gChildC.data());
    cellNode.append_attribute(TextParsing::gAttributeR.data()).set_value(cellRef.GetAddress().c_str());

    return rowNode.last_child();
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::Worksheet::GetCellNodeInTwoColumnNumber(int rowNumber, int columnNumber, XMLNode rowNode) const
{
    auto cellNode = rowNode.last_child();
    while (columnNumber < CellReference::GetColumn(GetAttributeR(cellNode)))
    {
        cellNode = cellNode.previous_sibling();
    }

    if (CellReference::GetColumn(GetAttributeR(cellNode)) < columnNumber)
    {
        const CellReference cellRef{ rowNumber, columnNumber };

        cellNode = rowNode.insert_child_after(TextParsing::gChildC.data(), cellNode);
        cellNode.append_attribute(TextParsing::gAttributeR.data()).set_value(cellRef.GetAddress().c_str());
    }

    return cellNode;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::Worksheet::GetCellNodeGreaterTwoColumnNumber(int rowNumber, int columnNumber, XMLNode rowNode) const
{
    auto cellNode = rowNode.first_child();
    while (CellReference::GetColumn(GetAttributeR(cellNode)) < columnNumber)
    {
        cellNode = cellNode.next_sibling();
    }

    if (columnNumber < CellReference::GetColumn(GetAttributeR(cellNode)))
    {
        const CellReference cellRef{ rowNumber, columnNumber };

        cellNode = rowNode.insert_child_before(TextParsing::gChildC.data(), cellNode);
        cellNode.append_attribute(TextParsing::gAttributeR.data()).set_value(cellRef.GetAddress().c_str());
    }

    return cellNode;
}

CoreTools::SimpleCSV::CellRange CoreTools::SimpleCSV::Worksheet::GetRange() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetRange(CellReference{ TextParsing::gDefaultCellAddress.data() }, GetLastCell());
}

CoreTools::SimpleCSV::CellRange CoreTools::SimpleCSV::Worksheet::GetRange(const CellReference& topLeft, const CellReference& bottomRight) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto xmlDocument = GetXmlDocument();

    const auto querySharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

    return CellRange{ xmlDocument,
                      xmlDocument->first_child().child(TextParsing::gSheetData.data()),
                      topLeft,
                      bottomRight,
                      querySharedStrings };
}

CoreTools::SimpleCSV::RowRange CoreTools::SimpleCSV::Worksheet::GetRows() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto xmlDocument = GetXmlDocument();

    const auto querySharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

    const auto sheetData = GetSheetData();

    return RowRange{ xmlDocument,
                     sheetData,
                     1,
                     (sheetData.last_child() ? sheetData.last_child().attribute(TextParsing::gAttributeR.data()).as_int() : 1),
                     querySharedStrings };
}

CoreTools::SimpleCSV::RowRange CoreTools::SimpleCSV::Worksheet::GetRows(int rowCount) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto xmlDocument = GetXmlDocument();

    const auto querySharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

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

    const auto xmlDocument = GetXmlDocument();

    const auto sheetData = GetSheetData();
    const auto querySharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

    return RowRange{ xmlDocument,
                     sheetData,
                     firstRow,
                     lastRow,
                     querySharedStrings };
}

CoreTools::SimpleCSV::Worksheet::RowSharedPtr CoreTools::SimpleCSV::Worksheet::GetRow(int rowNumber) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto xmlDocument = GetXmlDocument();
    const auto querySharedStrings = GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();

    return Row::CreateRow(xmlDocument,
                          GetRowNode(GetSheetData(), rowNumber),
                          querySharedStrings);
}

CoreTools::SimpleCSV::Column CoreTools::SimpleCSV::Worksheet::GetColumn(int columnNumber) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto xmlDocument = GetXmlDocument();

    if (!GetFirstChildColumns())
    {
        xmlDocument->root().insert_child_before(TextParsing::gColumns.data(), GetSheetData());
    }

    auto column = GetFirstChildColumns();

    auto columnNode = column.find_child([&](const auto& node) {
        return columnNumber <= GetAttributeMin(node);
    });

    if (const auto attributeMin = GetAttributeMin(columnNode); attributeMin < 0 || columnNumber < attributeMin)
    {
        if (columnNumber < attributeMin)
        {
            columnNode = column.insert_child_before(TextParsing::gColumn.data(), columnNode);
        }
        else
        {
            columnNode = column.append_child(TextParsing::gColumn.data());
        }

        columnNode.append_attribute(TextParsing::gMin.data()) = columnNumber;
        columnNode.append_attribute(TextParsing::gMax.data()) = columnNumber;
        columnNode.append_attribute(TextParsing::gWidth.data()) = 10;
        columnNode.append_attribute(TextParsing::gCustomWidth.data()) = 1;
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

    using CountType = std::vector<int>;

    CountType counts{};
    for (const auto& row : GetRows())
    {
        counts.emplace_back(row.GetCellCount());
    }

    if (const auto iter = std::ranges::max_element(counts); iter != counts.cend())
    {
        return *iter;
    }
    else
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("Worksheet GetColumnCount 错误。"s))
    }
}

int CoreTools::SimpleCSV::Worksheet::GetRowCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument()->document_element().child(TextParsing::gSheetData.data()).last_child().attribute(TextParsing::gAttributeR.data()).as_int();
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

    auto colorNode = sheetPr.child(TextParsing::gTabColor.data());
    for (const auto attr : colorNode.attributes())
    {
        colorNode.remove_attribute(attr);
    }

    colorNode.prepend_attribute(TextParsing::gRgb.data()).set_value(color.GetHex().c_str());
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::Worksheet::CreateTabColor(const XMLDocument& xmlDocument)
{
    auto documentElement = xmlDocument.document_element();
    if (!documentElement.child(TextParsing::gSheetPr.data()))
    {
        documentElement.prepend_child(TextParsing::gSheetPr.data());
    }

    auto sheetPr = documentElement.child(TextParsing::gSheetPr.data());
    if (!sheetPr.child(TextParsing::gTabColor.data()))
    {
        sheetPr.prepend_child(TextParsing::gTabColor.data());
    }

    return sheetPr;
}

CoreTools::SimpleCSV::Color CoreTools::SimpleCSV::Worksheet::GetTabColor(const XMLDocument& xmlDocument)
{
    const auto sheetPr = CreateTabColor(xmlDocument);

    const auto colorNode = sheetPr.child(TextParsing::gTabColor.data());

    return Color{ colorNode.attribute(TextParsing::gRgb.data()).value() };
}

void CoreTools::SimpleCSV::Worksheet::SetTabSelected(const XMLDocument& xmlDocument, bool selected)
{
    const auto value = (selected ? 1u : 0u);
    xmlDocument.first_child().child(TextParsing::gSheetViews.data()).first_child().attribute(TextParsing::gTabSelected.data()).set_value(value);
}

bool CoreTools::SimpleCSV::Worksheet::TabIsSelected(const XMLDocument& xmlDocument)
{
    return xmlDocument.first_child().child(TextParsing::gSheetViews.data()).first_child().attribute(TextParsing::gTabSelected.data()).as_bool();
}

void CoreTools::SimpleCSV::Worksheet::Init()
{
    const auto xmlDocument = GetXmlDocument();
    auto dimensionNode = xmlDocument->document_element().child(TextParsing::gDimension.data());

    const std::string dimensions{ dimensionNode.attribute(TextParsing::gRef.data()).value() };

    if (const auto position = dimensions.find(TextParsing::gColon); position == std::string::npos)
    {
        dimensionNode.set_value(TextParsing::gDefaultCellAddress.data());
    }
    else
    {
        dimensionNode.set_value(dimensions.substr(position + 1).c_str());
    }

    if (const auto colsNode = xmlDocument->first_child().child(TextParsing::gColumns.data());
        colsNode.type() != pugi::node_null)
    {
        Init(colsNode);
    }
}

void CoreTools::SimpleCSV::Worksheet::Init(XMLNode colsNode)
{
    auto currentNode = colsNode.first_child();
    while (currentNode != nullptr)
    {
        const auto min = GetAttributeMin(currentNode);
        const auto max = GetAttributeMax(currentNode);
        if (min != max)
        {
            currentNode.attribute(TextParsing::gMin.data()).set_value(max);
            for (auto i = min; i < max; ++i)
            {
                auto newNode = colsNode.insert_child_before(TextParsing::gColumn.data(), currentNode);
                auto attr = currentNode.first_attribute();
                while (attr != nullptr)
                {
                    newNode.append_attribute(attr.name()) = attr.value();
                    attr = attr.next_attribute();
                }
                newNode.attribute(TextParsing::gMin.data()) = i;
                newNode.attribute(TextParsing::gMax.data()) = i;
            }
        }
        currentNode = currentNode.next_sibling();
    }
}