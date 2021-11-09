/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++17
/// 自动生成

#ifndef C_S_V_CONFIGURE_CHAPTER_CONTAINER_DETAIL_H
#define C_S_V_CONFIGURE_CHAPTER_CONTAINER_DETAIL_H

#include "ChapterContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
CSVConfigure::ChapterContainer::ConstChapterBaseSharedPtr CSVConfigure::ChapterContainer::GetFirstChapter(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(chapter.cbegin(), chapter.cend(), function);

    if (iter != chapter.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("chapter表未找到满足条件的配置信息。"s));
}

template <typename Function>
CSVConfigure::ChapterContainer::Container CSVConfigure::ChapterContainer::GetChapter(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& value : chapter)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

#endif  // C_S_V_CONFIGURE_CHAPTER_CONTAINER_DETAIL_H
