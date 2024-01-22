/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:03)

#include "CoreTools/CoreToolsExport.h"

#include "Utilities.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::GetRowNode(XMLNode sheetDataNode, int rowNumber)
{
    XMLNode result{};
    if (!sheetDataNode.last_child() || sheetDataNode.last_child().attribute("r").as_int() < rowNumber)
    {
        result = sheetDataNode.append_child("row");

        result.append_attribute("r") = rowNumber;
    }
    else if (sheetDataNode.last_child().attribute("r").as_int() - rowNumber < rowNumber)
    {
        result = sheetDataNode.last_child();
        while (rowNumber < result.attribute("r").as_int())
        {
            result = result.previous_sibling();
        }
        if (result.attribute("r").as_int() < rowNumber)
        {
            result = sheetDataNode.insert_child_after("row", result);

            result.append_attribute("r") = rowNumber;
        }
    }
    else
    {
        result = sheetDataNode.first_child();
        while (result.attribute("r").as_int() < rowNumber)
        {
            result = result.next_sibling();
        }
        if (rowNumber < result.attribute("r").as_int())
        {
            result = sheetDataNode.insert_child_before("row", result);

            result.append_attribute("r") = rowNumber;
        }
    }

    return result;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::GetCellNode(XMLNode rowNode, int columnNumber)
{
    const CellReference cellRef{ rowNode.attribute("r").as_int(), columnNumber };

    if (rowNode.last_child().empty() || CellReference{ rowNode.last_child().attribute("r").value() }.GetColumn() < columnNumber)
    {
        rowNode.append_child("c").append_attribute("r").set_value(cellRef.GetAddress().c_str());
        const XMLNode cellNode = rowNode.last_child();

        return cellNode;
    }
    else if (CellReference{ rowNode.last_child().attribute("r").value() }.GetColumn() - columnNumber < columnNumber)
    {
        XMLNode cellNode = rowNode.last_child();
        while (CellReference{ cellNode.attribute("r").value() }.GetColumn() > columnNumber)
        {
            cellNode = cellNode.previous_sibling();
        }
        if (CellReference{ cellNode.attribute("r").value() }.GetColumn() < columnNumber)
        {
            cellNode = rowNode.insert_child_after("c", cellNode);
            cellNode.append_attribute("r").set_value(cellRef.GetAddress().c_str());
        }

        return cellNode;
    }
    else
    {
        XMLNode cellNode = rowNode.first_child();
        while (CellReference{ cellNode.attribute("r").value() }.GetColumn() < columnNumber)
        {
            cellNode = cellNode.next_sibling();
        }
        if (CellReference{ cellNode.attribute("r").value() }.GetColumn() > columnNumber)
        {
            cellNode = rowNode.insert_child_before("c", cellNode);
            cellNode.append_attribute("r").set_value(cellRef.GetAddress().c_str());
        }

        return cellNode;
    }
}

std::string CoreTools::SimpleCSV::GetLastChildAttributeR(const XMLNode& rowNode)
{
    return rowNode.last_child().attribute(TextParsing::gAttributeR.data()).value();
}

std::string CoreTools::SimpleCSV::GetAttributeR(const XMLNode& rowNode)
{
    return rowNode.attribute(TextParsing::gAttributeR.data()).value();
}

int CoreTools::SimpleCSV::GetAttributeMin(const XMLNode& columnNode)
{
    if (!columnNode)
        return -1;
    else
        return columnNode.attribute(TextParsing::gMin.data()).as_int();
}

int CORE_TOOLS_HIDDEN_DECLARE CoreTools::SimpleCSV::GetAttributeMax(const XMLNode& columnNode)
{
    if (!columnNode)
        return -1;
    else
        return columnNode.attribute(TextParsing::gMax.data()).as_int();
}

int CoreTools::SimpleCSV::GetColumnNumber(const XMLNode& rowNode)
{
    if (rowNode.last_child().empty())
        return 0;
    else
        return CellReference::GetColumn(GetLastChildAttributeR(rowNode));
}
