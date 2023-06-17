///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionEnumMap.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionEnumMap::GLSLReflectionEnumMap(GLSLReflectionEnumType inValue, const std::string& inName, const std::string& inShaderName, int inRows, int inCols, int inSize)
    : value{ inValue },
      name{ inName },
      shaderName{ inShaderName },
      rows{ inRows },
      cols{ inCols },
      size{ inSize }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionEnumMap)

Rendering::GLSLReflectionEnumMap::GLSLReflectionEnumType Rendering::GLSLReflectionEnumMap::GetValue() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return value;
}

std::string Rendering::GLSLReflectionEnumMap::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

std::string Rendering::GLSLReflectionEnumMap::GetShaderName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return shaderName;
}

int Rendering::GLSLReflectionEnumMap::GetRows() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rows;
}

int Rendering::GLSLReflectionEnumMap::GetCols() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cols;
}

int Rendering::GLSLReflectionEnumMap::GetSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return size;
}
