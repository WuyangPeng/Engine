/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_EMPEROR_CONTAINER_H
#define ANCIENT_BOOKS_EMPEROR_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class EmperorContainer final
    {
    public:
        using ClassType = EmperorContainer;

        using ConstEmperorSharedPtr = std::shared_ptr<const EmperorMappingType>;
        using Container = std::vector<ConstEmperorSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit EmperorContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstEmperorSharedPtr GetFirstEmperor() const;
        NODISCARD ConstEmperorSharedPtr GetEmperor(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstEmperorSharedPtr GetFirstEmperor(Function function) const;

        template <typename Function>
        NODISCARD Container GetEmperor(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container emperor;
    };
}

#endif  // ANCIENT_BOOKS_EMPEROR_CONTAINER_H
