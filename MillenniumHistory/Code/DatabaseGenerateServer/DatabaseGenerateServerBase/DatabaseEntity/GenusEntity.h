/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_GENUS_ENTITY_H
#define DATABASE_ENTITY_GENUS_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class GenusEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = GenusEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static GenusEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        explicit GenusEntity(const BasisDatabaseManager& entity);
        GenusEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int32 GetId() const noexcept;
        NODISCARD Database::Traits::Int32 GetCategory() const noexcept;
        NODISCARD Database::Traits::String GetName() const;
        NODISCARD Database::Traits::Int32 GetFather() const noexcept;
        NODISCARD Database::Traits::String GetBegin() const;
        NODISCARD Database::Traits::String GetEnd() const;

        void SetId(Database::Traits::ParamType::Int32 aId);
        void SetCategory(Database::Traits::ParamType::Int32 aCategory);
        void SetName(Database::Traits::ParamType::String aName);
        void SetFather(Database::Traits::ParamType::Int32 aFather);
        void SetBegin(Database::Traits::ParamType::String aBegin);
        void SetEnd(Database::Traits::ParamType::String aEnd);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        NODISCARD static BasisDatabaseManager GetSelectAll(Database::WrappersStrategy wrappersStrategy);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "genus" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view categoryDescribe{ "category" };
        static constexpr std::string_view nameDescribe{ "name" };
        static constexpr std::string_view fatherDescribe{ "father" };
        static constexpr std::string_view beginDescribe{ "begin" };
        static constexpr std::string_view endDescribe{ "end" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id);

    private:
        Database::Entity<idDescribe, DataType::Int32, IndexType::Key> id;
        Database::Entity<categoryDescribe, DataType::Int32> category;
        Database::Entity<nameDescribe, DataType::String> name;
        Database::Entity<fatherDescribe, DataType::Int32> father;
        Database::Entity<beginDescribe, DataType::String> begin;
        Database::Entity<endDescribe, DataType::String> end;
    };
}

#endif  // DATABASE_ENTITY_GENUS_ENTITY_H