/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:26)

#include "CoreTools/CoreToolsExport.h"

#include "AppProperties.h"
#include "SimpleCSVInternalFwd.h"
#include "Detail/Utilities.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::AppProperties::AppProperties(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, AppProperties)

void CoreTools::SimpleCSV::AppProperties::AppendSheetName(const std::string& sheetName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();
    const auto documentElement = xmlDocument->document_element();

    const auto theNode = GetSheetNames(documentElement).append_child("vt:lpstr");
    theNode.text().set(sheetName.c_str());
    auto sheetCount = GetSheetCount(documentElement);
    sheetCount.set_value(sheetCount.as_uint() + 1);
}

void CoreTools::SimpleCSV::AppProperties::DeleteSheetName(const std::string& title)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();

    for (const auto documentElement = xmlDocument->document_element();
         const auto& iter : GetSheetNames(documentElement).children())
    {
        if (iter.child_value() == title)
        {
            GetSheetNames(documentElement).remove_child(iter);
            auto sheetCount = GetSheetCount(documentElement);
            sheetCount.set_value(sheetCount.as_uint() - 1);
            return;
        }
    }
}

void CoreTools::SimpleCSV::AppProperties::SetSheetName(const std::string& oldTitle, const std::string& newTitle)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();

    for (const auto documentElement = xmlDocument->document_element();
         const auto& iter : GetSheetNames(documentElement).children())
    {
        if (iter.child_value() == oldTitle)
        {
            iter.text().set(newTitle.c_str());
            return;
        }
    }
}

void CoreTools::SimpleCSV::AppProperties::SetProperty(const std::string& name, const std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();

    auto property = xmlDocument->first_child().child(name.c_str());
    if (property == nullptr)
    {
        property = xmlDocument->first_child().append_child(name.c_str());
    }

    property.text().set(value.c_str());
}

std::string CoreTools::SimpleCSV::AppProperties::GetProperty(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto xmlDocument = GetXmlDocument();

    auto property = xmlDocument->first_child().child(name.c_str());
    if (property == nullptr)
    {
        property = xmlDocument->first_child().append_child(name.c_str());
    }

    return property.text().get();
}

void CoreTools::SimpleCSV::AppProperties::DeleteProperty(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();

    if (const auto property = xmlDocument->first_child().child(name.c_str());
        property != nullptr)
    {
        xmlDocument->first_child().remove_child(property);
    }
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::AppProperties::GetSheetNames(const XMLNode& docNode)
{
    return docNode.child("TitleOfParts").first_child();
}

CoreTools::SimpleCSV::XMLAttribute CoreTools::SimpleCSV::AppProperties::GetSheetCount(const XMLNode& docNode)
{
    return GetSheetNames(docNode).attribute("size");
}
