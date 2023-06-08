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

std::shared_ptr<const AncientBooks::GenusMappingType> AncientBooks::BookBase::GetGenus(MAYBE_UNUSED const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取映射值。"s))
}

System::String AncientBooks::BookBase::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取字符串。"s))
}

std::vector<System::String> AncientBooks::BookBase::GetAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

System::String AncientBooks::BookBase::GetAlias(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::BookBase::GetAliasBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::BookBase::GetAliasEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetVolume() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

std::vector<int> AncientBooks::BookBase::GetAuthor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAuthorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAuthor(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::BookBase::GetAuthorBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::BookBase::GetAuthorEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<System::String> AncientBooks::BookBase::GetAuthorDescribe() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAuthorDescribeCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

System::String AncientBooks::BookBase::GetAuthorDescribe(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::BookBase::GetAuthorDescribeBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::BookBase::GetAuthorDescribeEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<int> AncientBooks::BookBase::GetAnnotator() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAnnotatorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAnnotator(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::BookBase::GetAnnotatorBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::BookBase::GetAnnotatorEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<System::String> AncientBooks::BookBase::GetAnnotateDescribe() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetAnnotateDescribeCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

System::String AncientBooks::BookBase::GetAnnotateDescribe(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::BookBase::GetAnnotateDescribeBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::BookBase::GetAnnotateDescribeEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<int> AncientBooks::BookBase::GetCountry() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetCountryCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetCountry(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::BookBase::GetCountryBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::BookBase::GetCountryEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<int> AncientBooks::BookBase::GetPerson() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetPersonCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetPerson(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::BookBase::GetPersonBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<int>::const_iterator AncientBooks::BookBase::GetPersonEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<System::String> AncientBooks::BookBase::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

int AncientBooks::BookBase::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

System::String AncientBooks::BookBase::GetUnansweredQuestion(MAYBE_UNUSED int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::BookBase::GetUnansweredQuestionBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

std::vector<System::String>::const_iterator AncientBooks::BookBase::GetUnansweredQuestionEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("book表基类不允许获取数组。"s))
}

