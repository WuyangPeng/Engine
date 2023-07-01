/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "VersionBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::VersionBase::VersionBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, VersionBase)

int AncientBooks::VersionBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int AncientBooks::VersionBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::VersionBase::GetBook() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::VersionBase::ConstBookSharedPtr AncientBooks::VersionBase::GetBook(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取映射值。"s))
}

int AncientBooks::VersionBase::GetSource() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

System::String AncientBooks::VersionBase::GetSourceName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取字符串。"s))
}

int AncientBooks::VersionBase::GetCountry() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::VersionBase::ConstCountrySharedPtr AncientBooks::VersionBase::GetCountry(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取映射值。"s))
}

int64_t AncientBooks::VersionBase::GetReignTitle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::VersionBase::ConstReignTitleSharedPtr AncientBooks::VersionBase::GetReignTitle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取映射值。"s))
}

int AncientBooks::VersionBase::GetYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::VersionBase::ConstYearSharedPtr AncientBooks::VersionBase::GetYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取映射值。"s))
}

System::String AncientBooks::VersionBase::GetVersion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取字符串。"s))
}

AncientBooks::VersionBase::IntContainer AncientBooks::VersionBase::GetOtherAuthor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取数组。"s))
}

int AncientBooks::VersionBase::GetOtherAuthorCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取数组。"s))
}

int AncientBooks::VersionBase::GetOtherAuthor(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取数组。"s))
}

AncientBooks::VersionBase::IntContainerConstIter AncientBooks::VersionBase::GetOtherAuthorBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取数组。"s))
}

AncientBooks::VersionBase::IntContainerConstIter AncientBooks::VersionBase::GetOtherAuthorEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取数组。"s))
}

AncientBooks::VersionBase::CharacterContainer AncientBooks::VersionBase::GetOtherAuthor(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取映射值。"s))
}

AncientBooks::VersionBase::StringContainer AncientBooks::VersionBase::GetAuthorDescribe() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取数组。"s))
}

int AncientBooks::VersionBase::GetAuthorDescribeCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取数组。"s))
}

System::String AncientBooks::VersionBase::GetAuthorDescribe(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取数组。"s))
}

AncientBooks::VersionBase::StringContainerConstIter AncientBooks::VersionBase::GetAuthorDescribeBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取数组。"s))
}

AncientBooks::VersionBase::StringContainerConstIter AncientBooks::VersionBase::GetAuthorDescribeEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("version表基类不允许获取数组。"s))
}

