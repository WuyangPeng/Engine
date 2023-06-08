/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Month.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Month::Month(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      name{ csvRow.GetString(SYSTEM_TEXT("name"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Month)

int AncientBooks::Month::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Month::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

System::String AncientBooks::Month::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

