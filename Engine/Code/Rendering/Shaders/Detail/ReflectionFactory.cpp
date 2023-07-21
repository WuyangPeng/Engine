///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:31)

#include "Rendering/RenderingExport.h"

#include "ReflectionFactory.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflection.h"

CLASS_INVARIANT_STUB_DEFINE(Rendering, ReflectionFactory)

Rendering::ReflectionFactory::ReflectionSharedPtr Rendering::ReflectionFactory::Create(OpenGLUInt handle)
{
    return std::make_shared<GLSLReflection>(handle);
}

Rendering::ReflectionFactory::ReflectionSharedPtr Rendering::ReflectionFactory::Create()
{
    return std::make_shared<GLSLReflection>();
}
