// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 18:13)

#include "Rendering/RenderingExport.h"

#include "ProjectorMatrixConstant.h"
#include "Detail/ProjectorMatrixConstantImpl.h"

#include "Rendering/SceneGraph/Visual.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26434)
CORE_TOOLS_RTTI_DEFINE(Rendering, ProjectorMatrixConstant);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ProjectorMatrixConstant);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ProjectorMatrixConstant); 
Rendering::ProjectorMatrixConstant::ProjectorMatrixConstant(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ make_shared<ImplType>() }
{
    SELF_CLASS_IS_VALID_0;
}
CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, ProjectorMatrixConstant)
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, ProjectorMatrixConstant);

#define COPY_CONSTRUCTION_DEFINE_WITH_PARENT(namespaceName, className)                      \
    namespaceName::className::className(const className& rhs)                               \
        : ParentType{ rhs }, impl{ std::make_shared<ImplType>(*rhs.impl) }                  \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        SELF_CLASS_IS_VALID_0;                                                              \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(const className& rhs)     \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        className temp{ rhs };                                                              \
        Swap(temp);                                                                         \
        return *this;                                                                       \
    }                                                                                       \
    void namespaceName::className::Swap(className& rhs) noexcept                            \
    {                                                                                       \
        ;                                       \
        std::swap(impl, rhs.impl);                                                          \
    }                                                                                       \
    namespaceName::className::className(className&& rhs) noexcept                           \
        : ParentType{ std::move(rhs) }, impl{ std::move(rhs.impl) }                         \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
    }                                                                                       \
    namespaceName::className& namespaceName::className::operator=(className&& rhs) noexcept \
    {                                                                                       \
        IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;                                       \
        ParentType::operator=(std::move(rhs));                                              \
        impl = std::move(rhs.impl);                                                         \
        return *this;                                                                       \
    }                                                                                        
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, ProjectorMatrixConstant);

Rendering::ProjectorMatrixConstant
	::ProjectorMatrixConstant(const ProjectorSharedPtr& projector,bool biased, int biasScaleMatrixIndex)
	:ParentType(sm_NumRegisters),  impl{ make_shared<ImplType>(projector,biased,biasScaleMatrixIndex) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ProjectorMatrixConstant)

void Rendering::ProjectorMatrixConstant
	::SetNumRegisters(int numRegisters)
{
	RENDERING_CLASS_IS_VALID_1;
	RENDERING_ASSERTION_2(numRegisters == sm_NumRegisters, "ProjectorMatrixConstantºƒ¥Ê∆˜µƒ ˝¡ø±ÿ–ÎŒ™4");

	ParentType::SetNumRegisters(numRegisters);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, ProjectorMatrixConstant,GetProjector, const Rendering::ConstProjectorSharedPtr )
									
void Rendering::ProjectorMatrixConstant::Update(const Visual* visual, [[maybe_unused]] const Camera* camera)
{
	RENDERING_CLASS_IS_VALID_1;

	const auto projectionViewMatrix = GetProjector()->GetProjectionViewMatrix();
	const auto worldMatrix = visual->GetWorldTransform().GetMatrix();
	auto projectionViewWorldMatrix = projectionViewMatrix * worldMatrix;
	projectionViewWorldMatrix = impl->GetProjectionViewWorldMatrix(projectionViewWorldMatrix);

	SetRegisters(projectionViewWorldMatrix);

	 
}

Rendering::ShaderFloatSharedPtr Rendering::ProjectorMatrixConstant
	::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ShaderFloatSharedPtr{ std::make_shared<ClassType>(*this) };
}

 #include STSTEM_WARNING_POP