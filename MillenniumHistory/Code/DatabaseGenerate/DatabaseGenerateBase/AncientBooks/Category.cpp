/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "AncientBooksContainer.h"
#include "Category.h"
#include "GatherContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals; 

AncientBooks::Category::Category(const CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      gather{ csvRow.GetInt(SYSTEM_TEXT("gather"s)) },
      category{ csvRow.GetString(SYSTEM_TEXT("category"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, Category)

int AncientBooks::Category::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Category::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int AncientBooks::Category::GetGather() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return gather;
}

AncientBooks::Category::ConstGatherSharedPtr AncientBooks::Category::GetGather(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return csvContainer.GetGatherContainer()->GetGather(gather);
}

System::String AncientBooks::Category::GetCategory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return category;
}

