/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "SexagenaryCycle.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals; 

AncientBooks::SexagenaryCycle::SexagenaryCycle(const CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      heavenly{ csvRow.GetString(SYSTEM_TEXT("heavenly"s)) },
      branch{ csvRow.GetString(SYSTEM_TEXT("branch"s)) },
      name{ csvRow.GetString(SYSTEM_TEXT("name"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, SexagenaryCycle)

int AncientBooks::SexagenaryCycle::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::SexagenaryCycle::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

System::String AncientBooks::SexagenaryCycle::GetHeavenly() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return heavenly;
}

System::String AncientBooks::SexagenaryCycle::GetBranch() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return branch;
}

System::String AncientBooks::SexagenaryCycle::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return name;
}

