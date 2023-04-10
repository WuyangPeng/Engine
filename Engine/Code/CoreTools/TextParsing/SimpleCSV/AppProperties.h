///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:16)

#ifndef CORE_TOOLS_TEXT_PARSING_APP_PROPERTIES_H
#define CORE_TOOLS_TEXT_PARSING_APP_PROPERTIES_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlFile.h"

#include <string>

namespace CoreTools::SimpleCSV
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

#endif  // CORE_TOOLS_TEXT_PARSING_APP_PROPERTIES_H
