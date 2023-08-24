///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/09 22:12)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_ANCIENT_BOOKS_DATABASE_SAVE_TESTING_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_ANCIENT_BOOKS_DATABASE_SAVE_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateServerCoreTesting
{
    class AncientBooksDatabaseSaveTesting final : public ConvertTesting
    {
    public:
        using ClassType = AncientBooksDatabaseSaveTesting;
        using ParentType = ConvertTesting;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        AncientBooksDatabaseSaveTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;

    private:
        AncientBooksContainer ancientBooksContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_ANCIENT_BOOKS_DATABASE_SAVE_TESTING_H