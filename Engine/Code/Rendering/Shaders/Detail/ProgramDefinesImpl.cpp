///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:30)

#include "Rendering/RenderingExport.h"

#include "ProgramDefinesImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::ProgramDefinesImpl::ProgramDefinesImpl() noexcept
    : definitions{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProgramDefinesImpl)

void Rendering::ProgramDefinesImpl::Remove(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto iter = std::ranges::remove_if(definitions, [&name](const auto& element) {
        return element.first == name;
    });

    definitions.erase(iter.begin(), iter.end());
}

void Rendering::ProgramDefinesImpl::Clear() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    definitions.clear();
}

void Rendering::ProgramDefinesImpl::Update(const std::string& name, const std::string& value)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto& definition : definitions)
    {
        if (name == definition.first)
        {
            definition.second = value;
            return;
        }
    }

    definitions.emplace_back(name, value);
}

std::string Rendering::ProgramDefinesImpl::Get(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    for (auto& definition : definitions)
    {
        if (name == definition.first)
        {
            return definition.second;
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("查找ProgramDefines失败。"s))
}

int Rendering::ProgramDefinesImpl::GetSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(definitions.size());
}

Rendering::ProgramDefinesImpl::ContainerConstIter Rendering::ProgramDefinesImpl::begin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return definitions.begin();
}

Rendering::ProgramDefinesImpl::ContainerConstIter Rendering::ProgramDefinesImpl::end() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return definitions.end();
}
