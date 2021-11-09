///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/13 18:30)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTENT_ITEM_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CONTENT_ITEM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

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
            ConstXMLDocumentWeakPtr document;
            XMLNode contentNode;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTENT_ITEM_IMPL_H
