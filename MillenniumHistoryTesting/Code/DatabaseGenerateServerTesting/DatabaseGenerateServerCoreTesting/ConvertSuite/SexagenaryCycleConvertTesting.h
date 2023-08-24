///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/05 21:08)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_SEXAGENARY_CYCLE_CONVERT_TESTING_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_SEXAGENARY_CYCLE_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/SexagenaryCycleContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateServerCoreTesting
{
    class SexagenaryCycleConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = SexagenaryCycleConvertTesting;
        using ParentType = ConvertTesting;

        using SexagenaryCycleContainer = AncientBooks::SexagenaryCycleContainer;

    public:
        SexagenaryCycleConvertTesting(const OStreamShared& stream, const SexagenaryCycleContainer& sexagenaryCycleContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using SexagenaryCycle = AncientBooks::SexagenaryCycleBase;
        using SexagenaryCycleEntity = DatabaseEntity::SexagenaryCycleEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const SexagenaryCycle& sexagenaryCycle, const SexagenaryCycleEntity& sexagenaryCycleEntity);

    private:
        SexagenaryCycleContainer sexagenaryCycleContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_SEXAGENARY_CYCLE_CONVERT_TESTING_H