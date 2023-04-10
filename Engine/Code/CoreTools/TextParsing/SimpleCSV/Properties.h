///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:17)

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
