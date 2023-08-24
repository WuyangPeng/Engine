///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/05 21:04)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_CONVERT_TESTING_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ReignTitleContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateServerCoreTesting
{
    class ReignTitleConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = ReignTitleConvertTesting;
        using ParentType = ConvertTesting;

        using ReignTitleContainer = AncientBooks::ReignTitleContainer;

    public:
        ReignTitleConvertTesting(const OStreamShared& stream, const ReignTitleContainer& reignTitleContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using ReignTitle = AncientBooks::ReignTitleBase;
        using ReignTitleEntity = DatabaseEntity::ReignTitleEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const ReignTitle& reignTitle, const ReignTitleEntity& reignTitleEntity);

    private:
        ReignTitleContainer reignTitleContainer;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_CONVERT_TESTING_H