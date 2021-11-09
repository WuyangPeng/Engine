///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/18 10:55)

#include "CoreTools/CoreToolsExport.h"

#include "CSVRowImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Data/IntVector2.h"
#include "CoreTools/TextParsing/Data/IntVector3.h"
#include "CoreTools/TextParsing/Data/IntVector4.h"
#include "CoreTools/TextParsing/Data/Vector2.h"
#include "CoreTools/TextParsing/Data/Vector3.h"
#include "CoreTools/TextParsing/Data/Vector4.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

using namespace std::literals;
using std::deque;
using std::vector;

CoreTools::CSVRowImpl::CSVRowImpl(const CSVHead& csvHead, const String& rowContent)
    : csvHead{ csvHead }, rowContent{ rowContent }, rowType{}
{
    Parsing();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::CSVRowImpl::Parsing()
{
    if (rowContent.find(SYSTEM_TEXT("\\,"s)) != String::npos)
    {
        StringExistCommaParsing();
    }
    else
    {
        StringNotExistCommaParsing();
    }
}

void CoreTools::CSVRowImpl::StringNotExistCommaParsing()
{
    vector<String> column{};
    boost::algorithm::split(column, rowContent, boost::is_any_of(SYSTEM_TEXT(","s)), boost::token_compress_on);

    auto index = 0;
    for (auto& value : column)
    {
        if (csvHead.GetDataType(index) == CSVDataType::String)
        {
            boost::algorithm::trim_if(value, boost::algorithm::is_any_of(SYSTEM_TEXT("\""s)));
        }

        if (value.empty())
        {
            value = csvHead.GetDefaultValue(index);
        }

        rowType.emplace(csvHead.GetVariableName(index), value);
        ++index;
    }
}

void CoreTools::CSVRowImpl::StringExistCommaParsing()
{
    String lastCache{};
    size_t lastLocation{ 0u };
    auto index = 0;

    for (auto location = rowContent.find(SYSTEM_TEXT(","s)); location != String::npos; location = rowContent.find(SYSTEM_TEXT(","s), lastLocation))
    {
        lastCache += rowContent.substr(lastLocation, location - lastLocation);
        if (!lastCache.empty() && lastCache.back() == SYSTEM_TEXT('\\'))
        {
            lastCache += SYSTEM_TEXT(","s);
            lastLocation = location + 1;
            continue;
        }
        else
        {
            if (csvHead.GetDataType(index) == CSVDataType::String)
            {
                boost::algorithm::trim_if(lastCache, boost::algorithm::is_any_of(SYSTEM_TEXT("\""s)));
                boost::replace_all(lastCache, SYSTEM_TEXT("\\,"s), SYSTEM_TEXT(","s));
            }

            if (lastCache.empty())
            {
                lastCache = csvHead.GetDefaultValue(index);
            }

            rowType.emplace(csvHead.GetVariableName(index), lastCache);
            lastCache.clear();
            ++index;
        }

        lastLocation = location + 1;
    }

    auto remaining = rowContent.substr(lastLocation);
    if (remaining.empty())
    {
        rowType.emplace(csvHead.GetVariableName(index), csvHead.GetDefaultValue(index));
    }
    else
    {
        rowType.emplace(csvHead.GetVariableName(index), remaining);
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVRowImpl)

int CoreTools::CSVRowImpl::GetCount() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(rowType.size());
}

System::String CoreTools::CSVRowImpl::GetString(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        return StringConversion::UTF8ConversionStandard(iter->second);
    }
    else
    {
        return String{};
    }
}

bool CoreTools::CSVRowImpl::GetBool(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;

        if (result.empty() || result == SYSTEM_TEXT("false"s))
        {
            return false;
        }
        else if (result == SYSTEM_TEXT("true"s))
        {
            return true;
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("bool 值不合法。\n"s));
        }
    }
    else
    {
        return false;
    }
}

System::TChar CoreTools::CSVRowImpl::GetChar(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (result.empty())
        {
            return SYSTEM_TEXT('\0');
        }
        else
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            return result[0];

#include STSTEM_WARNING_POP
        }
    }
    else
    {
        return '\0';
    }
}

