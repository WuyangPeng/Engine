/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_REIGN_TITLE_ENTITY_H
#define DATABASE_ENTITY_REIGN_TITLE_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class ReignTitleEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = ReignTitleEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static ReignTitleEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id);
        explicit ReignTitleEntity(const BasisDatabaseManager& entity);
        ReignTitleEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int64 GetId() const noexcept;
        NODISCARD Database::Traits::String GetName() const;
        NODISCARD Database::Traits::Int32Array GetEmperor() const;
        NODISCARD Database::Traits::Int32 GetSerial() const noexcept;
        NODISCARD Database::Traits::Int32 GetBeginYear() const noexcept;
        NODISCARD Database::Traits::Int32 GetBeginMonth() const noexcept;
        NODISCARD Database::Traits::Int32 GetBeginSexagenaryCycle() const noexcept;
        NODISCARD Database::Traits::Int32 GetBeginDay() const noexcept;
        NODISCARD Database::Traits::Int32 GetEndYear() const noexcept;
        NODISCARD Database::Traits::Int32 GetEndMonth() const noexcept;
        NODISCARD Database::Traits::Int32 GetEndSexagenaryCycle() const noexcept;
        NODISCARD Database::Traits::Int32 GetEndDay() const noexcept;

        void SetId(Database::Traits::ParamType::Int64 aId);
        void SetName(Database::Traits::ParamType::String aName);
        void SetEmperor(Database::Traits::ParamType::Int32Array aEmperor);
        void SetSerial(Database::Traits::ParamType::Int32 aSerial);
        void SetBeginYear(Database::Traits::ParamType::Int32 aBeginYear);
        void SetBeginMonth(Database::Traits::ParamType::Int32 aBeginMonth);
        void SetBeginSexagenaryCycle(Database::Traits::ParamType::Int32 aBeginSexagenaryCycle);
        void SetBeginDay(Database::Traits::ParamType::Int32 aBeginDay);
        void SetEndYear(Database::Traits::ParamType::Int32 aEndYear);
        void SetEndMonth(Database::Traits::ParamType::Int32 aEndMonth);
        void SetEndSexagenaryCycle(Database::Traits::ParamType::Int32 aEndSexagenaryCycle);
        void SetEndDay(Database::Traits::ParamType::Int32 aEndDay);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "reignTitle" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view nameDescribe{ "name" };
        static constexpr std::string_view emperorDescribe{ "emperor" };
        static constexpr std::string_view serialDescribe{ "serial" };
        static constexpr std::string_view beginYearDescribe{ "beginYear" };
        static constexpr std::string_view beginMonthDescribe{ "beginMonth" };
        static constexpr std::string_view beginSexagenaryCycleDescribe{ "beginSexagenaryCycle" };
        static constexpr std::string_view beginDayDescribe{ "beginDay" };
        static constexpr std::string_view endYearDescribe{ "endYear" };
        static constexpr std::string_view endMonthDescribe{ "endMonth" };
        static constexpr std::string_view endSexagenaryCycleDescribe{ "endSexagenaryCycle" };
        static constexpr std::string_view endDayDescribe{ "endDay" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int64 id);

    private:
        Database::Entity<idDescribe, DataType::Int64, IndexType::Key> id;
        Database::Entity<nameDescribe, DataType::String> name;
        Database::Entity<emperorDescribe, DataType::Int32Array> emperor;
        Database::Entity<serialDescribe, DataType::Int32> serial;
        Database::Entity<beginYearDescribe, DataType::Int32> beginYear;
        Database::Entity<beginMonthDescribe, DataType::Int32> beginMonth;
        Database::Entity<beginSexagenaryCycleDescribe, DataType::Int32> beginSexagenaryCycle;
        Database::Entity<beginDayDescribe, DataType::Int32> beginDay;
        Database::Entity<endYearDescribe, DataType::Int32> endYear;
        Database::Entity<endMonthDescribe, DataType::Int32> endMonth;
        Database::Entity<endSexagenaryCycleDescribe, DataType::Int32> endSexagenaryCycle;
        Database::Entity<endDayDescribe, DataType::Int32> endDay;
    };
}

#endif  // DATABASE_ENTITY_REIGN_TITLE_ENTITY_H