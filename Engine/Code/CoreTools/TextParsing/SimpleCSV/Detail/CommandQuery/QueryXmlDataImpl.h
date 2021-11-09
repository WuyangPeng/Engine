///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/09/29 23:00)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE QueryXmlDataImpl final
        {
        public:
            using ClassType = QueryXmlDataImpl;
            using XmlDataSharedPtr = std::shared_ptr<XmlData>;

        public:
            explicit QueryXmlDataImpl(const std::string& xmlPath);
            QueryXmlDataImpl(const std::string& xmlPath, const XmlDataSharedPtr& xmlData);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetXmlPath() const;
            NODISCARD XmlDataSharedPtr GetXmlData() const;
            void SetXmlData(const XmlDataSharedPtr& xmlData) noexcept;

        private:
            using XmlDataWeakPtr = std::weak_ptr<XmlData>;

        private:
            std::string xmlPath;
            XmlDataWeakPtr m_XmlData;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_IMPL_H
