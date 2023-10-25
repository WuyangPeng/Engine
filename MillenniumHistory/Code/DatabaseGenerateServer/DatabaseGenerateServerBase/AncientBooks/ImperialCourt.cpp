/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "AncientBooksContainer.h"
#include "ImperialCourt.h"
#include "YearContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals; 

AncientBooks::ImperialCourt::ImperialCourt(const CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      category{ csvRow.GetString(SYSTEM_TEXT("category"s)) },
      book{ csvRow.GetString(SYSTEM_TEXT("book"s)) },
      begin{ csvRow.GetInt(SYSTEM_TEXT("begin"s)) },
      end{ csvRow.GetInt(SYSTEM_TEXT("end"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, ImperialCourt)

int AncientBooks::ImperialCourt::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::ImperialCourt::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

System::String AncientBooks::ImperialCourt::GetCategory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return category;
}

System::String AncientBooks::ImperialCourt::GetBook() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return book;
}

int AncientBooks::ImperialCourt::GetBegin() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return begin;
}

AncientBooks::ImperialCourt::ConstYearSharedPtr AncientBooks::ImperialCourt::GetBegin(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(begin);
}

int AncientBooks::ImperialCourt::GetEnd() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return end;
}

AncientBooks::ImperialCourt::ConstYearSharedPtr AncientBooks::ImperialCourt::GetEnd(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetYearContainer()->GetYear(end);
}

