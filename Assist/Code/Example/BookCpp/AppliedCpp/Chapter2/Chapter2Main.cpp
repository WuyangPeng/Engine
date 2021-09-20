///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/26 23:59)

#include "Example/BookCpp/AppliedCpp/AppliedCppExport.h"

#include "APThumbNail.h"
#include "Chapter2Main.h"
#include "Example/BookCpp/AppliedCpp/Helper/AppliedCppClassInvariantMacro.h"

#include <iostream>

using std::string;

BookIntermediate::AppliedCpp::Chapter2Main::Chapter2Main() noexcept
{
    APPLIED_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookIntermediate::AppliedCpp, Chapter2Main)

int BookIntermediate::AppliedCpp::Chapter2Main::Main() const
{
    APPLIED_CPP_CLASS_IS_VALID_CONST_9;

    APThumbNail thumbnail{};

    try
    {
        thumbnail.CreateThumbNail("input.bmp", "output.bmp", 2);
    }
    catch (const APThumbNail::Invalid&)
    {
        std::cerr << "invalid exception caught" << std::endl;
        return 1;
    }

    return 0;
}

void BookIntermediate::AppliedCpp::Chapter2Main::ArbitraryAlgorithm() const
{
    APPLIED_CPP_CLASS_IS_VALID_CONST_9;

    APImage input{};
    string args{};

    APImage output = input.ArbitraryAlgorithm(args);
    if (!output.IsImageValid())
    {
        // ������ ArbitraryAlgorithm ʧ�ܡ�
    }
}
