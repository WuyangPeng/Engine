///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 21:50)

#include "CoreTools/CoreToolsExport.h"

#include "JsonRowImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::deque;
using std::vector;
using namespace std::literals;

CoreTools::JsonRowImpl::JsonRowImpl(const BasicTree& basicTree)
    : basicTree{ basicTree }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonRowImpl)

int CoreTools::JsonRowImpl::GetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(basicTree.size());
}

System::String CoreTools::JsonRowImpl::GetString(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return basicTree.get(field, String{});
}

bool CoreTools::JsonRowImpl::GetBool(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return basicTree.get(field, false);
}

int CoreTools::JsonRowImpl::GetInt(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return basicTree.get(field, 0);
}

int64_t CoreTools::JsonRowImpl::GetInt64(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return basicTree.get(field, 0);
}

double CoreTools::JsonRowImpl::GetDouble(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return basicTree.get(field, 0.0);
}

CoreTools::JsonRowImpl::BoolContainer CoreTools::JsonRowImpl::GetBoolArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    BoolContainer result{};

    for (const auto& value : basicTree.get_child(field))
    {
        result.emplace_back(value.second.get_value(false));
    }

    return result;
}

CoreTools::JsonRowImpl::IntContainer CoreTools::JsonRowImpl::GetIntArray(const String& field) const
{
    IntContainer result{};

    for (const auto& value : basicTree.get_child(field))
    {
        result.emplace_back(value.second.get_value(0));
    }

    return result;
}

CoreTools::JsonRowImpl::Int64Container CoreTools::JsonRowImpl::GetInt64Array(const String& field) const
{
    Int64Container result{};

    for (const auto& value : basicTree.get_child(field))
    {
        result.emplace_back(value.second.get_value(0));
    }

    return result;
}

CoreTools::JsonRowImpl::DoubleContainer CoreTools::JsonRowImpl::GetDoubleArray(const String& field) const
{
    DoubleContainer result{};

    for (const auto& value : basicTree.get_child(field))
    {
        result.emplace_back(value.second.get_value(0.0));
    }

    return result;
}

CoreTools::JsonRowImpl::StringContainer CoreTools::JsonRowImpl::GetStringArray(const String& field) const
{
    StringContainer result{};

    for (const auto& value : basicTree.get_child(field))
    {
        result.emplace_back(value.second.get_value(SYSTEM_TEXT(""s)));
    }

    return result;
}
