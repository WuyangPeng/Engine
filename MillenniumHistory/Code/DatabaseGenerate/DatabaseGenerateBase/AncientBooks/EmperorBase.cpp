/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "EmperorBase.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AncientBooks::EmperorBase::EmperorBase(int key) noexcept
    : key{ key }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, EmperorBase)

int AncientBooks::EmperorBase::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return key;
}

int AncientBooks::EmperorBase::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

int AncientBooks::EmperorBase::GetCharacter() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstCharacterSharedPtr AncientBooks::EmperorBase::GetCharacter(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

System::String AncientBooks::EmperorBase::GetName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ�ַ�����"s))
}

System::String AncientBooks::EmperorBase::GetDynasticTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ�ַ�����"s))
}

AncientBooks::EmperorBase::StringContainer AncientBooks::EmperorBase::GetDynasticTitleAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

int AncientBooks::EmperorBase::GetDynasticTitleAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

System::String AncientBooks::EmperorBase::GetDynasticTitleAlias(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

AncientBooks::EmperorBase::StringContainerConstIter AncientBooks::EmperorBase::GetDynasticTitleAliasBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

AncientBooks::EmperorBase::StringContainerConstIter AncientBooks::EmperorBase::GetDynasticTitleAliasEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

System::String AncientBooks::EmperorBase::GetPosthumousTitle() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ�ַ�����"s))
}

AncientBooks::EmperorBase::StringContainer AncientBooks::EmperorBase::GetPosthumousTitleAlias() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

int AncientBooks::EmperorBase::GetPosthumousTitleAliasCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

System::String AncientBooks::EmperorBase::GetPosthumousTitleAlias(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

AncientBooks::EmperorBase::StringContainerConstIter AncientBooks::EmperorBase::GetPosthumousTitleAliasBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

AncientBooks::EmperorBase::StringContainerConstIter AncientBooks::EmperorBase::GetPosthumousTitleAliasEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

int AncientBooks::EmperorBase::GetBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstYearSharedPtr AncientBooks::EmperorBase::GetBeginYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstMonthSharedPtr AncientBooks::EmperorBase::GetBeginMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstSexagenaryCycleSharedPtr AncientBooks::EmperorBase::GetBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstDaySharedPtr AncientBooks::EmperorBase::GetBeginDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstYearSharedPtr AncientBooks::EmperorBase::GetEndYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstMonthSharedPtr AncientBooks::EmperorBase::GetEndMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstSexagenaryCycleSharedPtr AncientBooks::EmperorBase::GetEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstDaySharedPtr AncientBooks::EmperorBase::GetEndDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetAgainBeginYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstYearSharedPtr AncientBooks::EmperorBase::GetAgainBeginYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetAgainBeginMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstMonthSharedPtr AncientBooks::EmperorBase::GetAgainBeginMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetAgainBeginSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstSexagenaryCycleSharedPtr AncientBooks::EmperorBase::GetAgainBeginSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetAgainBeginDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstDaySharedPtr AncientBooks::EmperorBase::GetAgainBeginDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetAgainEndYear() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstYearSharedPtr AncientBooks::EmperorBase::GetAgainEndYear(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetAgainEndMonth() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstMonthSharedPtr AncientBooks::EmperorBase::GetAgainEndMonth(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetAgainEndSexagenaryCycle() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstSexagenaryCycleSharedPtr AncientBooks::EmperorBase::GetAgainEndSexagenaryCycle(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

int AncientBooks::EmperorBase::GetAgainEndDay() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return 0;
}

AncientBooks::EmperorBase::ConstDaySharedPtr AncientBooks::EmperorBase::GetAgainEndDay(const AncientBooksContainer& csvContainer) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(csvContainer);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡӳ��ֵ��"s))
}

AncientBooks::EmperorBase::StringContainer AncientBooks::EmperorBase::GetUnansweredQuestion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

int AncientBooks::EmperorBase::GetUnansweredQuestionCount() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

System::String AncientBooks::EmperorBase::GetUnansweredQuestion(int index) const
{
    USER_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(index);

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

AncientBooks::EmperorBase::StringContainerConstIter AncientBooks::EmperorBase::GetUnansweredQuestionBegin() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

AncientBooks::EmperorBase::StringContainerConstIter AncientBooks::EmperorBase::GetUnansweredQuestionEnd() const
{
    USER_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("emperor����಻�����ȡ���顣"s))
}

