/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "AncientBooksContainer.h"
#include "CategoryContainer.h"
#include "Genus.h"
#include "GenusContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Genus::Genus(const CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      category{ csvRow.GetInt(SYSTEM_TEXT("category"s)) },
      name{ csvRow.GetString(SYSTEM_TEXT("name"s)) },
      father{ csvRow.GetInt(SYSTEM_TEXT("father"s)) },
      begin{ csvRow.GetString(SYSTEM_TEXT("begin"s)) },
      end{ csvRow.GetString(SYSTEM_TEXT("end"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Genus)

int AncientBooks::Genus::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Genus::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Genus::GetCategory() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return category;
}

AncientBooks::Genus::ConstCategorySharedPtr AncientBooks::Genus::GetCategory(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetCategoryContainer()->GetCategory(category);
}

System::String AncientBooks::Genus::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

int AncientBooks::Genus::GetFather() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return father;
}

AncientBooks::Genus::ConstGenusSharedPtr AncientBooks::Genus::GetFather(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetGenusContainer()->GetGenus(father);
}

System::String AncientBooks::Genus::GetBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return begin;
}

System::String AncientBooks::Genus::GetEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return end;
}

