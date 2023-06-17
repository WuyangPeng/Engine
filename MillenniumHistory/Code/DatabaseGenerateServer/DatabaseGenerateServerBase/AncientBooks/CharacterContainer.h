/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef ANCIENT_BOOKS_CHARACTER_CONTAINER_H
#define ANCIENT_BOOKS_CHARACTER_CONTAINER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <vector>

namespace AncientBooks
{
    class CharacterContainer final
    {
    public:
        using ClassType = CharacterContainer;
        using ConstCharacterBaseSharedPtr = std::shared_ptr<const CharacterBase>;
        using Container = std::vector<ConstCharacterBaseSharedPtr>;

    public:
        explicit CharacterContainer(const CoreTools::CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstCharacterBaseSharedPtr GetFirstCharacter() const;
        NODISCARD ConstCharacterBaseSharedPtr GetCharacter(int key) const;
        NODISCARD Container GetContainer() const;

        template <typename Function>
        NODISCARD ConstCharacterBaseSharedPtr GetFirstCharacter(Function function) const;

        template <typename Function>
        NODISCARD Container GetCharacter(Function function) const;

    private:
        void Parsing(const CoreTools::CSVContent& csvContent);

    private:
        Container character;
    };
}

#endif  // ANCIENT_BOOKS_CHARACTER_CONTAINER_H
