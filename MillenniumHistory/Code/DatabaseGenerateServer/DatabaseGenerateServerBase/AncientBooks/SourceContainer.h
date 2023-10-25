/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_SOURCE_CONTAINER_H
#define ANCIENT_BOOKS_SOURCE_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class SourceContainer final
    {
    public:
        using ClassType = SourceContainer;

        using ConstSourceSharedPtr = std::shared_ptr<const SourceMappingType>;
        using Container = std::vector<ConstSourceSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit SourceContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSourceSharedPtr GetFirstSource() const;
        NODISCARD ConstSourceSharedPtr GetSource(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstSourceSharedPtr GetFirstSource(Function function) const;

        template <typename Function>
        NODISCARD Container GetSource(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container source;
    };
}

#endif  // ANCIENT_BOOKS_SOURCE_CONTAINER_H
