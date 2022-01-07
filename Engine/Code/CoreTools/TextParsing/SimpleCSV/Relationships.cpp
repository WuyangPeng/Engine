///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:27)

#include "CoreTools/CoreToolsExport.h"

#include "RelationshipItem.h"

#include "Document.h"
#include "Relationships.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <algorithm>

using std::string;

CoreTools::SimpleCSV::Relationships::Relationships(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, Relationships)

CoreTools::SimpleCSV::RelationshipItem CoreTools::SimpleCSV::Relationships::GetRelationshipByID(const string& id) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDocument = GetXmlDocument();

    return RelationshipItem{ xmlDocument, xmlDocument->document_element().find_child_by_attribute(TextParsing::g_ID.data(), id.c_str()) };
}

CoreTools::SimpleCSV::RelationshipItem CoreTools::SimpleCSV::Relationships::GetRelationshipByTarget(const std::string& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDocument = GetXmlDocument();

    return RelationshipItem{ xmlDocument, xmlDocument->document_element().find_child_by_attribute(TextParsing::g_Target.data(), target.c_str()) };
}

CoreTools::SimpleCSV::Relationships::RelationshipItemContainer CoreTools::SimpleCSV::Relationships::GetRelationships() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDocument = GetXmlDocument();

    RelationshipItemContainer result{};
    for (const auto& item : xmlDocument->document_element().children())
    {
        result.emplace_back(xmlDocument, item);
    }

    return result;
}

void CoreTools::SimpleCSV::Relationships::DeleteRelationship(const string& relID)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto xmlDocument = GetXmlDocument();

    xmlDocument->document_element().remove_child(xmlDocument->document_element().find_child_by_attribute(TextParsing::g_ID.data(), relID.c_str()));
}

void CoreTools::SimpleCSV::Relationships::DeleteRelationship(const RelationshipItem& item)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    DeleteRelationship(item.GetID());
}

int CoreTools::SimpleCSV::Relationships::GetNewRelsID(XMLNode relationshipsNode)
{
    constexpr auto idBeginIndex = 3;

    const auto children = relationshipsNode.children();
    const auto iter = std::max_element(children.begin(),
                                       children.end(),
                                       [&](const auto& lhs, const auto& rhs) {
                                           return stoi(string{ lhs.attribute(TextParsing::g_ID.data()).value() }.substr(idBeginIndex)) < stoi(string{ rhs.attribute(TextParsing::g_ID.data()).value() }.substr(idBeginIndex));
                                       });
    if (iter != children.end())
    {
        return stoi(string{ iter->attribute(TextParsing::g_ID.data()).value() }.substr(idBeginIndex)) + 1;
    }
    else
    {
        return 1;
    }
}

CoreTools::SimpleCSV::RelationshipItem CoreTools::SimpleCSV::Relationships::AddRelationship(RelationshipType type, const string& target)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto xmlDocument = GetXmlDocument();

    auto typeString = RelationshipItem::GetStringFromType(type);

    auto id = "rId" + std::to_string(GetNewRelsID(xmlDocument->document_element()));

    auto node = xmlDocument->document_element().append_child("Relationship");
    node.append_attribute(TextParsing::g_ID.data()).set_value(id.c_str());
    node.append_attribute("Type").set_value(typeString.c_str());
    node.append_attribute(TextParsing::g_Target.data()).set_value(target.c_str());

    if (type == RelationshipType::ExternalLinkPath)
    {
        node.append_attribute("TargetMode").set_value("External");
    }

    return RelationshipItem{ xmlDocument, node };
}

bool CoreTools::SimpleCSV::Relationships::IsTargetExists(const string& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument()->document_element().find_child_by_attribute(TextParsing::g_Target.data(), target.c_str()) != nullptr;
}

bool CoreTools::SimpleCSV::Relationships::IsIDExists(const string& id) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument()->document_element().find_child_by_attribute(TextParsing::g_ID.data(), id.c_str()) != nullptr;
}
