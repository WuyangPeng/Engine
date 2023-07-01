///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/30 23:23)

#ifndef DATABASE_GENERATE_SERVER_BASE_DATABASE_ENTITY_ARTICLE_ENTITY_H
#define DATABASE_GENERATE_SERVER_BASE_DATABASE_ENTITY_ARTICLE_ENTITY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace AncientBooks
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
        explicit ArticleEntity(const BasisDatabaseManager& entity);
        ArticleEntity(WrappersStrategy wrappersStrategy,
                      boost::call_traits<Database::Traits::Int64>::param_type id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int64 GetId() const noexcept;
        NODISCARD Database::Traits::Int32 GetVersion() const noexcept;
        NODISCARD Database::Traits::Int32 GetChapter() const noexcept;
        NODISCARD Database::Traits::String GetChapterName() const;
        NODISCARD Database::Traits::Int32 GetVolume() const noexcept;
        NODISCARD Database::Traits::Int32 GetChapterVolume() const noexcept;
        NODISCARD Database::Traits::Int32Array GetOtherAuthor() const;
        NODISCARD Database::Traits::StringArray GetAuthorDescribe() const;
        NODISCARD Database::Traits::String GetTitle() const;
        NODISCARD Database::Traits::String GetAbbreviation() const;
        NODISCARD Database::Traits::String GetDirectory() const;

        void SetVersion(boost::call_traits<Database::Traits::Int32>::param_type aVersion);
        void SetChapter(boost::call_traits<Database::Traits::Int32>::param_type aChapter);
        void SetChapterName(boost::call_traits<Database::Traits::String>::param_type aChapterName);
        void SetVolume(boost::call_traits<Database::Traits::Int32>::param_type aVolume);
        void SetChapterVolume(boost::call_traits<Database::Traits::Int32>::param_type aChapterVolume);
        void SetOtherAuthor(boost::call_traits<Database::Traits::Int32Array>::param_type aOtherAuthor);
        void SetAuthorDescribe(boost::call_traits<Database::Traits::StringArray>::param_type aAuthorDescribe);
        void SetTitle(boost::call_traits<Database::Traits::String>::param_type aTitle);
        void SetAbbreviation(boost::call_traits<Database::Traits::String>::param_type aAbbreviation);
        void SeDirectory(boost::call_traits<Database::Traits::String>::param_type aDirectory);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy,
                                                        boost::call_traits<Database::Traits::Int64>::param_type id);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "UserChapter" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view versionDescribe{ "version" };
        static constexpr std::string_view chapterDescribe{ "chapter" };
        static constexpr std::string_view chapterNameDescribe{ "chapterName" };
        static constexpr std::string_view volumeDescribe{ "volume" };
        static constexpr std::string_view chapterVolumeDescribe{ "chapterVolume" };
        static constexpr std::string_view otherAuthorDescribe{ "otherAuthor" };
        static constexpr std::string_view authorDescribeDescribe{ "authorDescribe" };
        static constexpr std::string_view titleDescribe{ "title" };
        static constexpr std::string_view abbreviationDescribe{ "abbreviation" };
        static constexpr std::string_view directoryDescribe{ "directory" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(boost::call_traits<Database::Traits::Int64>::param_type id);

    private:
        Database::Entity<idDescribe, DataType::Int64, IndexType::Key> id;
        Database::Entity<versionDescribe, DataType::Int32> version;
        Database::Entity<chapterDescribe, DataType::Int32> chapter;
        Database::Entity<chapterNameDescribe, DataType::String> chapterName;
        Database::Entity<volumeDescribe, DataType::Int32> volume;
        Database::Entity<chapterVolumeDescribe, DataType::Int32> chapterVolume;
        Database::Entity<chapterVolumeDescribe, DataType::Int32Array> otherAuthor;
        Database::Entity<chapterVolumeDescribe, DataType::StringArray> authorDescribe;
        Database::Entity<chapterVolumeDescribe, DataType::String> title;
        Database::Entity<chapterVolumeDescribe, DataType::String> abbreviation;
        Database::Entity<chapterVolumeDescribe, DataType::String> directory;
    };
}

#endif  // DATABASE_GENERATE_SERVER_BASE_DATABASE_ENTITY_ARTICLE_ENTITY_H
