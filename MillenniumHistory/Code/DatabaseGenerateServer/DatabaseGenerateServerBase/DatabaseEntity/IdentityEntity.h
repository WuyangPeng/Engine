/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef DATABASE_ENTITY_IDENTITY_ENTITY_H
#define DATABASE_ENTITY_IDENTITY_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class IdentityEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = IdentityEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static IdentityEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        explicit IdentityEntity(const BasisDatabaseManager& entity);
        IdentityEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int32 GetId() const noexcept;
        NODISCARD Database::Traits::String GetIdentity() const;

        void SetId(Database::Traits::ParamType::Int32 aId);
        void SetIdentity(Database::Traits::ParamType::String aIdentity);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        NODISCARD static BasisDatabaseManager GetSelectAll(Database::WrappersStrategy wrappersStrategy);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "identity" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view identityDescribe{ "identity" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id);

    private:
        Database::Entity<idDescribe, DataType::Int32, IndexType::Key> id;
        Database::Entity<identityDescribe, DataType::String> identity;
    };
}

#endif  // DATABASE_ENTITY_IDENTITY_ENTITY_H