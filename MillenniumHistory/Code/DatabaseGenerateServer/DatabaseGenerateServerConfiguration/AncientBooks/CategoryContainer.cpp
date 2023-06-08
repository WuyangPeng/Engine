/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Category.h"
#include "CategoryContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::CategoryContainer::CategoryContainer(const CoreTools::CSVContent& csvContent)
    : category{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::CategoryContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        category.emplace_back(std::make_shared<Category>(csvRow));
    }

    std::ranges::sort(category, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(category, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("category表存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        category.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, CategoryContainer)

AncientBooks::CategoryContainer::ConstCategoryBaseSharedPtr AncientBooks::CategoryContainer::GetFirstCategory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return category.at(0);
}

AncientBooks::CategoryContainer::ConstCategoryBaseSharedPtr AncientBooks::CategoryContainer::GetCategory(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(category, std::make_shared<CategoryBase>(key), function);

    if (iter != category.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("category表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

AncientBooks::CategoryContainer::Container AncientBooks::CategoryContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return category;
}

