///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/16 19:37)

#include "ArtificialIntelligence/ArtificialIntelligenceExport.h"

#include "ArtificialIntelligencePerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/ArtificialIntelligencePerformanceUnsharedMacroImpl.h"

ArtificialIntelligence::ArtificialIntelligencePerformanceUnsharedMacro::ArtificialIntelligencePerformanceUnsharedMacro(int count)
    : impl{ count }
{
    ARTIFICIAL_INTELLIGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntelligence, ArtificialIntelligencePerformanceUnsharedMacro)

int ArtificialIntelligence::ArtificialIntelligencePerformanceUnsharedMacro::GetCount() const noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

const void* ArtificialIntelligence::ArtificialIntelligencePerformanceUnsharedMacro::GetAddress() const noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}