/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_BOOK_CONTAINER_H
#define ANCIENT_BOOKS_BOOK_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class BookContainer final
    {
    public:
        using ClassType = BookContainer;
        using ConstBookBaseSharedPtr = std::shared_ptr<const BookBase>;
        using Container = std::vector<ConstBookBaseSharedPtr>;

    public:
        explicit BookContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstBookBaseSharedPtr GetFirstBook() const;
        NODISCARD ConstBookBaseSharedPtr GetBook(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstBookBaseSharedPtr GetFirstBook(Function function) const;

        template <typename Function>
        NODISCARD Container GetBook(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container book;
    };
}

#endif  // ANCIENT_BOOKS_BOOK_CONTAINER_H
