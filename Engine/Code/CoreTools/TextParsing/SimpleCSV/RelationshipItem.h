/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:38)

#ifndef CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_ITEM_H
#define CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_ITEM_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>
#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::RelationshipItemImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::RelationshipItemImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE RelationshipItem final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(RelationshipItem);

    public:
        RelationshipItem(const ConstXMLDocumentSharedPtr& document, const XMLNode& node);

        CLASS_INVARIANT_DECLARE;

        NODISCARD RelationshipType GetType() const;
        NODISCARD std::string GetTarget() const;
        NODISCARD std::string GetId() const;

        NODISCARD static RelationshipType GetTypeFromString(const std::string& typeString);
        NODISCARD static std::string GetStringFromType(RelationshipType type);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_RELATIONSHIP_ITEM_H
