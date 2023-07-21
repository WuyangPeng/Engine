///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/16 15:55)

#ifndef DATABASE_GENERATE_SERVER_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_H
#define DATABASE_GENERATE_SERVER_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_H

#include "DatabaseGenerateServer/DatabaseGenerateServerCore/DatabaseGenerateServerCoreDll.h"

#include "ConvertEntity.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooks.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntity.h"
#include "Framework/Helper/UserMacro.h"

EXPORT_SHARED_PTR(DatabaseGenerateServerCore, AncientBooksDatabaseSaveImpl, DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE);
EXPORT_NON_COPY(DatabaseGenerateServerCore, AncientBooksDatabaseSaveImpl, DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE);

namespace DatabaseGenerateServerCore
{
    class DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE AncientBooksDatabaseSave final
    {
    public:
        NON_COPY_TYPE_DECLARE(AncientBooksDatabaseSave);

        using DatabaseFlush = Database::DatabaseFlush;
        using DatabaseFlushSharedPtr = std::shared_ptr<DatabaseFlush>;

    public:
        explicit AncientBooksDatabaseSave(const DatabaseFlushSharedPtr& databaseFlush) noexcept;

        CLASS_INVARIANT_DECLARE;

        void DatabaseSave(const AncientBooksContainer& ancientBooksContainer);

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_H