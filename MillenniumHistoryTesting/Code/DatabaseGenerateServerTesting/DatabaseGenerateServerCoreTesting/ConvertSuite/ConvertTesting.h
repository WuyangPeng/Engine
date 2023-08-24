///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/01 21:51)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_CONVERT_TESTING_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_CONVERT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Database/Configuration/AnalysisDatabaseConfiguration.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"

namespace DatabaseGenerateServerCoreTesting
{
    class ConvertTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConvertTesting;
        using ParentType = UnitTest;

    public:
        explicit ConvertTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using StringArray = Database::Traits::StringArray;
        using String = System::String;
        using StringContainer = std::vector<String>;
        using StringContainerConstIter = StringContainer::const_iterator;

        using DatabaseFlush = Database::DatabaseFlush;
        using DatabaseFlushSharedPtr = std::shared_ptr<DatabaseFlush>;
        using ConfigurationStrategy = Database::ConfigurationStrategy;
        using AnalysisDatabaseConfiguration = Database::AnalysisDatabaseConfiguration;

    protected:
        NODISCARD static StringArray Convert(const StringContainerConstIter& begin, const StringContainerConstIter& end);

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void InitEnvironmentTest();
        void DatabaseFlushTest();
        void DoDatabaseFlushTest(const ConfigurationStrategy& configurationStrategy);

        virtual void ConvertTest(const DatabaseFlushSharedPtr& databaseFlush) = 0;

    private:
        AnalysisDatabaseConfiguration analysisDatabaseConfiguration;
    };
}

#endif  // DATABASE_GENERATE_SERVER_CORE_TESTING_DATABASE_ENTITY_SUITE_CONVERT_TESTING_H