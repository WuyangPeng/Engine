/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 21:49)

#ifndef RENDERING_TERRAIN_TERRAIN_PAGE_IMPL_H
#define RENDERING_TERRAIN_TERRAIN_PAGE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/Vector2.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TerrainPageImpl
    {
    public:
        using ClassType = TerrainPageImpl;

        using HeightsType = std::vector<uint16_t>;
        using Vector2 = Mathematics::Vector2F;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        TerrainPageImpl() noexcept;
        TerrainPageImpl(int size,
                        float minElevation,
                        float maxElevation,
                        float spacing,
                        const Vector2& origin);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetSize() const noexcept;
        NODISCARD HeightsType GetHeights() const noexcept;
        NODISCARD Vector2 GetOrigin() const noexcept;
        NODISCARD float GetMinElevation() const noexcept;
        NODISCARD float GetMaxElevation() const noexcept;
        NODISCARD float GetSpacing() const noexcept;

        void SetHeights(int index, uint16_t height);
        NODISCARD float GetHeight(float x, float y) const;

        NODISCARD float GetHeight(int index) const;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        NODISCARD static HeightsType GetHeights(int size);

        NODISCARD float GetHeight(int row, int col) const;

    private:
        int size;
        float minElevation;
        float maxElevation;
        float spacing;
        Vector2 origin;
        HeightsType heights;
    };
}

#endif  // RENDERING_TERRAIN_TERRAIN_PAGE_IMPL_H
