/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/25 22:14)

#ifndef DATABASE_GENERATE_CORE_TESTING_HELPER_H
#define DATABASE_GENERATE_CORE_TESTING_HELPER_H

#include "DatabaseGenerate/DatabaseGenerateBase/AncientBooks/AncientBooksContainer.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace DatabaseGenerateCoreTesting
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

        void AddHelperSuite();
        void AddConvertSuite(const AncientBooksContainer& ancientBooksContainer);
    };
}

#endif  //  DATABASE_GENERATE_CORE_TESTING_HELPER_H