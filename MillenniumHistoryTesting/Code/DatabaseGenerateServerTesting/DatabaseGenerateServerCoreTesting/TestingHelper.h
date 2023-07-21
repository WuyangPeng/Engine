///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 22:19)

#ifndef DATABASE_GENERATE_SERVER_CORE_TESTING_HELPER_H
#define DATABASE_GENERATE_SERVER_CORE_TESTING_HELPER_H

#include "DatabaseGenerateServer/DatabaseGenerateServerBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace DatabaseGenerateServerCoreTesting
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
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

        void AddEngineSuite();
        void AddConvertSuite(const AncientBooksContainer& ancientBooksContainer);
    };
}

#endif  //  DATABASE_GENERATE_SERVER_CORE_TESTING_HELPER_H