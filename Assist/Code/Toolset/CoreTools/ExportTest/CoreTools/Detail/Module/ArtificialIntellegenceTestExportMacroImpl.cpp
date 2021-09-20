///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 20:56)

#include "ArtificialIntellegence/ArtificialIntellegenceExport.h"

#include "ArtificialIntellegenceTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntellegenceClassInvariantMacro.h"

ArtificialIntellegence::ArtificialIntellegenceTestExportMacroImpl::ArtificialIntellegenceTestExportMacroImpl(int count) noexcept
    : m_Count{ count }
{
    ARTIFICIAL_INTELLEGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntellegence, ArtificialIntellegenceTestExportMacroImpl)

int ArtificialIntellegence::ArtificialIntellegenceTestExportMacroImpl::GetCount() const noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void ArtificialIntellegence::ArtificialIntellegenceTestExportMacroImpl::SetCount(int count) noexcept
{
    ARTIFICIAL_INTELLEGENCE_CLASS_IS_VALID_9;

    m_Count = count;
}