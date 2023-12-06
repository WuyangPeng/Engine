/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:49)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_VERSION_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_VERSION_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/VersionContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
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

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_VERSION_CONVERT_TESTING_H