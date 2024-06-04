/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/31 15:30)

#include "CSVRowTesting.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"
#include "CoreTools/TextParsing/CSV/ExcelConversionCSV.h"
#include "CoreTools/TextParsing/Data/IntVector2.h"
#include "CoreTools/TextParsing/Data/IntVector3.h"
#include "CoreTools/TextParsing/Data/IntVector4.h"
#include "CoreTools/TextParsing/Data/Vector2.h"
#include "CoreTools/TextParsing/Data/Vector3.h"
#include "CoreTools/TextParsing/Data/Vector4.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <map>

using System::operator+;
using System::operator++;
using namespace std::literals;

template <>
CoreTools::CSVDataType CoreTools::CSVRow::StringCastEnum<CoreTools::CSVDataType>(const String& describe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    static std::map<String, CSVDataType> typeDescribe{ { SYSTEM_TEXT("String"s), CSVDataType::String },
                                                       { SYSTEM_TEXT("Bool"s), CSVDataType::Bool },
                                                       { SYSTEM_TEXT("Char"s), CSVDataType::Char },
                                                       { SYSTEM_TEXT("Int"s), CSVDataType::Int },
                                                       { SYSTEM_TEXT("Int64"s), CSVDataType::Int64 },
                                                       { SYSTEM_TEXT("Double"s), CSVDataType::Double },
                                                       { SYSTEM_TEXT("Enum"s), CSVDataType::Enum },
                                                       { SYSTEM_TEXT("Bit"s), CSVDataType::Bit },
                                                       { SYSTEM_TEXT("Vector2"s), CSVDataType::Vector2 },
                                                       { SYSTEM_TEXT("Vector3"s), CSVDataType::Vector3 },
                                                       { SYSTEM_TEXT("Vector4"s), CSVDataType::Vector4 },
                                                       { SYSTEM_TEXT("IntVector2"s), CSVDataType::IntVector2 },
                                                       { SYSTEM_TEXT("IntVector3"s), CSVDataType::IntVector3 },
                                                       { SYSTEM_TEXT("IntVector4"s), CSVDataType::IntVector4 },

                                                       { SYSTEM_TEXT("BoolArray"s), CSVDataType::BoolArray },
                                                       { SYSTEM_TEXT("CharArray"s), CSVDataType::CharArray },
                                                       { SYSTEM_TEXT("IntArray"s), CSVDataType::IntArray },
                                                       { SYSTEM_TEXT("Int64Array"s), CSVDataType::Int64Array },
                                                       { SYSTEM_TEXT("DoubleArray"s), CSVDataType::DoubleArray },
                                                       { SYSTEM_TEXT("EnumArray"s), CSVDataType::EnumArray },
                                                       { SYSTEM_TEXT("BitArray"s), CSVDataType::BitArray },
                                                       { SYSTEM_TEXT("Vector2Array"s), CSVDataType::Vector2Array },
                                                       { SYSTEM_TEXT("Vector3Array"s), CSVDataType::Vector3Array },
                                                       { SYSTEM_TEXT("Vector4Array"s), CSVDataType::Vector4Array },
                                                       { SYSTEM_TEXT("IntVector2Array"s), CSVDataType::IntVector2Array },
                                                       { SYSTEM_TEXT("IntVector3Array"s), CSVDataType::IntVector3Array },
                                                       { SYSTEM_TEXT("IntVector4Array"s), CSVDataType::IntVector4Array } };

    if (const auto iter = typeDescribe.find(describe);
        iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。\n"s))
    }
}

CoreTools::CSVRowTesting::CSVRowTesting(const OStreamShared& stream)
    : ParentType{ stream },
      rowContent0{},
      rowContent1{},
      csvFileName{ SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"s) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CSVRowTesting)

void CoreTools::CSVRowTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CSVRowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateCSV);

    ASSERT_NOT_THROW_EXCEPTION_0(CSVRow0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVRow1Test);
}

void CoreTools::CSVRowTesting::CreateCSV()
{
    ExcelConversionCSV excelConversionCSV{ "Resource/CSVTesting/CSVHeadTesting.xlsx"s, csvFileName, false };
}

