///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 14:58)

#ifndef CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_H
#define CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_H

#include "CoreTools/CoreToolsDll.h"

#include "RelationshipItem.h"
#include "XmlFile.h"
#include "XmlParser.h"

#include <string>
#include <vector>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE Relationships final : public XmlFile
    {
    public:
        using ClassType = Relationships;
        using ParentType = XmlFile;
        using RelationshipItemContainer = std::vector<RelationshipItem>;

    public:
        explicit Relationships(const XmlDataSharedPtr& xmlData);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD RelationshipItem GetRelationshipById(const std::string& id) const;
        NODISCARD RelationshipItem GetRelationshipByTarget(const std::string& target) const;
        NODISCARD RelationshipItemContainer GetRelationships() const;
        void DeleteRelationship(const std::string& relId);
        void DeleteRelationship(const RelationshipItem& item);
        RelationshipItem AddRelationship(RelationshipType type, const std::string& target);
        NODISCARD bool IsTargetExists(const std::string& target) const;
        NODISCARD bool IsIdExists(const std::string& id) const;

    private:
        NODISCARD static int GetNewRelsId(XMLNode relationshipsNode);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_H
