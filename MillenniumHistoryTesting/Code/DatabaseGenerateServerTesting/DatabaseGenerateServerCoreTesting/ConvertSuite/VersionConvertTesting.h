///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/05 21:15)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_VERSION_CONVERT_TESTING_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_VERSION_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/VersionContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateServerCoreTesting
{
    class VersionConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = VersionConvertTesting;
        using ParentType = ConvertTesting;

        using VersionContainer = AncientBooks::VersionContainer;

    public:
        VersionConvertTesting(const OStreamShared& stream, const VersionContainer& versionContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Version = AncientBooks::VersionBase;
        using VersionEntity = DatabaseEntity::VersionEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Version& version, const VersionEntity& versionEntity);

    private:
        VersionContainer versionContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_VERSION_CONVERT_TESTING_H