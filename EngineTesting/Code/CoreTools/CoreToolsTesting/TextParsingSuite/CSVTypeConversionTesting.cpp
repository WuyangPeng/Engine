///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/15 17:03)

#include "CSVTypeConversionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::CSVTypeConversionTesting::CSVTypeConversionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVTypeConversionTesting)

void CoreTools::CSVTypeConversionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CSVTypeConversionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CSVDataTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVFormatTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ActualTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetFunctionNameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BaseReturnDescribeTest);
}

void CoreTools::CSVTypeConversionTesting::CSVDataTypeTest()
{
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::String), "string"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Bool), "bool"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Char), "char"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Int), "int"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Int64), "int64"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Double), "double"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Enum), "enum"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Bit), "bit"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Vector2), "vector2"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Vector3), "vector3"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Vector4), "vector4"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::IntVector2), "intVector2"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::IntVector3), "intVector3"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::IntVector4), "intVector4"s);

    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::BoolArray), "bool[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::CharArray), "char[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::IntArray), "int[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Int64Array), "int64[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::DoubleArray), "double[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::EnumArray), "enum[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::BitArray), "bit[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Vector2Array), "vector2[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Vector3Array), "vector3[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::Vector4Array), "vector4[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::IntVector2Array), "intVector2[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::IntVector3Array), "intVector3[]"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVDataType::IntVector4Array), "intVector4[]"s);

    ASSERT_ENUM_EQUAL(CSVDataType::String, CSVTypeConversion::GetDataType(SYSTEM_TEXT("string"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Bool, CSVTypeConversion::GetDataType(SYSTEM_TEXT("bool"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Char, CSVTypeConversion::GetDataType(SYSTEM_TEXT("char"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Int, CSVTypeConversion::GetDataType(SYSTEM_TEXT("int"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Int64, CSVTypeConversion::GetDataType(SYSTEM_TEXT("int64"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Double, CSVTypeConversion::GetDataType(SYSTEM_TEXT("double"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Enum, CSVTypeConversion::GetDataType(SYSTEM_TEXT("enum"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Enum, CSVTypeConversion::GetDataType(SYSTEM_TEXT("enum|CSVType"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Bit, CSVTypeConversion::GetDataType(SYSTEM_TEXT("bit"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Vector2, CSVTypeConversion::GetDataType(SYSTEM_TEXT("vector2"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Vector3, CSVTypeConversion::GetDataType(SYSTEM_TEXT("vector3"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Vector4, CSVTypeConversion::GetDataType(SYSTEM_TEXT("vector4"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::IntVector2, CSVTypeConversion::GetDataType(SYSTEM_TEXT("intVector2"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::IntVector3, CSVTypeConversion::GetDataType(SYSTEM_TEXT("intVector3"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::IntVector4, CSVTypeConversion::GetDataType(SYSTEM_TEXT("intVector4"s)));

    ASSERT_ENUM_EQUAL(CSVDataType::BoolArray, CSVTypeConversion::GetDataType(SYSTEM_TEXT("bool[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::CharArray, CSVTypeConversion::GetDataType(SYSTEM_TEXT("char[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::IntArray, CSVTypeConversion::GetDataType(SYSTEM_TEXT("int[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Int64Array, CSVTypeConversion::GetDataType(SYSTEM_TEXT("int64[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::DoubleArray, CSVTypeConversion::GetDataType(SYSTEM_TEXT("double[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::EnumArray, CSVTypeConversion::GetDataType(SYSTEM_TEXT("enum[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::EnumArray, CSVTypeConversion::GetDataType(SYSTEM_TEXT("enum[]|CSVType"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::BitArray, CSVTypeConversion::GetDataType(SYSTEM_TEXT("bit[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Vector2Array, CSVTypeConversion::GetDataType(SYSTEM_TEXT("vector2[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Vector3Array, CSVTypeConversion::GetDataType(SYSTEM_TEXT("vector3[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::Vector4Array, CSVTypeConversion::GetDataType(SYSTEM_TEXT("vector4[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::IntVector2Array, CSVTypeConversion::GetDataType(SYSTEM_TEXT("intVector2[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::IntVector3Array, CSVTypeConversion::GetDataType(SYSTEM_TEXT("intVector3[]"s)));
    ASSERT_ENUM_EQUAL(CSVDataType::IntVector4Array, CSVTypeConversion::GetDataType(SYSTEM_TEXT("intVector4[]"s)));
}

void CoreTools::CSVTypeConversionTesting::CSVFormatTypeTest()
{
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVFormatType::Default), "@default"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVFormatType::Ignore), "@ignore"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVFormatType::Vector), "@vector"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVFormatType::TreeMap), "@treeMap"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVFormatType::HashMap), "@hashMap"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVFormatType::Key), "@key"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVFormatType::Enum), "@enum"s);
    ASSERT_EQUAL(CSVTypeConversion::GetTypeDescribe(CSVFormatType::Unique), "@unique"s);

    ASSERT_ENUM_EQUAL(CSVFormatType::Default, CSVTypeConversion::GetFormatType(SYSTEM_TEXT("@default"s)));
    ASSERT_ENUM_EQUAL(CSVFormatType::Ignore, CSVTypeConversion::GetFormatType(SYSTEM_TEXT("@ignore"s)));
    ASSERT_ENUM_EQUAL(CSVFormatType::Vector, CSVTypeConversion::GetFormatType(SYSTEM_TEXT("@vector"s)));
    ASSERT_ENUM_EQUAL(CSVFormatType::TreeMap, CSVTypeConversion::GetFormatType(SYSTEM_TEXT("@treeMap"s)));
    ASSERT_ENUM_EQUAL(CSVFormatType::HashMap, CSVTypeConversion::GetFormatType(SYSTEM_TEXT("@hashMap"s)));
    ASSERT_ENUM_EQUAL(CSVFormatType::Key, CSVTypeConversion::GetFormatType(SYSTEM_TEXT("@key"s)));
    ASSERT_ENUM_EQUAL(CSVFormatType::Enum, CSVTypeConversion::GetFormatType(SYSTEM_TEXT("@enum"s)));
    ASSERT_ENUM_EQUAL(CSVFormatType::Unique, CSVTypeConversion::GetFormatType(SYSTEM_TEXT("@unique"s)));
}

void CoreTools::CSVTypeConversionTesting::ActualTypeTest()
{
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::String), SYSTEM_TEXT("System::String"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Bool), SYSTEM_TEXT("bool"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Char), SYSTEM_TEXT("System::TChar"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Int), SYSTEM_TEXT("int"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Int64), SYSTEM_TEXT("int64_t"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Double), SYSTEM_TEXT("double"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Vector2), SYSTEM_TEXT("CoreTools::Vector2"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Vector3), SYSTEM_TEXT("CoreTools::Vector3"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Vector4), SYSTEM_TEXT("CoreTools::Vector4"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::IntVector2), SYSTEM_TEXT("CoreTools::IntVector2"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::IntVector3), SYSTEM_TEXT("CoreTools::IntVector3"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::IntVector4), SYSTEM_TEXT("CoreTools::IntVector4"s));

    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::BoolArray), SYSTEM_TEXT("std::deque<bool>"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::CharArray), SYSTEM_TEXT("std::vector<System::TChar>"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::IntArray), SYSTEM_TEXT("std::vector<int>"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Int64Array), SYSTEM_TEXT("std::vector<int64_t>"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::DoubleArray), SYSTEM_TEXT("std::vector<double>"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Vector2Array), SYSTEM_TEXT("std::vector<CoreTools::Vector2>"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Vector3Array), SYSTEM_TEXT("std::vector<CoreTools::Vector3>"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::Vector4Array), SYSTEM_TEXT("std::vector<CoreTools::Vector4>"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::IntVector2Array), SYSTEM_TEXT("std::vector<CoreTools::IntVector2>"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::IntVector3Array), SYSTEM_TEXT("std::vector<CoreTools::IntVector3>"s));
    ASSERT_EQUAL(CSVTypeConversion::GetActualType(CSVDataType::IntVector4Array), SYSTEM_TEXT("std::vector<CoreTools::IntVector4>"s));
}

void CoreTools::CSVTypeConversionTesting::GetFunctionNameTest()
{
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::String), SYSTEM_TEXT("GetString"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Bool), SYSTEM_TEXT("GetBool"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Char), SYSTEM_TEXT("GetChar"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Int), SYSTEM_TEXT("GetInt"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Int64), SYSTEM_TEXT("GetInt64"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Double), SYSTEM_TEXT("GetDouble"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Vector2), SYSTEM_TEXT("GetVector2"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Vector3), SYSTEM_TEXT("GetVector3"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Vector4), SYSTEM_TEXT("GetVector4"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::IntVector2), SYSTEM_TEXT("GetIntVector2"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::IntVector3), SYSTEM_TEXT("GetIntVector3"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::IntVector4), SYSTEM_TEXT("GetIntVector4"s));

    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::BoolArray), SYSTEM_TEXT("GetBoolArray"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::CharArray), SYSTEM_TEXT("GetCharArray"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::IntArray), SYSTEM_TEXT("GetIntArray"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Int64Array), SYSTEM_TEXT("GetInt64Array"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::DoubleArray), SYSTEM_TEXT("GetDoubleArray"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Vector2Array), SYSTEM_TEXT("GetVector2Array"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Vector3Array), SYSTEM_TEXT("GetVector3Array"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::Vector4Array), SYSTEM_TEXT("GetVector4Array"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::IntVector2Array), SYSTEM_TEXT("GetIntVector2Array"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::IntVector3Array), SYSTEM_TEXT("GetIntVector3Array"s));
    ASSERT_EQUAL(CSVTypeConversion::GetFunctionName(CSVDataType::IntVector4Array), SYSTEM_TEXT("GetIntVector4Array"s));
}

void CoreTools::CSVTypeConversionTesting::ValueTypeTest()
{
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::String), SYSTEM_TEXT("System::String"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Bool), SYSTEM_TEXT("bool"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Char), SYSTEM_TEXT("System::TChar"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Int), SYSTEM_TEXT("int"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Int64), SYSTEM_TEXT("int64_t"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Double), SYSTEM_TEXT("double"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Vector2), SYSTEM_TEXT("CoreTools::Vector2"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Vector3), SYSTEM_TEXT("CoreTools::Vector3"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Vector4), SYSTEM_TEXT("CoreTools::Vector4"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::IntVector2), SYSTEM_TEXT("CoreTools::IntVector2"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::IntVector3), SYSTEM_TEXT("CoreTools::IntVector3"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::IntVector4), SYSTEM_TEXT("CoreTools::IntVector4"s));

    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::BoolArray), SYSTEM_TEXT("bool"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::CharArray), SYSTEM_TEXT("System::TChar"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::IntArray), SYSTEM_TEXT("int"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Int64Array), SYSTEM_TEXT("int64_t"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::DoubleArray), SYSTEM_TEXT("double"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Vector2Array), SYSTEM_TEXT("CoreTools::Vector2"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Vector3Array), SYSTEM_TEXT("CoreTools::Vector3"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::Vector4Array), SYSTEM_TEXT("CoreTools::Vector4"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::IntVector2Array), SYSTEM_TEXT("CoreTools::IntVector2"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::IntVector3Array), SYSTEM_TEXT("CoreTools::IntVector3"s));
    ASSERT_EQUAL(CSVTypeConversion::GetValueType(CSVDataType::IntVector4Array), SYSTEM_TEXT("CoreTools::IntVector4"s));
}

void CoreTools::CSVTypeConversionTesting::BaseReturnDescribeTest()
{
    ASSERT_EQUAL(CSVTypeConversion::GetBaseReturnDescribe(CSVDataType::Bool), SYSTEM_TEXT("return false;\n"s));
    ASSERT_EQUAL(CSVTypeConversion::GetBaseReturnDescribe(CSVDataType::Char), SYSTEM_TEXT("return SYSTEM_TEXT('\\0');\n"s));
    ASSERT_EQUAL(CSVTypeConversion::GetBaseReturnDescribe(CSVDataType::Int), SYSTEM_TEXT("return 0;\n"s));
    ASSERT_EQUAL(CSVTypeConversion::GetBaseReturnDescribe(CSVDataType::Int64), SYSTEM_TEXT("return 0;\n"s));
    ASSERT_EQUAL(CSVTypeConversion::GetBaseReturnDescribe(CSVDataType::Double), SYSTEM_TEXT("return 0.0;\n"s));
    ASSERT_EQUAL(CSVTypeConversion::GetBaseReturnDescribe(CSVDataType::Vector2), SYSTEM_TEXT("return CoreTools::Vector2{};\n"s));
    ASSERT_EQUAL(CSVTypeConversion::GetBaseReturnDescribe(CSVDataType::Vector3), SYSTEM_TEXT("return CoreTools::Vector3{};\n"s));
    ASSERT_EQUAL(CSVTypeConversion::GetBaseReturnDescribe(CSVDataType::Vector4), SYSTEM_TEXT("return CoreTools::Vector4{};\n"s));
    ASSERT_EQUAL(CSVTypeConversion::GetBaseReturnDescribe(CSVDataType::IntVector2), SYSTEM_TEXT("return CoreTools::IntVector2{};\n"s));
    ASSERT_EQUAL(CSVTypeConversion::GetBaseReturnDescribe(CSVDataType::IntVector3), SYSTEM_TEXT("return CoreTools::IntVector3{};\n"s));
    ASSERT_EQUAL(CSVTypeConversion::GetBaseReturnDescribe(CSVDataType::IntVector4), SYSTEM_TEXT("return CoreTools::IntVector4{};\n"s));
}
