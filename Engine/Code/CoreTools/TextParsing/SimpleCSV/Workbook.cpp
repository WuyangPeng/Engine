///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:29)

#include "CoreTools/CoreToolsExport.h"

#include "Document.h"
#include "Workbook.h"
#include "Worksheet.h"
#include "Flags/SheetFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandAddWorksheet.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandCloneSheet.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/CommandDeleteSheet.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySharedStrings.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelsID.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelsTarget.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetType.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QueryXmlData.h"

#include <algorithm>
#include <iterator>
#include <vector>

using std::string;
using std::vector;
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

    return GetXmlDocument()->document_element().child(TextParsing::g_Sheets.data());
}

CoreTools::SimpleCSV::Worksheet CoreTools::SimpleCSV::Workbook::GetSheet(const string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto attribute = GetSheetsNode().find_child_by_attribute(TextParsing::g_Name.data(), sheetName.c_str());

    if (attribute == nullptr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "表 \""s + sheetName + "\" 不存在。"s);
    }

    auto xmlID = attribute.attribute(TextParsing::g_RID.data()).value();

    auto parentDocument = GetParentDocument();
    auto xmlPath = parentDocument->ExecuteQuery(QuerySheetRelsTarget{ xmlID }).GetSheetTarget();
    return Worksheet{ parentDocument->ExecuteQuery(QueryXmlData{ TextParsing::g_X1.data() + xmlPath }).GetXmlData() };
}

CoreTools::SimpleCSV::Worksheet CoreTools::SimpleCSV::Workbook::GetSheet(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (index < 1 || GetSheetCount() < index)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "工作表索引超出范围。"s);
    }

    const auto sheetsNode = GetSheetsNode();
    vector<XMLNode> xmlNode{ sheetsNode.begin(), sheetsNode.end() };
    const auto previousIndex = index - 1;

    return GetSheet(xmlNode.at(previousIndex).attribute(TextParsing::g_Name.data()).as_string());
}

CoreTools::SimpleCSV::Worksheet CoreTools::SimpleCSV::Workbook::GetWorksheet(const string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetSheet(sheetName);
}

CoreTools::SimpleCSV::Worksheet CoreTools::SimpleCSV::Workbook::GetChartsheet(const string& sheetName)
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

void CoreTools::SimpleCSV::Workbook::DeleteSheet(const string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto xmlDocument = GetXmlDocument();
    auto parentDocument = GetParentDocument();
    auto node = GetSheetsNode();

    auto sheetID = node.find_child_by_attribute(TextParsing::g_Name.data(), sheetName.c_str()).attribute(TextParsing::g_RID.data()).value();

    auto sheetType = parentDocument->ExecuteQuery(QuerySheetType{ GetRelationshipID() }).GetSheetType();

    const auto sheetsNode = node.children();
    const auto worksheetCount = std::count_if(sheetsNode.begin(), sheetsNode.end(), [&](const auto& item) {
        return parentDocument->ExecuteQuery(QuerySheetType{ item.attribute(TextParsing::g_RID.data()).value() }).GetSheetType() == ContentType::Worksheet;
    });

    if (worksheetCount == 1 && sheetType == ContentType::Worksheet)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "无效操作。工作簿中必须至少有一张工作表。"s);
    }

    parentDocument->ExecuteCommand(CommandDeleteSheet{ sheetID, sheetName });
    node.remove_child(node.find_child_by_attribute(TextParsing::g_Name.data(), sheetName.c_str()));
}

void CoreTools::SimpleCSV::Workbook::AddWorksheet(const string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (GetXmlDocument()->document_element().child(TextParsing::g_Sheets.data()).find_child_by_attribute(TextParsing::g_Name.data(), sheetName.c_str()))
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "工作表名字 \""s + sheetName + "\" 已经存在。"s);
    }

    const auto internalID = CreateInternalSheetID();

    GetParentDocument()->ExecuteCommand(CommandAddWorksheet{ sheetName, TextParsing::g_Worksheets.data() + std::to_string(internalID) + TextParsing::g_XML.data() });
    PrepareSheetMetadata(sheetName, internalID);
}

void CoreTools::SimpleCSV::Workbook::CloneSheet(const string& existingName, const string& newName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    GetParentDocument()->ExecuteCommand(CommandCloneSheet{ GetSheetID(existingName), newName });
}

