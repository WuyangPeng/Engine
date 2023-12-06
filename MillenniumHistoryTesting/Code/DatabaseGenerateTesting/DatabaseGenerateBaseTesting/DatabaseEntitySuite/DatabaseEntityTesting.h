/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 22:38)

#ifndef DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_DATABASE_ENTITY_TESTING_H
#define DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_DATABASE_ENTITY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Database/Configuration/AnalysisDatabaseConfiguration.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"

namespace DatabaseGenerateBaseTesting
{
    class DatabaseEntityTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = DatabaseEntityTesting;
        using ParentType = UnitTest;

    public:
        explicit DatabaseEntityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

    protected:
        using StringArray = Database::Traits::StringArray;
        using String = System::String;
        using StringContainer = std::vector<String>;
        using StringContainerConstIter = StringContainer::const_iterator;

        using DatabaseFlush = Database::DatabaseFlush;
        using ConfigurationStrategy = Database::ConfigurationStrategy;
        using BasisDatabaseManager = Database::BasisDatabaseManager;
        using ResultContainer = std::vector<BasisDatabaseManager>;

    protected:
        NODISCARD static StringArray Convert(const StringContainerConstIter& begin, const StringContainerConstIter& end);

        template <typename KeyType, typename EntityType>
        NODISCARD std::map<KeyType, EntityType> GetEntityContainer(const ResultContainer& database);

    private:
        using AnalysisDatabaseConfiguration = Database::AnalysisDatabaseConfiguration;

    private:
        void InitEnvironmentTest();
        void DatabaseFlushTest();
        void DoDatabaseFlushTest(const ConfigurationStrategy& configurationStrategy);

        virtual void SelectOneTest(DatabaseFlush& databaseFlush) = 0;
        virtual void SelectAllTest(DatabaseFlush& databaseFlush) = 0;
        virtual void SelectAllSizeTest(const DatabaseFlush& databaseFlush) = 0;

    private:
        AnalysisDatabaseConfiguration analysisDatabaseConfiguration;
    };
}

#endif  // DATABASE_GENERATE_BASE_TESTING_DATABASE_ENTITY_SUITE_DATABASE_ENTITY_TESTING_H