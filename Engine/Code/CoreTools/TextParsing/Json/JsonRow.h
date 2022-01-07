///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:39)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_ROW_H
#define CORE_TOOLS_TEXT_PARSING_JSON_ROW_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <deque>
#include <vector>

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(JsonRowImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE JsonRow final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(JsonRow);
        using String = System::String;
        using BoolContainer = std::deque<bool>;
        using IntContainer = std::vector<int>;
        using Int64Container = std::vector<int64_t>;
        using DoubleContainer = std::vector<double>;
        using StringContainer = std::vector<String>;
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    public:
        explicit JsonRow(const BasicTree& basicTree);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const;

        NODISCARD String GetString(const String& field) const;
        NODISCARD bool GetBool(const String& field) const;
        NODISCARD int GetInt(const String& field) const;
        NODISCARD int64_t GetInt64(const String& field) const;
        NODISCARD double GetDouble(const String& field) const;

        NODISCARD BoolContainer GetBoolArray(const String& field) const;
        NODISCARD IntContainer GetIntArray(const String& field) const;
        NODISCARD Int64Container GetInt64Array(const String& field) const;
        NODISCARD DoubleContainer GetDoubleArray(const String& field) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_ROW_H