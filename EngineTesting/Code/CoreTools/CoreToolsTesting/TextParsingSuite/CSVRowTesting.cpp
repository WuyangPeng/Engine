///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/10 10:18)

#include "CSVRowTesting.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"
#include "CoreTools/TextParsing/CSV/CSVTypeConversion.h"
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

    if (const auto iter = typeDescribe.find(describe); iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。\n"s))
    }
}

CoreTools::CSVRowTesting::CSVRowTesting(const OStreamShared& stream)
    : ParentType{ stream }, rowContent0{}, rowContent1{}
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
    ASSERT_NOT_THROW_EXCEPTION_0(CSVRow0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVRow1Test);
}

void CoreTools::CSVRowTesting::CreateCSV()
{
    ExcelConversionCSV excelConversionCSV{ "Resource/CSVTesting/CSVHeadTesting.xlsx"s, SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"s), false };
}

CoreTools::CSVHead CoreTools::CSVRowTesting::ReadFile()
{
    using FileContent = std::vector<String>;

    FileContent fileContent{};

    const IFStreamManager streamManager{ SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"s) };

    const auto content = streamManager.GetFileContent();

    std::vector<String> row{};
    split(row, content, boost::is_any_of(SYSTEM_TEXT("\r\n")), boost::token_compress_on);

    auto csvType = CSVType::Format;
    for (const auto& value : row)
    {
        fileContent.emplace_back(value);

        ++csvType;
        if (CSVType::VariableName < csvType)
        {
            break;
        }
    }

    rowContent0 = row.at(System::EnumCastUnderlying(CSVType::VariableName));
    constexpr auto nextIndex = System::EnumCastUnderlying(CSVType::VariableName) + 1;
    rowContent1 = row.at(nextIndex);

    CSVHead csvHead{ SYSTEM_TEXT("Resource/CSVTesting/CSVHead/CSVHeadTesting.csv"s), fileContent };

    return csvHead;
}

void CoreTools::CSVRowTesting::CSVRow0Test()
{
    const CSVRow csvRow{ ReadFile(), rowContent0 };

    ASSERT_EQUAL(csvRow.GetCount(), 27);

    ASSERT_EQUAL(csvRow.GetInt(SYSTEM_TEXT("id"s)), 10001);
    ASSERT_TRUE(csvRow.GetBool(SYSTEM_TEXT("test0"s)));
    ASSERT_EQUAL(System::String{ csvRow.GetChar(SYSTEM_TEXT("test1"s)) }, System::String{ SYSTEM_TEXT('a') });
    ASSERT_APPROXIMATE(csvRow.GetDouble(SYSTEM_TEXT("test2"s)), 1.1, Mathematics::MathD::epsilon);
    ASSERT_EQUAL(csvRow.GetInt64(SYSTEM_TEXT("test3"s)), 10001);
    ASSERT_EQUAL(csvRow.GetInt(SYSTEM_TEXT("test4"s)), 7);
    ASSERT_EQUAL(csvRow.GetString(SYSTEM_TEXT("test5"s)), SYSTEM_TEXT("测试4,测试5,测试6,"s));
    ASSERT_ENUM_EQUAL(csvRow.GetEnum<CSVDataType>(SYSTEM_TEXT("test6"s)), CSVDataType::String);

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

    ASSERT_EQUAL(csvRow.GetIntVector2(SYSTEM_TEXT("test10"s)).GetX(), 1);
    ASSERT_EQUAL(csvRow.GetIntVector2(SYSTEM_TEXT("test10"s)).GetY(), 5);

    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetX(), 2);
    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetY(), 8);
    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetZ(), 4);

    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetX(), 1);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetY(), 5);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetZ(), 4);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetW(), 7);

    ASSERT_EQUAL(csvRow.GetIntArray(SYSTEM_TEXT("test13"s)), (std::vector<int>{ 10001, 14, 66 }));
    ASSERT_EQUAL(csvRow.GetBoolArray(SYSTEM_TEXT("test14"s)), (std::deque<bool>{ true, false }));
    ASSERT_EQUAL(csvRow.GetCharArray(SYSTEM_TEXT("test15"s)), (std::vector<System::TChar>{ SYSTEM_TEXT('a'), SYSTEM_TEXT('i') }));

    const auto doubleArray = csvRow.GetDoubleArray(SYSTEM_TEXT("test16"s));
    ASSERT_EQUAL(doubleArray.size(), 2u);
    ASSERT_APPROXIMATE(doubleArray.at(0), 1.1, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(doubleArray.at(1), 1.1, Mathematics::MathD::epsilon);

    ASSERT_EQUAL(csvRow.GetInt64Array(SYSTEM_TEXT("test17"s)), (std::vector<int64_t>{ 10001 }));
    ASSERT_EQUAL(csvRow.GetIntArray(SYSTEM_TEXT("test18"s)), (std::vector<int>{ 7, 2 }));
    ASSERT_EQUAL(csvRow.GetEnumArray<CSVDataType>(SYSTEM_TEXT("test19"s)), (std::vector<CSVDataType>{ CSVDataType::String, CSVDataType::Vector2 }));

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

void CoreTools::CSVRowTesting::CSVRow1Test()
{
    const CSVRow csvRow{ ReadFile(), rowContent1 };

    ASSERT_EQUAL(csvRow.GetCount(), 27);

    ASSERT_EQUAL(csvRow.GetInt(SYSTEM_TEXT("id"s)), 10002);
    ASSERT_TRUE(csvRow.GetBool(SYSTEM_TEXT("test0"s)));
    ASSERT_EQUAL(System::String{ csvRow.GetChar(SYSTEM_TEXT("test1"s)) }, System::String{ SYSTEM_TEXT('b') });
    ASSERT_APPROXIMATE(csvRow.GetDouble(SYSTEM_TEXT("test2"s)), 1.2, Mathematics::MathD::epsilon);
    ASSERT_EQUAL(csvRow.GetInt64(SYSTEM_TEXT("test3"s)), 10002);
    ASSERT_EQUAL(csvRow.GetInt(SYSTEM_TEXT("test4"s)), 3);
    ASSERT_EQUAL(csvRow.GetString(SYSTEM_TEXT("test5"s)), SYSTEM_TEXT("测试5"s));
    ASSERT_ENUM_EQUAL(csvRow.GetEnum<CSVDataType>(SYSTEM_TEXT("test6"s)), CSVDataType::Char);

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

    ASSERT_EQUAL(csvRow.GetIntVector2(SYSTEM_TEXT("test10"s)).GetX(), 1);
    ASSERT_EQUAL(csvRow.GetIntVector2(SYSTEM_TEXT("test10"s)).GetY(), 6);

    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetX(), 2);
    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetY(), 8);
    ASSERT_EQUAL(csvRow.GetIntVector3(SYSTEM_TEXT("test11"s)).GetZ(), 5);

    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetX(), 3);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetY(), 7);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetZ(), 4);
    ASSERT_EQUAL(csvRow.GetIntVector4(SYSTEM_TEXT("test12"s)).GetW(), 6);

    ASSERT_EQUAL(csvRow.GetIntArray(SYSTEM_TEXT("test13"s)), (std::vector{ 10002, 55, 4 }));
    ASSERT_EQUAL(csvRow.GetBoolArray(SYSTEM_TEXT("test14"s)), (std::deque{ true }));
    ASSERT_EQUAL(csvRow.GetCharArray(SYSTEM_TEXT("test15"s)), (std::vector{ SYSTEM_TEXT('b') }));

    const auto doubleArray = csvRow.GetDoubleArray(SYSTEM_TEXT("test16"s));
    ASSERT_EQUAL(doubleArray.size(), 1u);
    ASSERT_APPROXIMATE(doubleArray.at(0), 1.2, Mathematics::MathD::epsilon);

    ASSERT_EQUAL(csvRow.GetInt64Array(SYSTEM_TEXT("test17"s)), (std::vector<int64_t>{ 10002 }));
    ASSERT_EQUAL(csvRow.GetIntArray(SYSTEM_TEXT("test18"s)), (std::vector{ 3 }));
    ASSERT_EQUAL(csvRow.GetEnumArray<CSVDataType>(SYSTEM_TEXT("test19"s)), (std::vector{ CSVDataType::Char }));

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
