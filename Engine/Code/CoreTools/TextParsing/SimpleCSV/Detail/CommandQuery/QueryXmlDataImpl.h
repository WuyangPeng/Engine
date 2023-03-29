///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/06 15:54)

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
