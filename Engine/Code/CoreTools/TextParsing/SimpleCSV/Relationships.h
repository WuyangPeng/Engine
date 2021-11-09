///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/10/13 19:18)

#ifndef CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_H
#define CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_H

#include "CoreTools/CoreToolsDll.h"

#include "RelationshipItem.h"
#include "XmlFile.h"
#include "XmlParser.h"

#include <string>
#include <vector>

namespace CoreTools
{
    namespace SimpleCSV
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

            NODISCARD RelationshipItem GetRelationshipByID(const std::string& id) const;
            NODISCARD RelationshipItem GetRelationshipByTarget(const std::string& target) const;
            NODISCARD RelationshipItemContainer GetRelationships() const;
            void DeleteRelationship(const std::string& relID);
            void DeleteRelationship(const RelationshipItem& item);
            RelationshipItem AddRelationship(RelationshipType type, const std::string& target);
            NODISCARD bool IsTargetExists(const std::string& target) const;
            NODISCARD bool IsIDExists(const std::string& id) const;

        private:
            NODISCARD static int GetNewRelsID(XMLNode relationshipsNode);
        };
    }
}  

#endif  // CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_H
