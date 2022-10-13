///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.1 (2022/08/20 16:17)

#include "Rendering/RenderingExport.h"

#include "ProgramDefinesImpl.h"
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

    definitions.erase(remove_if(definitions.begin(), definitions.end(), [&name](const auto& value) {
                          return value.first == name;
                      }),
                      definitions.end());
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

    THROW_EXCEPTION(SYSTEM_TEXT("����ProgramDefinesʧ�ܡ�"s));
}
