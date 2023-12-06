/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_ARTICLE_ENTITY_H
#define DATABASE_ENTITY_ARTICLE_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class ArticleEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = ArticleEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static ArticleEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id);
        explicit ArticleEntity(const BasisDatabaseManager& entity);
        ArticleEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int64 GetId() const noexcept;
        NODISCARD Database::Traits::Int32 GetVersion() const noexcept;
        NODISCARD Database::Traits::Int32 GetChapter() const noexcept;
        NODISCARD Database::Traits::String GetChapterName() const;
        NODISCARD Database::Traits::Int32 GetChapterVolume() const noexcept;
        NODISCARD Database::Traits::Int32Array GetOtherAuthor() const;
        NODISCARD Database::Traits::StringArray GetAuthorNotes() const;
        NODISCARD Database::Traits::String GetTitle() const;
        NODISCARD Database::Traits::String GetAbbreviation() const;
        NODISCARD Database::Traits::String GetDirectory() const;

        void SetId(Database::Traits::ParamType::Int64 aId);
        void SetVersion(Database::Traits::ParamType::Int32 aVersion);
        void SetChapter(Database::Traits::ParamType::Int32 aChapter);
        void SetChapterName(Database::Traits::ParamType::String aChapterName);
        void SetChapterVolume(Database::Traits::ParamType::Int32 aChapterVolume);
        void SetOtherAuthor(Database::Traits::ParamType::Int32Array aOtherAuthor);
        void SetAuthorNotes(Database::Traits::ParamType::StringArray aAuthorNotes);
        void SetTitle(Database::Traits::ParamType::String aTitle);
        void SetAbbreviation(Database::Traits::ParamType::String aAbbreviation);
        void SetDirectory(Database::Traits::ParamType::String aDirectory);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 id);
        NODISCARD static BasisDatabaseManager GetSelectAll(Database::WrappersStrategy wrappersStrategy);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "article" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view versionDescribe{ "version" };
        static constexpr std::string_view chapterDescribe{ "chapter" };
        static constexpr std::string_view chapterNameDescribe{ "chapterName" };
        static constexpr std::string_view chapterVolumeDescribe{ "chapterVolume" };
        static constexpr std::string_view otherAuthorDescribe{ "otherAuthor" };
        static constexpr std::string_view authorNotesDescribe{ "authorNotes" };
        static constexpr std::string_view titleDescribe{ "title" };
        static constexpr std::string_view abbreviationDescribe{ "abbreviation" };
        static constexpr std::string_view directoryDescribe{ "directory" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int64 id);

    private:
        Database::Entity<idDescribe, DataType::Int64, IndexType::Key> id;
        Database::Entity<versionDescribe, DataType::Int32> version;
        Database::Entity<chapterDescribe, DataType::Int32> chapter;
        Database::Entity<chapterNameDescribe, DataType::String> chapterName;
        Database::Entity<chapterVolumeDescribe, DataType::Int32> chapterVolume;
        Database::Entity<otherAuthorDescribe, DataType::Int32Array> otherAuthor;
        Database::Entity<authorNotesDescribe, DataType::StringArray> authorNotes;
        Database::Entity<titleDescribe, DataType::String> title;
        Database::Entity<abbreviationDescribe, DataType::String> abbreviation;
        Database::Entity<directoryDescribe, DataType::String> directory;
    };
}

#endif  // DATABASE_ENTITY_ARTICLE_ENTITY_H