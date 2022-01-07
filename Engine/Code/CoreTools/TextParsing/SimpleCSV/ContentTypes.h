///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:50)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTENT_TYPES_H
#define CORE_TOOLS_TEXT_PARSING_CONTENT_TYPES_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlFile.h"
#include "XmlParser.h"
#include "Flags/ContentFlags.h"
#include "System/Helper/PragmaWarning/PugiXml.h"

#include <vector>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE ContentTypes : public XmlFile
        {
        public:
            using ClassType = ContentTypes;
            using ParentType = XmlFile;
            using ContentItemContainer = std::vector<ContentItem>;

        public:
            ContentTypes() noexcept = default;

            explicit ContentTypes(const XmlDataSharedPtr& xmlData);

            CLASS_INVARIANT_FINAL_DECLARE;

            void AddOverride(const std::string& path, ContentType type);
            void DeleteOverride(const std::string& path);
            void DeleteOverride(const ContentItem& item);

            NODISCARD ContentItem GetContentItem(const std::string& path) const;
            NODISCARD ContentItemContainer GetContentItems() const;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTENT_TYPES_H
