///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/08 15:08)

#include "CoreTools/CoreToolsExport.h"

#include "Utilities.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"

using std::string;

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::GetRowNode(XMLNode sheetDataNode, int rowNumber)
{
    XMLNode result{};
    if (!sheetDataNode.last_child() || sheetDataNode.last_child().attribute("r").as_ullong() < rowNumber)
    {
        result = sheetDataNode.append_child("row");

        result.append_attribute("r") = rowNumber;
    }
    else if (sheetDataNode.last_child().attribute("r").as_ullong() - rowNumber < rowNumber)
    {
        result = sheetDataNode.last_child();
        while (rowNumber < result.attribute("r").as_ullong())
        {
            result = result.previous_sibling();
        }
        if (result.attribute("r").as_ullong() < rowNumber)
        {
            result = sheetDataNode.insert_child_after("row", result);

            result.append_attribute("r") = rowNumber;
        }
    }
    else
    {
        result = sheetDataNode.first_child();
        while (result.attribute("r").as_ullong() < rowNumber)
        {
            result = result.next_sibling();
        }
        if (rowNumber < result.attribute("r").as_ullong())
        {
            result = sheetDataNode.insert_child_before("row", result);

            result.append_attribute("r") = rowNumber;
        }
    }

    return result;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::GetCellNode(XMLNode rowNode, int columnNumber)
{
    XMLNode cellNode{};
    CellReference cellRef{ rowNode.attribute("r").as_int(), columnNumber };

    if (rowNode.last_child().empty() || CellReference{ rowNode.last_child().attribute("r").value() }.GetColumn() < columnNumber)
    {
        rowNode.append_child("c").append_attribute("r").set_value(cellRef.GetAddress().c_str());
        cellNode = rowNode.last_child();
    }
    else if (CellReference{ rowNode.last_child().attribute("r").value() }.GetColumn() - columnNumber < columnNumber)
    {
        cellNode = rowNode.last_child();
        while (CellReference{ cellNode.attribute("r").value() }.GetColumn() > columnNumber)
        {
            cellNode = cellNode.previous_sibling();
        }
        if (CellReference{ cellNode.attribute("r").value() }.GetColumn() < columnNumber)
        {
            cellNode = rowNode.insert_child_after("c", cellNode);
            cellNode.append_attribute("r").set_value(cellRef.GetAddress().c_str());
        }
    }
    else
    {
        cellNode = rowNode.first_child();
        while (CellReference{ cellNode.attribute("r").value() }.GetColumn() < columnNumber)
        {
            cellNode = cellNode.next_sibling();
        }
        if (CellReference{ cellNode.attribute("r").value() }.GetColumn() > columnNumber)
        {
            cellNode = rowNode.insert_child_before("c", cellNode);
            cellNode.append_attribute("r").set_value(cellRef.GetAddress().c_str());
        }
    }

    return cellNode;
}

string CoreTools::SimpleCSV::GetLastChildAttributeR(const XMLNode& rowNode)
{
    return rowNode.last_child().attribute(TextParsing::g_AttributeR.data()).value();
}

string CoreTools::SimpleCSV::GetAttributeR(const XMLNode& rowNode)
{
    return rowNode.attribute(TextParsing::g_AttributeR.data()).value();
}

int CoreTools::SimpleCSV::GetAttributeMin(const XMLNode& columnNode)
{
    if (!columnNode)
        return -1;
    else
        return columnNode.attribute(TextParsing::g_Min.data()).as_int();
}

int CORE_TOOLS_HIDDEN_DECLARE CoreTools::SimpleCSV::GetAttributeMax(const XMLNode& columnNode)
{
    if (!columnNode)
        return -1;
    else
        return columnNode.attribute(TextParsing::g_Max.data()).as_int();
}

int CoreTools::SimpleCSV::GetColumnNumber(const XMLNode& rowNode)
{
    if (rowNode.last_child().empty())
        return 0;
    else
        return CellReference::GetColumn(GetLastChildAttributeR(rowNode));
}
