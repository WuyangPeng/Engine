///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:35)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTENT_ITEM_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CONTENT_ITEM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <map>
#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE ContentItemImpl final
        {
        public:
            using ClassType = ContentItemImpl;

        public:
            explicit ContentItemImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& node) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD ContentType GetType() const;
            NODISCARD std::string GetPath() const;

            NODISCARD static ContentType GetTypeFromString(const std::string& typeString);
            NODISCARD static std::string GetStringFromType(ContentType type);

        private:
            using StringFromTypeContent = std::map<ContentType, std::string>;
            using TypeFromStringContent = std::map<std::string, ContentType>;

        private:
            NODISCARD static StringFromTypeContent GetStringFromTypeContent();
            NODISCARD static TypeFromStringContent GetTypeFromStringContent();

        private:
            ConstXMLDocumentWeakPtr document;
            XMLNode contentNode;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTENT_ITEM_IMPL_H