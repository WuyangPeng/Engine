/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:48)

#ifndef DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_COUNTRY_CONVERT_TESTING_H
#define DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_COUNTRY_CONVERT_TESTING_H

#include "ConvertTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CountryContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateCoreTesting
{
    class CountryConvertTesting final : public ConvertTesting
    {
    public:
        using ClassType = CountryConvertTesting;
        using ParentType = ConvertTesting;

        using CountryContainer = AncientBooks::CountryContainer;

    public:
        CountryConvertTesting(const OStreamShared& stream, const CountryContainer& countryContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Country = AncientBooks::CountryBase;
        using CountryEntity = DatabaseEntity::CountryEntity;

    private:
        void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) override;
        void EqualTest(const Country& country, const CountryEntity& countryEntity);

    private:
        CountryContainer countryContainer;
    };
}

#endif  // DATABASE_GENERATE_CORE_TESTING_DATABASE_ENTITY_SUITE_COUNTRY_CONVERT_TESTING_H