CoreTools::CSVHead CoreTools::CSVRowTesting::ReadFile()
{
    const IFileStreamManager streamManager{ csvFileName };

    const auto content = streamManager.GetFileContent(SYSTEM_TEXT("\r\n"));

    const auto fileContent = GetFileContent(content);

    rowContent0 = content.at(System::EnumCastUnderlying(CSVType::VariableName));
    constexpr auto nextIndex = System::EnumCastUnderlying(CSVType::VariableName + 1);
    rowContent1 = content.at(nextIndex);

    return CSVHead{ csvFileName, fileContent };
}

CoreTools::CSVRowTesting::FileContent CoreTools::CSVRowTesting::GetFileContent(const FileContent& content)
{
    FileContent fileContent{};

    auto csvType = CSVType::Format;
    for (const auto& element : content)
    {
        fileContent.emplace_back(element);

        ++csvType;
        if (CSVType::VariableName < csvType)
        {
            break;
        }
    }

    return fileContent;
}

void CoreTools::CSVRowTesting::CSVRow0Test()
{
    const auto csvHead = ReadFile();
    const CSVRow csvRow{ csvHead, rowContent0 };

    ASSERT_EQUAL(csvRow.GetCount(), 28);

    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow0BaseTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow0VectorTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow0IntVectorTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow0ArrayTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow0VectorArrayTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow0IntVectorArrayTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow0StringArrayTest, csvRow);
}

void CoreTools::CSVRowTesting::CSVRow0BaseTest(const CSVRow& csvRow)
{
    ASSERT_EQUAL(csvRow.GetInt(SYSTEM_TEXT("id"s)), 10001);
    ASSERT_TRUE(csvRow.GetBool(SYSTEM_TEXT("test0"s)));
    ASSERT_EQUAL(System::String{ csvRow.GetChar(SYSTEM_TEXT("test1"s)) }, System::String{ SYSTEM_TEXT('a') });
    ASSERT_APPROXIMATE(csvRow.GetDouble(SYSTEM_TEXT("test2"s)), 1.1, Mathematics::MathD::epsilon);
    ASSERT_EQUAL(csvRow.GetInt64(SYSTEM_TEXT("test3"s)), 10001);
    ASSERT_EQUAL(csvRow.GetInt(SYSTEM_TEXT("test4"s)), 7);
    ASSERT_EQUAL(csvRow.GetString(SYSTEM_TEXT("test5"s)), SYSTEM_TEXT("测试4,测试5,测试6,"s));
    ASSERT_EQUAL(csvRow.GetEnum<CSVDataType>(SYSTEM_TEXT("test6"s)), CSVDataType::String);
}

void CoreTools::CSVRowTesting::CSVRow0VectorTest(const CSVRow& csvRow)
{
    const auto vector2 = csvRow.GetVector2(SYSTEM_TEXT("test7"s));
    ASSERT_APPROXIMATE(vector2.GetX(), 1.1, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector2.GetY(), 1.2, Mathematics::MathD::epsilon);

    const auto vector3 = csvRow.GetVector3(SYSTEM_TEXT("test8"s));
    ASSERT_APPROXIMATE(vector3.GetX(), 1.2, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector3.GetY(), 1.3, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector3.GetZ(), 1.5, Mathematics::MathD::epsilon);

    const auto vector4 = csvRow.GetVector4(SYSTEM_TEXT("test9"s));
    ASSERT_APPROXIMATE(vector4.GetX(), 1.1, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4.GetY(), 1.5, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4.GetZ(), 1.6, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4.GetW(), 1.4, Mathematics::MathD::epsilon);
}

void CoreTools::CSVRowTesting::CSVRow0IntVectorTest(const CSVRow& csvRow)
{
    ASSERT_EQUAL(csvRow.GetIntVector2(SYSTEM_TEXT("test10"s)).GetX(), 1);
    ASSERT_EQUAL(csvRow.GetIntVector2(SYSTEM_TEXT("test10"s)).GetY(), 5);

    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetX(), 2);
    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetY(), 8);
    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetZ(), 4);

    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetX(), 1);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetY(), 5);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetZ(), 4);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetW(), 7);
}

