/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

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
