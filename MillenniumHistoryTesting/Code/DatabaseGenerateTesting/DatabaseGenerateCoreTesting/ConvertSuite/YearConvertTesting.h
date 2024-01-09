/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:17)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_YEAR_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_YEAR_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/YearContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class YearConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = YearConvertTesting;
        using ParentType = ConvertTesting;

        using YearContainer = AncientBooks::YearContainer;

    public:
        YearConvertTesting(const OStreamShared& stream, YearContainer yearContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Year = AncientBooks::YearBase;
        using YearEntity = DatabaseEntity::YearEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Year& year, const YearEntity& yearEntity);

    private:
        YearContainer yearContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_YEAR_CONVERT_TESTING_H