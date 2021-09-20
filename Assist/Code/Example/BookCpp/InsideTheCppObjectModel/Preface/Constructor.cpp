///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/12 21:17)

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

    cout << "请输入一些字符：\n";

    // buf必须在这个时候构造起来
    cin >> setw(1024) >> buf;
}
