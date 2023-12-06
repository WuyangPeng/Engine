/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/30 22:49)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_EMPEROR_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_EMPEROR_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/EmperorContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class EmperorConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = EmperorConvertTesting;
        using ParentType = ConvertTesting;

        using EmperorContainer = AncientBooks::EmperorContainer;

    public:
        EmperorConvertTesting(const OStreamShared& stream, const EmperorContainer& emperorContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Emperor = AncientBooks::EmperorBase;
        using EmperorEntity = DatabaseEntity::EmperorEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Emperor& emperor, const EmperorEntity& emperorEntity);

    private:
        EmperorContainer emperorContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_EMPEROR_CONVERT_TESTING_H