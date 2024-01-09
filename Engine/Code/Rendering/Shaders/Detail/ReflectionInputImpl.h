/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:00)

#ifndef RENDERING_SHADERS_REFLECTION_INPUT_IMPL_H
#define RENDERING_SHADERS_REFLECTION_INPUT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <array>
#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ReflectionInputImpl
    {
    public:
        using ClassType = ReflectionInputImpl;
        using FactoryType = ReflectionInputFactory;

        using OpenGLInt = System::OpenGLInt;
        using ReferencedBy = std::array<OpenGLInt, 6>;
        using GLSLReflectionEnumType = System::GLSLReflectionEnumType;
        using ReflectionInputSharedPtr = std::shared_ptr<ReflectionInputImpl>;

    public:
        ReflectionInputImpl() noexcept;
        virtual ~ReflectionInputImpl() noexcept = default;
        ReflectionInputImpl(const ReflectionInputImpl& rhs) noexcept = default;
        ReflectionInputImpl& operator=(const ReflectionInputImpl& rhs) noexcept = default;
        ReflectionInputImpl(ReflectionInputImpl&& rhs) noexcept = default;
        ReflectionInputImpl& operator=(ReflectionInputImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ReflectionInputSharedPtr Clone() const = 0;

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
    };
}

#endif  // RENDERING_SHADERS_REFLECTION_INPUT_IMPL_H