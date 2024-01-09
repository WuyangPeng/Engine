/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 21:53)

#ifndef RENDERING_TERRAIN_TERRAIN_PAGE_H
#define RENDERING_TERRAIN_TERRAIN_PAGE_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Base/Float.h"
#include "Rendering/SceneGraph/Visual.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(TerrainPage, TerrainPageImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TerrainPage : public Visual
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(TerrainPage);
        using ParentType = Visual;

        using HeightsType = std::vector<uint16_t>;
        using Vector2 = Mathematics::Vector2F;

    public:
        TerrainPage(const std::string& name,
                    int size,
                    float minElevation,
                    float maxElevation,
                    float spacing,
                    float length,
                    const Vector2& origin,
                    const VertexFormatSharedPtr& vertexFormat);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TerrainPage);

        NODISCARD HeightsType GetHeights() const noexcept;
        NODISCARD Vector2 GetOrigin() const noexcept;
        void SetHeights(const HeightsType& height);

        NODISCARD float GetHeight(float x, float y) const;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD ControllerSharedPtr Clone() const override;

    private:
        NODISCARD static VisualSharedPtr CreateRectangle(int size, float length, const VertexFormatSharedPtr& vertexFormat);

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TerrainPage);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TerrainPage);

}

#endif  // RENDERING_TERRAIN_TERRAIN_PAGE_H
