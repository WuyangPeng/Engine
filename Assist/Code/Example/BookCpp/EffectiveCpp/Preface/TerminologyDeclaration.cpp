///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:47)

#include "Example/BookCpp/EffectiveCpp/EffectiveCppExport.h"

#include "TerminologyDeclaration.h"
#include "Example/BookCpp/EffectiveCpp/Helper/EffectiveCppClassInvariantMacro.h"

namespace BookExperience
{
    namespace EffectiveCpp
    {
        // ����Ķ���ʽ
        int x;
    }
}

BookExperience::EffectiveCpp::B::B([[maybe_unused]] int a, [[maybe_unused]] bool b) noexcept
{
}

BookExperience::EffectiveCpp::C::C([[maybe_unused]] int a) noexcept
{
}

void BookExperience::EffectiveCpp::DoSomething([[maybe_unused]] B bObject) noexcept
{
}

bool BookExperience::EffectiveCpp::HasAcceptableQuality([[maybe_unused]] Widget w) noexcept
{
    return false;
}
