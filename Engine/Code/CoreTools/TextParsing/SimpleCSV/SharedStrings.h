/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:49)

#ifndef CORE_TOOLS_TEXT_PARSING_SHARED_STRINGS_H
#define CORE_TOOLS_TEXT_PARSING_SHARED_STRINGS_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlFile.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::SharedStringsImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::CopyUnsharedImpl<CoreTools::SimpleCSV::SharedStrings, CoreTools::SimpleCSV::SharedStringsImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE SharedStrings : public XmlFile
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(SharedStrings);
        using ParentType = XmlFile;

    public:
        explicit SharedStrings(const XmlDataSharedPtr& xmlData);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetStringIndex(const std::string& str) const;
        NODISCARD bool IsStringExists(const std::string& str) const;
        NODISCARD bool IsStringExists(int index) const;
        NODISCARD const std::string& GetString(int index) const;
        NODISCARD int AppendString(const std::string& str);

        void ClearString(int index);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SHARED_STRINGS_H
