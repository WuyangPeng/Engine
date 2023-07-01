/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef ANCIENT_BOOKS_CHARACTER_H
#define ANCIENT_BOOKS_CHARACTER_H

#include "CoreTools/CoreToolsDll.h"

#include "AncientBooksFwd.h"
#include "CharacterBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AncientBooks
{
    class Character final : public CharacterBase
    {
    public:
        using ClassType = Character;
        using ParentType = CharacterBase;

        using CSVRow = CoreTools::CSVRow;

    public:
        explicit Character(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetCountry() const noexcept override;
        NODISCARD ConstCountrySharedPtr GetCountry(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetIdentity() const noexcept override;
        NODISCARD ConstIdentitySharedPtr GetIdentity(const AncientBooksContainer& csvContainer) const override;

        NODISCARD String GetFamily() const override;

        NODISCARD String GetName() const override;

        NODISCARD String GetFullName() const override;

        NODISCARD StringContainer GetAlias() const override;
        NODISCARD int GetAliasCount() const override;
        NODISCARD String GetAlias(int index) const override;
        NODISCARD StringContainerConstIter GetAliasBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetAliasEnd() const noexcept override;

        NODISCARD String GetStyleName() const override;

        NODISCARD int GetSex() const noexcept override;

        NODISCARD int GetFather() const noexcept override;
        NODISCARD ConstCharacterSharedPtr GetFather(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetMother() const noexcept override;
        NODISCARD ConstCharacterSharedPtr GetMother(const AncientBooksContainer& csvContainer) const override;

        NODISCARD IntContainer GetFosterFather() const override;
        NODISCARD int GetFosterFatherCount() const override;
        NODISCARD int GetFosterFather(int index) const override;
        NODISCARD IntContainerConstIter GetFosterFatherBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetFosterFatherEnd() const noexcept override;
        NODISCARD CharacterContainer GetFosterFather(const AncientBooksContainer& csvContainer) const override;

        NODISCARD IntContainer GetFosterMother() const override;
        NODISCARD int GetFosterMotherCount() const override;
        NODISCARD int GetFosterMother(int index) const override;
        NODISCARD IntContainerConstIter GetFosterMotherBegin() const noexcept override;
        NODISCARD IntContainerConstIter GetFosterMotherEnd() const noexcept override;
        NODISCARD CharacterContainer GetFosterMother(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBirthYear() const noexcept override;
        NODISCARD ConstYearSharedPtr GetBirthYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBirthMonth() const noexcept override;
        NODISCARD ConstMonthSharedPtr GetBirthMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBirthSexagenaryCycle() const noexcept override;
        NODISCARD ConstSexagenaryCycleSharedPtr GetBirthSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBirthDay() const noexcept override;
        NODISCARD ConstDaySharedPtr GetBirthDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetDeathYear() const noexcept override;
        NODISCARD ConstYearSharedPtr GetDeathYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetDeathMonth() const noexcept override;
        NODISCARD ConstMonthSharedPtr GetDeathMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetDeathSexagenaryCycle() const noexcept override;
        NODISCARD ConstSexagenaryCycleSharedPtr GetDeathSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetDeathDay() const noexcept override;
        NODISCARD ConstDaySharedPtr GetDeathDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD StringContainer GetUnansweredQuestion() const override;
        NODISCARD int GetUnansweredQuestionCount() const override;
        NODISCARD String GetUnansweredQuestion(int index) const override;
        NODISCARD StringContainerConstIter GetUnansweredQuestionBegin() const noexcept override;
        NODISCARD StringContainerConstIter GetUnansweredQuestionEnd() const noexcept override;

    private:
        int id;  // Id
        int country;  // ����
        int identity;  // ���
        String family;  // ��
        String name;  // ��
        String fullName;  // ȫ��
        StringContainer alias;  // �e��
        String styleName;  // ��
        int sex;  // �Մe
        int father;  // ��
        int mother;  // ĸ
        IntContainer fosterFather;  // �B��
        IntContainer fosterMother;  // �Bĸ
        int birthYear;  // ������
        int birthMonth;  // ������
        int birthSexagenaryCycle;  // ������֧��
        int birthDay;  // ������
        int deathYear;  // ������
        int deathMonth;  // ������
        int deathSexagenaryCycle;  // ������֧��
        int deathDay;  // ������
        StringContainer unansweredQuestion;  // ����
    };
}

#endif  // ANCIENT_BOOKS_CHARACTER_H
