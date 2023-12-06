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

        using ConstCharacterSharedPtr = std::shared_ptr<const CharacterMappingType>;
        using Container = std::vector<ConstCharacterSharedPtr>;
        using CSVContent = CoreTools::CSVContent;

    public:
        explicit CharacterContainer(const CSVContent& csvContent);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstCharacterSharedPtr GetFirstCharacter() const;
        NODISCARD ConstCharacterSharedPtr GetCharacter(int key) const;
        NODISCARD Container GetContainer() const;

        NODISCARD int GetContainerSize() const;

        template <typename Function>
        NODISCARD ConstCharacterSharedPtr GetFirstCharacter(Function function) const;

        template <typename Function>
        NODISCARD Container GetCharacter(Function function) const;

    private:
        void Parsing(const CSVContent& csvContent);
        void Load(const CSVContent& csvContent);
        void Unique();

    private:
        Container character;
    };
}

#endif  // ANCIENT_BOOKS_CHARACTER_CONTAINER_H
