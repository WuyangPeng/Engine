///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:51)

#ifndef CORE_TOOLS_TEXT_PARSING_PROPERTIES_H
#define CORE_TOOLS_TEXT_PARSING_PROPERTIES_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlFile.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
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
}

#endif  // CORE_TOOLS_TEXT_PARSING_PROPERTIES_H
