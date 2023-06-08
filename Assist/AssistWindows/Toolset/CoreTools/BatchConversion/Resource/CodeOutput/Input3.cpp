/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Input3.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

CsvOutput::Input3::Input3(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      test0{ csvRow.GetBool(SYSTEM_TEXT("test0"s)) },
      test1{ csvRow.GetChar(SYSTEM_TEXT("test1"s)) },
      test2{ csvRow.GetDouble(SYSTEM_TEXT("test2"s)) },
      test4{ csvRow.GetInt(SYSTEM_TEXT("test4"s)) },
      test5{ csvRow.GetString(SYSTEM_TEXT("test5"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CsvOutput, Input3)

int CsvOutput::Input3::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int CsvOutput::Input3::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

bool CsvOutput::Input3::IsTest0() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test0;
}

System::TChar CsvOutput::Input3::GetTest1() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test1;
}

double CsvOutput::Input3::GetTest2() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test2;
}

int CsvOutput::Input3::GetTest4() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return test4;
}

System::String CsvOutput::Input3::GetTest5() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return test5;
}

