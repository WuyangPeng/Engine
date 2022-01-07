///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 18:19)

#include "CoreTools/CoreToolsExport.h"

#include "EquilongReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::EquilongReportOutputImpl::EquilongReportOutputImpl(int borderLineLength, const OStreamShared& streamShared) noexcept
    : ParentType{ streamShared }, borderLineLength{ borderLineLength }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::EquilongReportOutputImpl::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 < borderLineLength)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::EquilongReportOutputImpl::PrintBorderLine(char character)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    string borderLine(borderLineLength, character);

    PrintString(borderLine);
}

// protected
int CoreTools::EquilongReportOutputImpl::GetBorderLineLength() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return borderLineLength;
}