int CoreTools::SimpleCSV::Workbook::CreateInternalSheetID()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto children = GetXmlDocument()->document_element().child(TextParsing::g_Sheets.data()).children();
    const auto iter = std::max_element(children.begin(),
                                       children.end(),
                                       [](const auto& lhs, const auto& rhs) {
                                           return lhs.attribute(TextParsing::g_SheetID.data()).as_uint() < rhs.attribute(TextParsing::g_SheetID.data()).as_uint();
                                       });

    if (iter != children.end())
    {
        return iter->attribute(TextParsing::g_SheetID.data()).as_int() + 1;
    }
    else
    {
        return 1;
    }
}

string CoreTools::SimpleCSV::Workbook::GetSheetID(const string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetXmlDocument()->document_element().child(TextParsing::g_Sheets.data()).find_child_by_attribute(TextParsing::g_Name.data(), sheetName.c_str()).attribute(TextParsing::g_RID.data()).value();
}

string CoreTools::SimpleCSV::Workbook::GetSheetName(const string& sheetID) const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetXmlDocument()->document_element().child(TextParsing::g_Sheets.data()).find_child_by_attribute(TextParsing::g_RID.data(), sheetID.c_str()).attribute(TextParsing::g_Name.data()).value();
}

string CoreTools::SimpleCSV::Workbook::GetSheetVisibility(const string& sheetID) const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetXmlDocument()->document_element().child(TextParsing::g_Sheets.data()).find_child_by_attribute(TextParsing::g_RID.data(), sheetID.c_str()).attribute(TextParsing::g_State.data()).value();
}

void CoreTools::SimpleCSV::Workbook::PrepareSheetMetadata(const string& sheetName, int internalID)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto node = GetSheetsNode().append_child(TextParsing::g_Sheet.data());

    auto sheetPath = TextParsing::g_Worksheets.data() + std::to_string(internalID) + TextParsing::g_XML.data();
    node.append_attribute(TextParsing::g_Name.data()) = sheetName.c_str();
    node.append_attribute(TextParsing::g_SheetID.data()) = std::to_string(internalID).c_str();
    node.append_attribute(TextParsing::g_RID.data()) = GetParentDocument()->ExecuteQuery(QuerySheetRelsID{ sheetPath }).GetSheetID().c_str();
}

void CoreTools::SimpleCSV::Workbook::SetSheetName(const string& sheetRID, const string& newName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto sheetName = GetXmlDocument()->document_element().child(TextParsing::g_Sheets.data()).find_child_by_attribute(TextParsing::g_RID.data(), sheetRID.c_str()).attribute(TextParsing::g_Name.data());

    UpdateSheetReferences(sheetName.value(), newName);
    sheetName.set_value(newName.c_str());
}

void CoreTools::SimpleCSV::Workbook::SetSheetVisibility(const string& sheetRID, const string& state)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto stateAttribute = GetXmlDocument()->document_element().child(TextParsing::g_Sheets.data()).find_child_by_attribute(TextParsing::g_RID.data(), sheetRID.c_str()).attribute(TextParsing::g_State.data());
    if (!stateAttribute)
    {
        stateAttribute = GetXmlDocument()->document_element().child(TextParsing::g_Sheets.data()).find_child_by_attribute(TextParsing::g_RID.data(), sheetRID.c_str()).append_attribute(TextParsing::g_State.data());
    }

    stateAttribute.set_value(state.c_str());
}

void CoreTools::SimpleCSV::Workbook::SetSheetIndex(const string& sheetName, int index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto xmlDocument = GetXmlDocument();

    const auto children = xmlDocument->document_element().child(TextParsing::g_Sheets.data()).children();
    const auto iter = std::find_if(children.begin(),
                                   children.end(),
                                   [&](const auto& item) {
                                       return sheetName == item.attribute(TextParsing::g_Name.data()).value();
                                   });

    if (index == std::distance(children.begin(), iter) + 1)
    {
        return;
    }

    auto node = GetSheetsNode();

    if (index <= 1)
    {
        node.prepend_move(node.find_child_by_attribute(TextParsing::g_Name.data(), sheetName.c_str()));
    }
    else if (GetSheetCount() <= index)
    {
        node.append_move(node.find_child_by_attribute(TextParsing::g_Name.data(), sheetName.c_str()));
    }
    else
    {
        const auto sheets = node.children();
        vector<XMLNode> vec{ sheets.begin(), sheets.end() };

        const auto previousIndex = index - 1;
        auto existingSheet = vec.at(previousIndex);
        if (GetIndexOfSheet(sheetName) < index)
        {
            node.insert_move_after(node.find_child_by_attribute(TextParsing::g_Name.data(), sheetName.c_str()), existingSheet);
        }
        else if (index < GetIndexOfSheet(sheetName))
        {
            node.insert_move_before(node.find_child_by_attribute(TextParsing::g_Name.data(), sheetName.c_str()), existingSheet);
        }
    }

    for (const auto& definedName : xmlDocument->document_element().child(TextParsing::g_DefinedNames.data()).children())
    {
        definedName.attribute(TextParsing::g_LocalSheetID.data()).set_value(GetIndexOfSheet(sheetName) - 1);
    }
}

