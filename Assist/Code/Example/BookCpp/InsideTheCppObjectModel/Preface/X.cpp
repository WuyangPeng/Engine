///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/12 21:17)

#include "Example/BookCpp/InsideTheCppObjectModel/InsideTheCppObjectModelExport.h"

#include "X.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/InsideTheCppObjectModel/Helper/InsideTheCppObjectModelClassInvariantMacro.h"

#include <iostream>

using std::istream;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26455)

BookAdvanced::InsideTheCppObjectModel::X::X(int sz)
    : ptr{ new char[sz] }
{
    INSIDE_THE_CPP_OBJECT_MODEL_SELF_CLASS_IS_VALID_1;
}

BookAdvanced::InsideTheCppObjectModel::X::~X()
{
    INSIDE_THE_CPP_OBJECT_MODEL_SELF_CLASS_IS_VALID_1;

    delete[] ptr;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
bool BookAdvanced::InsideTheCppObjectModel::X::IsValid() const noexcept
{
    if (ptr != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

istream& BookAdvanced::InsideTheCppObjectModel::operator>>(istream& is, X& rhs)
{
    is >> *rhs.ptr;

    return is;
}
