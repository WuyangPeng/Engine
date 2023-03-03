///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:23)

#include "CoreTools/CoreToolsExport.h"

#include "CSVRowImplDetail.h"
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
#include "CoreTools/TextParsing/Detail/Parsing.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

using std::deque;
using std::vector;

CoreTools::CSVRowImpl::CSVRowImpl(const CSVHead& csvHead, const String& rowContent)
    : csvHead{ csvHead }, rowContent{ rowContent }, rowType{}
{
    RowParsing();

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::CSVRowImpl::RowParsing()
{
    if (rowContent.find(TextParsing::g_StringComma) != String::npos)
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
    auto column = Parsing::GetSplitComma(rowContent);

    auto index = 0;
    for (auto& value : column)
    {
        if (csvHead.GetDataType(index) == CSVDataType::String)
        {
            boost::algorithm::trim_if(value, boost::algorithm::is_any_of(TextParsing::g_QuotationMarks));
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

    for (auto location = rowContent.find(TextParsing::g_Comma); location != String::npos; location = rowContent.find(TextParsing::g_Comma, lastLocation))
    {
        lastCache += rowContent.substr(lastLocation, location - lastLocation);
        if (!lastCache.empty() && lastCache.back() == TextParsing::g_BackSlash)
        {
            lastCache += TextParsing::g_Comma;
        }
        else
        {
            if (csvHead.GetDataType(index) == CSVDataType::String)
            {
                boost::algorithm::trim_if(lastCache, boost::algorithm::is_any_of(TextParsing::g_QuotationMarks));
                boost::replace_all(lastCache, TextParsing::g_StringComma, TextParsing::g_Comma);
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
        return StringConversion::Utf8ConversionStandard(iter->second);
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

        if (result.empty() || result == TextParsing::g_False)
        {
            return false;
        }
        else if (result == TextParsing::g_True)
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
            return result.front();
        }
    }
    else
    {
        return SYSTEM_TEXT('\0');
    }
}

int CoreTools::CSVRowImpl::GetInt(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetValue<int>(field);
}

int64_t CoreTools::CSVRowImpl::GetInt64(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetValue<int64_t>(field);
}

double CoreTools::CSVRowImpl::GetDouble(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetValue<double>(field);
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

CoreTools::CSVRowImpl::VectorType CoreTools::CSVRowImpl::GetVectorType(const String& field) const
{
    VectorType vectorType{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (!result.empty())
        {
            boost::algorithm::split(vectorType, result, boost::is_any_of(TextParsing::g_Or), boost::token_compress_on);
        }
    }

    return vectorType;
}

CoreTools::Vector2 CoreTools::CSVRowImpl::GetVector2(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto column = GetVectorType(field);

    if (2 <= column.size())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return Vector2{ boost::lexical_cast<double>(column[0]),
                        boost::lexical_cast<double>(column[1]) };

#include STSTEM_WARNING_POP
    }

    return Vector2{};
}

CoreTools::Vector3 CoreTools::CSVRowImpl::GetVector3(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto column = GetVectorType(field);

    if (3 <= column.size())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return Vector3{ boost::lexical_cast<double>(column[0]),
                        boost::lexical_cast<double>(column[1]),
                        boost::lexical_cast<double>(column[2]) };

#include STSTEM_WARNING_POP
    }

    return Vector3{};
}

CoreTools::Vector4 CoreTools::CSVRowImpl::GetVector4(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto column = GetVectorType(field);

    if (4 <= column.size())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return Vector4{ boost::lexical_cast<double>(column[0]),
                        boost::lexical_cast<double>(column[1]),
                        boost::lexical_cast<double>(column[2]),
                        boost::lexical_cast<double>(column[3]) };

#include STSTEM_WARNING_POP
    }

    return Vector4{};
}

CoreTools::IntVector2 CoreTools::CSVRowImpl::GetIntVector2(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto column = GetVectorType(field);

    if (2 <= column.size())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return IntVector2{ boost::lexical_cast<int>(column[0]),
                           boost::lexical_cast<int>(column[1]) };

#include STSTEM_WARNING_POP
    }

    return IntVector2{};
}

CoreTools::IntVector3 CoreTools::CSVRowImpl::GetIntVector3(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto column = GetVectorType(field);

    if (3 <= column.size())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return IntVector3{ boost::lexical_cast<int>(column[0]),
                           boost::lexical_cast<int>(column[1]),
                           boost::lexical_cast<int>(column[2]) };

#include STSTEM_WARNING_POP
    }

    return IntVector3{};
}

CoreTools::IntVector4 CoreTools::CSVRowImpl::GetIntVector4(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto column = GetVectorType(field);

    if (4 <= column.size())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return IntVector4{ boost::lexical_cast<int>(column[0]),
                           boost::lexical_cast<int>(column[1]),
                           boost::lexical_cast<int>(column[2]),
                           boost::lexical_cast<int>(column[3]) };

#include STSTEM_WARNING_POP
    }

    return IntVector4{};
}

