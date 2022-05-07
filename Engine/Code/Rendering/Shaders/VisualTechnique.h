///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 21:10)

#ifndef RENDERING_SHADERS_VISUAL_TECHNIQUE_H
#define RENDERING_SHADERS_VISUAL_TECHNIQUE_H

#include "Rendering/RenderingDll.h"

#include "VisualPass.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(VisualTechnique, VisualTechniqueImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisualTechnique : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(VisualTechnique);
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        explicit VisualTechnique(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualTechnique);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // 支持延迟构造。函数追加新的pass到数组的末尾。
        void InsertPass(const VisualPassSharedPtr& pass);

        NODISCARD int GetNumPasses() const;
        NODISCARD ConstVisualPassSharedPtr GetPass(int passIndex) const;

        // 访问pass的组件。
        NODISCARD ConstVertexShaderSharedPtr GetVertexShader(int passIndex) const;
        NODISCARD ConstPixelShaderSharedPtr GetPixelShader(int passIndex) const;
        NODISCARD ConstAlphaStateSharedPtr GetAlphaState(int passIndex) const;
        NODISCARD ConstCullStateSharedPtr GetCullState(int passIndex) const;
        NODISCARD ConstDepthStateSharedPtr GetDepthState(int passIndex) const;
        NODISCARD ConstOffsetStateSharedPtr GetOffsetState(int passIndex) const;
        NODISCARD ConstStencilStateSharedPtr GetStencilState(int passIndex) const;
        NODISCARD ConstWireStateSharedPtr GetWireState(int passIndex) const;

        void SaveVisualPass(WriteFileManager& manager) const;
        void LoadVisualPass(ReadFileManager& manager);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(VisualTechnique);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VisualTechnique);
}

#endif  // RENDERING_SHADERS_VISUAL_TECHNIQUE_H
