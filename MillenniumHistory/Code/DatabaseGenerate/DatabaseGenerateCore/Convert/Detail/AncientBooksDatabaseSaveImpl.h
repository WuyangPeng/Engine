/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/28 22:30)

#ifndef DATABASE_GENERATE_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_H
#define DATABASE_GENERATE_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_H

#include "DatabaseGenerate/DatabaseGenerateCore/DatabaseGenerateCoreDll.h"

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooks.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntity.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertEntity.h"
#include "Framework/Helper/UserMacro.h"

namespace DatabaseGenerateCore
{
    class DATABASE_GENERATE_CORE_HIDDEN_DECLARE AncientBooksDatabaseSaveImpl final
    {
    public:
        using ClassType = AncientBooksDatabaseSaveImpl;

        using DatabaseFlush = Database::DatabaseFlush;
        using DatabaseFlushSharedPtr = std::shared_ptr<DatabaseFlush>;

    public:
        explicit AncientBooksDatabaseSaveImpl(const DatabaseFlushSharedPtr& databaseFlush);

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

#endif  // DATABASE_GENERATE_CORE_CONVERT_ANCIENT_BOOKS_DATABASE_SAVE_IMPL_H