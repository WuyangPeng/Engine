///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:45)

#ifndef CORE_TOOLS_TEXT_PARSING_APP_PROPERTIES_H
#define CORE_TOOLS_TEXT_PARSING_APP_PROPERTIES_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlFile.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE AppProperties final : public XmlFile
        {
        public:
            using ClassType = AppProperties;
            using ParentType = XmlFile;

        public:
            explicit AppProperties(const XmlDataSharedPtr& xmlData);

            CLASS_INVARIANT_FINAL_DECLARE;

            void AppendSheetName(const std::string& sheetName);
            void DeleteSheetName(const std::string& title);
            void SetSheetName(const std::string& oldTitle, const std::string& newTitle);

            void SetProperty(const std::string& name, const std::string& value);
            NODISCARD std::string GetProperty(const std::string& name) const;
            void DeleteProperty(const std::string& name);

        private:
            NODISCARD static XMLNode GetSheetNames(const XMLNode& docNode);
            NODISCARD static XMLAttribute GetSheetCount(const XMLNode& docNode);
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_APP_PROPERTIES_H
