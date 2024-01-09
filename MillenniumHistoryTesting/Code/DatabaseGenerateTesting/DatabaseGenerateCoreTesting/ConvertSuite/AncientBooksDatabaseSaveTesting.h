/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/25 22:11)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_ANCIENT_BOOKS_DATABASE_SAVE_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_ANCIENT_BOOKS_DATABASE_SAVE_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"

namespace DatabaseGenerateCoreTesting
{
    class AncientBooksDatabaseSaveTesting final : public ConvertTesting
    {
    public:
        using ClassType = AncientBooksDatabaseSaveTesting;
        using ParentType = ConvertTesting;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        AncientBooksDatabaseSaveTesting(const OStreamShared& stream, AncientBooksContainer ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;

    private:
        AncientBooksContainer ancientBooksContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_ANCIENT_BOOKS_DATABASE_SAVE_TESTING_H