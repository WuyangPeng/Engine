///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/07 22:06)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerCore/Convert/ConvertFwd.h"

namespace DatabaseGenerateServerCoreTesting
{
    class DeleteInvalidDatabaseTesting final : public ConvertTesting
    {
    public:
        using ClassType = DeleteInvalidDatabaseTesting;
        using ParentType = ConvertTesting;

        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    public:
        DeleteInvalidDatabaseTesting(const OStreamShared& stream, const AncientBooksContainer& ancientBooksContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using ConvertEntity = DatabaseGenerateServerCore::ConvertEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;

        template <typename T>
        void DatabaseSave(ConvertEntity& convertEntity, const T& container);

    private:
        AncientBooksContainer ancientBooksContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_H