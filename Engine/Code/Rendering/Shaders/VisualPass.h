// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:33)

#ifndef RENDERING_SHADERS_VISUAL_PASS_H
#define RENDERING_SHADERS_VISUAL_PASS_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/PixelShader.h"
#include "Rendering/Shaders/StencilState.h"
#include "Rendering/Shaders/VertexShader.h"
#include "Rendering/Shaders/WireState.h"

RENDERING_EXPORT_SHARED_PTR(VisualPassImpl);

namespace CoreTools
{
    class WriteFileManager;
    class ReadFileManager;
}

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisualPass : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(VisualPass);
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        VisualPass();
        ~VisualPass();
        VisualPass(VisualPass&&) noexcept = default;
        VisualPass& operator=(VisualPass&&) noexcept = default;
        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualPass);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        void SetVertexShader(const VertexShaderSmartPointer& vertexShader);
        void SetPixelShader(const PixelShaderSmartPointer& pixelShader);
        void SetAlphaState(const AlphaStateSmartPointer& alphaState);
        void SetCullState(const CullStateSmartPointer& cullState);
        void SetDepthState(const DepthStateSmartPointer& depthState);
        void SetOffsetState(const OffsetStateSmartPointer& offsetState);
        void SetStencilState(const StencilStateSmartPointer& stencilState);
        void SetWireState(const WireStateSmartPointer& wireState);

        const ConstVertexShaderSmartPointer GetVertexShader() const;
        const ConstPixelShaderSmartPointer GetPixelShader() const;
        const ConstAlphaStateSmartPointer GetAlphaState() const;
        const ConstCullStateSmartPointer GetCullState() const;
        const ConstDepthStateSmartPointer GetDepthState() const;
        const ConstOffsetStateSmartPointer GetOffsetState() const;
        const ConstStencilStateSmartPointer GetStencilState() const;
        const ConstWireStateSmartPointer GetWireState() const;

        void SaveShader(WriteFileManager& manager) const;
        void SaveState(WriteFileManager& manager) const;
        void LoadShader(ReadFileManager& manager);
        void LoadState(ReadFileManager& manager);

    private:
        IMPL_TYPE_DECLARE(VisualPass);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(VisualPass);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, VisualPass);
}

#endif  // RENDERING_SHADERS_VISUAL_PASS_H
