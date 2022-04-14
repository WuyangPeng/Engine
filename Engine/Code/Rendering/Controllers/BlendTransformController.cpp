// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 14:18)

#include "Rendering/RenderingExport.h"

#include "BlendTransformController.h"
#include "Detail/BlendTransformControllerImpl.h"
#include "Rendering/SceneGraph/Spatial.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26434)
CORE_TOOLS_RTTI_DEFINE(Rendering, BlendTransformController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BlendTransformController);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BlendTransformController);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, BlendTransformController);

Rendering::BlendTransformController
	::BlendTransformController(const TransformControllerSharedPtr& firstController,const TransformControllerSharedPtr& secondController, 
							   bool rotationScaleMatrices,bool geometricRotation,bool geometricScale) 
	: ParentType{ TransformF{} }, impl{ make_shared<ImplType>(firstController, secondController, rotationScaleMatrices, geometricRotation, geometricScale) }
{
     RENDERING_SELF_CLASS_IS_VALID_1;
}

 
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
COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, BlendTransformController)

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BlendTransformController)

Rendering::ControllerInterfaceSharedPtr Rendering::BlendTransformController
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

CoreTools::ObjectInterfaceSharedPtr Rendering::BlendTransformController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
} 
									  
Rendering::BlendTransformController
	::BlendTransformController(LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>()}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::BlendTransformController
::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();	 

	size += impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::BlendTransformController
::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;    

	const auto uniqueID = ParentType::Register(target);
	if (uniqueID != 0)
	{
		impl->Register(target);
	}

	return uniqueID;
}

void Rendering::BlendTransformController
::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::BlendTransformController::Link(CoreTools::ObjectLink& source)
{
	;

	ParentType::Link(source); 	

	//impl->Link(source);
}

void Rendering::BlendTransformController
::PostLink ()
{
	;
    
	ParentType::PostLink();	 
}

void Rendering::BlendTransformController::Load(CoreTools::BufferSource& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	//impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController, GetFirstController, const Rendering::ConstTransformControllerSharedPtr)	

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController, GetSecondController, const Rendering::ConstTransformControllerSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController,IsRotationScaleMatrices,bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, BlendTransformController, SetWeight, float, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController, GetWeight, float)
									
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController, IsGeometricRotation, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController, IsGeometricScale, bool)


void Rendering::BlendTransformController
	::SetObject(ControllerInterface* object) 
{
	;
	RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Spatial::GetCurrentRttiType()), "Œﬁ–ß¿‡\n");
	
	ParentType::SetObject(object);
	impl->SetObject(object); 
}

void Rendering::BlendTransformController
	::SetObjectInCopy(ControllerInterface* object) 
{
	;
	
	ParentType::SetObject(object);
	impl->SetObject(object); 
}

bool Rendering::BlendTransformController
	::Update(double applicationTime)
{
	;

	if (ParentType::Update(applicationTime))
	{
		impl->Update(applicationTime); 

		auto blendTranslate = impl->GetBlendTranslate();

		SetTranslate(blendTranslate);

		if (impl->IsRotationScaleMatrices())
		{
			const auto blendQuaternion = impl->GetBlendQuaternion();

			SetRotate(blendQuaternion);

			auto blendScale = impl->GetBlendScale();

			SetScale(blendScale);
		}
		else
		{
			// À„ ıªÏ∫œæÿ’Û°£		
			const auto blendMatrix = impl->GetMatrix();

			SetMatrix(blendMatrix);
		}

		auto spatial = dynamic_cast<Spatial*>(GetControllerObject());

		spatial->SetLocalTransform(GetTransform());	 

		return true;

	}

	return false;	 
} 
#include STSTEM_WARNING_POP