void CoreTools::CSVRowTesting::CSVRow0ArrayTest(const CSVRow& csvRow)
{
    ASSERT_EQUAL(csvRow.GetIntArray(SYSTEM_TEXT("test13"s)), (std::vector{ 10001, 14, 66 }));
    ASSERT_EQUAL(csvRow.GetBoolArray(SYSTEM_TEXT("test14"s)), (std::deque{ true, false }));
    ASSERT_EQUAL(csvRow.GetCharArray(SYSTEM_TEXT("test15"s)), (std::vector{ SYSTEM_TEXT('a'), SYSTEM_TEXT('i') }));

    const auto doubleArray = csvRow.GetDoubleArray(SYSTEM_TEXT("test16"s));
    ASSERT_EQUAL(doubleArray.size(), 2u);
    ASSERT_APPROXIMATE(doubleArray.at(0), 1.1, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(doubleArray.at(1), 1.1, Mathematics::MathD::epsilon);

    ASSERT_EQUAL(csvRow.GetInt64Array(SYSTEM_TEXT("test17"s)), (std::vector{ 10001LL }));
    ASSERT_EQUAL(csvRow.GetIntArray(SYSTEM_TEXT("test18"s)), (std::vector{ 7, 2 }));
    ASSERT_EQUAL(csvRow.GetEnumArray<CSVDataType>(SYSTEM_TEXT("test19"s)), (std::vector{ CSVDataType::String, CSVDataType::Vector2 }));
}

void CoreTools::CSVRowTesting::CSVRow0VectorArrayTest(const CSVRow& csvRow)
{
    const auto vector2Array = csvRow.GetVector2Array(SYSTEM_TEXT("test20"s));
    ASSERT_EQUAL(vector2Array.size(), 2u);
    ASSERT_APPROXIMATE(vector2Array.at(0).GetX(), 1.1, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector2Array.at(0).GetY(), 1.2, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector2Array.at(1).GetX(), 1.3, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector2Array.at(1).GetY(), 1.4, Mathematics::MathD::epsilon);

    const auto vector3Array = csvRow.GetVector3Array(SYSTEM_TEXT("test21"s));
    ASSERT_EQUAL(vector3Array.size(), 1u);
    ASSERT_APPROXIMATE(vector3Array.at(0).GetX(), 1.2, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector3Array.at(0).GetY(), 1.3, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector3Array.at(0).GetZ(), 1.5, Mathematics::MathD::epsilon);

    const auto vector4Array = csvRow.GetVector4Array(SYSTEM_TEXT("test22"s));
    ASSERT_EQUAL(vector4Array.size(), 1u);
    ASSERT_APPROXIMATE(vector4Array.at(0).GetX(), 1.1, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4Array.at(0).GetY(), 1.5, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4Array.at(0).GetZ(), 1.6, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4Array.at(0).GetW(), 1.4, Mathematics::MathD::epsilon);
}

void CoreTools::CSVRowTesting::CSVRow0IntVectorArrayTest(const CSVRow& csvRow)
{
    ASSERT_EQUAL(csvRow.GetIntVector2Array(SYSTEM_TEXT("test23"s)).at(0).GetX(), 1);
    ASSERT_EQUAL(csvRow.GetIntVector2Array(SYSTEM_TEXT("test23"s)).at(0).GetY(), 5);

    ASSERT_EQUAL(csvRow.GetIntVector3Array(SYSTEM_TEXT("test24"s)).at(0).GetX(), 2);
    ASSERT_EQUAL(csvRow.GetIntVector3Array(SYSTEM_TEXT("test24"s)).at(0).GetY(), 8);
    ASSERT_EQUAL(csvRow.GetIntVector3Array(SYSTEM_TEXT("test24"s)).at(0).GetZ(), 4);

    ASSERT_EQUAL(csvRow.GetIntVector4Array(SYSTEM_TEXT("test25"s)).at(0).GetX(), 1);
    ASSERT_EQUAL(csvRow.GetIntVector4Array(SYSTEM_TEXT("test25"s)).at(0).GetY(), 5);
    ASSERT_EQUAL(csvRow.GetIntVector4Array(SYSTEM_TEXT("test25"s)).at(0).GetZ(), 6);
    ASSERT_EQUAL(csvRow.GetIntVector4Array(SYSTEM_TEXT("test25"s)).at(0).GetW(), 7);
}

void CoreTools::CSVRowTesting::CSVRow0StringArrayTest(const CSVRow& csvRow)
{
    const auto result = csvRow.GetStringArray(SYSTEM_TEXT("test26"s));
    ASSERT_EQUAL(result.at(0), SYSTEM_TEXT("a"s));
    ASSERT_EQUAL(result.at(1), SYSTEM_TEXT("i"s));
    ASSERT_EQUAL(result.size(), 2u);
}

void CoreTools::CSVRowTesting::CSVRow1Test()
{
    const auto csvHead = ReadFile();
    const CSVRow csvRow{ csvHead, rowContent1 };

    ASSERT_EQUAL(csvRow.GetCount(), 28);

    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow1BaseTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow1VectorTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow1IntVectorTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow1ArrayTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow1VectorArrayTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow1IntVectorArrayTest, csvRow);
    ASSERT_NOT_THROW_EXCEPTION_1(CSVRow1StringArrayTest, csvRow);
}

