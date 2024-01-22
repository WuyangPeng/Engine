/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:00)

#include "CoreTools/CoreToolsExport.h"

#include "Document.h"
#include "Workbook.h"
#include "Worksheet.h"
#include "Flags/SheetFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandAddWorksheet.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandCloneSheet.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandDeleteSheet.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySharedStrings.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelsId.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelsTarget.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetType.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QueryXmlData.h"

#include <algorithm>
#include <iterator>
#include <vector>

using namespace std::literals;

CoreTools::SimpleCSV::Workbook::Workbook(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, Workbook)

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::Workbook::GetSheetsNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument()->document_element().child(TextParsing::gSheets.data());
}

CoreTools::SimpleCSV::Worksheet CoreTools::SimpleCSV::Workbook::GetSheet(const std::string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto attribute = GetSheetsNode().find_child_by_attribute(TextParsing::gName.data(), sheetName.c_str());

    if (attribute == nullptr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "表 \""s + sheetName + "\" 不存在。"s)
    }

    const auto xmlId = attribute.attribute(TextParsing::gRId.data()).value();

    const auto parentDocument = GetParentDocument();
    const auto xmlPath = parentDocument->ExecuteQuery(QuerySheetRelsTarget{ xmlId }).GetSheetTarget();
    return Worksheet{ parentDocument->ExecuteQuery(QueryXmlData{ TextParsing::gX1.data() + xmlPath }).GetXmlData() };
}

CoreTools::SimpleCSV::Worksheet CoreTools::SimpleCSV::Workbook::GetSheet(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (index < 1 || GetSheetCount() < index)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "工作表索引超出范围。"s)
    }

    const auto sheetsNode = GetSheetsNode();
    const XMLNodeContainer xmlNode{ sheetsNode.begin(), sheetsNode.end() };
    const auto previousIndex = index - 1;

    return GetSheet(xmlNode.at(previousIndex).attribute(TextParsing::gName.data()).as_string());
}

CoreTools::SimpleCSV::Worksheet CoreTools::SimpleCSV::Workbook::GetWorksheet(const std::string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetSheet(sheetName);
}

CoreTools::SimpleCSV::Worksheet CoreTools::SimpleCSV::Workbook::GetChartSheet(const std::string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetSheet(sheetName);
}

bool CoreTools::SimpleCSV::Workbook::HasSharedStrings() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings() != nullptr;
}

CoreTools::SimpleCSV::Workbook::SharedStringsSharedPtr CoreTools::SimpleCSV::Workbook::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetParentDocument()->ExecuteQuery(QuerySharedStrings::Create()).GetSharedStrings();
}

void CoreTools::SimpleCSV::Workbook::DeleteSheet(const std::string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto xmlDocument = GetXmlDocument();
    const auto parentDocument = GetParentDocument();
    auto node = GetSheetsNode();

    const auto sheetId = node.find_child_by_attribute(TextParsing::gName.data(), sheetName.c_str()).attribute(TextParsing::gRId.data()).value();

    const auto sheetType = parentDocument->ExecuteQuery(QuerySheetType{ GetRelationshipId() }).GetSheetType();

    const auto sheetsNode = node.children();

    const auto countFunction = [&](const auto& item) {
        return parentDocument->ExecuteQuery(QuerySheetType{ item.attribute(TextParsing::gRId.data()).value() }).GetSheetType() == ContentType::Worksheet;
    };

    if (const auto worksheetCount = std::ranges::count_if(sheetsNode, countFunction);
        worksheetCount == 1 && sheetType == ContentType::Worksheet)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "无效操作。工作簿中必须至少有一张工作表。"s)
    }

    parentDocument->ExecuteCommand(CommandDeleteSheet{ sheetId, sheetName });
    node.remove_child(node.find_child_by_attribute(TextParsing::gName.data(), sheetName.c_str()));
}

void CoreTools::SimpleCSV::Workbook::AddWorksheet(const std::string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (GetXmlDocument()->document_element().child(TextParsing::gSheets.data()).find_child_by_attribute(TextParsing::gName.data(), sheetName.c_str()))
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "工作表名字 \""s + sheetName + "\" 已经存在。"s)
    }

    const auto internalId = CreateInternalSheetId();

    GetParentDocument()->ExecuteCommand(CommandAddWorksheet{ sheetName, TextParsing::gWorksheets.data() + std::to_string(internalId) + TextParsing::gXML.data() });
    PrepareSheetMetadata(sheetName, internalId);
}

void CoreTools::SimpleCSV::Workbook::CloneSheet(const std::string& existingName, const std::string& newName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    GetParentDocument()->ExecuteCommand(CommandCloneSheet{ GetSheetId(existingName), newName });
}

