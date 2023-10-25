/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_REIGN_TITLE_CONTAINER_H
#define ANCIENT_BOOKS_REIGN_TITLE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class ReignTitleContainer final
    {
    public:
        using ClassType = ReignTitleContainer;

        using ConstReignTitleSharedPtr = std::shared_ptr<const ReignTitleMappingType>;
        using Container = std::vector<ConstReignTitleSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit ReignTitleContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstReignTitleSharedPtr GetFirstReignTitle() const;
        NODISCARD ConstReignTitleSharedPtr GetReignTitle(int64_t key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstReignTitleSharedPtr GetFirstReignTitle(Function function) const;

        template <typename Function>
        NODISCARD Container GetReignTitle(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container reignTitle;
    };
}

#endif  // ANCIENT_BOOKS_REIGN_TITLE_CONTAINER_H
