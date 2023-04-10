///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 15:07)

#include "CoreTools/CoreToolsExport.h"

#include "RelationshipItem.h"

#include "Document.h"
#include "Relationships.h"
#include "Flags/RelationshipFlags.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <algorithm>

CoreTools::SimpleCSV::Relationships::Relationships(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, Relationships)

CoreTools::SimpleCSV::RelationshipItem CoreTools::SimpleCSV::Relationships::GetRelationshipByID(const std::string& id) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto xmlDocument = GetXmlDocument();

    return RelationshipItem{ xmlDocument, xmlDocument->document_element().find_child_by_attribute(TextParsing::gId.data(), id.c_str()) };
}

CoreTools::SimpleCSV::RelationshipItem CoreTools::SimpleCSV::Relationships::GetRelationshipByTarget(const std::string& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto xmlDocument = GetXmlDocument();

    return RelationshipItem{ xmlDocument, xmlDocument->document_element().find_child_by_attribute(TextParsing::gTarget.data(), target.c_str()) };
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

void CoreTools::SimpleCSV::Relationships::DeleteRelationship(const std::string& relId)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();

    xmlDocument->document_element().remove_child(xmlDocument->document_element().find_child_by_attribute(TextParsing::gId.data(), relId.c_str()));
}

void CoreTools::SimpleCSV::Relationships::DeleteRelationship(const RelationshipItem& item)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    DeleteRelationship(item.GetId());
}

int CoreTools::SimpleCSV::Relationships::GetNewRelsId(XMLNode relationshipsNode)
{
    constexpr auto idBeginIndex = 3;

    const auto children = relationshipsNode.children();

    constexpr auto maxElement = [&](const auto& lhs, const auto& rhs) {
        return stoi(std::string{ lhs.attribute(TextParsing::gId.data()).value() }.substr(idBeginIndex)) < stoi(std::string{ rhs.attribute(TextParsing::gId.data()).value() }.substr(idBeginIndex));
    };

    if (const auto iter = std::ranges::max_element(children, maxElement);
        iter != children.end())
    {
        return std::stoi(std::string{ iter->attribute(TextParsing::gId.data()).value() }.substr(idBeginIndex)) + 1;
    }
    else
    {
        return 1;
    }
}

CoreTools::SimpleCSV::RelationshipItem CoreTools::SimpleCSV::Relationships::AddRelationship(RelationshipType type, const std::string& target)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();

    const auto typeString = RelationshipItem::GetStringFromType(type);

    const auto id = "rId" + std::to_string(GetNewRelsId(xmlDocument->document_element()));

    auto node = xmlDocument->document_element().append_child("Relationship");
    node.append_attribute(TextParsing::gId.data()).set_value(id.c_str());
    node.append_attribute("Type").set_value(typeString.c_str());
    node.append_attribute(TextParsing::gTarget.data()).set_value(target.c_str());

    if (type == RelationshipType::ExternalLinkPath)
    {
        node.append_attribute("TargetMode").set_value("External");
    }

    return RelationshipItem{ xmlDocument, node };
}

bool CoreTools::SimpleCSV::Relationships::IsTargetExists(const std::string& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument()->document_element().find_child_by_attribute(TextParsing::gTarget.data(), target.c_str()) != nullptr;
}

bool CoreTools::SimpleCSV::Relationships::IsIdExists(const std::string& id) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument()->document_element().find_child_by_attribute(TextParsing::gId.data(), id.c_str()) != nullptr;
}
