/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:49)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_GEOGRAPHIC_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_GEOGRAPHIC_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GeographicContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class GeographicConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = GeographicConvertTesting;
        using ParentType = ConvertTesting;

        using GeographicContainer = AncientBooks::GeographicContainer;

    public:
        GeographicConvertTesting(const OStreamShared& stream, const GeographicContainer& geographicContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Geographic = AncientBooks::GeographicBase;
        using GeographicEntity = DatabaseEntity::GeographicEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Geographic& geographic, const GeographicEntity& geographicEntity);

    private:
        GeographicContainer geographicContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_GEOGRAPHIC_CONVERT_TESTING_H