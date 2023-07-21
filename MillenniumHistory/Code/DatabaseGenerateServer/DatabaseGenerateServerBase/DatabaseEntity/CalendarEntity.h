/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_CALENDAR_ENTITY_H
#define DATABASE_ENTITY_CALENDAR_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class CalendarEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = CalendarEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static CalendarEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        explicit CalendarEntity(const BasisDatabaseManager& entity);
        CalendarEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int32 GetId() const noexcept;
        NODISCARD Database::Traits::String GetName() const;
        NODISCARD Database::Traits::StringArray GetAlias() const;
        NODISCARD Database::Traits::Int32Array GetSource() const;
        NODISCARD Database::Traits::String GetPublication() const;
        NODISCARD Database::Traits::Int32Array GetCreator() const;
        NODISCARD Database::Traits::Int32 GetFormulate() const noexcept;
        NODISCARD Database::Traits::Int32 GetCountry() const noexcept;
        NODISCARD Database::Traits::Int32 GetBegin() const noexcept;
        NODISCARD Database::Traits::Int32 GetEnd() const noexcept;
        NODISCARD Database::Traits::Int32 GetAgainBegin() const noexcept;
        NODISCARD Database::Traits::Int32 GetAgainEnd() const noexcept;

        void SetId(Database::Traits::ParamType::Int32 aId);
        void SetName(Database::Traits::ParamType::String aName);
        void SetAlias(Database::Traits::ParamType::StringArray aAlias);
        void SetSource(Database::Traits::ParamType::Int32Array aSource);
        void SetPublication(Database::Traits::ParamType::String aPublication);
        void SetCreator(Database::Traits::ParamType::Int32Array aCreator);
        void SetFormulate(Database::Traits::ParamType::Int32 aFormulate);
        void SetCountry(Database::Traits::ParamType::Int32 aCountry);
        void SetBegin(Database::Traits::ParamType::Int32 aBegin);
        void SetEnd(Database::Traits::ParamType::Int32 aEnd);
        void SetAgainBegin(Database::Traits::ParamType::Int32 aAgainBegin);
        void SetAgainEnd(Database::Traits::ParamType::Int32 aAgainEnd);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "calendar" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view nameDescribe{ "name" };
        static constexpr std::string_view aliasDescribe{ "alias" };
        static constexpr std::string_view sourceDescribe{ "source" };
        static constexpr std::string_view publicationDescribe{ "publication" };
        static constexpr std::string_view creatorDescribe{ "creator" };
        static constexpr std::string_view formulateDescribe{ "formulate" };
        static constexpr std::string_view countryDescribe{ "country" };
        static constexpr std::string_view beginDescribe{ "begin" };
        static constexpr std::string_view endDescribe{ "end" };
        static constexpr std::string_view againBeginDescribe{ "againBegin" };
        static constexpr std::string_view againEndDescribe{ "againEnd" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id);

    private:
        Database::Entity<idDescribe, DataType::Int32, IndexType::Key> id;
        Database::Entity<nameDescribe, DataType::String> name;
        Database::Entity<aliasDescribe, DataType::StringArray> alias;
        Database::Entity<sourceDescribe, DataType::Int32Array> source;
        Database::Entity<publicationDescribe, DataType::String> publication;
        Database::Entity<creatorDescribe, DataType::Int32Array> creator;
        Database::Entity<formulateDescribe, DataType::Int32> formulate;
        Database::Entity<countryDescribe, DataType::Int32> country;
        Database::Entity<beginDescribe, DataType::Int32> begin;
        Database::Entity<endDescribe, DataType::Int32> end;
        Database::Entity<againBeginDescribe, DataType::Int32> againBegin;
        Database::Entity<againEndDescribe, DataType::Int32> againEnd;
    };
}

#endif  // DATABASE_ENTITY_CALENDAR_ENTITY_H