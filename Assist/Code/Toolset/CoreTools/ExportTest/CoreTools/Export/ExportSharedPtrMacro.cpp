///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 22:59)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "ExportSharedPtrMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Export/ExportSharedPtrMacroImpl.h"

using std::make_shared;

ExportTest::ExportSharedPtrMacro::ExportSharedPtrMacro(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)  
    : impl{ make_shared<ImplType>() }, constImpl{ make_shared<ImplType>() }
{
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
