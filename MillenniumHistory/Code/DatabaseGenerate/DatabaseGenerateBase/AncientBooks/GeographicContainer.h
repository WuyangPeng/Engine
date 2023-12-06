/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_GEOGRAPHIC_CONTAINER_H
#define ANCIENT_BOOKS_GEOGRAPHIC_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class GeographicContainer final
    {
    public:
        using ClassType = GeographicContainer;

        using ConstGeographicSharedPtr = std::shared_ptr<const GeographicMappingType>;
        using Container = std::vector<ConstGeographicSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit GeographicContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstGeographicSharedPtr GetFirstGeographic() const;
        NODISCARD ConstGeographicSharedPtr GetGeographic(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstGeographicSharedPtr GetFirstGeographic(Function function) const;

        template <typename Function>
        NODISCARD Container GetGeographic(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container geographic;
    };
}

#endif  // ANCIENT_BOOKS_GEOGRAPHIC_CONTAINER_H
