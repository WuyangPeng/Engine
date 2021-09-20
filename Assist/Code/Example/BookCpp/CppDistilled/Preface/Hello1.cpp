///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2020/12/31 23:06)

// hello.cpp - Script 1.1
// ����һ��ʾ��C++�ļ���

#include "Example/BookCpp/CppDistilled/CppDistilledExport.h"

#include "Example/BookCpp/CppDistilled/Helper/CppDistilledClassInvariantMacro.h"
#include "Hello1.h"

// ��ͳ�ϵĵ�һ�γ���
#include <iostream>

BookPrimary::CppDistilled::Hello1::Hello1() noexcept
{
    CPP_DISTILLED_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookPrimary::CppDistilled, Hello1)

int BookPrimary::CppDistilled::Hello1::Main() const
{
    CPP_DISTILLED_CLASS_IS_VALID_CONST_9;

    using namespace std;

    cout << "HELLO, WORLD!" << endl;

    return 0;
}
