///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 18:32)

#ifndef RENDERING_SHADERS_VISUAL_EFFECT_H
#define RENDERING_SHADERS_VISUAL_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualTechnique.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(VisualEffect, VisualEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisualEffect : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(VisualEffect);
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        explicit VisualEffect(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualEffect);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // 支持延迟构造。函数追加新的technique到数组的末尾。
        void InsertTechnique(const VisualTechniqueSharedPtr& technique);

        NODISCARD int GetNumTechniques() const;
        NODISCARD ConstVisualTechniqueSharedPtr GetTechnique(int techniqueIndex) const;

        // 获得的effect的组件。
        NODISCARD int GetNumPasses(int techniqueIndex) const;
        NODISCARD ConstVisualPassSharedPtr GetPass(int techniqueIndex, int passIndex) const;
        NODISCARD ConstVertexShaderSharedPtr GetVertexShader(int techniqueIndex, int passIndex) const;
        NODISCARD ConstPixelShaderSharedPtr GetPixelShader(int techniqueIndex, int passIndex) const;
        NODISCARD ConstAlphaStateSharedPtr GetAlphaState(int techniqueIndex, int passIndex) const;
        NODISCARD ConstCullStateSharedPtr GetCullState(int techniqueIndex, int passIndex) const;
        NODISCARD ConstDepthStateSharedPtr GetDepthState(int techniqueIndex, int passIndex) const;
        NODISCARD ConstOffsetStateSharedPtr GetOffsetState(int techniqueIndex, int passIndex) const;
        NODISCARD ConstStencilStateSharedPtr GetStencilState(int techniqueIndex, int passIndex) const;
        NODISCARD ConstWireStateSharedPtr GetWireState(int techniqueIndex, int passIndex) const;

        void SaveVisualTechnique(WriteFileManager& manager) const;
        void LoadVisualTechnique(ReadFileManager& manager);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(VisualEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VisualEffect);
}

#endif  // RENDERING_SHADERS_VISUAL_EFFECT_H
