/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/29 00:17)

#ifndef DATABASE_GENERATE_BASE_TESTING_HELPER_H
#define DATABASE_GENERATE_BASE_TESTING_HELPER_H

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksFwd.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace DatabaseGenerateBaseTesting
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using AncientBooksContainer = AncientBooks::AncientBooksContainer;

    private:
        void InitSuite();

        void AddAncientBooksSuite(const AncientBooksContainer& ancientBooksContainer);
        void AddDatabaseEntitySuite(const AncientBooksContainer& ancientBooksContainer);
    };
}

#endif  //  DATABASE_GENERATE_BASE_TESTING_HELPER_H