/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_YEAR_ENTITY_H
#define DATABASE_ENTITY_YEAR_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class YearEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = YearEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static YearEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        explicit YearEntity(const BasisDatabaseManager& entity);
        YearEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int32 GetId() const noexcept;
        NODISCARD Database::Traits::String GetName() const;
        NODISCARD Database::Traits::Int32 GetSexagenaryCycle() const noexcept;
        NODISCARD Database::Traits::Int64 GetReignTitle() const noexcept;
        NODISCARD Database::Traits::Int32 GetYear() const noexcept;
        NODISCARD Database::Traits::Int64Array GetUnorthodoxReignTitle() const;
        NODISCARD Database::Traits::Int32Array GetUnorthodoxYear() const;

        void SetId(Database::Traits::ParamType::Int32 aId);
        void SetName(Database::Traits::ParamType::String aName);
        void SetSexagenaryCycle(Database::Traits::ParamType::Int32 aSexagenaryCycle);
        void SetReignTitle(Database::Traits::ParamType::Int64 aReignTitle);
        void SetYear(Database::Traits::ParamType::Int32 aYear);
        void SetUnorthodoxReignTitle(Database::Traits::ParamType::Int64Array aUnorthodoxReignTitle);
        void SetUnorthodoxYear(Database::Traits::ParamType::Int32Array aUnorthodoxYear);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        NODISCARD static BasisDatabaseManager GetSelectAll(Database::WrappersStrategy wrappersStrategy);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "year" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view nameDescribe{ "name" };
        static constexpr std::string_view sexagenaryCycleDescribe{ "sexagenaryCycle" };
        static constexpr std::string_view reignTitleDescribe{ "reignTitle" };
        static constexpr std::string_view yearDescribe{ "year" };
        static constexpr std::string_view unorthodoxReignTitleDescribe{ "unorthodoxReignTitle" };
        static constexpr std::string_view unorthodoxYearDescribe{ "unorthodoxYear" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id);

    private:
        Database::Entity<idDescribe, DataType::Int32, IndexType::Key> id;
        Database::Entity<nameDescribe, DataType::String> name;
        Database::Entity<sexagenaryCycleDescribe, DataType::Int32> sexagenaryCycle;
        Database::Entity<reignTitleDescribe, DataType::Int64> reignTitle;
        Database::Entity<yearDescribe, DataType::Int32> year;
        Database::Entity<unorthodoxReignTitleDescribe, DataType::Int64Array> unorthodoxReignTitle;
        Database::Entity<unorthodoxYearDescribe, DataType::Int32Array> unorthodoxYear;
    };
}

#endif  // DATABASE_ENTITY_YEAR_ENTITY_H