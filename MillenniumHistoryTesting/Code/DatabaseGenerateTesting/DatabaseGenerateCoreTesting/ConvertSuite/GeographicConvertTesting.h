/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/25 22:16)

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
        GeographicConvertTesting(const OStreamShared& stream, GeographicContainer geographicContainer);

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