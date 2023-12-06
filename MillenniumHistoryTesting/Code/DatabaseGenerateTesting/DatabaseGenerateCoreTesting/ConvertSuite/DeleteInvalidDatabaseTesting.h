/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:48)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "DatabaseGenerate/DatabaseGenerateCore/Convert/ConvertFwd.h"

namespace DatabaseGenerateCoreTesting
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
        using ConvertEntity = DatabaseGenerateCore::ConvertEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;

        template <typename T>
        void DatabaseSave(ConvertEntity& convertEntity, const T& container);

    private:
        AncientBooksContainer ancientBooksContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_DELETE_INVALID_DATABASE_TESTING_H