CoreTools::CSVRowImpl::ArrayType CoreTools::CSVRowImpl::GetArrayType(const String& field) const
{
    ArrayType arrayType{};

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;

        if (!result.empty())
        {
            boost::algorithm::split(arrayType, result, boost::is_any_of(TextParsing::g_And), boost::token_compress_on);
        }
    }

    return arrayType;
}

CoreTools::CSVRowImpl::BoolContainer CoreTools::CSVRowImpl::GetBoolArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    BoolContainer result{};

    const auto column = GetArrayType(field);

    for (const auto& value : column)
    {
        if (value.empty() || value == TextParsing::g_False)
        {
            result.emplace_back(false);
        }
        else if (value == TextParsing::g_True)
        {
            result.emplace_back(true);
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("bool 值不合法。\n"s));
        }
    }

    return result;
}

CoreTools::CSVRowImpl::CharContainer CoreTools::CSVRowImpl::GetCharArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    CharContainer result{};

    const auto column = GetArrayType(field);

    for (const auto& value : column)
    {
        if (value.empty())
        {
            result.emplace_back(SYSTEM_TEXT('\0'));
        }
        else
        {
            result.emplace_back(value.front());
        }
    }

    return result;
}

CoreTools::CSVRowImpl::IntContainer CoreTools::CSVRowImpl::GetIntArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetValueArray<int>(field);
}

CoreTools::CSVRowImpl::Int64Container CoreTools::CSVRowImpl::GetInt64Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetValueArray<int64_t>(field);
}

CoreTools::CSVRowImpl::DoubleContainer CoreTools::CSVRowImpl::GetDoubleArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetValueArray<double>(field);
}

CoreTools::CSVRowImpl::StringContainer CoreTools::CSVRowImpl::GetEnumStringArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetArrayType(field);
}

CoreTools::CSVRowImpl::VectorType CoreTools::CSVRowImpl::GetSplit(const String& column) const
{
    VectorType result{};

    boost::algorithm::split(result, column, boost::is_any_of(TextParsing::g_Or), boost::token_compress_on);

    return result;
}

CoreTools::CSVRowImpl::Vector2Container CoreTools::CSVRowImpl::GetVector2Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    Vector2Container result{};

    const auto column = GetArrayType(field);

    for (const auto& value : column)
    {
        const auto& single = GetSplit(value);

        result.emplace_back(boost::lexical_cast<double>(single.at(0)), boost::lexical_cast<double>(single.at(1)));
    }

    return result;
}

CoreTools::CSVRowImpl::Vector3Container CoreTools::CSVRowImpl::GetVector3Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    Vector3Container result{};

    const auto column = GetArrayType(field);

    for (const auto& value : column)
    {
        const auto& single = GetSplit(value);

        result.emplace_back(boost::lexical_cast<double>(single.at(0)), boost::lexical_cast<double>(single.at(1)), boost::lexical_cast<double>(single.at(2)));
    }

    return result;
}

CoreTools::CSVRowImpl::Vector4Container CoreTools::CSVRowImpl::GetVector4Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    Vector4Container result{};

    const auto column = GetArrayType(field);

    for (const auto& value : column)
    {
        const auto& single = GetSplit(value);

        result.emplace_back(boost::lexical_cast<double>(single.at(0)),
                            boost::lexical_cast<double>(single.at(1)),
                            boost::lexical_cast<double>(single.at(2)),
                            boost::lexical_cast<double>(single.at(3)));
    }

    return result;
}

CoreTools::CSVRowImpl::IntVector2Container CoreTools::CSVRowImpl::GetIntVector2Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    IntVector2Container result{};

    const auto column = GetArrayType(field);

    for (const auto& value : column)
    {
        const auto& single = GetSplit(value);

        result.emplace_back(boost::lexical_cast<int>(single.at(0)), boost::lexical_cast<int>(single.at(1)));
    }

    return result;
}

CoreTools::CSVRowImpl::IntVector3Container CoreTools::CSVRowImpl::GetIntVector3Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    IntVector3Container result{};

    const auto column = GetArrayType(field);

    for (const auto& value : column)
    {
        const auto& single = GetSplit(value);

        result.emplace_back(boost::lexical_cast<int>(single.at(0)), boost::lexical_cast<int>(single.at(1)), boost::lexical_cast<int>(single.at(2)));
    }

    return result;
}

CoreTools::CSVRowImpl::IntVector4Container CoreTools::CSVRowImpl::GetIntVector4Array(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    IntVector4Container result{};

    const auto column = GetArrayType(field);

    for (const auto& value : column)
    {
        const auto& single = GetSplit(value);

        result.emplace_back(boost::lexical_cast<int>(single.at(0)),
                            boost::lexical_cast<int>(single.at(1)),
                            boost::lexical_cast<int>(single.at(2)),
                            boost::lexical_cast<int>(single.at(3)));
    }

    return result;
}
