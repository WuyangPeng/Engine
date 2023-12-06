/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:49)

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
        YearConvertTesting(const OStreamShared& stream, const YearContainer& yearContainer);

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