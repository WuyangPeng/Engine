/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:38)

#ifndef CORE_TOOLS_TEXT_PARSING_PROPERTIES_H
#define CORE_TOOLS_TEXT_PARSING_PROPERTIES_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlFile.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE Properties final : public XmlFile
    {
    public:
        using ClassType = Properties;
        using ParentType = XmlFile;

    public:
        explicit Properties(const XmlDataSharedPtr& xmlData);

        CLASS_INVARIANT_FINAL_DECLARE;

        void SetProperty(const std::string& name, const std::string& value);
        NODISCARD std::string GetProperty(const std::string& name) const;
        void DeleteProperty(const std::string& name);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_PROPERTIES_H
