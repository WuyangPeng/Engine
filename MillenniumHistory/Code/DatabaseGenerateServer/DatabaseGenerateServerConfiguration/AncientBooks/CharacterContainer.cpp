/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Character.h"
#include "CharacterContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::CharacterContainer::CharacterContainer(const CoreTools::CSVContent& csvContent)
    : character{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::CharacterContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        character.emplace_back(std::make_shared<Character>(csvRow));
    }

    std::ranges::sort(character, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(character, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("character������ظ�������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        character.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, CharacterContainer)

AncientBooks::CharacterContainer::ConstCharacterBaseSharedPtr AncientBooks::CharacterContainer::GetFirstCharacter() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return character.at(0);
}

AncientBooks::CharacterContainer::ConstCharacterBaseSharedPtr AncientBooks::CharacterContainer::GetCharacter(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(character, std::make_shared<CharacterBase>(key), function);

    if (iter != character.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("character��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::CharacterContainer::Container AncientBooks::CharacterContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return character;
}

