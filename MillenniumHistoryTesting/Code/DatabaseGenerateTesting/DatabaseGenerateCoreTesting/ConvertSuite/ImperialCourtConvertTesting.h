/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:49)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_IMPERIAL_COURT_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_IMPERIAL_COURT_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/ImperialCourtContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class ImperialCourtConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = ImperialCourtConvertTesting;
        using ParentType = ConvertTesting;

        using ImperialCourtContainer = AncientBooks::ImperialCourtContainer;

    public:
        ImperialCourtConvertTesting(const OStreamShared& stream, const ImperialCourtContainer& imperialCourtContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using ImperialCourt = AncientBooks::ImperialCourtBase;
        using ImperialCourtEntity = DatabaseEntity::ImperialCourtEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const ImperialCourt& imperialCourt, const ImperialCourtEntity& imperialCourtEntity);

    private:
        ImperialCourtContainer imperialCourtContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_IMPERIAL_COURT_CONVERT_TESTING_H