int CoreTools::SimpleCSV::Workbook::GetIndexOfSheet(const string& sheetName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto index = 1;
    for (const auto& sheet : GetSheetsNode().children())
    {
        if (sheetName == sheet.attribute(TextParsing::g_Name.data()).value())
        {
            return index;
        }
        index++;
    }

    THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "工作表不存在。"s);
}

CoreTools::SimpleCSV::SheetType CoreTools::SimpleCSV::Workbook::GetTypeOfSheet(const std::string& sheetName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (!IsSheetExists(sheetName))
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, "工作表 \""s + sheetName + "\" 不存在。"s);
    }

    if (IsWorksheetExists(sheetName))
        return SheetType::Worksheet;
    else
        return SheetType::Chartsheet;
}

CoreTools::SimpleCSV::SheetType CoreTools::SimpleCSV::Workbook::GetTypeOfSheet(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto sheets = GetSheetsNode();
    vector<XMLNode> vec{ sheets.begin(), sheets.end() };

    const auto previousIndex = index - 1;
    const auto name = vec.at(previousIndex).attribute(TextParsing::g_Name.data()).as_string();
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

int CoreTools::SimpleCSV::Workbook::GetChartsheetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(GetChartsheetNames().size());
}

CoreTools::SimpleCSV::Workbook::SheetNamesType CoreTools::SimpleCSV::Workbook::GetSheetNames() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    vector<string> results{};

    for (const auto& item : GetSheetsNode().children())
    {
        results.emplace_back(item.attribute(TextParsing::g_Name.data()).value());
    }

    return results;
}

CoreTools::SimpleCSV::Workbook::SheetNamesType CoreTools::SimpleCSV::Workbook::GetWorksheetNames() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    vector<string> results{};

    for (const auto& item : GetSheetsNode().children())
    {
        if (GetParentDocument()->ExecuteQuery(QuerySheetType{ item.attribute(TextParsing::g_RID.data()).value() }).GetSheetType() == ContentType::Worksheet)
        {
            results.emplace_back(item.attribute(TextParsing::g_Name.data()).value());
        }
    }

    return results;
}

CoreTools::SimpleCSV::Workbook::SheetNamesType CoreTools::SimpleCSV::Workbook::GetChartsheetNames() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    vector<string> results;

    for (const auto& item : GetSheetsNode().children())
    {
        if (GetParentDocument()->ExecuteQuery(QuerySheetType{ item.attribute(TextParsing::g_RID.data()).value() }).GetSheetType() == ContentType::Chartsheet)
        {
            results.emplace_back(item.attribute(TextParsing::g_Name.data()).value());
        }
    }

    return results;
}

bool CoreTools::SimpleCSV::Workbook::IsSheetExists(const std::string& sheetName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return IsChartsheetExists(sheetName) || IsWorksheetExists(sheetName);
}

bool CoreTools::SimpleCSV::Workbook::IsWorksheetExists(const std::string& sheetName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto wksNames = GetWorksheetNames();

    return std::find(wksNames.begin(), wksNames.end(), sheetName) != wksNames.end();
}

bool CoreTools::SimpleCSV::Workbook::IsChartsheetExists(const std::string& sheetName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto chsNames = GetChartsheetNames();

    return std::find(chsNames.begin(), chsNames.end(), sheetName) != chsNames.end();
}

void CoreTools::SimpleCSV::Workbook::UpdateSheetReferences(string oldName, string newName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (oldName.find(TextParsing::g_Space) != std::string::npos)
    {
        oldName = "\'" + oldName + "\'";
    }
    if (newName.find(TextParsing::g_Space) != std::string::npos)
    {
        newName = "\'" + newName + "\'";
    }

    oldName += '!';
    newName += '!';

    for (const auto& definedName : GetXmlDocument()->document_element().child(TextParsing::g_DefinedNames.data()).children())
    {
        string formula{ definedName.text().get() };

        if (formula.find('[') == string::npos && formula.find(']') == string::npos)
        {
            while (formula.find(oldName) != string::npos)
            {
                formula.replace(formula.find(oldName), oldName.length(), newName);
            }
            definedName.text().set(formula.c_str());
        }
    }
}
