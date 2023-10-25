/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

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

        using ConstBookSharedPtr = std::shared_ptr<const BookMappingType>;
        using Container = std::vector<ConstBookSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit BookContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstBookSharedPtr GetFirstBook() const;
        NODISCARD ConstBookSharedPtr GetBook(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstBookSharedPtr GetFirstBook(Function function) const;

        template <typename Function>
        NODISCARD Container GetBook(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container book;
    };
}

#endif  // ANCIENT_BOOKS_BOOK_CONTAINER_H