void CoreTools::CSVRowTesting::CSVRow1BaseTest(const CSVRow& csvRow)
{
    ASSERT_EQUAL(csvRow.GetInt(SYSTEM_TEXT("id"s)), 10002);
    ASSERT_TRUE(csvRow.GetBool(SYSTEM_TEXT("test0"s)));
    ASSERT_EQUAL(System::String{ csvRow.GetChar(SYSTEM_TEXT("test1"s)) }, System::String{ SYSTEM_TEXT('b') });
    ASSERT_APPROXIMATE(csvRow.GetDouble(SYSTEM_TEXT("test2"s)), 1.2, Mathematics::MathD::epsilon);
    ASSERT_EQUAL(csvRow.GetInt64(SYSTEM_TEXT("test3"s)), 10002);
    ASSERT_EQUAL(csvRow.GetInt(SYSTEM_TEXT("test4"s)), 3);
    ASSERT_EQUAL(csvRow.GetString(SYSTEM_TEXT("test5"s)), SYSTEM_TEXT("测试5"s));
    ASSERT_EQUAL(csvRow.GetEnum<CSVDataType>(SYSTEM_TEXT("test6"s)), CSVDataType::Char);
}

void CoreTools::CSVRowTesting::CSVRow1VectorTest(const CSVRow& csvRow)
{
    const auto vector2 = csvRow.GetVector2(SYSTEM_TEXT("test7"s));
    ASSERT_APPROXIMATE(vector2.GetX(), 1.1, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector2.GetY(), 1.3, Mathematics::MathD::epsilon);

    const auto vector3 = csvRow.GetVector3(SYSTEM_TEXT("test8"s));
    ASSERT_APPROXIMATE(vector3.GetX(), 1.2, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector3.GetY(), 1.3, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector3.GetZ(), 1.6, Mathematics::MathD::epsilon);

    const auto vector4 = csvRow.GetVector4(SYSTEM_TEXT("test9"s));
    ASSERT_APPROXIMATE(vector4.GetX(), 1.1, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4.GetY(), 1.5, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4.GetZ(), 1.6, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4.GetW(), 1.5, Mathematics::MathD::epsilon);
}

void CoreTools::CSVRowTesting::CSVRow1IntVectorTest(const CSVRow& csvRow)
{
    ASSERT_EQUAL(csvRow.GetIntVector2(SYSTEM_TEXT("test10"s)).GetX(), 1);
    ASSERT_EQUAL(csvRow.GetIntVector2(SYSTEM_TEXT("test10"s)).GetY(), 6);

    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetX(), 2);
    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetY(), 8);
    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetZ(), 5);

    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetX(), 3);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetY(), 7);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetZ(), 4);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetW(), 6);
}