int CoreTools::CSVRowImpl::GetInt(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (!result.empty())
        {
            return boost::lexical_cast<int>(result);
        }
    }

    return 0;
}

int64_t CoreTools::CSVRowImpl::GetInt64(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (!result.empty())
        {
            return boost::lexical_cast<int64_t>(result);
        }
    }

    return 0;
}

double CoreTools::CSVRowImpl::GetDouble(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (!result.empty())
        {
            return boost::lexical_cast<double>(result);
        }
    }

    return 0;
}

System::String CoreTools::CSVRowImpl::GetEnumString(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        return iter->second;
    }
    else
    {
        return String{};
    }
}

CoreTools::Vector2 CoreTools::CSVRowImpl::GetVector2(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (!result.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, result, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

            return Vector2{ boost::lexical_cast<double>(column.at(0)), boost::lexical_cast<double>(column.at(1)) };
        }
    }

    return Vector2{};
}

CoreTools::Vector3 CoreTools::CSVRowImpl::GetVector3(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (!result.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, result, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

            return Vector3{ boost::lexical_cast<double>(column.at(0)), boost::lexical_cast<double>(column.at(1)), boost::lexical_cast<double>(column.at(2)) };
        }
    }

    return Vector3{};
}

CoreTools::Vector4 CoreTools::CSVRowImpl::GetVector4(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (!result.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, result, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

            return Vector4{ boost::lexical_cast<double>(column.at(0)),
                            boost::lexical_cast<double>(column.at(1)),
                            boost::lexical_cast<double>(column.at(2)),
                            boost::lexical_cast<double>(column.at(3)) };
        }
    }

    return Vector4{};
}

CoreTools::IntVector2 CoreTools::CSVRowImpl::GetIntVector2(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (!result.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, result, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

            return IntVector2{ boost::lexical_cast<int>(column.at(0)), boost::lexical_cast<int>(column.at(1)) };
        }
    }

    return IntVector2{};
}

CoreTools::IntVector3 CoreTools::CSVRowImpl::GetIntVector3(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (!result.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, result, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

            return IntVector3{ boost::lexical_cast<int>(column.at(0)), boost::lexical_cast<int>(column.at(1)), boost::lexical_cast<int>(column.at(2)) };
        }
    }

    return IntVector3{};
}

CoreTools::IntVector4 CoreTools::CSVRowImpl::GetIntVector4(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (!result.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, result, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

            return IntVector4{ boost::lexical_cast<int>(column.at(0)),
                               boost::lexical_cast<int>(column.at(1)),
                               boost::lexical_cast<int>(column.at(2)),
                               boost::lexical_cast<int>(column.at(3)) };
        }
    }

    return IntVector4{};
}

CoreTools::CSVRowImpl::BoolContainer CoreTools::CSVRowImpl::GetBoolArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    BoolContainer result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);

            for (const auto& value : column)
            {
                if (value.empty() || value == SYSTEM_TEXT("false"s))
                {
                    result.emplace_back(false);
                }
                else if (value == SYSTEM_TEXT("true"s))
                {
                    result.emplace_back(true);
                }
                else
                {
                    THROW_EXCEPTION(SYSTEM_TEXT("bool 值不合法。\n"s));
                }
            }
        }
    }

    return result;
}

CoreTools::CSVRowImpl::CharContainer CoreTools::CSVRowImpl::GetCharArray(const String& field) const
{
    CharContainer result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);

            for (const auto& value : column)
            {
                if (value.empty())
                {
                    result.emplace_back(SYSTEM_TEXT('\0'));
                }
                else
                {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

                    result.emplace_back(value[0]);

#include STSTEM_WARNING_POP
                }
            }
        }
    }

    return result;
}

CoreTools::CSVRowImpl::IntContainer CoreTools::CSVRowImpl::GetIntArray(const String& field) const
{
    IntContainer result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);

            for (const auto& value : column)
            {
                if (value.empty())
                {
                    result.emplace_back(0);
                }
                else
                {
                    result.emplace_back(boost::lexical_cast<int>(value));
                }
            }
        }
    }

    return result;
}

