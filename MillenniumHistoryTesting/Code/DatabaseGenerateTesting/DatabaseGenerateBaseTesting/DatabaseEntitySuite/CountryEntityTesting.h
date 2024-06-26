/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:19)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_COUNTRY_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_COUNTRY_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/CountryContainer.h"
#include "DatabaseGenerate/DatabaseGenerateBase/DatabaseEntity/DatabaseEntityFwd.h"

namespace DatabaseGenerateBaseTesting
{
    class CountryEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = CountryEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using CountryContainer = AncientBooks::CountryContainer;

    public:
        CountryEntityTesting(const OStreamShared& stream, CountryContainer countryContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using Country = AncientBooks::CountryBase;
        using CountryEntity = DatabaseEntity::CountryEntity;
        using EntityContainer = std::map<int32_t, CountryEntity>;

    private:
        void SelectOneTest(DatabaseFlush& databaseFlush) override;
        void SelectAllTest(DatabaseFlush& databaseFlush) override;
        void SelectAllSizeTest(const DatabaseFlush& databaseFlush) override;

        void SetEntity(CountryEntity& countryEntity, const Country& country);

        void DoSelectOneTest(DatabaseFlush& databaseFlush, const Country& country);
        void DoSelectAllTest(DatabaseFlush& databaseFlush, const Country& country, const EntityContainer& entityContainer);
        void EqualTest(const Country& country, const EntityContainer& entityContainer);

    private:
        CountryContainer countryContainer;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_COUNTRY_ENTITY_TESTING_H