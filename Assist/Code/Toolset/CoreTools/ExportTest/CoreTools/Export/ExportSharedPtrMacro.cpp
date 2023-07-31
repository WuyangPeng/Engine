///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:14)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "ExportSharedPtrMacro.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Export/ExportSharedPtrMacroImpl.h"

ExportTest::ExportSharedPtrMacro ExportTest::ExportSharedPtrMacro::Create()
{
    return ExportSharedPtrMacro{ DisableNotThrow::Disable };
}

ExportTest::ExportSharedPtrMacro::ExportSharedPtrMacro(DisableNotThrow disableNotThrow)
    : impl{ std::make_shared<ImplType>() }, constImpl{ std::make_shared<ImplType>() }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#if defined(OPEN_CLASS_INVARIANT)

bool ExportTest::ExportSharedPtrMacro::IsValid() const noexcept
{
    if (impl != nullptr && constImpl != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT
