/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:16)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_SEXAGENARY_CYCLE_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_SEXAGENARY_CYCLE_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/SexagenaryCycleContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class SexagenaryCycleConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = SexagenaryCycleConvertTesting;
        using ParentType = ConvertTesting;

        using SexagenaryCycleContainer = AncientBooks::SexagenaryCycleContainer;

    public:
        SexagenaryCycleConvertTesting(const OStreamShared& stream, SexagenaryCycleContainer sexagenaryCycleContainer);

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

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_SEXAGENARY_CYCLE_CONVERT_TESTING_H