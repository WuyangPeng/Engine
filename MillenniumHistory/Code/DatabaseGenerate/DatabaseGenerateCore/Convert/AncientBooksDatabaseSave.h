/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:29)

#ifndef DATABASE_GENERATE_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_H
#define DATABASE_GENERATE_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_H

#include "DatabaseGenerate/DatabaseGenerateCore/DatabaseGenerateCoreDll.h"

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooks.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Helper/ExportMacro.h"

DATABASE_GENERATE_CORE_EXPORT_NON_COPY(AncientBooksDatabaseSaveImpl);

namespace DatabaseGenerateCore
{
    class DATABASE_GENERATE_CORE_DEFAULT_DECLARE AncientBooksDatabaseSave final
    {
    public:
        NON_COPY_TYPE_DECLARE(AncientBooksDatabaseSave);

        using DatabaseFlush = Database::DatabaseFlush;
        using DatabaseFlushSharedPtr = std::shared_ptr<DatabaseFlush>;
        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        explicit AncientBooksDatabaseSave(const DatabaseFlushSharedPtr& databaseFlush);

        CLASS_INVARIANT_DECLARE;

        void DatabaseSave(const AncientBooksContainer& ancientBooksContainer);

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_GENERATE_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_H