﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/26 15:50)

#ifndef DATABASE_TESTING_STATEMENT_SUITE_SQL_STATEMENT_TESTING_H
#define DATABASE_TESTING_STATEMENT_SUITE_SQL_STATEMENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class SqlStatementTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SqlStatementTesting;
        using ParentType = UnitTest;

    public:
        explicit SqlStatementTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() override;

        void InsertStatementTest();
        void UpdateStatementTest();
        void DeleteStatementTest();
        void SelectOneStatementTest();
        void SelectAllStatementTest();
    };
}

#endif  // DATABASE_TESTING_STATEMENT_SUITE_SQL_STATEMENT_TESTING_H