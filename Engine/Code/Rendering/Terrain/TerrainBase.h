/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 21:53)

#ifndef RENDERING_TERRAIN_TERRAIN_BASE_H
#define RENDERING_TERRAIN_TERRAIN_BASE_H

#include "Rendering/RenderingDll.h"

#include "TerrainPage.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Node.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(TerrainBase, TerrainBaseImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TerrainBase : public Node
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(TerrainBase);
        using ParentType = Node;

        using Vector2 = Mathematics::Vector2F;
        using Vector3 = Mathematics::Vector3F;
        using HeightsType = std::vector<uint16_t>;

    public:
        TerrainBase(const std::string& name,
                    int numRows,
                    int numColumns,
                    int size,
                    float minElevation,
                    float maxElevation,
                    float spacing,
                    const VertexFormatSharedPtr& vertexFormat,
                    const CameraSharedPtr& camera);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TerrainBase);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumColumns() const noexcept;
        NODISCARD int GetSize() const noexcept;
        NODISCARD float GetMinElevation() const noexcept;
        NODISCARD float GetMaxElevation() const noexcept;
        NODISCARD float GetSpacing() const noexcept;

        NODISCARD ConstVisualSharedPtr GetPage(int row, int column) const;
        void SetHeights(int row, int column, const HeightsType& heights);
        NODISCARD HeightsType GetHeights(int row, int column) const;
        NODISCARD float GetHeight(float x, float y) const;
        NODISCARD Vector3 GetNormal(float x, float y) const;
        void OnCameraMotion();

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD ControllerSharedPtr Clone() const override;

    protected:
        NODISCARD ConstTerrainPageSharedPtr GetPage(float x, float y) const;

    private:
        void AttachTerrainPage(const std::string& name,
                               int numRows,
                               int numCols,
                               int size,
                               float minElevation,
                               float maxElevation,
                               float spacing,
                               const VertexFormatSharedPtr& vertexFormat,
                               const CameraSharedPtr& camera);

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TerrainBase);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TerrainBase);
}

#endif  // RENDERING_TERRAIN_TERRAIN_BASE_H
