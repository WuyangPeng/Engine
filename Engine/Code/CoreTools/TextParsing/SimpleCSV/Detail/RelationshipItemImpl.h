///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:35)

#ifndef CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_ITEM_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_ITEM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataProxy.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <map>
#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE RelationshipItemImpl final
        {
        public:
            using ClassType = RelationshipItemImpl;

        public:
            RelationshipItemImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& node) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD RelationshipType GetType() const;
            NODISCARD std::string GetTarget() const;
            NODISCARD std::string GetID() const;

            NODISCARD static RelationshipType GetTypeFromString(const std::string& typeString);
            NODISCARD static std::string GetStringFromType(RelationshipType type);

        private:
            using TypeFromStringRelationship = std::map<std::string, RelationshipType>;
            using StringFromTypeRelationship = std::map<RelationshipType, std::string>;

        private:
            NODISCARD static TypeFromStringRelationship GetTypeFromStringRelationship();
            NODISCARD static StringFromTypeRelationship GetStringFromTypeRelationship();

        private:
            ConstXMLDocumentWeakPtr document;
            XMLNode relationshipNode;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_ITEM_IMPL_H