int CoreTools::SimpleCSV::Workbook::CreateInternalSheetId()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto children = GetXmlDocument()->document_element().child(TextParsing::gSheets.data()).children();

    constexpr auto maxElement = [](const auto& lhs, const auto& rhs) {
        return lhs.attribute(TextParsing::gSheetId.data()).as_uint() < rhs.attribute(TextParsing::gSheetId.data()).as_uint();
    };

    if (const auto iter = std::ranges::max_element(children, maxElement);
        iter != children.end())
    {
        return iter->attribute(TextParsing::gSheetId.data()).as_int() + 1;
    }
    else
    {
        return 1;
    }
}

std::string CoreTools::SimpleCSV::Workbook::GetSheetId(const std::string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetXmlDocument()->document_element().child(TextParsing::gSheets.data()).find_child_by_attribute(TextParsing::gName.data(), sheetName.c_str()).attribute(TextParsing::gRId.data()).value();
}

std::string CoreTools::SimpleCSV::Workbook::GetSheetName(const std::string& sheetId) const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetXmlDocument()->document_element().child(TextParsing::gSheets.data()).find_child_by_attribute(TextParsing::gRId.data(), sheetId.c_str()).attribute(TextParsing::gName.data()).value();
}

std::string CoreTools::SimpleCSV::Workbook::GetSheetVisibility(const std::string& sheetId) const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetXmlDocument()->document_element().child(TextParsing::gSheets.data()).find_child_by_attribute(TextParsing::gRId.data(), sheetId.c_str()).attribute(TextParsing::gState.data()).value();
}

void CoreTools::SimpleCSV::Workbook::PrepareSheetMetadata(const std::string& sheetName, int internalId)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto node = GetSheetsNode().append_child(TextParsing::gSheet.data());

    const auto sheetPath = TextParsing::gWorksheets.data() + std::to_string(internalId) + TextParsing::gXML.data();
    node.append_attribute(TextParsing::gName.data()) = sheetName.c_str();
    node.append_attribute(TextParsing::gSheetId.data()) = std::to_string(internalId).c_str();
    node.append_attribute(TextParsing::gRId.data()) = GetParentDocument()->ExecuteQuery(QuerySheetRelsId{ sheetPath }).GetSheetId().c_str();
}

void CoreTools::SimpleCSV::Workbook::SetSheetName(const std::string& sheetRId, const std::string& newName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto sheetName = GetXmlDocument()->document_element().child(TextParsing::gSheets.data()).find_child_by_attribute(TextParsing::gRId.data(), sheetRId.c_str()).attribute(TextParsing::gName.data());

    UpdateSheetReferences(sheetName.value(), newName);
    sheetName.set_value(newName.c_str());
}

void CoreTools::SimpleCSV::Workbook::SetSheetVisibility(const std::string& sheetRId, const std::string& state)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto stateAttribute = GetXmlDocument()->document_element().child(TextParsing::gSheets.data()).find_child_by_attribute(TextParsing::gRId.data(), sheetRId.c_str()).attribute(TextParsing::gState.data());
    if (!stateAttribute)
    {
        stateAttribute = GetXmlDocument()->document_element().child(TextParsing::gSheets.data()).find_child_by_attribute(TextParsing::gRId.data(), sheetRId.c_str()).append_attribute(TextParsing::gState.data());
    }

    stateAttribute.set_value(state.c_str());
}

void CoreTools::SimpleCSV::Workbook::SetSheetIndex(const std::string& sheetName, int index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();

    const auto children = xmlDocument->document_element().child(TextParsing::gSheets.data()).children();

    const auto equation = [&](const auto& item) {
        return sheetName == item.attribute(TextParsing::gName.data()).value();
    };

    if (const auto iter = std::ranges::find_if(children, equation);
        index == std::distance(children.begin(), iter) + 1)
    {
        return;
    }

    auto node = GetSheetsNode();

    if (index <= 1)
    {
        node.prepend_move(node.find_child_by_attribute(TextParsing::gName.data(), sheetName.c_str()));
    }
    else if (GetSheetCount() <= index)
    {
        node.append_move(node.find_child_by_attribute(TextParsing::gName.data(), sheetName.c_str()));
    }
    else
    {
        const auto sheets = node.children();
        const XMLNodeContainer xmlNodeContainer{ sheets.begin(), sheets.end() };

        const auto previousIndex = index - 1;
        const auto existingSheet = xmlNodeContainer.at(previousIndex);
        if (GetIndexOfSheet(sheetName) < index)
        {
            node.insert_move_after(node.find_child_by_attribute(TextParsing::gName.data(), sheetName.c_str()), existingSheet);
        }
        else if (index < GetIndexOfSheet(sheetName))
        {
            node.insert_move_before(node.find_child_by_attribute(TextParsing::gName.data(), sheetName.c_str()), existingSheet);
        }
    }

    for (const auto& definedName : xmlDocument->document_element().child(TextParsing::gDefinedNames.data()).children())
    {
        definedName.attribute(TextParsing::gLocalSheetId.data()).set_value(GetIndexOfSheet(sheetName) - 1);
    }
}

