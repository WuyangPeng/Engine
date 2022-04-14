///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 14:45)

#include "Rendering/RenderingExport.h"

#include "LoadVisual.h"
#include "Polypoint.h"
#include "Polysegment.h"
#include "TrianglesFan.h"
#include "TrianglesMesh.h"
#include "TrianglesStrip.h"
#include "Visual.h"
#include "Detail/VisualData.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using CoreTools::ReadFileManager;
using std::make_shared;

Rendering::LoadVisual::LoadVisual(const System::String& name)
    : impl{ VisualPrimitiveType::None }
{
    LoadFromFile(name);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::LoadVisual::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::VisualPrimitiveType Rendering::LoadVisual::GetPrimitiveType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetPrimitiveType();
}

Rendering::VertexFormatSharedPtr Rendering::LoadVisual::GetVertexFormat() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetVertexFormat();
}

Rendering::VertexBufferSharedPtr Rendering::LoadVisual::GetVertexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetVertexBuffer();
}

Rendering::IndexBufferSharedPtr Rendering::LoadVisual::GetIndexBuffer() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetIndexBuffer();
}

void Rendering::LoadVisual::LoadFromFile(const System::String& name)
{
    ReadFileManager manager{ name };

    auto type = VisualPrimitiveType::None;

    manager.Read(sizeof(VisualPrimitiveType), &type);

    if (VisualPrimitiveType::None < type && type < VisualPrimitiveType::MaxQuantity)
    {
        auto vertexFormat = VertexFormat::LoadFromFile(manager);

        auto vertexBuffer = VertexBuffer::Create();

        vertexBuffer->ReadFromFile(manager, *vertexFormat);

        auto indexBuffer = IndexBuffer::Create();
        indexBuffer->ReadFromFile(manager);

        impl->SetPrimitiveType(type);
        impl->SetVertexFormat(vertexFormat);
        impl->SetVertexBuffer(vertexBuffer);

        if (indexBuffer->GetNumElements() != 0)
            impl->SetIndexBuffer(indexBuffer);
        else
            impl->SetIndexBuffer(nullptr);
    }
}

Rendering::VisualSharedPtr Rendering::LoadVisual::CreateFromFile(const System::String& name)
{
    LoadVisual loadVisual{ name };

    switch (loadVisual.GetPrimitiveType())
    {
        case VisualPrimitiveType::Polypoint:
        {
            return std::make_shared<Polypoint>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer());
        }
        case VisualPrimitiveType::PolysegmentsDisjoint:
        {
            return std::make_shared<Polysegment>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), false);
        }
        case VisualPrimitiveType::PolysegmentsContiguous:
        {
            return std::make_shared<Polysegment>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), true);
        }
        case VisualPrimitiveType::TriangleMesh:
        {
            return std::make_shared<TrianglesMesh>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), loadVisual.GetIndexBuffer());
        }
        case VisualPrimitiveType::TriangleStrip:
        {
            auto indexBuffer = loadVisual.GetIndexBuffer();
            if (!indexBuffer)
            {
                return std::make_shared<TrianglesStrip>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), 2);
            }
            else
            {
                return std::make_shared<TrianglesStrip>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), indexBuffer);
            }
        }
        case VisualPrimitiveType::TriangleFan:
        {
            auto indexBuffer = loadVisual.GetIndexBuffer();
            if (!indexBuffer)
            {
                return std::make_shared<TrianglesFan>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), 2);
            }
            else
            {
                return std::make_shared<TrianglesFan>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), indexBuffer);
            }
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("PrimitiveType错误！"s));
        }
    }
}

Rendering::VisualSharedPtr Rendering::LoadVisual::CreateFromFile(const System::String& name, int indexSize)
{
    LoadVisual loadVisual{ name };

    switch (loadVisual.GetPrimitiveType())
    {
        case VisualPrimitiveType::TriangleStrip:
        {
            return std::make_shared<TrianglesStrip>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), indexSize);
        }
        case VisualPrimitiveType::TriangleFan:
        {
            return std::make_shared<TrianglesFan>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), indexSize);
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("PrimitiveType错误！"s));
        }
    }
}
