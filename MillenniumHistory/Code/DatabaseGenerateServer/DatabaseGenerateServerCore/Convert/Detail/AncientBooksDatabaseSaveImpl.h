///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/16 15:55)

#ifndef DATABASE_GENERATE_SERVER_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_H
#define DATABASE_GENERATE_SERVER_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_H

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreDll.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooks.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertEntity.h"
#include "Framework/Helper/UserMacro.h"

namespace DatabaseGenerateServerCore
{
    class DATABASE_GENERATE_SERVER_CORE_HIDDEN_DECLARE AncientBooksDatabaseSaveImpl final
    {
    public:
        using ClassType = AncientBooksDatabaseSaveImpl;

        using DatabaseFlush = Database::DatabaseFlush;
        using DatabaseFlushSharedPtr = std::shared_ptr<DatabaseFlush>;

    public:
        explicit AncientBooksDatabaseSaveImpl(const DatabaseFlushSharedPtr& databaseFlush) noexcept;

        CLASS_INVARIANT_DECLARE;

        void DatabaseSave(const AncientBooksContainer& ancientBooksContainer);

    private:
        template <typename T>
        void DatabaseSave(const T& container);

    private:
        DatabaseFlushSharedPtr databaseFlush;
        ConvertEntity convertEntity;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_H