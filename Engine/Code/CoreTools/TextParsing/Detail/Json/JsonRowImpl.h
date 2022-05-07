///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 12:02)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_ROW_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_JSON_ROW_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <deque>
#include <map>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonRowImpl final
    {
    public:
        using ClassType = JsonRowImpl;
        using String = System::String;
        using BoolContainer = std::deque<bool>;
        using IntContainer = std::vector<int>;
        using Int64Container = std::vector<int64_t>;
        using DoubleContainer = std::vector<double>;
        using StringContainer = std::vector<String>;
        using BasicTree = boost::property_tree::basic_ptree<String, String>;

    public:
        explicit JsonRowImpl(const BasicTree& basicTree);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetCount() const;

        NODISCARD String GetString(const String& field) const;
        NODISCARD bool GetBool(const String& field) const;
        NODISCARD int GetInt(const String& field) const;
        NODISCARD int64_t GetInt64(const String& field) const;
        NODISCARD double GetDouble(const String& field) const;

        NODISCARD StringContainer GetStringArray(const String& field) const;
        NODISCARD BoolContainer GetBoolArray(const String& field) const;
        NODISCARD IntContainer GetIntArray(const String& field) const;
        NODISCARD Int64Container GetInt64Array(const String& field) const;
        NODISCARD DoubleContainer GetDoubleArray(const String& field) const;

    private:
        BasicTree basicTree;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_ROW_IMPL_H