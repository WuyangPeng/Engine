///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/16 20:32)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "ExportNonCopyImplMacro.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Export/ExportNonCopyImplMacroImpl.h"

ExportTest::ExportNonCopyImplMacro ExportTest::ExportNonCopyImplMacro::Create()
{
    return ExportNonCopyImplMacro{ DisableNotThrow::Disable };
}

ExportTest::ExportNonCopyImplMacro::ExportNonCopyImplMacro(DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, ExportNonCopyImplMacro)
