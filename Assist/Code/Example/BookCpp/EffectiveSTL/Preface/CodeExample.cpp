///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:47)

#include "Example/BookCpp/EffectiveSTL/EffectiveSTLExport.h"

#include "CodeExample.h"
#include "CodeExampleDeclaration.h"
#include "Example/BookCpp/EffectiveSTL/Helper/EffectiveSTLClassInvariantMacro.h"

#include <map>
#include <string>

using std::vector;

BookExperience::EffectiveSTL::CodeExample::CodeExample() noexcept
{
    EFFECTIVE_STL_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveSTL, CodeExample)

void BookExperience::EffectiveSTL::CodeExample::Main() const
{
    EFFECTIVE_STL_CLASS_IS_VALID_CONST_9;

    using std::map;
    using std::string;

    map<string, double> m;

    Rational x, y;
    if (x == y)
    {
    }
}

bool BookExperience::EffectiveSTL::CodeExample::LastGreaterThanFirst(const vector<int>& container) const noexcept
{
    EFFECTIVE_STL_CLASS_IS_VALID_CONST_9;

    return BookExperience::EffectiveSTL::LastGreaterThanFirst(container);
}
