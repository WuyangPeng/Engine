/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:16)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ReignTitleContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class ReignTitleConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = ReignTitleConvertTesting;
        using ParentType = ConvertTesting;

        using ReignTitleContainer = AncientBooks::ReignTitleContainer;

    public:
        ReignTitleConvertTesting(const OStreamShared& stream, ReignTitleContainer reignTitleContainer);

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

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_REIGN_TITLE_CONVERT_TESTING_H