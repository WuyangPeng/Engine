/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_GATHER_CONTAINER_H
#define ANCIENT_BOOKS_GATHER_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class GatherContainer final
    {
    public:
        using ClassType = GatherContainer;

        using ConstGatherBaseSharedPtr = std::shared_ptr<const GatherBase>;
        using Container = std::vector<ConstGatherBaseSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit GatherContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstGatherBaseSharedPtr GetFirstGather() const;
        NODISCARD ConstGatherBaseSharedPtr GetGather(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstGatherBaseSharedPtr GetFirstGather(Function function) const;

        template <typename Function>
        NODISCARD Container GetGather(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container gather;
    };
}

#endif  // ANCIENT_BOOKS_GATHER_CONTAINER_H
