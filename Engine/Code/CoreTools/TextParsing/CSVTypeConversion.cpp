///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/16 20:24)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTypeConversion.h"
#include "Flags/CSVFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <map>

using std::map;
using std::string;
using namespace std::literals;

string CoreTools::CSVTypeConversion::GetTypeDescribe(CSVDataType csvDataType)
{
    static map<CSVDataType, string> typeDescribe{ { CSVDataType::String, "string"s },
                                                  { CSVDataType::Bool, "bool"s },
                                                  { CSVDataType::Char, "char"s },
                                                  { CSVDataType::Int, "int"s },
                                                  { CSVDataType::Int64, "int64"s },
                                                  { CSVDataType::Double, "double"s },
                                                  { CSVDataType::Enum, "enum"s },
                                                  { CSVDataType::Bit, "bit"s },
                                                  { CSVDataType::Vector2, "vector2"s },
                                                  { CSVDataType::Vector3, "vector3"s },
                                                  { CSVDataType::Vector4, "vector4"s },
                                                  { CSVDataType::IntVector2, "intVector2"s },
                                                  { CSVDataType::IntVector3, "intVector3"s },
                                                  { CSVDataType::IntVector4, "intVector4"s },

                                                  { CSVDataType::BoolArray, "bool[]"s },
                                                  { CSVDataType::CharArray, "char[]"s },
                                                  { CSVDataType::IntArray, "int[]"s },
                                                  { CSVDataType::Int64Array, "int64[]"s },
                                                  { CSVDataType::DoubleArray, "double[]"s },
                                                  { CSVDataType::EnumArray, "enum[]"s },
                                                  { CSVDataType::BitArray, "bit[]"s },
                                                  { CSVDataType::Vector2Array, "vector2[]"s },
                                                  { CSVDataType::Vector3Array, "vector3[]"s },
                                                  { CSVDataType::Vector4Array, "vector4[]"s },
                                                  { CSVDataType::IntVector2Array, "intVector2[]"s },
                                                  { CSVDataType::IntVector3Array, "intVector3[]"s },
                                                  { CSVDataType::IntVector4Array, "intVector4[]"s } };

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

string CoreTools::CSVTypeConversion::GetTypeDescribe(CSVFormatType csvFormatType)
{
    static map<CSVFormatType, string> typeDescribe{ { CSVFormatType::Default, "@default"s },
                                                    { CSVFormatType::Ignore, "@ignore"s },
                                                    { CSVFormatType::Vector, "@vector"s },
                                                    { CSVFormatType::TreeMap, "@treeMap"s },
                                                    { CSVFormatType::HashMap, "@hashMap"s },
                                                    { CSVFormatType::Key, "@key"s },
                                                    { CSVFormatType::Enum, "@enum"s },
                                                    { CSVFormatType::Unique, "@unique"s } };

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
    static map<String, CSVFormatType> typeDescribe{ { SYSTEM_TEXT("@default"s), CSVFormatType::Default },
                                                    { SYSTEM_TEXT("@ignore"s), CSVFormatType::Ignore },
                                                    { SYSTEM_TEXT("@vector"s), CSVFormatType::Vector },
                                                    { SYSTEM_TEXT("@treeMap"s), CSVFormatType::TreeMap },
                                                    { SYSTEM_TEXT("@hashMap"s), CSVFormatType::HashMap },
                                                    { SYSTEM_TEXT("@key"s), CSVFormatType::Key },
                                                    { SYSTEM_TEXT("@enum"s), CSVFormatType::Enum },
                                                    { SYSTEM_TEXT("@unique"s), CSVFormatType::Unique } };

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

CoreTools::CSVDataType CoreTools::CSVTypeConversion::GetDataType(const String& describe)
{
    static map<String, CSVDataType> typeDescribe{ { SYSTEM_TEXT("string"s), CSVDataType::String },
                                                  { SYSTEM_TEXT("bool"s), CSVDataType::Bool },
                                                  { SYSTEM_TEXT("char"s), CSVDataType::Char },
                                                  { SYSTEM_TEXT("int"s), CSVDataType::Int },
                                                  { SYSTEM_TEXT("int64"s), CSVDataType::Int64 },
                                                  { SYSTEM_TEXT("double"s), CSVDataType::Double },
                                                  { SYSTEM_TEXT("enum"s), CSVDataType::Enum },
                                                  { SYSTEM_TEXT("bit"s), CSVDataType::Bit },
                                                  { SYSTEM_TEXT("vector2"s), CSVDataType::Vector2 },
                                                  { SYSTEM_TEXT("vector3"s), CSVDataType::Vector3 },
                                                  { SYSTEM_TEXT("vector4"s), CSVDataType::Vector4 },
                                                  { SYSTEM_TEXT("intVector2"s), CSVDataType::IntVector2 },
                                                  { SYSTEM_TEXT("intVector3"s), CSVDataType::IntVector3 },
                                                  { SYSTEM_TEXT("intVector4"s), CSVDataType::IntVector4 },

                                                  { SYSTEM_TEXT("bool[]"s), CSVDataType::BoolArray },
                                                  { SYSTEM_TEXT("char[]"s), CSVDataType::CharArray },
                                                  { SYSTEM_TEXT("int[]"s), CSVDataType::IntArray },
                                                  { SYSTEM_TEXT("int64[]"s), CSVDataType::Int64Array },
                                                  { SYSTEM_TEXT("double[]"s), CSVDataType::DoubleArray },
                                                  { SYSTEM_TEXT("enum[]"s), CSVDataType::EnumArray },
                                                  { SYSTEM_TEXT("bit[]"s), CSVDataType::BitArray },
                                                  { SYSTEM_TEXT("vector2[]"s), CSVDataType::Vector2Array },
                                                  { SYSTEM_TEXT("vector3[]"s), CSVDataType::Vector3Array },
                                                  { SYSTEM_TEXT("vector4[]"s), CSVDataType::Vector4Array },
                                                  { SYSTEM_TEXT("intVector2[]"s), CSVDataType::IntVector2Array },
                                                  { SYSTEM_TEXT("intVector3[]"s), CSVDataType::IntVector3Array },
                                                  { SYSTEM_TEXT("intVector4[]"s), CSVDataType::IntVector4Array } };

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

System::String CoreTools::CSVTypeConversion::GetActualType(CSVDataType csvDataType)
{
    static map<CSVDataType, String> typeDescribe{ { CSVDataType::String, SYSTEM_TEXT("System::String"s) },
                                                  { CSVDataType::Bool, SYSTEM_TEXT("bool"s) },
                                                  { CSVDataType::Char, SYSTEM_TEXT("System::TChar"s) },
                                                  { CSVDataType::Int, SYSTEM_TEXT("int"s) },
                                                  { CSVDataType::Int64, SYSTEM_TEXT("int64_t"s) },
                                                  { CSVDataType::Double, SYSTEM_TEXT("double"s) },
                                                  { CSVDataType::Vector2, SYSTEM_TEXT("CoreTools::Vector2"s) },
                                                  { CSVDataType::Vector3, SYSTEM_TEXT("CoreTools::Vector3"s) },
                                                  { CSVDataType::Vector4, SYSTEM_TEXT("CoreTools::Vector4"s) },
                                                  { CSVDataType::IntVector2, SYSTEM_TEXT("CoreTools::IntVector2"s) },
                                                  { CSVDataType::IntVector3, SYSTEM_TEXT("CoreTools::IntVector3"s) },
                                                  { CSVDataType::IntVector4, SYSTEM_TEXT("CoreTools::IntVector4"s) },

                                                  { CSVDataType::BoolArray, SYSTEM_TEXT("std::deque<bool>"s) },
                                                  { CSVDataType::CharArray, SYSTEM_TEXT("std::vector<System::TChar>"s) },
                                                  { CSVDataType::IntArray, SYSTEM_TEXT("std::vector<int>"s) },
                                                  { CSVDataType::Int64Array, SYSTEM_TEXT("std::vector<int64_t>"s) },
                                                  { CSVDataType::DoubleArray, SYSTEM_TEXT("std::vector<double>"s) },
                                                  { CSVDataType::Vector2Array, SYSTEM_TEXT("std::vector<CoreTools::Vector2>"s) },
                                                  { CSVDataType::Vector3Array, SYSTEM_TEXT("std::vector<CoreTools::Vector3>"s) },
                                                  { CSVDataType::Vector4Array, SYSTEM_TEXT("std::vector<CoreTools::Vector4>"s) },
                                                  { CSVDataType::IntVector2Array, SYSTEM_TEXT("std::vector<CoreTools::IntVector2>"s) },
                                                  { CSVDataType::IntVector3Array, SYSTEM_TEXT("std::vector<CoreTools::IntVector3>"s) },
                                                  { CSVDataType::IntVector4Array, SYSTEM_TEXT("std::vector<CoreTools::IntVector4>"s) } };

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

System::String CoreTools::CSVTypeConversion::GetFunctionName(CSVDataType csvDataType)
{
    static map<CSVDataType, String> typeDescribe{ { CSVDataType::String, SYSTEM_TEXT("GetString"s) },
                                                  { CSVDataType::Bool, SYSTEM_TEXT("GetBool"s) },
                                                  { CSVDataType::Char, SYSTEM_TEXT("GetChar"s) },
                                                  { CSVDataType::Int, SYSTEM_TEXT("GetInt"s) },
                                                  { CSVDataType::Int64, SYSTEM_TEXT("GetInt64"s) },
                                                  { CSVDataType::Double, SYSTEM_TEXT("GetDouble"s) },
                                                  { CSVDataType::Vector2, SYSTEM_TEXT("GetVector2"s) },
                                                  { CSVDataType::Vector3, SYSTEM_TEXT("GetVector3"s) },
                                                  { CSVDataType::Vector4, SYSTEM_TEXT("GetVector4"s) },
                                                  { CSVDataType::IntVector2, SYSTEM_TEXT("GetIntVector2"s) },
                                                  { CSVDataType::IntVector3, SYSTEM_TEXT("GetIntVector3"s) },
                                                  { CSVDataType::IntVector4, SYSTEM_TEXT("GetIntVector4"s) },

                                                  { CSVDataType::BoolArray, SYSTEM_TEXT("GetBoolArray"s) },
                                                  { CSVDataType::CharArray, SYSTEM_TEXT("GetCharArray"s) },
                                                  { CSVDataType::IntArray, SYSTEM_TEXT("GetIntArray"s) },
                                                  { CSVDataType::Int64Array, SYSTEM_TEXT("GetInt64Array"s) },
                                                  { CSVDataType::DoubleArray, SYSTEM_TEXT("GetDoubleArray"s) },
                                                  { CSVDataType::Vector2Array, SYSTEM_TEXT("GetVector2Array"s) },
                                                  { CSVDataType::Vector3Array, SYSTEM_TEXT("GetVector3Array"s) },
                                                  { CSVDataType::Vector4Array, SYSTEM_TEXT("GetVector4Array"s) },
                                                  { CSVDataType::IntVector2Array, SYSTEM_TEXT("GetIntVector2Array"s) },
                                                  { CSVDataType::IntVector3Array, SYSTEM_TEXT("GetIntVector3Array"s) },
                                                  { CSVDataType::IntVector4Array, SYSTEM_TEXT("GetIntVector4Array"s) } };

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
