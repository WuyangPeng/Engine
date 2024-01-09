/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:06)

#include "Rendering/RenderingExport.h"

#include "ReflectionAtomicCounterBufferFactory.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflectionAtomicCounterBuffer.h"

CLASS_INVARIANT_STUB_DEFINE(Rendering, ReflectionAtomicCounterBufferFactory)

Rendering::ReflectionAtomicCounterBufferFactory::ReflectionAtomicCounterBufferSharedPtr Rendering::ReflectionAtomicCounterBufferFactory::Create(OpenGLInt bufferBinding)
{
    return std::make_shared<GLSLReflectionAtomicCounterBuffer>(bufferBinding);
}

Rendering::ReflectionAtomicCounterBufferFactory::ReflectionAtomicCounterBufferSharedPtr Rendering::ReflectionAtomicCounterBufferFactory::Create()
{
    return std::make_shared<GLSLReflectionAtomicCounterBuffer>();
}
