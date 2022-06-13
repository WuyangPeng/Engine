///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/19 17:45)

#ifndef RENDERING_TERRAIN_TERRAIN_BASE_H
#define RENDERING_TERRAIN_TERRAIN_BASE_H

#include "Rendering/RenderingDll.h"

#include "TerrainPage.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Node.h"

namespace Rendering
{
    class TerrainBase : public Node
    {
    public:
        using ClassType = TerrainBase;
        using ParentType = Node;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TerrainBase);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

    public:
        TerrainBase(const System::String& heightName, const VertexFormatSharedPtr& vformat, const CameraSharedPtr& camera);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetRowQuantity() const noexcept;
        NODISCARD int GetColQuantity() const noexcept;
        NODISCARD int GetSize() const noexcept;
        NODISCARD float GetMinElevation() const noexcept;
        NODISCARD float GetMaxElevation() const noexcept;
        NODISCARD float GetSpacing() const noexcept;

        NODISCARD TerrainPageSharedPtr GetPage(int row, int col);
        NODISCARD TerrainPageSharedPtr GetCurrentPage(float x, float y) const;
        NODISCARD float GetHeight(float x, float y) const;

        NODISCARD AVector GetNormal(float x, float y) const;

        NODISCARD TerrainPageSharedPtr ReplacePage(int row, int col, const System::String& heightName, const System::String& heightSuffix);

        NODISCARD TerrainPageSharedPtr ReplacePage(int row, int col, TerrainPageSharedPtr newPage);

        void OnCameraMotion();
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        void LoadHeader(const System::String& heightName);

        void LoadPage(int row, int col, const System::String& heightName, const System::String& heightSuffix);

    private:
        int mode;

        CoreTools::ObjectAssociated<VertexFormat> vFormat;

        int numRows;
        int numCols;
        int size;
        float minElevation;
        float maxElevation;
        float spacing;
        std::vector<std::vector<CoreTools::ObjectAssociated<TerrainPage>>> pages;

        int cameraRow;
        int cameraCol;
        CoreTools::ObjectAssociated<Camera> camera;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(TerrainBase);
}

#endif  // RENDERING_TERRAIN_TERRAIN_BASE_H
