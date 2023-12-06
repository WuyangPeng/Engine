/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_CHARACTER_ENTITY_H
#define DATABASE_ENTITY_CHARACTER_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class CharacterEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = CharacterEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static CharacterEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        explicit CharacterEntity(const BasisDatabaseManager& entity);
        CharacterEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int32 GetId() const noexcept;
        NODISCARD Database::Traits::Int32 GetCountry() const noexcept;
        NODISCARD Database::Traits::Int32 GetIdentity() const noexcept;
        NODISCARD Database::Traits::String GetFamily() const;
        NODISCARD Database::Traits::String GetName() const;
        NODISCARD Database::Traits::String GetFullName() const;
        NODISCARD Database::Traits::StringArray GetAlias() const;
        NODISCARD Database::Traits::String GetStyleName() const;
        NODISCARD Database::Traits::Int32 GetSex() const noexcept;
        NODISCARD Database::Traits::Int32 GetFather() const noexcept;
        NODISCARD Database::Traits::Int32 GetMother() const noexcept;
        NODISCARD Database::Traits::Int32Array GetFosterFather() const;
        NODISCARD Database::Traits::Int32Array GetFosterMother() const;
        NODISCARD Database::Traits::Int32 GetBirthYear() const noexcept;
        NODISCARD Database::Traits::Int32 GetBirthMonth() const noexcept;
        NODISCARD Database::Traits::Int32 GetBirthSexagenaryCycle() const noexcept;
        NODISCARD Database::Traits::Int32 GetBirthDay() const noexcept;
        NODISCARD Database::Traits::Int32 GetDeathYear() const noexcept;
        NODISCARD Database::Traits::Int32 GetDeathMonth() const noexcept;
        NODISCARD Database::Traits::Int32 GetDeathSexagenaryCycle() const noexcept;
        NODISCARD Database::Traits::Int32 GetDeathDay() const noexcept;
        NODISCARD Database::Traits::StringArray GetUnansweredQuestion() const;

        void SetId(Database::Traits::ParamType::Int32 aId);
        void SetCountry(Database::Traits::ParamType::Int32 aCountry);
        void SetIdentity(Database::Traits::ParamType::Int32 aIdentity);
        void SetFamily(Database::Traits::ParamType::String aFamily);
        void SetName(Database::Traits::ParamType::String aName);
        void SetFullName(Database::Traits::ParamType::String aFullName);
        void SetAlias(Database::Traits::ParamType::StringArray aAlias);
        void SetStyleName(Database::Traits::ParamType::String aStyleName);
        void SetSex(Database::Traits::ParamType::Int32 aSex);
        void SetFather(Database::Traits::ParamType::Int32 aFather);
        void SetMother(Database::Traits::ParamType::Int32 aMother);
        void SetFosterFather(Database::Traits::ParamType::Int32Array aFosterFather);
        void SetFosterMother(Database::Traits::ParamType::Int32Array aFosterMother);
        void SetBirthYear(Database::Traits::ParamType::Int32 aBirthYear);
        void SetBirthMonth(Database::Traits::ParamType::Int32 aBirthMonth);
        void SetBirthSexagenaryCycle(Database::Traits::ParamType::Int32 aBirthSexagenaryCycle);
        void SetBirthDay(Database::Traits::ParamType::Int32 aBirthDay);
        void SetDeathYear(Database::Traits::ParamType::Int32 aDeathYear);
        void SetDeathMonth(Database::Traits::ParamType::Int32 aDeathMonth);
        void SetDeathSexagenaryCycle(Database::Traits::ParamType::Int32 aDeathSexagenaryCycle);
        void SetDeathDay(Database::Traits::ParamType::Int32 aDeathDay);
        void SetUnansweredQuestion(Database::Traits::ParamType::StringArray aUnansweredQuestion);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        NODISCARD static BasisDatabaseManager GetSelectAll(Database::WrappersStrategy wrappersStrategy);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "character" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view countryDescribe{ "country" };
        static constexpr std::string_view identityDescribe{ "identity" };
        static constexpr std::string_view familyDescribe{ "family" };
        static constexpr std::string_view nameDescribe{ "name" };
        static constexpr std::string_view fullNameDescribe{ "fullName" };
        static constexpr std::string_view aliasDescribe{ "alias" };
        static constexpr std::string_view styleNameDescribe{ "styleName" };
        static constexpr std::string_view sexDescribe{ "sex" };
        static constexpr std::string_view fatherDescribe{ "father" };
        static constexpr std::string_view motherDescribe{ "mother" };
        static constexpr std::string_view fosterFatherDescribe{ "fosterFather" };
        static constexpr std::string_view fosterMotherDescribe{ "fosterMother" };
        static constexpr std::string_view birthYearDescribe{ "birthYear" };
        static constexpr std::string_view birthMonthDescribe{ "birthMonth" };
        static constexpr std::string_view birthSexagenaryCycleDescribe{ "birthSexagenaryCycle" };
        static constexpr std::string_view birthDayDescribe{ "birthDay" };
        static constexpr std::string_view deathYearDescribe{ "deathYear" };
        static constexpr std::string_view deathMonthDescribe{ "deathMonth" };
        static constexpr std::string_view deathSexagenaryCycleDescribe{ "deathSexagenaryCycle" };
        static constexpr std::string_view deathDayDescribe{ "deathDay" };
        static constexpr std::string_view unansweredQuestionDescribe{ "unansweredQuestion" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id);

    private:
        Database::Entity<idDescribe, DataType::Int32, IndexType::Key> id;
        Database::Entity<countryDescribe, DataType::Int32> country;
        Database::Entity<identityDescribe, DataType::Int32> identity;
        Database::Entity<familyDescribe, DataType::String> family;
        Database::Entity<nameDescribe, DataType::String> name;
        Database::Entity<fullNameDescribe, DataType::String> fullName;
        Database::Entity<aliasDescribe, DataType::StringArray> alias;
        Database::Entity<styleNameDescribe, DataType::String> styleName;
        Database::Entity<sexDescribe, DataType::Int32> sex;
        Database::Entity<fatherDescribe, DataType::Int32> father;
        Database::Entity<motherDescribe, DataType::Int32> mother;
        Database::Entity<fosterFatherDescribe, DataType::Int32Array> fosterFather;
        Database::Entity<fosterMotherDescribe, DataType::Int32Array> fosterMother;
        Database::Entity<birthYearDescribe, DataType::Int32> birthYear;
        Database::Entity<birthMonthDescribe, DataType::Int32> birthMonth;
        Database::Entity<birthSexagenaryCycleDescribe, DataType::Int32> birthSexagenaryCycle;
        Database::Entity<birthDayDescribe, DataType::Int32> birthDay;
        Database::Entity<deathYearDescribe, DataType::Int32> deathYear;
        Database::Entity<deathMonthDescribe, DataType::Int32> deathMonth;
        Database::Entity<deathSexagenaryCycleDescribe, DataType::Int32> deathSexagenaryCycle;
        Database::Entity<deathDayDescribe, DataType::Int32> deathDay;
        Database::Entity<unansweredQuestionDescribe, DataType::StringArray> unansweredQuestion;
    };
}

#endif  // DATABASE_ENTITY_CHARACTER_ENTITY_H