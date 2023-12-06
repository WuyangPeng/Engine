/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_CATEGORY_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_CATEGORY_CONTAINER_DETAIL_H

#include "CategoryContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::CategoryContainer::ConstCategorySharedPtr AncientBooks::CategoryContainer::GetFirstCategory(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    if (const auto iter = std::ranges::find_if(category, function);
        iter != category.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("category��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
AncientBooks::CategoryContainer::Container AncientBooks::CategoryContainer::GetCategory(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : category)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_CATEGORY_CONTAINER_DETAIL_H
