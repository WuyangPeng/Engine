/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/25 21:44)

#ifndef RENDERING_TERRAIN_TERRAIN_BASE_IMPL_H
#define RENDERING_TERRAIN_TERRAIN_BASE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TerrainBaseImpl
    {
    public:
        using ClassType = TerrainBaseImpl;

        using Vector3 = Mathematics::Vector3F;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectRegister = CoreTools::ObjectRegister;

    public:
        TerrainBaseImpl() noexcept;
        TerrainBaseImpl(int numRows,
                        int numColumns,
                        int size,
                        float minElevation,
                        float maxElevation,
                        float spacing,
                        const CameraSharedPtr& camera);

        CLASS_INVARIANT_DECLARE;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumColumns() const noexcept;
        NODISCARD int GetSize() const noexcept;
        NODISCARD float GetMinElevation() const noexcept;
        NODISCARD float GetMaxElevation() const noexcept;
        NODISCARD float GetSpacing() const noexcept;
        NODISCARD float GetLength() const noexcept;
        NODISCARD CameraSharedPtr GetCamera();

        NODISCARD int GetCameraRow() const noexcept;
        NODISCARD int GetCameraColumn() const noexcept;

        void SetCameraRow(int aCameraRow) noexcept;
        void SetCameraColumn(int aCameraColumn) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);
        void Link(ObjectLink& source);
        void Register(ObjectRegister& target) const;

    private:
        using ObjectAssociated = CoreTools::ObjectAssociated<Camera>;

    private:
        void Check() const;

    private:
        int numRows;
        int numColumns;
        int size;
        float minElevation;
        float maxElevation;
        float spacing;
        float length;

        int cameraRow;
        int cameraColumn;
        ObjectAssociated camera;
    };
}

#endif  // RENDERING_TERRAIN_TERRAIN_BASE_IMPL_H
