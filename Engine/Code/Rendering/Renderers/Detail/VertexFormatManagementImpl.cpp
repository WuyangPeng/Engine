///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 12:45)

#include "Rendering/RenderingExport.h"

#include "VertexFormatManagementImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Renderers/PlatformVertexFormat.h"

Rendering::VertexFormatManagementImpl::VertexFormatManagementImpl(const RendererSharedPtr& renderer)
    : renderer{ renderer }, vertexFormats{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::VertexFormatManagementImpl::IsValid() const noexcept
{
    if (renderer.lock())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::VertexFormatManagementImpl::Bind(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;

    if (vertexFormats.find(vertexFormat) == vertexFormats.end())
    {
        auto ptr = renderer.lock();
        if (ptr)
        {
            auto platformVertexForma = make_shared<PlatformVertexFormat>(ptr.get(), vertexFormat.get());
            vertexFormats.emplace(vertexFormat, platformVertexForma);
        }
    }
}

void Rendering::VertexFormatManagementImpl::Unbind(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;

    vertexFormats.erase(vertexFormat);
}

void Rendering::VertexFormatManagementImpl::Enable(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = vertexFormats.find(vertexFormat);
    PlatformVertexFormatSharedPtr platformVertexFormat;
    if (iter != vertexFormats.end())
    {
        platformVertexFormat = iter->second;
    }
    else
    {
        // �ӳٹ��졣
        auto ptr = renderer.lock();
        if (ptr)
        {
            platformVertexFormat = make_shared<PlatformVertexFormat>(ptr.get(), vertexFormat.get());
            vertexFormats.emplace(vertexFormat, platformVertexFormat);
        }
    }

    auto ptr = renderer.lock();
    if (ptr)
    {
        platformVertexFormat->Enable(ptr.get());
    }
}

void Rendering::VertexFormatManagementImpl::Disable(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = vertexFormats.find(vertexFormat);

    if (iter != vertexFormats.end())
    {
        auto platformVertexFormat = iter->second;

        auto ptr = renderer.lock();
        if (ptr)
        {
            platformVertexFormat->Disable(ptr.get());
        }
    }
}

Rendering::VertexFormatManagementImpl::PlatformVertexFormatSharedPtr Rendering::VertexFormatManagementImpl::GetResource(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = vertexFormats.find(vertexFormat);
    if (iter != vertexFormats.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ���ָ���Ķ����ʽ��Դ��"s));
    }
}
