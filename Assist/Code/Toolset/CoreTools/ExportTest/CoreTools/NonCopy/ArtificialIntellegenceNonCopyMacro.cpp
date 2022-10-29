///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 23:01)

#include "ArtificialIntellegence/ArtificialIntellegenceExport.h"

#include "ArtificialIntellegenceNonCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntellegenceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/NonCopy/ArtificialIntellegenceNonCopyMacroImpl.h"

ArtificialIntellegence::ArtificialIntellegenceNonCopyMacro::ArtificialIntellegenceNonCopyMacro(int count)
    : impl{ count }
{
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntellegence, ArtificialIntellegenceNonCopyMacro)

int ArtificialIntellegence::ArtificialIntellegenceNonCopyMacro::GetCount() const noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ArtificialIntellegence::ArtificialIntellegenceNonCopyMacro::SetCount(int count) noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
