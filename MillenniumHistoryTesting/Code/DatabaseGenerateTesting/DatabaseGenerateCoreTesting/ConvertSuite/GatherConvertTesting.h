/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/25 22:15)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_GATHER_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_GATHER_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/GatherContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class GatherConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = GatherConvertTesting;
        using ParentType = ConvertTesting;

        using GatherContainer = AncientBooks::GatherContainer;

    public:
        GatherConvertTesting(const OStreamShared& stream, GatherContainer gatherContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Gather = AncientBooks::GatherBase;
        using GatherEntity = DatabaseEntity::GatherEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Gather& gather, const GatherEntity& gatherEntity);

    private:
        GatherContainer gatherContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_GATHER_CONVERT_TESTING_H