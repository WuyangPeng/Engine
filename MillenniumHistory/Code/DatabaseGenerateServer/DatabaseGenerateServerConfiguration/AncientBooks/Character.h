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

    public:
        explicit Character(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetCountry() const noexcept override;
        NODISCARD std::shared_ptr<const CountryMappingType> GetCountry(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetIdentity() const noexcept override;
        NODISCARD std::shared_ptr<const IdentityMappingType> GetIdentity(const AncientBooksContainer& csvContainer) const override;

        NODISCARD System::String GetFamily() const override;

        NODISCARD System::String GetName() const override;

        NODISCARD System::String GetFullName() const override;

        NODISCARD std::vector<System::String> GetAlias() const override;
        NODISCARD int GetAliasCount() const override;
        NODISCARD System::String GetAlias(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetAliasBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetAliasEnd() const noexcept override;

        NODISCARD System::String GetStyleName() const override;

        NODISCARD int GetSex() const noexcept override;

        NODISCARD int GetFather() const noexcept override;

        NODISCARD int GetMother() const noexcept override;

        NODISCARD std::vector<int> GetFosterFather() const override;
        NODISCARD int GetFosterFatherCount() const override;
        NODISCARD int GetFosterFather(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetFosterFatherBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetFosterFatherEnd() const noexcept override;

        NODISCARD std::vector<int> GetFosterMother() const override;
        NODISCARD int GetFosterMotherCount() const override;
        NODISCARD int GetFosterMother(int index) const override;
        NODISCARD std::vector<int>::const_iterator GetFosterMotherBegin() const noexcept override;
        NODISCARD std::vector<int>::const_iterator GetFosterMotherEnd() const noexcept override;

        NODISCARD int GetBirthYear() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetBirthYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBirthMonth() const noexcept override;
        NODISCARD std::shared_ptr<const MonthMappingType> GetBirthMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBirthSexagenaryCycle() const noexcept override;
        NODISCARD std::shared_ptr<const SexagenaryCycleMappingType> GetBirthSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetBirthDay() const noexcept override;
        NODISCARD std::shared_ptr<const DayMappingType> GetBirthDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetDeathYear() const noexcept override;
        NODISCARD std::shared_ptr<const YearMappingType> GetDeathYear(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetDeathMonth() const noexcept override;
        NODISCARD std::shared_ptr<const MonthMappingType> GetDeathMonth(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetDeathSexagenaryCycle() const noexcept override;
        NODISCARD std::shared_ptr<const SexagenaryCycleMappingType> GetDeathSexagenaryCycle(const AncientBooksContainer& csvContainer) const override;

        NODISCARD int GetDeathDay() const noexcept override;
        NODISCARD std::shared_ptr<const DayMappingType> GetDeathDay(const AncientBooksContainer& csvContainer) const override;

        NODISCARD std::vector<System::String> GetUnansweredQuestion() const override;
        NODISCARD int GetUnansweredQuestionCount() const override;
        NODISCARD System::String GetUnansweredQuestion(int index) const override;
        NODISCARD std::vector<System::String>::const_iterator GetUnansweredQuestionBegin() const noexcept override;
        NODISCARD std::vector<System::String>::const_iterator GetUnansweredQuestionEnd() const noexcept override;

    private:
        int id;  // Id
        int country;  // ����
        int identity;  // ���
        System::String family;  // ��
        System::String name;  // ��
        System::String fullName;  // ȫ��
        std::vector<System::String> alias;  // �e��
        System::String styleName;  // ��
        int sex;  // �Մe
        int father;  // ��
        int mother;  // ĸ
        std::vector<int> fosterFather;  // �B��
        std::vector<int> fosterMother;  // �Bĸ
        int birthYear;  // ������
        int birthMonth;  // ������
        int birthSexagenaryCycle;  // ������֧��
        int birthDay;  // ������
        int deathYear;  // ������
        int deathMonth;  // ������
        int deathSexagenaryCycle;  // ������֧��
        int deathDay;  // ������
        std::vector<System::String> unansweredQuestion;  // ����
    };
}

#endif  // ANCIENT_BOOKS_CHARACTER_H
