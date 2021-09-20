///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/14 16:17)

#include "ArtificialIntellegence/ArtificialIntellegenceExport.h"

#include "ArtificialIntellegenceMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntellegenceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Shared/ArtificialIntellegenceMacroSharedImpl.h"

ArtificialIntellegence::ArtificialIntellegenceMacroShared::ArtificialIntellegenceMacroShared(int count)
    : impl{ count }
{
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntellegence, ArtificialIntellegenceMacroShared)

int ArtificialIntellegence::ArtificialIntellegenceMacroShared::GetCount() const noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ArtificialIntellegence::ArtificialIntellegenceMacroShared::SetCount(int count) noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}