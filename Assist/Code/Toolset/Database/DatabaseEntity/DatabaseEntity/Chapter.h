///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.9 (2023/05/25 11:25)

#ifndef DATABASE_ENTITY_CHAPTER_H
#define DATABASE_ENTITY_CHAPTER_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseEntity.h"
#include "Database/DatabaseInterface/EntityDetail.h"

namespace DatabaseEntity
{
    class Chapter final : public Database::DatabaseEntity
    {
    public:
        using ClassType = Chapter;
        using ParentType = DatabaseEntity;

        using DataType = Database::DataType;
        using IndexType = Database::IndexType;
        using BasisDatabaseContainer = Database::BasisDatabaseContainer;

    public:
        explicit Chapter(const BasisDatabaseContainer& entity);
        Chapter(Database::WrappersStrategy wrappersStrategy,
                boost::call_traits<Database::Traits::Int64>::param_type userId);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD Database::Traits::Int64 GetUserId() const noexcept;
        NODISCARD Database::Traits::Int32 GetChapterId() const noexcept;
        NODISCARD Database::Traits::String GetChapterName() const;
        NODISCARD Database::Traits::Double GetChanceWinning() const noexcept;
        NODISCARD Database::Traits::Bool IsChanceWinning() const noexcept;
        NODISCARD Database::Traits::Int64Count GetCurrency() const noexcept;
        NODISCARD Database::Traits::Int32Count GetCount() const noexcept;

        void SetChapterId(boost::call_traits<Database::Traits::Int32>::param_type aChapterId);
        void SetChapterName(boost::call_traits<Database::Traits::String>::param_type aChapterName);
        void SetChanceWinning(boost::call_traits<Database::Traits::Double>::param_type aChanceWinning);
        void SetChanceWinning(boost::call_traits<Database::Traits::Bool>::param_type aIsWinning);
        void SetCurrency(boost::call_traits<Database::Traits::Int64Count>::param_type aCurrency);
        void ModifyCurrency(boost::call_traits<Database::Traits::Int64Count>::param_type aCurrency);
        void SetCount(boost::call_traits<Database::Traits::Int32Count>::param_type aCount);
        void ModifyCount(boost::call_traits<Database::Traits::Int32Count>::param_type aCount);

        NODISCARD FieldNameContainer GetFieldNameContainer() const override;

        NODISCARD static constexpr std::string_view GetDatabaseName()
        {
            return databaseName;
        }

    private:
        static constexpr std::string_view databaseName{ "UserChapter" };

        static constexpr std::string_view userIdDescribe{ "userId" };
        static constexpr std::string_view chapterIdDescribe{ "chapterId" };
        static constexpr std::string_view chapterNameDescribe{ "chapterName" };
        static constexpr std::string_view chanceWinningDescribe{ "chanceWinning" };
        static constexpr std::string_view isWinningDescribe{ "isWinning" };
        static constexpr std::string_view currencyDescribe{ "currency" };
        static constexpr std::string_view countDescribe{ "count" };

    private:
        NODISCARD static ObjectContainer GetKeyBasisDatabaseContainer(boost::call_traits<Database::Traits::Int64>::param_type userId);

    private:
        Database::Entity<userIdDescribe, DataType::Int64, IndexType::Key> userId;
        Database::Entity<chapterIdDescribe, DataType::Int32> chapterId;
        Database::Entity<chapterNameDescribe, DataType::String> chapterName;
        Database::Entity<chanceWinningDescribe, DataType::Double> chanceWinning;
        Database::Entity<isWinningDescribe, DataType::Bool> isWinning;
        Database::Entity<currencyDescribe, DataType::Int64Count> currency;
        Database::Entity<countDescribe, DataType::Int32Count> count;
    };
}

#endif  // DATABASE_ENTITY_CHAPTER_H
