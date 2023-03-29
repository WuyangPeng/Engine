///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 09:15)

#include "ArtificialIntelligence/ArtificialIntelligenceExport.h"

#include "ArtificialIntelligenceTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/ArtificialIntelligenceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/ArtificialIntelligenceTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(ArtificialIntelligence, ArtificialIntelligenceTestExportCopyMacro)

ArtificialIntelligence::ArtificialIntelligenceTestExportCopyMacro::ArtificialIntelligenceTestExportCopyMacro(int count)
    : impl{ count }
{
    ARTIFICIAL_INTELLIGENCE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ArtificialIntelligence, ArtificialIntelligenceTestExportCopyMacro)

int ArtificialIntelligence::ArtificialIntelligenceTestExportCopyMacro::GetCount() const noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ArtificialIntelligence::ArtificialIntelligenceTestExportCopyMacro::SetCount(int count) noexcept
{
    ARTIFICIAL_INTELLIGENCE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
