/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_EMPEROR_ENTITY_H
#define DATABASE_ENTITY_EMPEROR_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class EmperorEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = EmperorEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static EmperorEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        explicit EmperorEntity(const BasisDatabaseManager& entity);
        EmperorEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int32 GetId() const noexcept;
        NODISCARD Database::Traits::Int32 GetCharacter() const noexcept;
        NODISCARD Database::Traits::String GetName() const;
        NODISCARD Database::Traits::String GetDynasticTitle() const;
        NODISCARD Database::Traits::StringArray GetDynasticTitleAlias() const;
        NODISCARD Database::Traits::String GetPosthumousTitle() const;
        NODISCARD Database::Traits::StringArray GetPosthumousTitleAlias() const;
        NODISCARD Database::Traits::Int32 GetBeginYear() const noexcept;
        NODISCARD Database::Traits::Int32 GetBeginMonth() const noexcept;
        NODISCARD Database::Traits::Int32 GetBeginSexagenaryCycle() const noexcept;
        NODISCARD Database::Traits::Int32 GetBeginDay() const noexcept;
        NODISCARD Database::Traits::Int32 GetEndYear() const noexcept;
        NODISCARD Database::Traits::Int32 GetEndMonth() const noexcept;
        NODISCARD Database::Traits::Int32 GetEndSexagenaryCycle() const noexcept;
        NODISCARD Database::Traits::Int32 GetEndDay() const noexcept;
        NODISCARD Database::Traits::Int32 GetAgainBeginYear() const noexcept;
        NODISCARD Database::Traits::Int32 GetAgainBeginMonth() const noexcept;
        NODISCARD Database::Traits::Int32 GetAgainBeginSexagenaryCycle() const noexcept;
        NODISCARD Database::Traits::Int32 GetAgainBeginDay() const noexcept;
        NODISCARD Database::Traits::Int32 GetAgainEndYear() const noexcept;
        NODISCARD Database::Traits::Int32 GetAgainEndMonth() const noexcept;
        NODISCARD Database::Traits::Int32 GetAgainEndSexagenaryCycle() const noexcept;
        NODISCARD Database::Traits::Int32 GetAgainEndDay() const noexcept;
        NODISCARD Database::Traits::StringArray GetUnansweredQuestion() const;

        void SetId(Database::Traits::ParamType::Int32 aId);
        void SetCharacter(Database::Traits::ParamType::Int32 aCharacter);
        void SetName(Database::Traits::ParamType::String aName);
        void SetDynasticTitle(Database::Traits::ParamType::String aDynasticTitle);
        void SetDynasticTitleAlias(Database::Traits::ParamType::StringArray aDynasticTitleAlias);
        void SetPosthumousTitle(Database::Traits::ParamType::String aPosthumousTitle);
        void SetPosthumousTitleAlias(Database::Traits::ParamType::StringArray aPosthumousTitleAlias);
        void SetBeginYear(Database::Traits::ParamType::Int32 aBeginYear);
        void SetBeginMonth(Database::Traits::ParamType::Int32 aBeginMonth);
        void SetBeginSexagenaryCycle(Database::Traits::ParamType::Int32 aBeginSexagenaryCycle);
        void SetBeginDay(Database::Traits::ParamType::Int32 aBeginDay);
        void SetEndYear(Database::Traits::ParamType::Int32 aEndYear);
        void SetEndMonth(Database::Traits::ParamType::Int32 aEndMonth);
        void SetEndSexagenaryCycle(Database::Traits::ParamType::Int32 aEndSexagenaryCycle);
        void SetEndDay(Database::Traits::ParamType::Int32 aEndDay);
        void SetAgainBeginYear(Database::Traits::ParamType::Int32 aAgainBeginYear);
        void SetAgainBeginMonth(Database::Traits::ParamType::Int32 aAgainBeginMonth);
        void SetAgainBeginSexagenaryCycle(Database::Traits::ParamType::Int32 aAgainBeginSexagenaryCycle);
        void SetAgainBeginDay(Database::Traits::ParamType::Int32 aAgainBeginDay);
        void SetAgainEndYear(Database::Traits::ParamType::Int32 aAgainEndYear);
        void SetAgainEndMonth(Database::Traits::ParamType::Int32 aAgainEndMonth);
        void SetAgainEndSexagenaryCycle(Database::Traits::ParamType::Int32 aAgainEndSexagenaryCycle);
        void SetAgainEndDay(Database::Traits::ParamType::Int32 aAgainEndDay);
        void SetUnansweredQuestion(Database::Traits::ParamType::StringArray aUnansweredQuestion);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "emperor" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view characterDescribe{ "character" };
        static constexpr std::string_view nameDescribe{ "name" };
        static constexpr std::string_view dynasticTitleDescribe{ "dynasticTitle" };
        static constexpr std::string_view dynasticTitleAliasDescribe{ "dynasticTitleAlias" };
        static constexpr std::string_view posthumousTitleDescribe{ "posthumousTitle" };
        static constexpr std::string_view posthumousTitleAliasDescribe{ "posthumousTitleAlias" };
        static constexpr std::string_view beginYearDescribe{ "beginYear" };
        static constexpr std::string_view beginMonthDescribe{ "beginMonth" };
        static constexpr std::string_view beginSexagenaryCycleDescribe{ "beginSexagenaryCycle" };
        static constexpr std::string_view beginDayDescribe{ "beginDay" };
        static constexpr std::string_view endYearDescribe{ "endYear" };
        static constexpr std::string_view endMonthDescribe{ "endMonth" };
        static constexpr std::string_view endSexagenaryCycleDescribe{ "endSexagenaryCycle" };
        static constexpr std::string_view endDayDescribe{ "endDay" };
        static constexpr std::string_view againBeginYearDescribe{ "againBeginYear" };
        static constexpr std::string_view againBeginMonthDescribe{ "againBeginMonth" };
        static constexpr std::string_view againBeginSexagenaryCycleDescribe{ "againBeginSexagenaryCycle" };
        static constexpr std::string_view againBeginDayDescribe{ "againBeginDay" };
        static constexpr std::string_view againEndYearDescribe{ "againEndYear" };
        static constexpr std::string_view againEndMonthDescribe{ "againEndMonth" };
        static constexpr std::string_view againEndSexagenaryCycleDescribe{ "againEndSexagenaryCycle" };
        static constexpr std::string_view againEndDayDescribe{ "againEndDay" };
        static constexpr std::string_view unansweredQuestionDescribe{ "unansweredQuestion" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id);

    private:
        Database::Entity<idDescribe, DataType::Int32, IndexType::Key> id;
        Database::Entity<characterDescribe, DataType::Int32> character;
        Database::Entity<nameDescribe, DataType::String> name;
        Database::Entity<dynasticTitleDescribe, DataType::String> dynasticTitle;
        Database::Entity<dynasticTitleAliasDescribe, DataType::StringArray> dynasticTitleAlias;
        Database::Entity<posthumousTitleDescribe, DataType::String> posthumousTitle;
        Database::Entity<posthumousTitleAliasDescribe, DataType::StringArray> posthumousTitleAlias;
        Database::Entity<beginYearDescribe, DataType::Int32> beginYear;
        Database::Entity<beginMonthDescribe, DataType::Int32> beginMonth;
        Database::Entity<beginSexagenaryCycleDescribe, DataType::Int32> beginSexagenaryCycle;
        Database::Entity<beginDayDescribe, DataType::Int32> beginDay;
        Database::Entity<endYearDescribe, DataType::Int32> endYear;
        Database::Entity<endMonthDescribe, DataType::Int32> endMonth;
        Database::Entity<endSexagenaryCycleDescribe, DataType::Int32> endSexagenaryCycle;
        Database::Entity<endDayDescribe, DataType::Int32> endDay;
        Database::Entity<againBeginYearDescribe, DataType::Int32> againBeginYear;
        Database::Entity<againBeginMonthDescribe, DataType::Int32> againBeginMonth;
        Database::Entity<againBeginSexagenaryCycleDescribe, DataType::Int32> againBeginSexagenaryCycle;
        Database::Entity<againBeginDayDescribe, DataType::Int32> againBeginDay;
        Database::Entity<againEndYearDescribe, DataType::Int32> againEndYear;
        Database::Entity<againEndMonthDescribe, DataType::Int32> againEndMonth;
        Database::Entity<againEndSexagenaryCycleDescribe, DataType::Int32> againEndSexagenaryCycle;
        Database::Entity<againEndDayDescribe, DataType::Int32> againEndDay;
        Database::Entity<unansweredQuestionDescribe, DataType::StringArray> unansweredQuestion;
    };
}

#endif  // DATABASE_ENTITY_EMPEROR_ENTITY_H