int CoreTools::SimpleCSV::Workbook::GetIndexOfSheet(const std::string& sheetName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto index = 1;
    for (const auto& sheet : GetSheetsNode().children())
    {
        if (sheetName == sheet.attribute(TextParsing::gName.data()).value())
        {
            return index;
        }
        index++;
    }

    THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "工作表不存在。"s)
}

CoreTools::SimpleCSV::SheetType CoreTools::SimpleCSV::Workbook::GetTypeOfSheet(const std::string& sheetName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (!IsSheetExists(sheetName))
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "工作表 \""s + sheetName + "\" 不存在。"s)
    }

    if (IsWorksheetExists(sheetName))
        return SheetType::Worksheet;
    else
        return SheetType::ChartSheet;
}

CoreTools::SimpleCSV::SheetType CoreTools::SimpleCSV::Workbook::GetTypeOfSheet(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto sheets = GetSheetsNode();
    const XMLNodeContainer vec{ sheets.begin(), sheets.end() };

    const auto previousIndex = index - 1;
    const auto name = vec.at(previousIndex).attribute(TextParsing::gName.data()).as_string();
    return GetTypeOfSheet(name);
}

int CoreTools::SimpleCSV::Workbook::GetSheetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto children = GetSheetsNode().children();

    return boost::numeric_cast<int>(std::distance(children.begin(), children.end()));
}

int CoreTools::SimpleCSV::Workbook::GetWorksheetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(GetWorksheetNames().size());
}

int CoreTools::SimpleCSV::Workbook::GetChartSheetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(GetChartSheetNames().size());
}

CoreTools::SimpleCSV::Workbook::SheetNamesType CoreTools::SimpleCSV::Workbook::GetSheetNames() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    SheetNamesType results{};

    for (const auto& item : GetSheetsNode().children())
    {
        results.emplace_back(item.attribute(TextParsing::gName.data()).value());
    }

    return results;
}

CoreTools::SimpleCSV::Workbook::SheetNamesType CoreTools::SimpleCSV::Workbook::GetWorksheetNames() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    SheetNamesType results{};

    for (const auto& item : GetSheetsNode().children())
    {
        if (GetParentDocument()->ExecuteQuery(QuerySheetType{ item.attribute(TextParsing::gRId.data()).value() }).GetSheetType() == ContentType::Worksheet)
        {
            results.emplace_back(item.attribute(TextParsing::gName.data()).value());
        }
    }

    return results;
}

CoreTools::SimpleCSV::Workbook::SheetNamesType CoreTools::SimpleCSV::Workbook::GetChartSheetNames() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    SheetNamesType results;

    for (const auto& item : GetSheetsNode().children())
    {
        if (GetParentDocument()->ExecuteQuery(QuerySheetType{ item.attribute(TextParsing::gRId.data()).value() }).GetSheetType() == ContentType::ChartSheet)
        {
            results.emplace_back(item.attribute(TextParsing::gName.data()).value());
        }
    }

    return results;
}

bool CoreTools::SimpleCSV::Workbook::IsSheetExists(const std::string& sheetName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return IsChartSheetExists(sheetName) || IsWorksheetExists(sheetName);
}

bool CoreTools::SimpleCSV::Workbook::IsWorksheetExists(const std::string& sheetName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto wksNames = GetWorksheetNames();

    return std::ranges::find(wksNames, sheetName) != wksNames.end();
}

bool CoreTools::SimpleCSV::Workbook::IsChartSheetExists(const std::string& sheetName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto chsNames = GetChartSheetNames();

    return std::ranges::find(chsNames, sheetName) != chsNames.end();
}

void CoreTools::SimpleCSV::Workbook::UpdateSheetReferences(std::string oldName, std::string newName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (oldName.find(TextParsing::gSpace) != std::string::npos)
    {
        oldName = "\'" + oldName + "\'";
    }
    if (newName.find(TextParsing::gSpace) != std::string::npos)
    {
        newName = "\'" + newName + "\'";
    }

    oldName += '!';
    newName += '!';

    for (const auto& definedName : GetXmlDocument()->document_element().child(TextParsing::gDefinedNames.data()).children())
    {
        std::string formula{ definedName.text().get() };

        if (formula.find('[') == std::string::npos && formula.find(']') == std::string::npos)
        {
            while (formula.find(oldName) != std::string::npos)
            {
                formula.replace(formula.find(oldName), oldName.length(), newName);
            }
            definedName.text().set(formula.c_str());
        }
    }
}
