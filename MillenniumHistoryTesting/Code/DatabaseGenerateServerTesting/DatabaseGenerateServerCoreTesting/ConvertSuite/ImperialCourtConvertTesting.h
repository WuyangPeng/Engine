///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 21:19)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_IMPERIAL_COURT_CONVERT_TESTING_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_IMPERIAL_COURT_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/ImperialCourtContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateServerCoreTesting
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

#endif  // DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_IMPERIAL_COURT_CONVERT_TESTING_H