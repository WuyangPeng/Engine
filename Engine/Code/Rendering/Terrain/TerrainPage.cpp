/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 22:02)

#include "Rendering/RenderingExport.h"

#include "TerrainPage.h"
#include "Detail/TerrainPageImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/MeshFactory.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, TerrainPage)

CORE_TOOLS_RTTI_DEFINE(Rendering, TerrainPage)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TerrainPage);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TerrainPage);

Rendering::TerrainPage::TerrainPage(const std::string& name,
                                    int size,
                                    float minElevation,
                                    float maxElevation,
                                    float spacing,
                                    float length,
                                    const Vector2& origin,
                                    const VertexFormatSharedPtr& vertexFormat)
    : ParentType{ name, *CreateRectangle(size, length, vertexFormat) },
      impl{ size, minElevation, maxElevation, spacing, origin }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Visual::VisualSharedPtr Rendering::TerrainPage::CreateRectangle(int size, float length, const VertexFormatSharedPtr& vertexFormat)
{
    MeshFactory meshFactory{ vertexFormat };

    return meshFactory.CreateRectangle(size, size, length, length);
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TerrainPage)

Rendering::TerrainPage::TerrainPage(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::TerrainPage::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::TerrainPage::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::TerrainPage::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TerrainPage::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::TerrainPage::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::TerrainPage::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::TerrainPage::HeightsType Rendering::TerrainPage::GetHeights() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetHeights();
}

Rendering::TerrainPage::Vector2 Rendering::TerrainPage::GetOrigin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetOrigin();
}

void Rendering::TerrainPage::SetHeights(const HeightsType& height)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto vertexBuffer = GetVertexBuffer();
    const auto origin = impl->GetOrigin();
    const auto size = impl->GetSize();
    const auto spacing = impl->GetSpacing();

    auto vertices = vertexBuffer->GetStorage();
    const auto vertexSize = vertexBuffer->GetFormat().GetVertexSize();
    const auto step = vertexSize - CoreTools::GetStreamSize<float>() * 3;
    if (step < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("步进值为负数。"))
    }

    for (auto row = 0, i = 0; row < size; ++row)
    {
        const auto y = origin[1] + spacing * static_cast<float>(row);
        for (auto column = 0; column < size; ++column, ++i)
        {
            impl->SetHeights(i, height.at(i));
            vertices.Increase(origin[0] + spacing * static_cast<float>(column));
            vertices.Increase(y);
            vertices.Increase(impl->GetHeight(i));
            vertices += step;
        }
    }

    UpdateModelBound();
    UpdateModelNormals();
}

float Rendering::TerrainPage::GetHeight(float x, float y) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetHeight(x, y);
}

CoreTools::ObjectInterface::ObjectInterfaceSharedPtr Rendering::TerrainPage::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

Rendering::ControllerInterface::ControllerSharedPtr Rendering::TerrainPage::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
