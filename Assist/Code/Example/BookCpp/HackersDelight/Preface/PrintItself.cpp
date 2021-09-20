///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 21:20)

#include "Example/BookCpp/HackersDelight/HackersDelightExport.h"

#include "PrintItself.h"
#include "Example/BookCpp/HackersDelight/Helper/HackersDelightClassInvariantMacro.h"

BookAlgorithm::HackersDelight::PrintItself::PrintItself() noexcept
{
    HACKERS_DELIGHT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookAlgorithm::HackersDelight, PrintItself)

void BookAlgorithm::HackersDelight::PrintItself::Main() const noexcept
{
    HACKERS_DELIGHT_CLASS_IS_VALID_CONST_9;

    auto ptr = "void Main() { auto ptr = %c%s%c; printf(ptr, 34, ptr, 34, 10); } %c";
    printf(ptr, 34, ptr, 34, 10);
}
