///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/08 09:56)

#ifndef CORE_TOOLS_TEXT_PARSING_CONTENT_ITEM_H
#define CORE_TOOLS_TEXT_PARSING_CONTENT_ITEM_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>
#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::ContentItemImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::ContentItemImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE ContentItem final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ContentItem);

    public:
        ContentItem(const ConstXMLDocumentSharedPtr& document, const XMLNode& node);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ContentType GetType() const;
        NODISCARD std::string GetPath() const;

        NODISCARD static ContentType GetTypeFromString(const std::string& typeString);
        NODISCARD static std::string GetStringFromType(ContentType type);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CONTENT_ITEM_H
