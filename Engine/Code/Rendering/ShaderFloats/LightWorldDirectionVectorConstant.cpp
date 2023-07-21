///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:05)

#include "Rendering/RenderingExport.h"

#include "LightWorldDirectionVectorConstant.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, LightWorldDirectionVectorConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightWorldDirectionVectorConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightWorldDirectionVectorConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, LightWorldDirectionVectorConstant);

Rendering::LightWorldDirectionVectorConstant::LightWorldDirectionVectorConstant(const LightSharedPtr& light)
    : ParentType{ light }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, LightWorldDirectionVectorConstant)

void Rendering::LightWorldDirectionVectorConstant::Update(MAYBE_UNUSED const Visual* visual, MAYBE_UNUSED const Camera* camera) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

Rendering::ShaderFloatSharedPtr Rendering::LightWorldDirectionVectorConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
