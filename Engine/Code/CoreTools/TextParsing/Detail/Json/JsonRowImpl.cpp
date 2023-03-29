///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 14:13)

#include "CoreTools/CoreToolsExport.h"

#include "JsonRowImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Json/JsonRow.h"

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
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    IntContainer result{};

    for (const auto& value : basicTree.get_child(field))
    {
        result.emplace_back(value.second.get_value(0));
    }

    return result;
}

CoreTools::JsonRowImpl::Int64Container CoreTools::JsonRowImpl::GetInt64Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    Int64Container result{};

    for (const auto& value : basicTree.get_child(field))
    {
        result.emplace_back(value.second.get_value(0));
    }

    return result;
}

CoreTools::JsonRowImpl::DoubleContainer CoreTools::JsonRowImpl::GetDoubleArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    DoubleContainer result{};

    for (const auto& value : basicTree.get_child(field))
    {
        result.emplace_back(value.second.get_value(0.0));
    }

    return result;
}

CoreTools::JsonRow CoreTools::JsonRowImpl::GetJsonRow(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return JsonRow{ basicTree.get_child(field) };
}

CoreTools::JsonRowImpl::JsonRowContainer CoreTools::JsonRowImpl::GetJsonRowContainer(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    JsonRowContainer result{};

    for (const auto& value : basicTree.get_child(field))
    {
        result.emplace_back(value.second);
    }

    return result;
}

CoreTools::JsonRowImpl::StringContainer CoreTools::JsonRowImpl::GetStringArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    StringContainer result{};

    for (const auto& value : basicTree.get_child(field))
    {
        result.emplace_back(value.second.get_value(SYSTEM_TEXT(""s)));
    }

    return result;
}
