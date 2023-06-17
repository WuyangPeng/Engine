///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:40)

#include "Rendering/RenderingExport.h"

#include "OpenGLInputLayoutManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLInputLayoutManagerImpl::OpenGLInputLayoutManagerImpl() noexcept
    : inputLayout{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLInputLayoutManagerImpl)

Rendering::OpenGLInputLayoutManagerImpl::OpenGLInputLayoutSharedPtr Rendering::OpenGLInputLayoutManagerImpl::Bind(OpenGLUInt programHandle, OpenGLUInt vertexBufferHandle, const VertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    if (programHandle == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入。"));
    }

    InputLayoutKey inputLayoutKey{ vertexBuffer, programHandle };
    auto iter = inputLayout.find(inputLayoutKey);
    if (iter == inputLayout.end())
    {
        auto layout = std::make_shared<OpenGLInputLayout>(programHandle, vertexBufferHandle, *vertexBuffer);
        iter = inputLayout.emplace(inputLayoutKey, layout).first;
    }

    return iter->second;
}

void Rendering::OpenGLInputLayoutManagerImpl::Unbind(const VertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    std::vector<InputLayoutKey> matches{};
    for (const auto& element : inputLayout)
    {
        if (vertexBuffer == element.first.first)
        {
            matches.emplace_back(element.first);
        }
    }

    for (const auto& match : matches)
    {
        inputLayout.erase(match);
    }
}

void Rendering::OpenGLInputLayoutManagerImpl::UnbindAll() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    inputLayout.clear();
}

bool Rendering::OpenGLInputLayoutManagerImpl::HasElements() const noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return !inputLayout.empty();
}
