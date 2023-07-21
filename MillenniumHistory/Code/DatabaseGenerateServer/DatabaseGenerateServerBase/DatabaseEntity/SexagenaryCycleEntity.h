/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_SEXAGENARY_CYCLE_ENTITY_H
#define DATABASE_ENTITY_SEXAGENARY_CYCLE_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class SexagenaryCycleEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = SexagenaryCycleEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static SexagenaryCycleEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        explicit SexagenaryCycleEntity(const BasisDatabaseManager& entity);
        SexagenaryCycleEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int32 GetId() const noexcept;
        NODISCARD Database::Traits::String GetHeavenly() const;
        NODISCARD Database::Traits::String GetBranch() const;
        NODISCARD Database::Traits::String GetName() const;

        void SetId(Database::Traits::ParamType::Int32 aId);
        void SetHeavenly(Database::Traits::ParamType::String aHeavenly);
        void SetBranch(Database::Traits::ParamType::String aBranch);
        void SetName(Database::Traits::ParamType::String aName);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "sexagenaryCycle" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view heavenlyDescribe{ "heavenly" };
        static constexpr std::string_view branchDescribe{ "branch" };
        static constexpr std::string_view nameDescribe{ "name" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id);

    private:
        Database::Entity<idDescribe, DataType::Int32, IndexType::Key> id;
        Database::Entity<heavenlyDescribe, DataType::String> heavenly;
        Database::Entity<branchDescribe, DataType::String> branch;
        Database::Entity<nameDescribe, DataType::String> name;
    };
}

#endif  // DATABASE_ENTITY_SEXAGENARY_CYCLE_ENTITY_H