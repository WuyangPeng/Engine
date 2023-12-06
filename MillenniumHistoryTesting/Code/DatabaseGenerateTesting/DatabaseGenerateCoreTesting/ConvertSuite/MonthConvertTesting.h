/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:49)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_MONTH_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_MONTH_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/MonthContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class MonthConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = MonthConvertTesting;
        using ParentType = ConvertTesting;

        using MonthContainer = AncientBooks::MonthContainer;

    public:
        MonthConvertTesting(const OStreamShared& stream, const MonthContainer& monthContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Month = AncientBooks::MonthBase;
        using MonthEntity = DatabaseEntity::MonthEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Month& month, const MonthEntity& monthEntity);

    private:
        MonthContainer monthContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_MONTH_CONVERT_TESTING_H