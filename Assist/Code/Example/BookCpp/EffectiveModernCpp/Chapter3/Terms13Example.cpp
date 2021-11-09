///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/04 21:36)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms13.h"
#include "Terms13Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms13::Terms13Example::Terms13Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms13, Terms13Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms13::Terms13Example::FindExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> values;

    // ...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    std::vector<int>::iterator it = std::find(values.begin(), values.end(), 1983);

#include STSTEM_WARNING_POP

    values.insert(it, 1998);
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms13::Terms13Example::ConstFindCpp98Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // һЩtypedef
    typedef std::vector<int>::iterator IterT;
    typedef std::vector<int>::const_iterator ConstIterT;

    std::vector<int> values;

    // ...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    ConstIterT ci = std::find(static_cast<ConstIterT>(values.begin()),  // ǿ���ͱ�ת��
                              static_cast<ConstIterT>(values.end()),  // ǿ���ͱ�ת��
                              1983);

#include STSTEM_WARNING_POP

    // values.insert(static_cast<IterT>(ci), 1998); // �����޷�ͨ������
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms13::Terms13Example::ConstFindCpp11Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> values;  // ͬǰ

    // ...

    auto it = std::find(values.cbegin(),  // ʹ��cbegin
                        values.cend(),  // ʹ��cend
                        1983);

    values.insert(it, 1998);
}
