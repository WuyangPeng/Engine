/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Source.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

AncientBooks::Source::Source(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      name{ csvRow.GetString(SYSTEM_TEXT("name"s)) },
      sort{ csvRow.GetInt(SYSTEM_TEXT("sort"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Source)

int AncientBooks::Source::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Source::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

System::String AncientBooks::Source::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

int AncientBooks::Source::GetSort() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return sort;
}

