/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/25 22:16)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_IDENTITY_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_IDENTITY_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/IdentityContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class IdentityConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = IdentityConvertTesting;
        using ParentType = ConvertTesting;

        using IdentityContainer = AncientBooks::IdentityContainer;

    public:
        IdentityConvertTesting(const OStreamShared& stream, IdentityContainer identityContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Identity = AncientBooks::IdentityBase;
        using IdentityEntity = DatabaseEntity::IdentityEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Identity& identity, const IdentityEntity& identityEntity);

    private:
        IdentityContainer identityContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_IDENTITY_CONVERT_TESTING_H