/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:02)

#include "CoreTools/CoreToolsExport.h"

#include "ContentItem.h"
#include "ContentTypes.h"
#include "SimpleCSVException.h"
#include "Flags/CSVExceptionFlags.h"
#include "System/Helper/PragmaWarning/PugiXml.h"

using namespace std::literals;

CoreTools::SimpleCSV::ContentTypes::ContentTypes(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, ContentTypes)

void CoreTools::SimpleCSV::ContentTypes::AddOverride(const std::string& path, ContentType type)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto typeString = ContentItem::GetStringFromType(type);

    auto node = GetXmlDocument()->first_child().append_child("Override");
    node.append_attribute("PartName").set_value(path.c_str());
    node.append_attribute("ContentType").set_value(typeString.c_str());
}

void CoreTools::SimpleCSV::ContentTypes::DeleteOverride(const std::string& path)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();

    xmlDocument->document_element().remove_child(xmlDocument->document_element().find_child_by_attribute("PartName", path.c_str()));
}

void CoreTools::SimpleCSV::ContentTypes::DeleteOverride(const ContentItem& item)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    DeleteOverride(item.GetPath());
}

CoreTools::SimpleCSV::ContentItem CoreTools::SimpleCSV::ContentTypes::GetContentItem(const std::string& path) const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();

    return ContentItem{ xmlDocument, xmlDocument->document_element().find_child_by_attribute("PartName", path.c_str()) };
}

CoreTools::SimpleCSV::ContentTypes::ContentItemContainer CoreTools::SimpleCSV::ContentTypes::GetContentItems() const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto xmlDocument = GetXmlDocument();

    ContentItemContainer result{};
    for (auto item : xmlDocument->document_element().children())
    {
        if (item.name() == "Override"s)
        {
            result.emplace_back(xmlDocument, item);
        }
    }

    return result;
}
