/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:18)

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
