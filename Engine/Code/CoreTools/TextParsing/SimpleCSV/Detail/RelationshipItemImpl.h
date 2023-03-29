///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/07 13:54)

#ifndef CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_ITEM_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_ITEM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <map>
#include <string>

namespace CoreTools::SimpleCSV
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
        NODISCARD std::string GetId() const;

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

#endif  // CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_ITEM_IMPL_H
