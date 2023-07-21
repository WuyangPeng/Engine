/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_VERSION_ENTITY_H
#define DATABASE_ENTITY_VERSION_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class VersionEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = VersionEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static VersionEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        explicit VersionEntity(const BasisDatabaseManager& entity);
        VersionEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int32 GetId() const noexcept;
        NODISCARD Database::Traits::Int32 GetBook() const noexcept;
        NODISCARD Database::Traits::Int32 GetSource() const noexcept;
        NODISCARD Database::Traits::String GetSourceName() const;
        NODISCARD Database::Traits::Int32 GetCountry() const noexcept;
        NODISCARD Database::Traits::Int64 GetReignTitle() const noexcept;
        NODISCARD Database::Traits::Int32 GetYear() const noexcept;
        NODISCARD Database::Traits::String GetVersion() const;
        NODISCARD Database::Traits::Int32Array GetOtherAuthor() const;
        NODISCARD Database::Traits::StringArray GetAuthorNotes() const;

        void SetId(Database::Traits::ParamType::Int32 aId);
        void SetBook(Database::Traits::ParamType::Int32 aBook);
        void SetSource(Database::Traits::ParamType::Int32 aSource);
        void SetSourceName(Database::Traits::ParamType::String aSourceName);
        void SetCountry(Database::Traits::ParamType::Int32 aCountry);
        void SetReignTitle(Database::Traits::ParamType::Int64 aReignTitle);
        void SetYear(Database::Traits::ParamType::Int32 aYear);
        void SetVersion(Database::Traits::ParamType::String aVersion);
        void SetOtherAuthor(Database::Traits::ParamType::Int32Array aOtherAuthor);
        void SetAuthorNotes(Database::Traits::ParamType::StringArray aAuthorNotes);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "version" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view bookDescribe{ "book" };
        static constexpr std::string_view sourceDescribe{ "source" };
        static constexpr std::string_view sourceNameDescribe{ "sourceName" };
        static constexpr std::string_view countryDescribe{ "country" };
        static constexpr std::string_view reignTitleDescribe{ "reignTitle" };
        static constexpr std::string_view yearDescribe{ "year" };
        static constexpr std::string_view versionDescribe{ "version" };
        static constexpr std::string_view otherAuthorDescribe{ "otherAuthor" };
        static constexpr std::string_view authorNotesDescribe{ "authorNotes" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id);

    private:
        Database::Entity<idDescribe, DataType::Int32, IndexType::Key> id;
        Database::Entity<bookDescribe, DataType::Int32> book;
        Database::Entity<sourceDescribe, DataType::Int32> source;
        Database::Entity<sourceNameDescribe, DataType::String> sourceName;
        Database::Entity<countryDescribe, DataType::Int32> country;
        Database::Entity<reignTitleDescribe, DataType::Int64> reignTitle;
        Database::Entity<yearDescribe, DataType::Int32> year;
        Database::Entity<versionDescribe, DataType::String> version;
        Database::Entity<otherAuthorDescribe, DataType::Int32Array> otherAuthor;
        Database::Entity<authorNotesDescribe, DataType::StringArray> authorNotes;
    };
}

#endif  // DATABASE_ENTITY_VERSION_ENTITY_H