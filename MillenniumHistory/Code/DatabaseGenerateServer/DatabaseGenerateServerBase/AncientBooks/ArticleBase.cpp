/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "ArticleBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::ArticleBase::ArticleBase(int64_t key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, ArticleBase)

int64_t AncientBooks::ArticleBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int64_t AncientBooks::ArticleBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::ArticleBase::GetVersion() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::ArticleBase::ConstVersionSharedPtr AncientBooks::ArticleBase::GetVersion(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取映射值。"s))
}

int AncientBooks::ArticleBase::GetChapter() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String AncientBooks::ArticleBase::GetChapterName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取字符串。"s))
}

int AncientBooks::ArticleBase::GetVolume() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::ArticleBase::GetChapterVolume() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::ArticleBase::IntContainer AncientBooks::ArticleBase::GetOtherAuthor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取数组。"s))
}

int AncientBooks::ArticleBase::GetOtherAuthorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取数组。"s))
}

int AncientBooks::ArticleBase::GetOtherAuthor(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取数组。"s))
}

AncientBooks::ArticleBase::IntContainerConstIter AncientBooks::ArticleBase::GetOtherAuthorBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取数组。"s))
}

AncientBooks::ArticleBase::IntContainerConstIter AncientBooks::ArticleBase::GetOtherAuthorEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取数组。"s))
}

AncientBooks::ArticleBase::CharacterContainer AncientBooks::ArticleBase::GetOtherAuthor(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取映射值。"s))
}

AncientBooks::ArticleBase::StringContainer AncientBooks::ArticleBase::GetAuthorNotes() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取数组。"s))
}

int AncientBooks::ArticleBase::GetAuthorNotesCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取数组。"s))
}

System::String AncientBooks::ArticleBase::GetAuthorNotes(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取数组。"s))
}

AncientBooks::ArticleBase::StringContainerConstIter AncientBooks::ArticleBase::GetAuthorNotesBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取数组。"s))
}

AncientBooks::ArticleBase::StringContainerConstIter AncientBooks::ArticleBase::GetAuthorNotesEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取数组。"s))
}

System::String AncientBooks::ArticleBase::GetTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取字符串。"s))
}

System::String AncientBooks::ArticleBase::GetAbbreviation() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取字符串。"s))
}

System::String AncientBooks::ArticleBase::GetDirectory() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("article表基类不允许获取字符串。"s))
}

