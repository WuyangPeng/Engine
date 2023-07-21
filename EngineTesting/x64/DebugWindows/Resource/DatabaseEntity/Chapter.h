/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef DATABASE_ENTITY_CHAPTER_H
#define DATABASE_ENTITY_CHAPTER_H

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/Entity.h"

namespace DatabaseEntity
{
    class Chapter final : public Database::DatabaseEntity
    {
    public:
        using ClassType = Chapter;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using WrappersStrategy = Database::WrappersStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        NODISCARD static Chapter Create(const BasisDatabaseManager& entity, WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 userId);
        explicit Chapter(const BasisDatabaseManager& entity);
        Chapter(WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 userId);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int64 GetUserId() const noexcept;
        NODISCARD Database::Traits::Int32 GetChapterId() const noexcept;
        NODISCARD Database::Traits::String GetChapterName() const;
        NODISCARD Database::Traits::Double GetChanceWinning() const noexcept;
        NODISCARD Database::Traits::Bool IsWinning() const noexcept;
        NODISCARD Database::Traits::Int64Count GetCurrency() const noexcept;
        NODISCARD Database::Traits::Int32Count GetCount() const noexcept;

        void SetUserId(Database::Traits::ParamType::Int64 aUserId);
        void SetChapterId(Database::Traits::ParamType::Int32 aChapterId);
        void SetChapterName(Database::Traits::ParamType::String aChapterName);
        void SetChanceWinning(Database::Traits::ParamType::Double aChanceWinning);
        void SetWinning(Database::Traits::ParamType::Bool aWinning);
        void SetCurrency(Database::Traits::ParamType::Int64Count aCurrency);
        void SetCount(Database::Traits::ParamType::Int32Count aCount);

        void ModifyCurrency(Database::Traits::ParamType::Int64Count aCurrency);
        void ModifyCount(Database::Traits::ParamType::Int32Count aCount);

        NODISCARD static const DatabaseFieldContainer& GetDatabaseFieldContainer();
        NODISCARD static BasisDatabaseManager GetSelect(Database::WrappersStrategy wrappersStrategy, Database::Traits::ParamType::Int64 userId);

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "UserChapter" };

        static constexpr std::string_view userIdDescribe{ "_id" };
        static constexpr std::string_view chapterIdDescribe{ "chapterId" };
        static constexpr std::string_view chapterNameDescribe{ "chapterName" };
        static constexpr std::string_view chanceWinningDescribe{ "chanceWinning" };
        static constexpr std::string_view winningDescribe{ "winning" };
        static constexpr std::string_view currencyDescribe{ "currency" };
        static constexpr std::string_view countDescribe{ "count" };

    private:
        NODISCARD static BasisDatabaseContainer GetKeyBasisDatabaseContainer(Database::Traits::ParamType::Int64 userId);

    private:
        Database::Entity<userIdDescribe, DataType::Int64, IndexType::Key> userId;
        Database::Entity<chapterIdDescribe, DataType::Int32> chapterId;
        Database::Entity<chapterNameDescribe, DataType::String> chapterName;
        Database::Entity<chanceWinningDescribe, DataType::Double> chanceWinning;
        Database::Entity<winningDescribe, DataType::Bool> winning;
        Database::Entity<currencyDescribe, DataType::Int64Count> currency;
        Database::Entity<countDescribe, DataType::Int32Count> count;
    };
}

#endif  // DATABASE_ENTITY_CHAPTER_H