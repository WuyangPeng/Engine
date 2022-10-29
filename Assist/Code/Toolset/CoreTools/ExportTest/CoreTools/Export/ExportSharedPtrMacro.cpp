///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:41)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "ExportSharedPtrMacro.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Export/ExportSharedPtrMacroImpl.h"

using std::make_shared;

ExportTest::ExportSharedPtrMacro::ExportSharedPtrMacro(DisableNotThrow disableNotThrow)
    : impl{ make_shared<ImplType>() }, constImpl{ make_shared<ImplType>() }
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
