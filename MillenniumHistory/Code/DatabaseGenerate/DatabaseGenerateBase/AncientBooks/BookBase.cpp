/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "BookBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::BookBase::BookBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, BookBase)

int AncientBooks::BookBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int AncientBooks::BookBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::BookBase::GetGenus() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::BookBase::ConstGenusSharedPtr AncientBooks::BookBase::GetGenus(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取映射值。"s))
}

System::String AncientBooks::BookBase::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取字符串。"s))
}

AncientBooks::BookBase::StringContainer AncientBooks::BookBase::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

System::String AncientBooks::BookBase::GetAlias(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::StringContainerConstIter AncientBooks::BookBase::GetAliasBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::StringContainerConstIter AncientBooks::BookBase::GetAliasEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetVolume() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::BookBase::IntContainer AncientBooks::BookBase::GetAuthor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAuthorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAuthor(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::IntContainerConstIter AncientBooks::BookBase::GetAuthorBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::IntContainerConstIter AncientBooks::BookBase::GetAuthorEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::CharacterContainer AncientBooks::BookBase::GetAuthor(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取映射值。"s))
}

AncientBooks::BookBase::StringContainer AncientBooks::BookBase::GetAuthorNotes() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAuthorNotesCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

System::String AncientBooks::BookBase::GetAuthorNotes(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::StringContainerConstIter AncientBooks::BookBase::GetAuthorNotesBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::StringContainerConstIter AncientBooks::BookBase::GetAuthorNotesEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::IntContainer AncientBooks::BookBase::GetAnnotator() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAnnotatorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAnnotator(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::IntContainerConstIter AncientBooks::BookBase::GetAnnotatorBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::IntContainerConstIter AncientBooks::BookBase::GetAnnotatorEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::CharacterContainer AncientBooks::BookBase::GetAnnotator(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取映射值。"s))
}

AncientBooks::BookBase::StringContainer AncientBooks::BookBase::GetAnnotateNotes() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAnnotateNotesCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

System::String AncientBooks::BookBase::GetAnnotateNotes(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::StringContainerConstIter AncientBooks::BookBase::GetAnnotateNotesBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::StringContainerConstIter AncientBooks::BookBase::GetAnnotateNotesEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::IntContainer AncientBooks::BookBase::GetCountry() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetCountryCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetCountry(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::IntContainerConstIter AncientBooks::BookBase::GetCountryBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::IntContainerConstIter AncientBooks::BookBase::GetCountryEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::CountryContainer AncientBooks::BookBase::GetCountry(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取映射值。"s))
}

AncientBooks::BookBase::IntContainer AncientBooks::BookBase::GetPerson() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetPersonCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetPerson(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::IntContainerConstIter AncientBooks::BookBase::GetPersonBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::IntContainerConstIter AncientBooks::BookBase::GetPersonEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::CharacterContainer AncientBooks::BookBase::GetPerson(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取映射值。"s))
}

AncientBooks::BookBase::StringContainer AncientBooks::BookBase::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

System::String AncientBooks::BookBase::GetUnansweredQuestion(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::StringContainerConstIter AncientBooks::BookBase::GetUnansweredQuestionBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

AncientBooks::BookBase::StringContainerConstIter AncientBooks::BookBase::GetUnansweredQuestionEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

