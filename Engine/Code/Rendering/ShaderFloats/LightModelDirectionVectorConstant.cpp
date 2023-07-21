///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:04)

#include "Rendering/RenderingExport.h"

#include "LightModelDirectionVectorConstant.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, LightModelDirectionVectorConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightModelDirectionVectorConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightModelDirectionVectorConstant);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, LightModelDirectionVectorConstant);

Rendering::LightModelDirectionVectorConstant::LightModelDirectionVectorConstant(const LightSharedPtr& light)
    : ParentType{ light }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, LightModelDirectionVectorConstant)

void Rendering::LightModelDirectionVectorConstant::Update(const Visual* visual, MAYBE_UNUSED const Camera* camera) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    if (visual != nullptr)
    {
    }
}

Rendering::ShaderFloatSharedPtr Rendering::LightModelDirectionVectorConstant::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
