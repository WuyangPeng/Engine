/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Input1.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

CsvOutput::Input1::Input1(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      test0{ csvRow.GetBool(SYSTEM_TEXT("test0"s)) },
      test1{ csvRow.GetChar(SYSTEM_TEXT("test1"s)) },
      test2{ csvRow.GetDouble(SYSTEM_TEXT("test2"s)) },
      test4{ csvRow.GetInt(SYSTEM_TEXT("test4"s)) },
      test5{ csvRow.GetString(SYSTEM_TEXT("test5"s)) },
      test6{ csvRow.GetStringArray(SYSTEM_TEXT("test6"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CsvOutput, Input1)

int CsvOutput::Input1::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int CsvOutput::Input1::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

bool CsvOutput::Input1::IsTest0() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test0;
}

System::TChar CsvOutput::Input1::GetTest1() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test1;
}

double CsvOutput::Input1::GetTest2() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test2;
}

int CsvOutput::Input1::GetTest4() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test4;
}

System::String CsvOutput::Input1::GetTest5() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return test5;
}

std::vector<System::String> CsvOutput::Input1::GetTest6() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return test6;
}

int CsvOutput::Input1::GetTest6Count() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(test6.size());
}

System::String CsvOutput::Input1::GetTest6(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return test6.at(index);
}

std::vector<System::String>::const_iterator CsvOutput::Input1::GetTest6Begin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test6.cbegin();
}

std::vector<System::String>::const_iterator CsvOutput::Input1::GetTest6End() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test6.cend();
}

