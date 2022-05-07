///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 18:30)

#include "Rendering/RenderingExport.h"

#include "VertexShader.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Renderers/RendererManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, VertexShader);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VertexShader);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VertexShader);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, VertexShader);

using std::string;

Rendering::VertexShader::VertexShader(const string& programName, int numInputs, int numOutputs, int numConstants, int numSamplers)
    : ParentType(programName, numInputs, numOutputs, numConstants, numSamplers)
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VertexShader)

CoreTools::ObjectInterfaceSharedPtr Rendering::VertexShader::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
