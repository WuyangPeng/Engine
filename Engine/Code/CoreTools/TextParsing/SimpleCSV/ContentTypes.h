///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 09:56)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTENT_TYPES_H
#define CORE_TOOLS_TEXT_PARSING_CONTENT_TYPES_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlFile.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <vector>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE ContentTypes final : public XmlFile
    {
    public:
        using ClassType = ContentTypes;
        using ParentType = XmlFile;
        using ContentItemContainer = std::vector<ContentItem>;

    public:
        ContentTypes() noexcept = delete;

        explicit ContentTypes(const XmlDataSharedPtr& xmlData);

        CLASS_INVARIANT_FINAL_DECLARE;

        void AddOverride(const std::string& path, ContentType type);
        void DeleteOverride(const std::string& path);
        void DeleteOverride(const ContentItem& item);

        NODISCARD ContentItem GetContentItem(const std::string& path) const;
        NODISCARD ContentItemContainer GetContentItems() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTENT_TYPES_H
