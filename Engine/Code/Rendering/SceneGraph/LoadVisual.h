///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:09)

#ifndef RENDERING_SCENE_GRAPH_LOAD_VISUAL_H
#define RENDERING_SCENE_GRAPH_LOAD_VISUAL_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"
#include "Flags/VisualFlags.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"

#include <string>

RENDERING_NON_COPY_EXPORT_IMPL(VisualData);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE LoadVisual
    {
    public:
        using LoadVisualImpl = VisualData;
        NON_COPY_TYPE_DECLARE(LoadVisual);
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        explicit LoadVisual(const System::String& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD VisualPrimitiveType GetPrimitiveType() const noexcept;

        NODISCARD VertexFormatSharedPtr GetVertexFormat() noexcept;
        NODISCARD VertexBufferSharedPtr GetVertexBuffer() noexcept;
        NODISCARD IndexBufferSharedPtr GetIndexBuffer() noexcept;

        NODISCARD static VisualSharedPtr CreateFromFile(const System::String& name);
        NODISCARD static VisualSharedPtr CreateFromFile(const System::String& name, int indexSize);

    private:
        void LoadFromFile(const System::String& name);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_LOAD_VISUAL_H
