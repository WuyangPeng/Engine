/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_IDENTITY_CONTAINER_H
#define ANCIENT_BOOKS_IDENTITY_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class IdentityContainer final
    {
    public:
        using ClassType = IdentityContainer;

        using ConstIdentitySharedPtr = std::shared_ptr<const IdentityMappingType>;
        using Container = std::vector<ConstIdentitySharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit IdentityContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstIdentitySharedPtr GetFirstIdentity() const;
        NODISCARD ConstIdentitySharedPtr GetIdentity(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstIdentitySharedPtr GetFirstIdentity(Function function) const;

        template <typename Function>
        NODISCARD Container GetIdentity(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container identity;
    };
}

#endif  // ANCIENT_BOOKS_IDENTITY_CONTAINER_H
