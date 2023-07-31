///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/27 21:21)

#ifndef DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_COUNTRY_ENTITY_TESTING_H
#define DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_COUNTRY_ENTITY_TESTING_H

#include "DatabaseEntityTesting.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/CountryContainer.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerBase/DatabaseEntity/DatabaseEntityFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace DatabaseGenerateServerBaseTesting
{
    class CountryEntityTesting final : public DatabaseEntityTesting
    {
    public:
        using ClassType = CountryEntityTesting;
        using ParentType = DatabaseEntityTesting;

        using CountryContainer = AncientBooks::CountryContainer;

    public:
        CountryEntityTesting(const OStreamShared& stream, const CountryContainer& countryContainer);

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

#endif  // DATABASE_GENERATE_SERVER_BASE_TESTING_DATABASE_ENTITY_SUITE_COUNTRY_ENTITY_TESTING_H