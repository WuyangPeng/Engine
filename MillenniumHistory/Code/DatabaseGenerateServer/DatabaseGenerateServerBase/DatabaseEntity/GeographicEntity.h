/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef DATABASE_ENTITY_GEOGRAPHIC_ENTITY_H
#define DATABASE_ENTITY_GEOGRAPHIC_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class GeographicEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = GeographicEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static GeographicEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        explicit GeographicEntity(const BasisDatabaseManager& entity);
        GeographicEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int32 GetId() const noexcept;
        NODISCARD Database::Traits::String GetName() const;

        void SetId(Database::Traits::ParamType::Int32 aId);
        void SetName(Database::Traits::ParamType::String aName);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "geographic" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view nameDescribe{ "name" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id);

    private:
        Database::Entity<idDescribe, DataType::Int32, IndexType::Key> id;
        Database::Entity<nameDescribe, DataType::String> name;
    };
}

#endif  // DATABASE_ENTITY_GEOGRAPHIC_ENTITY_H