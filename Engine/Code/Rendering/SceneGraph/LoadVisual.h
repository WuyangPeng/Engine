// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 11:23)

#ifndef RENDERING_SCENE_GRAPH_LOAD_VISUAL_H
#define RENDERING_SCENE_GRAPH_LOAD_VISUAL_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"
#include "Flags/VisualFlags.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/VertexFormat.h"

#include <boost/noncopyable.hpp>
#include <string>
EXPORT_SHARED_PTR(Rendering, VisualData, RENDERING_DEFAULT_DECLARE);
 

namespace CoreTools
{
    class ReadFileManager;
}

namespace Rendering
{
    class Visual;

    class RENDERING_DEFAULT_DECLARE LoadVisual
    {
    public:
        using ClassType = LoadVisual;
        using ClassShareType = CoreTools::NonCopyClasses;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        explicit LoadVisual(const System::String& name);
        ~LoadVisual() noexcept = default;
        LoadVisual(const LoadVisual& rhs) noexcept = delete;
        LoadVisual& operator=(const LoadVisual& rhs) noexcept = delete;
        LoadVisual(LoadVisual&& rhs) noexcept = delete;
        LoadVisual& operator=(LoadVisual&& rhs) noexcept = delete;
        CLASS_INVARIANT_DECLARE;

        VisualPrimitiveType GetPrimitiveType() const;

        VertexFormatSharedPtr GetVertexFormat();
        VertexBufferSharedPtr GetVertexBuffer();
        IndexBufferSharedPtr GetIndexBuffer();

        static VisualSharedPtr CreateFromFile(const System::String& name);
        static VisualSharedPtr CreateFromFile(const System::String& name, int indexSize);

    private:
        using VisualDataPtr = std::shared_ptr<VisualData>;

    private:
        void LoadFromFile(const System::String& name);

    private:
        VisualDataPtr m_Data;
    };
}

#endif  // RENDERING_SCENE_GRAPH_LOAD_VISUAL_H
