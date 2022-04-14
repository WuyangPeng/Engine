///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 14:41)

#ifndef RENDERING_SCENE_GRAPH_LOAD_VISUAL_H
#define RENDERING_SCENE_GRAPH_LOAD_VISUAL_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"
#include "Flags/VisualFlags.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/VertexFormat.h"

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