void CoreTools::CSVRowTesting::CSVRow1ArrayTest(const CSVRow& csvRow)
{
    ASSERT_EQUAL(csvRow.GetIntArray(SYSTEM_TEXT("test13"s)), (std::vector{ 10002, 55, 4 }));
    ASSERT_EQUAL(csvRow.GetBoolArray(SYSTEM_TEXT("test14"s)), (std::deque{ true }));
    ASSERT_EQUAL(csvRow.GetCharArray(SYSTEM_TEXT("test15"s)), (std::vector{ SYSTEM_TEXT('b') }));

    const auto doubleArray = csvRow.GetDoubleArray(SYSTEM_TEXT("test16"s));
    ASSERT_EQUAL(doubleArray.size(), 1u);
    ASSERT_APPROXIMATE(doubleArray.at(0), 1.2, Mathematics::MathD::epsilon);

    ASSERT_EQUAL(csvRow.GetInt64Array(SYSTEM_TEXT("test17"s)), (std::vector{ 10002LL }));
    ASSERT_EQUAL(csvRow.GetIntArray(SYSTEM_TEXT("test18"s)), (std::vector{ 3 }));
    ASSERT_EQUAL(csvRow.GetEnumArray<CSVDataType>(SYSTEM_TEXT("test19"s)), (std::vector{ CSVDataType::Char }));
}

void CoreTools::CSVRowTesting::CSVRow1VectorArrayTest(const CSVRow& csvRow)
{
    const auto vector2Array = csvRow.GetVector2Array(SYSTEM_TEXT("test20"s));
    ASSERT_EQUAL(vector2Array.size(), 1u);
    ASSERT_APPROXIMATE(vector2Array.at(0).GetX(), 1.1, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector2Array.at(0).GetY(), 1.3, Mathematics::MathD::epsilon);

    const auto vector3Array = csvRow.GetVector3Array(SYSTEM_TEXT("test21"s));
    ASSERT_EQUAL(vector3Array.size(), 1u);
    ASSERT_APPROXIMATE(vector3Array.at(0).GetX(), 1.2, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector3Array.at(0).GetY(), 1.3, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector3Array.at(0).GetZ(), 1.6, Mathematics::MathD::epsilon);

    const auto vector4Array = csvRow.GetVector4Array(SYSTEM_TEXT("test22"s));
    ASSERT_EQUAL(vector4Array.size(), 1u);
    ASSERT_APPROXIMATE(vector4Array.at(0).GetX(), 1.1, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4Array.at(0).GetY(), 1.5, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4Array.at(0).GetZ(), 1.6, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(vector4Array.at(0).GetW(), 1.5, Mathematics::MathD::epsilon);
}

void CoreTools::CSVRowTesting::CSVRow1IntVectorArrayTest(const CSVRow& csvRow)
{
    ASSERT_EQUAL(csvRow.GetIntVector2Array(SYSTEM_TEXT("test23"s)).at(0).GetX(), 1);
    ASSERT_EQUAL(csvRow.GetIntVector2Array(SYSTEM_TEXT("test23"s)).at(0).GetY(), 6);

    ASSERT_EQUAL(csvRow.GetIntVector3Array(SYSTEM_TEXT("test24"s)).at(0).GetX(), 2);
    ASSERT_EQUAL(csvRow.GetIntVector3Array(SYSTEM_TEXT("test24"s)).at(0).GetY(), 8);
    ASSERT_EQUAL(csvRow.GetIntVector3Array(SYSTEM_TEXT("test24"s)).at(0).GetZ(), 5);

    ASSERT_EQUAL(csvRow.GetIntVector4Array(SYSTEM_TEXT("test25"s)).at(0).GetX(), 3);
    ASSERT_EQUAL(csvRow.GetIntVector4Array(SYSTEM_TEXT("test25"s)).at(0).GetY(), 7);
    ASSERT_EQUAL(csvRow.GetIntVector4Array(SYSTEM_TEXT("test25"s)).at(0).GetZ(), 4);
    ASSERT_EQUAL(csvRow.GetIntVector4Array(SYSTEM_TEXT("test25"s)).at(0).GetW(), 6);
}

void CoreTools::CSVRowTesting::CSVRow1StringArrayTest(const CSVRow& csvRow)
{
    const auto result = csvRow.GetStringArray(SYSTEM_TEXT("test26"s));
    ASSERT_EQUAL(result.at(0), SYSTEM_TEXT("b"s));
    ASSERT_EQUAL(result.size(), 1u);
}