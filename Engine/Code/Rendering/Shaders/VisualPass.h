///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 21:06)

#ifndef RENDERING_SHADERS_VISUAL_PASS_H
#define RENDERING_SHADERS_VISUAL_PASS_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
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

RENDERING_COPY_UNSHARED_EXPORT_IMPL(VisualPass, VisualPassImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisualPass : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(VisualPass);
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        explicit VisualPass(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualPass);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        void SetVertexShader(const VertexShaderSharedPtr& vertexShader) noexcept;
        void SetPixelShader(const PixelShaderSharedPtr& pixelShader) noexcept;
        void SetAlphaState(const AlphaStateSharedPtr& alphaState) noexcept;
        void SetCullState(const CullStateSharedPtr& cullState) noexcept;
        void SetDepthState(const DepthStateSharedPtr& depthState) noexcept;
        void SetOffsetState(const OffsetStateSharedPtr& offsetState) noexcept;
        void SetStencilState(const StencilStateSharedPtr& stencilState) noexcept;
        void SetWireState(const WireStateSharedPtr& wireState) noexcept;

        NODISCARD ConstVertexShaderSharedPtr GetVertexShader() const noexcept;
        NODISCARD ConstPixelShaderSharedPtr GetPixelShader() const noexcept;
        NODISCARD ConstAlphaStateSharedPtr GetAlphaState() const noexcept;
        NODISCARD ConstCullStateSharedPtr GetCullState() const noexcept;
        NODISCARD ConstDepthStateSharedPtr GetDepthState() const noexcept;
        NODISCARD ConstOffsetStateSharedPtr GetOffsetState() const noexcept;
        NODISCARD ConstStencilStateSharedPtr GetStencilState() const noexcept;
        NODISCARD ConstWireStateSharedPtr GetWireState() const noexcept;

        void SaveShader(WriteFileManager& manager) const;
        void SaveState(WriteFileManager& manager) const;
        void LoadShader(ReadFileManager& manager);
        void LoadState(ReadFileManager& manager);

        ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(VisualPass);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VisualPass);
}

#endif  // RENDERING_SHADERS_VISUAL_PASS_H
