/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_IMPERIAL_COURT_CONTAINER_H
#define ANCIENT_BOOKS_IMPERIAL_COURT_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class ImperialCourtContainer final
    {
    public:
        using ClassType = ImperialCourtContainer;

        using ConstImperialCourtSharedPtr = std::shared_ptr<const ImperialCourtMappingType>;
        using Container = std::vector<ConstImperialCourtSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit ImperialCourtContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstImperialCourtSharedPtr GetFirstImperialCourt() const;
        NODISCARD ConstImperialCourtSharedPtr GetImperialCourt(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstImperialCourtSharedPtr GetFirstImperialCourt(Function function) const;

        template <typename Function>
        NODISCARD Container GetImperialCourt(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container imperialCourt;
    };
}

#endif  // ANCIENT_BOOKS_IMPERIAL_COURT_CONTAINER_H
