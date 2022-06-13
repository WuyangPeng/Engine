///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/19 19:02)

#ifndef RENDERING_TERRAIN_TERRAIN_PAGE_H
#define RENDERING_TERRAIN_TERRAIN_PAGE_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/PragmaWarning.h"
#include "Mathematics/Base/Float.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
    class TerrainPage : public TrianglesMesh
    {
    public:
        using ClassType = TerrainPage;
        using ParentType = TrianglesMesh;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TerrainPage);

    public:
        TerrainPage(const VertexFormatSharedPtr& vformat,
                    int size,
                    const std::vector<uint16_t>& heights,
                    const Mathematics::Float2& origin,
                    float minElevation,
                    float maxElevation,
                    float spacing);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetSize() const noexcept;
        NODISCARD std::vector<uint16_t> GetHeights() const noexcept;
        NODISCARD const Mathematics::Float2& GetOrigin() const noexcept;
        NODISCARD float GetMinElevation() const noexcept;
        NODISCARD float GetMaxElevation() const noexcept;
        NODISCARD float GetSpacing() const noexcept;

        NODISCARD float GetHeight(float x, float y) const;

    protected:
        NODISCARD float GetX(int x) const;
        NODISCARD float GetY(int y) const;
        NODISCARD float GetHeight(int index) const;

    private:
        int pageSize;
        int sizeM1;
        std::vector<uint16_t> heights;
        Mathematics::Float2 origin;
        float minElevation;
        float maxElevation;
        float spacing;
        float invSpacing;
        float multiplier;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(TerrainPage);
}

#endif  // RENDERING_TERRAIN_TERRAIN_PAGE_H
