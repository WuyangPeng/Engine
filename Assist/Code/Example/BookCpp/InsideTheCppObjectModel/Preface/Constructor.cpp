///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/12 21:17)

#include "Example/BookCpp/InsideTheCppObjectModel/InsideTheCppObjectModelExport.h"

#include "Constructor.h"
#include "X.h"
#include "Example/BookCpp/InsideTheCppObjectModel/Helper/InsideTheCppObjectModelClassInvariantMacro.h"

#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::setw;

BookAdvanced::InsideTheCppObjectModel::Constructor::Constructor() noexcept
{
    INSIDE_THE_CPP_OBJECT_MODEL_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::InsideTheCppObjectModel, Constructor)

BookAdvanced::InsideTheCppObjectModel::X buf;

void BookAdvanced::InsideTheCppObjectModel::Constructor::Main() const
{
    INSIDE_THE_CPP_OBJECT_MODEL_CLASS_IS_VALID_CONST_9;

    cout << "������һЩ�ַ���\n";

    // buf���������ʱ��������
    cin >> setw(1024) >> buf;
}
