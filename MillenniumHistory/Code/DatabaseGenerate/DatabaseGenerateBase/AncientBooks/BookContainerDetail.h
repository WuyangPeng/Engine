/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_BOOK_CONTAINER_DETAIL_H
#define ANCIENT_BOOKS_BOOK_CONTAINER_DETAIL_H

#include "BookContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
AncientBooks::BookContainer::ConstBookSharedPtr AncientBooks::BookContainer::GetFirstBook(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    if (const auto iter = std::ranges::find_if(book, function);
        iter != book.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("book��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
AncientBooks::BookContainer::Container AncientBooks::BookContainer::GetBook(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : book)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // ANCIENT_BOOKS_BOOK_CONTAINER_DETAIL_H