/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Hero.h"
#include "HeroContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

CSVConfigure::HeroContainer::HeroContainer(const CoreTools::CSVContent& csvContent)
    : hero{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::HeroContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        auto heroBase = std::make_shared<Hero>(csvRow);

        if (!hero.emplace(heroBase->GetKey(), heroBase).second)
        {

            LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("hero表存在重复主键："), heroBase->GetKey(), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, HeroContainer)

CSVConfigure::HeroContainer::ConstHeroSharedPtr CSVConfigure::HeroContainer::GetFirstHero() const
{
    USER_CLASS_IS_VALID_CONST_9;

    if (hero.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("hero表为空。"s))
    }
    else
    {
        return hero.begin()->second;
    }
}

CSVConfigure::HeroContainer::ConstHeroSharedPtr CSVConfigure::HeroContainer::GetHero(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = hero.find(key);

    if (iter != hero.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("hero表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

CSVConfigure::HeroContainer::MappingContainer CSVConfigure::HeroContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return hero;
}

