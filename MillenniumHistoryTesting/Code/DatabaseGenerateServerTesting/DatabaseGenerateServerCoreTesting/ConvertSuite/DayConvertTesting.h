///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/03 23:12)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_DAY_CONVERT_TESTING_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_DAY_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/DayContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateServerCoreTesting
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

#endif  // DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_DAY_CONVERT_TESTING_H