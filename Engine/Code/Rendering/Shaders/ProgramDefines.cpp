/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:10)

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

void Rendering::ProgramDefines::Remove(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Remove(name);
}

void Rendering::ProgramDefines::Clear() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Clear();
}

std::string Rendering::ProgramDefines::Get(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->Get(name);
}

int Rendering::ProgramDefines::GetSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetSize();
}

Rendering::ProgramDefines::ContainerConstIter Rendering::ProgramDefines::begin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->begin();
}

Rendering::ProgramDefines::ContainerConstIter Rendering::ProgramDefines::end() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->end();
}

void Rendering::ProgramDefines::Update(const std::string& name, const std::string& value)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Update(name, value);
}
