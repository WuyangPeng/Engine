/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_IMPERIAL_COURT_ENTITY_H
#define DATABASE_ENTITY_IMPERIAL_COURT_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class ImperialCourtEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = ImperialCourtEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static ImperialCourtEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        explicit ImperialCourtEntity(const BasisDatabaseManager& entity);
        ImperialCourtEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int32 GetId() const noexcept;
        NODISCARD Database::Traits::String GetCategory() const;
        NODISCARD Database::Traits::String GetBook() const;
        NODISCARD Database::Traits::Int32 GetBegin() const noexcept;
        NODISCARD Database::Traits::Int32 GetEnd() const noexcept;

        void SetId(Database::Traits::ParamType::Int32 aId);
        void SetCategory(Database::Traits::ParamType::String aCategory);
        void SetBook(Database::Traits::ParamType::String aBook);
        void SetBegin(Database::Traits::ParamType::Int32 aBegin);
        void SetEnd(Database::Traits::ParamType::Int32 aEnd);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        NODISCARD static BasisDatabaseManager GetSelectAll(Database::WrappersStrategy wrappersStrategy);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "imperialCourt" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view categoryDescribe{ "category" };
        static constexpr std::string_view bookDescribe{ "book" };
        static constexpr std::string_view beginDescribe{ "begin" };
        static constexpr std::string_view endDescribe{ "end" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id);

    private:
        Database::Entity<idDescribe, DataType::Int32, IndexType::Key> id;
        Database::Entity<categoryDescribe, DataType::String> category;
        Database::Entity<bookDescribe, DataType::String> book;
        Database::Entity<beginDescribe, DataType::Int32> begin;
        Database::Entity<endDescribe, DataType::Int32> end;
    };
}

#endif  // DATABASE_ENTITY_IMPERIAL_COURT_ENTITY_H