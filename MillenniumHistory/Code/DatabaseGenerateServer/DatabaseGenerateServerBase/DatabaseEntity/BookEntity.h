/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_BOOK_ENTITY_H
#define DATABASE_ENTITY_BOOK_ENTITY_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class BookEntity final : public Database::DatabaseEntity
    {
    public:
        using ClassType = BookEntity;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static BookEntity Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        explicit BookEntity(const BasisDatabaseManager& entity);
        BookEntity(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int32 GetId() const noexcept;
        NODISCARD Database::Traits::Int32 GetGenus() const noexcept;
        NODISCARD Database::Traits::String GetName() const;
        NODISCARD Database::Traits::StringArray GetAlias() const;
        NODISCARD Database::Traits::Int32 GetVolume() const noexcept;
        NODISCARD Database::Traits::Int32Array GetAuthor() const;
        NODISCARD Database::Traits::StringArray GetAuthorNotes() const;
        NODISCARD Database::Traits::Int32Array GetAnnotator() const;
        NODISCARD Database::Traits::StringArray GetAnnotateNotes() const;
        NODISCARD Database::Traits::Int32Array GetCountry() const;
        NODISCARD Database::Traits::Int32Array GetPerson() const;
        NODISCARD Database::Traits::StringArray GetUnansweredQuestion() const;

        void SetId(Database::Traits::ParamType::Int32 aId);
        void SetGenus(Database::Traits::ParamType::Int32 aGenus);
        void SetName(Database::Traits::ParamType::String aName);
        void SetAlias(Database::Traits::ParamType::StringArray aAlias);
        void SetVolume(Database::Traits::ParamType::Int32 aVolume);
        void SetAuthor(Database::Traits::ParamType::Int32Array aAuthor);
        void SetAuthorNotes(Database::Traits::ParamType::StringArray aAuthorNotes);
        void SetAnnotator(Database::Traits::ParamType::Int32Array aAnnotator);
        void SetAnnotateNotes(Database::Traits::ParamType::StringArray aAnnotateNotes);
        void SetCountry(Database::Traits::ParamType::Int32Array aCountry);
        void SetPerson(Database::Traits::ParamType::Int32Array aPerson);
        void SetUnansweredQuestion(Database::Traits::ParamType::StringArray aUnansweredQuestion);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int32 id);
        NODISCARD static BasisDatabaseManager GetSelectAll(Database::WrappersStrategy wrappersStrategy);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "book" };

        static constexpr std::string_view idDescribe{ "_id" };
        static constexpr std::string_view genusDescribe{ "genus" };
        static constexpr std::string_view nameDescribe{ "name" };
        static constexpr std::string_view aliasDescribe{ "alias" };
        static constexpr std::string_view volumeDescribe{ "volume" };
        static constexpr std::string_view authorDescribe{ "author" };
        static constexpr std::string_view authorNotesDescribe{ "authorNotes" };
        static constexpr std::string_view annotatorDescribe{ "annotator" };
        static constexpr std::string_view annotateNotesDescribe{ "annotateNotes" };
        static constexpr std::string_view countryDescribe{ "country" };
        static constexpr std::string_view personDescribe{ "person" };
        static constexpr std::string_view unansweredQuestionDescribe{ "unansweredQuestion" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int32 id);

    private:
        Database::Entity<idDescribe, DataType::Int32, IndexType::Key> id;
        Database::Entity<genusDescribe, DataType::Int32> genus;
        Database::Entity<nameDescribe, DataType::String> name;
        Database::Entity<aliasDescribe, DataType::StringArray> alias;
        Database::Entity<volumeDescribe, DataType::Int32> volume;
        Database::Entity<authorDescribe, DataType::Int32Array> author;
        Database::Entity<authorNotesDescribe, DataType::StringArray> authorNotes;
        Database::Entity<annotatorDescribe, DataType::Int32Array> annotator;
        Database::Entity<annotateNotesDescribe, DataType::StringArray> annotateNotes;
        Database::Entity<countryDescribe, DataType::Int32Array> country;
        Database::Entity<personDescribe, DataType::Int32Array> person;
        Database::Entity<unansweredQuestionDescribe, DataType::StringArray> unansweredQuestion;
    };
}

#endif  // DATABASE_ENTITY_BOOK_ENTITY_H