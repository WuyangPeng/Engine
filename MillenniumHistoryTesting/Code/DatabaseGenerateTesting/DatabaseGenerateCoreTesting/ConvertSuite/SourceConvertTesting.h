/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:49)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_SOURCE_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_SOURCE_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/SourceContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class SourceConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = SourceConvertTesting;
        using ParentType = ConvertTesting;

        using SourceContainer = AncientBooks::SourceContainer;

    public:
        SourceConvertTesting(const OStreamShared& stream, const SourceContainer& sourceContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Source = AncientBooks::SourceBase;
        using SourceEntity = DatabaseEntity::SourceEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Source& source, const SourceEntity& sourceEntity);

    private:
        SourceContainer sourceContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_SOURCE_CONVERT_TESTING_H