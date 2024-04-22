/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:53)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE QueryXmlDataImpl final
    {
    public:
        using ClassType = QueryXmlDataImpl;

        using XmlDataSharedPtr = std::shared_ptr<XmlData>;

    public:
        explicit QueryXmlDataImpl(std::string xmlPath) noexcept;
        QueryXmlDataImpl(std::string xmlPath, const XmlDataSharedPtr& xmlData) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetXmlPath() const;
        NODISCARD XmlDataSharedPtr GetXmlData() const;
        void SetXmlData(const XmlDataSharedPtr& aXmlData) noexcept;

    private:
        using XmlDataWeakPtr = std::weak_ptr<XmlData>;

    private:
        std::string xmlPath;
        XmlDataWeakPtr xmlData;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_IMPL_H
