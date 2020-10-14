// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:33)

#ifndef RENDERING_SHADERS_VISUAL_PASS_H
#define RENDERING_SHADERS_VISUAL_PASS_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

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
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(VisualPass, DESTRUCTOR_STATEMENT);
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        VisualPass(); 

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualPass);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        void SetVertexShader(const VertexShaderSharedPtr& vertexShader);
        void SetPixelShader(const PixelShaderSharedPtr& pixelShader);
        void SetAlphaState(const AlphaStateSharedPtr& alphaState);
        void SetCullState(const CullStateSharedPtr& cullState);
        void SetDepthState(const DepthStateSharedPtr& depthState);
        void SetOffsetState(const OffsetStateSharedPtr& offsetState);
        void SetStencilState(const StencilStateSharedPtr& stencilState);
        void SetWireState(const WireStateSharedPtr& wireState);

        const ConstVertexShaderSharedPtr GetVertexShader() const;
        const ConstPixelShaderSharedPtr GetPixelShader() const;
        const ConstAlphaStateSharedPtr GetAlphaState() const;
        const ConstCullStateSharedPtr GetCullState() const;
        const ConstDepthStateSharedPtr GetDepthState() const;
        const ConstOffsetStateSharedPtr GetOffsetState() const;
        const ConstStencilStateSharedPtr GetStencilState() const;
        const ConstWireStateSharedPtr GetWireState() const;

        void SaveShader(WriteFileManager& manager) const;
        void SaveState(WriteFileManager& manager) const;
        void LoadShader(ReadFileManager& manager);
        void LoadState(ReadFileManager& manager);

        ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        IMPL_TYPE_DECLARE(VisualPass);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(VisualPass);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( VisualPass);
}

#endif  // RENDERING_SHADERS_VISUAL_PASS_H
