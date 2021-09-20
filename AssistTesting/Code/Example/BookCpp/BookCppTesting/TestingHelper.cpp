///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.0 (2020/12/20 1:36)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookCpp/BookCpp/Helper/BookCppClassInvariantMacro.h"

BookCpp::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�鼮 C++" }
{
    InitSuite();

    BOOK_CPP_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookCpp, TestingHelper)

void BookCpp::TestingHelper::InitSuite() noexcept
{
}
