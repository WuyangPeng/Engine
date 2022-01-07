// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 17:17)

#include "Rendering/RenderingExport.h"

#include "Camera.h"
#include "Detail/CameraImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2DDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering,Camera);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,Camera);
CORE_TOOLS_FACTORY_DEFINE(Rendering,Camera); 

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
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, Camera);

Rendering::Camera
    ::Camera (bool isPerspective,float epsilon)
	:ParentType{ "Camera" }, impl{ make_shared<ImplType>(isPerspective,epsilon) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,Camera)

void Rendering::Camera
     ::SetFrame (const APoint& position,const AVector& directionVector,const AVector& upVector,const AVector& rightVector)
{
	;
   
    return impl->SetFrame(position,directionVector,upVector,rightVector);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Camera,SetPosition,APoint,void)

void Rendering::Camera
    ::SetAxes (const AVector& directionVector,const AVector& upVector,const AVector& rightVector)
{
	;
    
    return impl->SetAxes(directionVector,upVector,rightVector);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetEpsilon, float)
    IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Camera,GetPosition,const Rendering::Camera::APoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Camera, GetDirectionVector,const Rendering::Camera::AVector)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Camera,GetUpVector,const Rendering::Camera::AVector)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Camera,GetRightVector,const Rendering::Camera::AVector)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering,Camera,GetViewMatrix,const Rendering::Camera::Matrix)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, IsPerspective, bool)

void Rendering::Camera
    ::SetFrustum (float directionMin, float directionMax,float upMin, float upMax,float rightMin, float rightMax)
{
	;
    
    return impl->SetFrustum(directionMin,directionMax,upMin,upMax,rightMin,rightMax);

}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Camera,SetFrustum,const float*,void)

void Rendering::Camera
    ::SetFrustum (float upFovDegrees, float aspectRatio,float directionMin,float directionMax)
{
	;
    
    return impl->SetFrustum(upFovDegrees,aspectRatio,directionMin,directionMax);

}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetFrustum, const float*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetFrustumData, const Rendering::CameraFrustumData)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetDirectionMin, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetDirectionMax, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetUpMin, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetUpMax, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetRightMin, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetRightMax, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetProjectionMatrix, const Rendering::Camera::Matrix)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Camera,SetProjectionMatrix,Matrix,void)

void Rendering::Camera
    ::SetProjectionMatrix (const APoint& p00, const APoint& p10,const APoint& p11, const APoint& p01,float nearExtrude, float farExtrude)
{
	;
    
    return impl->SetProjectionMatrix(p00,p10,p11,p01,nearExtrude,farExtrude);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetDepthType, Rendering::DepthType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetProjectionViewMatrix, const Rendering::Camera::Matrix)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Camera,SetPreViewMatrix,Matrix,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetPreViewMatrix, const Rendering::Camera::Matrix)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, PreViewIsIdentity, bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering,Camera,SetPostProjectionMatrix,Matrix,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetPostProjectionMatrix, const Rendering::Camera::Matrix)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, PostProjectionIsIdentity, bool)

const Rendering::Camera::AxesAlignBoundingBox2D Rendering::Camera
      ::ComputeBoundingAABB (int numVertices,const char* vertices,int stride,const Matrix& worldMatrix) const
{
	;
    
    return impl->ComputeBoundingAABB(numVertices,vertices,stride,worldMatrix);
}


Rendering::Camera
    ::Camera (LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Camera
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = ParentType::GetStreamingSize();
    
	size += impl->GetStreamingSize();
    
	return size;
}

uint64_t Rendering::Camera
    ::Register( CoreTools::ObjectRegister& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);
}

void Rendering::Camera
    ::Save (CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	impl->Save(target);
    
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Camera
    ::Link (CoreTools::ObjectLink& source)
{
	;
    
	ParentType::Link(source);
}

void Rendering::Camera
    ::PostLink ()
{
	;
    
	ParentType::PostLink();
}

void Rendering::Camera
    ::Load (CoreTools::BufferSource& source)
{
	;
  
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	impl->Load(source);
    
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering,Camera,SetDepthType,DepthType, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::Camera::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}
 


#include STSTEM_WARNING_POP