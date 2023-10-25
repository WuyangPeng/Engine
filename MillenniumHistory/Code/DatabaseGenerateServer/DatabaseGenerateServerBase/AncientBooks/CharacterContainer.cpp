/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Character.h"
#include "CharacterContainerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::CharacterContainer::CharacterContainer(const CSVContent& csvContent)
    : character{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::CharacterContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("character表开始载入……"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("character表结束载入……"));
}

void AncientBooks::CharacterContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto index = 0; index < size; ++index)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(index) };

        character.emplace_back(std::make_shared<Character>(csvRow));
    }

    std::ranges::sort(character, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void AncientBooks::CharacterContainer::Unique()
{
    const auto iter = std::ranges::unique(character, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("character表存在重复主键，key = "), (*lhs).GetKey(), SYSTEM_TEXT("。\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        character.erase(iter.begin(), iter.end());
    }

    character.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, CharacterContainer)

AncientBooks::CharacterContainer::ConstCharacterSharedPtr AncientBooks::CharacterContainer::GetFirstCharacter() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return character.at(0);
}

AncientBooks::CharacterContainer::ConstCharacterSharedPtr AncientBooks::CharacterContainer::GetCharacter(int key) const
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
        THROW_EXCEPTION(SYSTEM_TEXT("character表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::CharacterContainer::Container AncientBooks::CharacterContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return character;
}

int AncientBooks::CharacterContainer::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(character.size());
}

