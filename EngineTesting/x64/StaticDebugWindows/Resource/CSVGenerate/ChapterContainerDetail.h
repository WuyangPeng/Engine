/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef C_S_V_CONFIGURE_CHAPTER_CONTAINER_DETAIL_H
#define C_S_V_CONFIGURE_CHAPTER_CONTAINER_DETAIL_H

#include "ChapterContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
CSVConfigure::ChapterContainer::ConstChapterSharedPtr CSVConfigure::ChapterContainer::GetFirstChapter(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    if (const auto iter = std::ranges::find_if(chapter, function);
        iter != chapter.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("chapter表未找到满足条件的配置信息。"s))
}

template <typename Function>
CSVConfigure::ChapterContainer::Container CSVConfigure::ChapterContainer::GetChapter(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : chapter)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // C_S_V_CONFIGURE_CHAPTER_CONTAINER_DETAIL_H