CoreTools::CSVRowImpl::Int64Container CoreTools::CSVRowImpl::GetInt64Array(const String& field) const
{
    Int64Container result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);

            for (const auto& value : column)
            {
                if (value.empty())
                {
                    result.emplace_back(0);
                }
                else
                {
                    result.emplace_back(boost::lexical_cast<int64_t>(value));
                }
            }
        }
    }

    return result;
}

CoreTools::CSVRowImpl::DoubleContainer CoreTools::CSVRowImpl::GetDoubleArray(const String& field) const
{
    DoubleContainer result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);

            for (const auto& value : column)
            {
                if (value.empty())
                {
                    result.emplace_back(0.0);
                }
                else
                {
                    result.emplace_back(boost::lexical_cast<double>(value));
                }
            }
        }
    }

    return result;
}

CoreTools::CSVRowImpl::StringContainer CoreTools::CSVRowImpl::GetEnumStringArray(const String& field) const
{
    StringContainer result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            boost::algorithm::split(result, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);
        }
    }

    return result;
}

CoreTools::CSVRowImpl::Vector2Container CoreTools::CSVRowImpl::GetVector2Array(const String& field) const
{
    Vector2Container result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);

            for (const auto& value : column)
            {
                vector<String> single{};
                boost::algorithm::split(single, value, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

                result.emplace_back(boost::lexical_cast<double>(single.at(0)), boost::lexical_cast<double>(single.at(1)));
            }
        }
    }

    return result;
}

CoreTools::CSVRowImpl::Vector3Container CoreTools::CSVRowImpl::GetVector3Array(const String& field) const
{
    Vector3Container result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);

            for (const auto& value : column)
            {
                vector<String> single{};
                boost::algorithm::split(single, value, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

                result.emplace_back(boost::lexical_cast<double>(single.at(0)), boost::lexical_cast<double>(single.at(1)), boost::lexical_cast<double>(single.at(2)));
            }
        }
    }

    return result;
}

CoreTools::CSVRowImpl::Vector4Container CoreTools::CSVRowImpl::GetVector4Array(const String& field) const
{
    Vector4Container result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);

            for (const auto& value : column)
            {
                vector<String> single{};
                boost::algorithm::split(single, value, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

                result.emplace_back(boost::lexical_cast<double>(single.at(0)),
                                    boost::lexical_cast<double>(single.at(1)),
                                    boost::lexical_cast<double>(single.at(2)),
                                    boost::lexical_cast<double>(single.at(3)));
            }
        }
    }

    return result;
}

CoreTools::CSVRowImpl::IntVector2Container CoreTools::CSVRowImpl::GetIntVector2Array(const String& field) const
{
    IntVector2Container result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);

            for (const auto& value : column)
            {
                vector<String> single{};
                boost::algorithm::split(single, value, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

                result.emplace_back(boost::lexical_cast<int>(single.at(0)), boost::lexical_cast<int>(single.at(1)));
            }
        }
    }

    return result;
}

CoreTools::CSVRowImpl::IntVector3Container CoreTools::CSVRowImpl::GetIntVector3Array(const String& field) const
{
    IntVector3Container result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);

            for (const auto& value : column)
            {
                vector<String> single{};
                boost::algorithm::split(single, value, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

                result.emplace_back(boost::lexical_cast<int>(single.at(0)), boost::lexical_cast<int>(single.at(1)), boost::lexical_cast<int>(single.at(2)));
            }
        }
    }

    return result;
}

CoreTools::CSVRowImpl::IntVector4Container CoreTools::CSVRowImpl::GetIntVector4Array(const String& field) const
{
    IntVector4Container result{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& columnResult = iter->second;

        if (!columnResult.empty())
        {
            vector<String> column{};
            boost::algorithm::split(column, columnResult, boost::is_any_of(SYSTEM_TEXT("&")), boost::token_compress_on);

            for (const auto& value : column)
            {
                vector<String> single{};
                boost::algorithm::split(single, value, boost::is_any_of(SYSTEM_TEXT("|")), boost::token_compress_on);

                result.emplace_back(boost::lexical_cast<int>(single.at(0)),
                                    boost::lexical_cast<int>(single.at(1)),
                                    boost::lexical_cast<int>(single.at(2)),
                                    boost::lexical_cast<int>(single.at(3)));
            }
        }
    }

    return result;
}
