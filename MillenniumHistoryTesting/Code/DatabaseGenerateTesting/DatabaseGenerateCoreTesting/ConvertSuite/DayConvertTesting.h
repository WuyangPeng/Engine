/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:48)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_DAY_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_DAY_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/DayContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class DayConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = DayConvertTesting;
        using ParentType = ConvertTesting;

        using DayContainer = AncientBooks::DayContainer;

    public:
        DayConvertTesting(const OStreamShared& stream, const DayContainer& dayContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Day = AncientBooks::DayBase;
        using DayEntity = DatabaseEntity::DayEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Day& day, const DayEntity& dayEntity);

    private:
        DayContainer dayContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_DAY_CONVERT_TESTING_H