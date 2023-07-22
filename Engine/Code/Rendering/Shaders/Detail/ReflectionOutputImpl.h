///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/05 11:23)

#ifndef RENDERING_SHADERS_REFLECTION_OUTPUT_IMPL_H
#define RENDERING_SHADERS_REFLECTION_OUTPUT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <array>
#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ReflectionOutputImpl
    {
    public:
        using ClassType = ReflectionOutputImpl;
        using FactoryType = ReflectionOutputFactory;

        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;
        using ReflectionOutputSharedPtr = std::shared_ptr<ReflectionOutputImpl>;

    public:
        ReflectionOutputImpl() noexcept;
        virtual ~ReflectionOutputImpl() noexcept = default;
        ReflectionOutputImpl(const ReflectionOutputImpl& rhs) noexcept = default;
        ReflectionOutputImpl& operator=(const ReflectionOutputImpl& rhs) noexcept = default;
        ReflectionOutputImpl(ReflectionOutputImpl&& rhs) noexcept = default;
        ReflectionOutputImpl& operator=(ReflectionOutputImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ReflectionOutputSharedPtr Clone() const = 0;

        NODISCARD virtual std::string GetName() const = 0;
        virtual void SetName(const std::string& aName) = 0;

        NODISCARD virtual GLSLReflectionEnumType GetType() const noexcept = 0;
        virtual void SetType(GLSLReflectionEnumType aType) noexcept = 0;

        NODISCARD virtual OpenGLInt GetLocation() const noexcept = 0;
        virtual void SetLocation(OpenGLInt aLocation) noexcept = 0;

        NODISCARD virtual OpenGLInt GetArraySize() const noexcept = 0;
        virtual void SetArraySize(OpenGLInt aArraySize) noexcept = 0;

        NODISCARD virtual ReferencedBy GetReferencedBy() const noexcept = 0;
        NODISCARD virtual OpenGLInt GetReferencedBy(int index) const = 0;
        virtual void SetReferencedBy(int index, OpenGLInt aReferencedBy) = 0;

        NODISCARD virtual OpenGLInt GetIsPerPatch() const noexcept = 0;
        virtual void SetIsPerPatch(OpenGLInt aIsPerPatch) noexcept = 0;

        NODISCARD virtual OpenGLInt GetLocationComponent() const noexcept = 0;
        virtual void SetLocationComponent(OpenGLInt aLocationComponent) noexcept = 0;

        NODISCARD virtual OpenGLInt GetLocationIndex() const noexcept = 0;
        virtual void SetLocationIndex(OpenGLInt aLocationIndex) noexcept = 0;
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_OUTPUT_IMPL_H