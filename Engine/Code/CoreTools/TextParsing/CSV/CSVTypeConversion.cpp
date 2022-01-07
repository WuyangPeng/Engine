///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 20:01)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTypeConversion.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

#include <map>

using std::map;
using std::string;
using namespace std::literals;

string CoreTools::CSVTypeConversion::GetTypeDescribe(CSVFormatType csvFormatType)
{
    static const auto typeDescribe = GetFormatTypeConversionDescribe();

    const auto iter = typeDescribe.find(csvFormatType);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型描述。\n"s));
    }
}

CoreTools::CSVFormatType CoreTools::CSVTypeConversion::GetFormatType(const String& describe)
{
    static const auto typeDescribe = GetDescribeConversionFormatType();

    const auto iter = typeDescribe.find(describe);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。\n"s));
    }
}

CoreTools::CSVTypeConversion::FormatTypeConversionDescribe CoreTools::CSVTypeConversion::GetFormatTypeConversionDescribe()
{
    const FormatTypeConversionDescribe typeDescribe{ { CSVFormatType::Default, "@default"s },
                                                     { CSVFormatType::Ignore, "@ignore"s },
                                                     { CSVFormatType::Vector, "@vector"s },
                                                     { CSVFormatType::TreeMap, "@treeMap"s },
                                                     { CSVFormatType::HashMap, "@hashMap"s },
                                                     { CSVFormatType::Key, "@key"s },
                                                     { CSVFormatType::Enum, "@enum"s },
                                                     { CSVFormatType::Unique, "@unique"s } };

    return typeDescribe;
}

CoreTools::CSVTypeConversion::DescribeConversionFormatType CoreTools::CSVTypeConversion::GetDescribeConversionFormatType()
{
    const auto typeDescribe = GetFormatTypeConversionDescribe();

    DescribeConversionFormatType result{};

    for (const auto& value : typeDescribe)
    {
        result.emplace(StringConversion::MultiByteConversionStandard(value.second), value.first);
    }

    return result;
}

