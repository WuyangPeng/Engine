///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:21)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_DATA_BLOCK_H
#define RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_DATA_BLOCK_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Detail/ReflectionDataBlockImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GLSLReflectionDataBlock : public ReflectionDataBlockImpl
    {
    public:
        using ClassType = GLSLReflectionDataBlock;
        using ParentType = ReflectionDataBlockImpl;

    public:
        GLSLReflectionDataBlock() noexcept;
        explicit GLSLReflectionDataBlock(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ReflectionDataBlockSharedPtr Clone() const override;

        NODISCARD std::string GetName() const override;
        void SetName(const std::string& aName) override;

        NODISCARD OpenGLInt GetBufferBinding() const noexcept override;
        void SetBufferBinding(OpenGLInt aBufferBinding) noexcept override;

        NODISCARD OpenGLInt GetBufferDataSize() const noexcept override;
        void SetBufferDataSize(OpenGLInt aBufferDataSize) noexcept override;

        NODISCARD ReferencedBy GetReferencedBy() const noexcept override;
        NODISCARD OpenGLInt GetReferencedBy(int index) const override;
        void SetReferencedBy(int index, OpenGLInt aReferencedBy) override;

        NODISCARD OpenGLInt GetActiveVariables(int index) const override;
        void SetActiveVariables(int index, OpenGLInt aActiveVariables) override;
        NODISCARD int GetActiveVariablesCount() const override;
        void SetActiveVariables(const ActiveVariables& aActiveVariables) override;

    private:
        std::string name;
        OpenGLInt bufferBinding;
        OpenGLInt bufferDataSize;
        ReferencedBy referencedBy;
        ActiveVariables activeVariables;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_REFLECTION_DATA_BLOCK_H