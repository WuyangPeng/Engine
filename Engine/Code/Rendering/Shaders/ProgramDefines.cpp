///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:34)

#include "Rendering/RenderingExport.h"

#include "ProgramDefinesDetail.h"
#include "Detail/ProgramDefinesImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ProgramDefines)

Rendering::ProgramDefines Rendering::ProgramDefines::Create()
{
    return ProgramDefines{ CoreTools::DisableNotThrow::Disable };
}

Rendering::ProgramDefines::ProgramDefines(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProgramDefines)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ProgramDefines, Remove, std::string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ProgramDefines, Clear, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, ProgramDefines, Get, std::string, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ProgramDefines, GetSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ProgramDefines, begin, Rendering::ProgramDefines::ContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, ProgramDefines, end, Rendering::ProgramDefines::ContainerConstIter)

void Rendering::ProgramDefines::Update(const std::string& name, const std::string& value)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Update(name, value);
}