CoreTools::CSVTypeConversion::DataTypeDescribeContainer CoreTools::CSVTypeConversion::GetDataTypeDescribeContainer()
{
    const DataTypeDescribeContainer container{ { CSVDataType::String,
                                                 SYSTEM_TEXT("string"sv),
                                                 SYSTEM_TEXT("System::String"sv),
                                                 SYSTEM_TEXT("GetString"sv),
                                                 SYSTEM_TEXT("System::String"sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::Bool,
                                                 SYSTEM_TEXT("bool"sv),
                                                 SYSTEM_TEXT("bool"sv),
                                                 SYSTEM_TEXT("GetBool"sv),
                                                 SYSTEM_TEXT("bool"sv),
                                                 SYSTEM_TEXT("return false;\n"sv) },

                                               { CSVDataType::Char,
                                                 SYSTEM_TEXT("char"sv),
                                                 SYSTEM_TEXT("System::TChar"sv),
                                                 SYSTEM_TEXT("GetChar"sv),
                                                 SYSTEM_TEXT("System::TChar"sv),
                                                 SYSTEM_TEXT("return SYSTEM_TEXT('\\0');\n"sv) },

                                               { CSVDataType::Int,
                                                 SYSTEM_TEXT("int"sv),
                                                 SYSTEM_TEXT("int"sv),
                                                 SYSTEM_TEXT("GetInt"sv),
                                                 SYSTEM_TEXT("int"sv),
                                                 SYSTEM_TEXT("return 0;\n"sv) },

                                               { CSVDataType::Int64,
                                                 SYSTEM_TEXT("int64"sv),
                                                 SYSTEM_TEXT("int64_t"sv),
                                                 SYSTEM_TEXT("GetInt64"sv),
                                                 SYSTEM_TEXT("int64_t"sv),
                                                 SYSTEM_TEXT("return 0;\n"sv) },

                                               { CSVDataType::Double,
                                                 SYSTEM_TEXT("double"sv),
                                                 SYSTEM_TEXT("double"sv),
                                                 SYSTEM_TEXT("GetDouble"sv),
                                                 SYSTEM_TEXT("double"sv),
                                                 SYSTEM_TEXT("return 0.0;\n"sv) },

                                               { CSVDataType::Enum,
                                                 SYSTEM_TEXT("enum"sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::Bit,
                                                 SYSTEM_TEXT("bit"sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT("return 0.0;\n"sv) },

                                               { CSVDataType::Vector2,
                                                 SYSTEM_TEXT("vector2"sv),
                                                 SYSTEM_TEXT("CoreTools::Vector2"sv),
                                                 SYSTEM_TEXT("GetVector2"sv),
                                                 SYSTEM_TEXT("CoreTools::Vector2"sv),
                                                 SYSTEM_TEXT("return CoreTools::Vector2{};\n"sv) },

                                               { CSVDataType::Vector3,
                                                 SYSTEM_TEXT("vector3"sv),
                                                 SYSTEM_TEXT("CoreTools::Vector3"sv),
                                                 SYSTEM_TEXT("GetVector3"sv),
                                                 SYSTEM_TEXT("CoreTools::Vector3"sv),
                                                 SYSTEM_TEXT("return CoreTools::Vector3{};\n"sv) },

                                               { CSVDataType::Vector4,
                                                 SYSTEM_TEXT("vector4"sv),
                                                 SYSTEM_TEXT("CoreTools::Vector4"sv),
                                                 SYSTEM_TEXT("GetVector4"sv),
                                                 SYSTEM_TEXT("CoreTools::Vector4"sv),
                                                 SYSTEM_TEXT("return CoreTools::Vector4{};\n"sv) },

                                               { CSVDataType::IntVector2,
                                                 SYSTEM_TEXT("intVector2"sv),
                                                 SYSTEM_TEXT("CoreTools::IntVector2"sv),
                                                 SYSTEM_TEXT("GetIntVector2"sv),
                                                 SYSTEM_TEXT("CoreTools::IntVector2"sv),
                                                 SYSTEM_TEXT("return CoreTools::IntVector2{};\n"sv) },

                                               { CSVDataType::IntVector3,
                                                 SYSTEM_TEXT("intVector3"sv),
                                                 SYSTEM_TEXT("CoreTools::IntVector3"sv),
                                                 SYSTEM_TEXT("GetIntVector3"sv),
                                                 SYSTEM_TEXT("CoreTools::IntVector3"sv),
                                                 SYSTEM_TEXT("return CoreTools::IntVector3{};\n"sv) },

                                               { CSVDataType::IntVector4,
                                                 SYSTEM_TEXT("intVector4"sv),
                                                 SYSTEM_TEXT("CoreTools::IntVector4"sv),
                                                 SYSTEM_TEXT("GetIntVector4"sv),
                                                 SYSTEM_TEXT("CoreTools::IntVector4"sv),
                                                 SYSTEM_TEXT("return CoreTools::IntVector4{};\n"sv) },

                                               { CSVDataType::BoolArray,
                                                 SYSTEM_TEXT("bool[]"sv),
                                                 SYSTEM_TEXT("std::deque<bool>"sv),
                                                 SYSTEM_TEXT("GetBoolArray"sv),
                                                 SYSTEM_TEXT("bool"sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::CharArray,
                                                 SYSTEM_TEXT("char[]"sv),
                                                 SYSTEM_TEXT("std::vector<System::TChar>"sv),
                                                 SYSTEM_TEXT("GetCharArray"sv),
                                                 SYSTEM_TEXT("System::TChar"sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::IntArray,
                                                 SYSTEM_TEXT("int[]"sv),
                                                 SYSTEM_TEXT("std::vector<int>"sv),
                                                 SYSTEM_TEXT("GetIntArray"sv),
                                                 SYSTEM_TEXT("int"sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::Int64Array,
                                                 SYSTEM_TEXT("int64[]"sv),
                                                 SYSTEM_TEXT("std::vector<int64_t>"sv),
                                                 SYSTEM_TEXT("GetInt64Array"sv),
                                                 SYSTEM_TEXT("int64_t"sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::DoubleArray,
                                                 SYSTEM_TEXT("double[]"sv),
                                                 SYSTEM_TEXT("std::vector<double>"sv),
                                                 SYSTEM_TEXT("GetDoubleArray"sv),
                                                 SYSTEM_TEXT("double"sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::EnumArray,
                                                 SYSTEM_TEXT("enum[]"sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::BitArray,
                                                 SYSTEM_TEXT("bit[]"sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT(""sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::Vector2Array,
                                                 SYSTEM_TEXT("vector2[]"sv),
                                                 SYSTEM_TEXT("std::vector<CoreTools::Vector2>"sv),
                                                 SYSTEM_TEXT("GetVector2Array"sv),
                                                 SYSTEM_TEXT("CoreTools::Vector2"sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::Vector3Array,
                                                 SYSTEM_TEXT("vector3[]"sv),
                                                 SYSTEM_TEXT("std::vector<CoreTools::Vector3>"sv),
                                                 SYSTEM_TEXT("GetVector3Array"sv),
                                                 SYSTEM_TEXT("CoreTools::Vector3"sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::Vector4Array,
                                                 SYSTEM_TEXT("vector4[]"sv),
                                                 SYSTEM_TEXT("std::vector<CoreTools::Vector4>"sv),
                                                 SYSTEM_TEXT("GetVector4Array"sv),
                                                 SYSTEM_TEXT("CoreTools::Vector4"sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::IntVector2Array,
                                                 SYSTEM_TEXT("intVector2[]"sv),
                                                 SYSTEM_TEXT("std::vector<CoreTools::IntVector2>"sv),
                                                 SYSTEM_TEXT("GetIntVector2Array"sv),
                                                 SYSTEM_TEXT("CoreTools::IntVector2"sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::IntVector3Array,
                                                 SYSTEM_TEXT("intVector3[]"sv),
                                                 SYSTEM_TEXT("std::vector<CoreTools::IntVector3>"sv),
                                                 SYSTEM_TEXT("GetIntVector3Array"sv),
                                                 SYSTEM_TEXT("CoreTools::IntVector3"sv),
                                                 SYSTEM_TEXT(""sv) },

                                               { CSVDataType::IntVector4Array,
                                                 SYSTEM_TEXT("intVector4[]"sv),
                                                 SYSTEM_TEXT("std::vector<CoreTools::IntVector4>"sv),
                                                 SYSTEM_TEXT("GetIntVector4Array"sv),
                                                 SYSTEM_TEXT("CoreTools::IntVector4"sv),
                                                 SYSTEM_TEXT(""sv) } };

    return container;
}

CoreTools::CSVTypeConversion::DataTypeConversionDescribe CoreTools::CSVTypeConversion::GetDataTypeConversionDescribe()
{
    const auto container = GetDataTypeDescribeContainer();

    DataTypeConversionDescribe result{};

    for (const auto& value : container)
    {
        result.emplace(value.GetCsvDataType(), StringConversion::StandardConversionMultiByte(value.GetDescribe().data()));
    }

    return result;
}

string CoreTools::CSVTypeConversion::GetTypeDescribe(CSVDataType csvDataType)
{
    static const auto typeDescribe = GetDataTypeConversionDescribe();

    const auto iter = typeDescribe.find(csvDataType);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型描述。\n"s));
    }
}

CoreTools::CSVTypeConversion::DescribeConversionDataType CoreTools::CSVTypeConversion::GetDescribeConversionDataType()
{
    const auto container = GetDataTypeDescribeContainer();

    DescribeConversionDataType result{};

    for (const auto& value : container)
    {
        result.emplace(value.GetDescribe(), value.GetCsvDataType());
    }

    return result;
}

CoreTools::CSVDataType CoreTools::CSVTypeConversion::GetDataType(const String& describe)
{
    static const auto typeDescribe = GetDescribeConversionDataType();

    const auto iter = typeDescribe.find(describe);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        if (describe.find(SYSTEM_TEXT("enum[]"s)) != String::npos)
        {
            return CSVDataType::EnumArray;
        }
        else if (describe.find(SYSTEM_TEXT("enum"s)) != String::npos)
        {
            return CSVDataType::Enum;
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。\n"s));
        }
    }
}

CoreTools::CSVTypeConversion::DataTypeConversionActualType CoreTools::CSVTypeConversion::GetDataTypeConversionActualType()
{
    const auto container = GetDataTypeDescribeContainer();

    DataTypeConversionActualType result{};

    for (const auto& value : container)
    {
        const auto actualType = value.GetActualType();
        if (!actualType.empty())
        {
            result.emplace(value.GetCsvDataType(), value.GetActualType());
        }
    }

    return result;
}

System::String CoreTools::CSVTypeConversion::GetActualType(CSVDataType csvDataType)
{
    static const auto typeDescribe = GetDataTypeConversionActualType();

    const auto iter = typeDescribe.find(csvDataType);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。\n"s));
    }
}

CoreTools::CSVTypeConversion::DataTypeConversionFunctionName CoreTools::CSVTypeConversion::GetDataTypeConversionFunctionName()
{
    const auto container = GetDataTypeDescribeContainer();

    DataTypeConversionActualType result{};

    for (const auto& value : container)
    {
        const auto actualType = value.GetActualType();
        if (!actualType.empty())
        {
            result.emplace(value.GetCsvDataType(), value.GetFunctionName());
        }
    }

    return result;
}

System::String CoreTools::CSVTypeConversion::GetFunctionName(CSVDataType csvDataType)
{
    static const auto typeDescribe = GetDataTypeConversionFunctionName();

    const auto iter = typeDescribe.find(csvDataType);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。\n"s));
    }
}

System::String CoreTools::CSVTypeConversion::GetValueType(CSVDataType csvDataType)
{
    static const auto typeDescribe = GetDataTypeConversionValueType();

    const auto iter = typeDescribe.find(csvDataType);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。\n"s));
    }
}

CoreTools::CSVTypeConversion::DataTypeConversionValueType CoreTools::CSVTypeConversion::GetDataTypeConversionValueType()
{
    const auto container = GetDataTypeDescribeContainer();

    DataTypeConversionValueType result{};

    for (const auto& value : container)
    {
        const auto valueType = value.GetValueType();
        if (!valueType.empty())
        {
            result.emplace(value.GetCsvDataType(), valueType);
        }
    }

    return result;
}

CoreTools::CSVTypeConversion::DataTypeConversionBaseReturnDescribe CoreTools::CSVTypeConversion::GetDataTypeConversionBaseReturnDescribe()
{
    const auto container = GetDataTypeDescribeContainer();

    DataTypeConversionValueType result{};

    for (const auto& value : container)
    {
        const auto baseReturnDescribe = value.GetBaseReturnDescribe();
        if (!baseReturnDescribe.empty())
        {
            result.emplace(value.GetCsvDataType(), baseReturnDescribe);
        }
    }

    return result;
}

System::String CoreTools::CSVTypeConversion::GetBaseReturnDescribe(CSVDataType csvDataType)
{
    static const auto baseReturnDescribe = GetDataTypeConversionBaseReturnDescribe();

    const auto iter = baseReturnDescribe.find(csvDataType);

    if (iter != baseReturnDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。\n"s));
    }
}
