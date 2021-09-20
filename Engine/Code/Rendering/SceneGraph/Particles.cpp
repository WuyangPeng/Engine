// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 17:50)

#include "Rendering/RenderingExport.h"

#include "Particles.h"
#include "Detail/ParticlesImpl.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/SceneGraph/Culler.h"
#include "Rendering/Renderers/RendererManager.h" 
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::make_shared;
 #include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26456)
CORE_TOOLS_RTTI_DEFINE(Rendering, Particles);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Particles);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Particles);

Rendering::Particles
	::Particles(const VertexFormatSharedPtr& vertexformat,const VertexBufferSharedPtr& vertexbuffer,
				int indexSize, const vector<APoint>& positions,const vector<float>& sizes, float sizeAdjust) 
	:ParentType{ vertexformat, vertexbuffer, IndexBufferSharedPtr() },
	 impl{ make_shared<ImplType>(positions, sizes, sizeAdjust) }
{
	InitIndexBuffer(indexSize);
	InitTextureCoord();

	// 计算边界范围仅基于粒子的位置。
	ComputeBounding(positions);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::Particles
	::InitIndexBuffer(int indexSize)
{
	RENDERING_ASSERTION_1(indexSize == 2 || indexSize == 4, "无效索引大小。\n");

	auto numVertices = GetVertexBuffer()->GetNumElements();
const	auto numParticles = numVertices / 4;

	RENDERING_ASSERTION_1(numVertices % 4 == 0, "顶点数必须是4的倍数。\n");
	RENDERING_ASSERTION_1(numParticles == impl->GetNumParticles(), "粒子数必须和位置数组大小相等。\n");

	IndexBufferSharedPtr indexBuffer{ std::make_shared< IndexBuffer>(6 * numParticles, indexSize) };
	indexBuffer->InitIndexBufferInParticles();
	SetIndexBuffer(indexBuffer);	
}

void Rendering::Particles
	::InitTextureCoord() 
{
	// 得到的纹理坐标。
	VertexBufferAccessor vertexBufferAccessor{ GetConstVertexFormat(), GetConstVertexBuffer() };

	RENDERING_ASSERTION_1(vertexBufferAccessor.HasTextureCoord(0),"纹理坐标必须存在且使用通道0\n");

	// 设置纹理坐标为标准的。
	GetVertexBuffer()->SetTextureCoordStandard(vertexBufferAccessor);
}

Rendering::Particles
	::~Particles() 
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
    COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, Particles)

 CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Particles)

Rendering::ControllerInterfaceSharedPtr Rendering::Particles
	::Clone() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
} 

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Particles,GetNumParticles, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Particles,GetPosition,int, const Rendering::Particles::APoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Particles,GetSize,int,float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Particles,SetSizeAdjust, float,void)										  
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Particles,GetSizeAdjust, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Particles, GetNumActive, int)

									
void Rendering::Particles
	::SetPosition(int index, const APoint& position)
{
	;

	return impl->SetPosition(index, position);
}

void Rendering::Particles
	::SetSize(int index, float size) 
{
	;

	return impl->SetSize(index, size);
}


void Rendering::Particles
	::SetNumActive(int numActive)
{
	;

	impl->SetNumActive(numActive);
	numActive = impl->GetNumActive();
	GetIndexBuffer()->SetNumElements(6 * numActive);
	GetVertexBuffer()->SetNumElements(4 * numActive);
}

void Rendering::Particles
	::GenerateParticles(const ConstCameraSharedPtr& camera)
{
	RENDERING_CLASS_IS_VALID_1;

	// 获取位置。
	VertexBufferAccessor vertexBufferAccessor{ GetConstVertexFormat(), GetConstVertexBuffer() };
	RENDERING_ASSERTION_1(vertexBufferAccessor.HasPosition(), "Positions must exist\n");

	// 获取在粒子模型空间中相机的轴方向。
	auto transform = GetWorldTransform().GetInverseTransform();
        const auto upPlusRight = transform * (camera->GetUpVector() + camera->GetRightVector());
        const auto upMinusRight = transform * (camera->GetUpVector() - camera->GetRightVector());

	// 生成四边形像一对三角形。
        const auto numActive = impl->GetNumActive();
	for (auto index = 0; index < numActive; index += 4)
	{
            const auto position = impl->GetPosition(index);
            const auto trueSize = impl->GetTrueSize(index);
		auto scaledUpPlusRight = trueSize * upPlusRight;
		auto scaledUpMinusRight = trueSize * upMinusRight;

		GetVertexBuffer()->SetPosition(vertexBufferAccessor, index, position - scaledUpPlusRight);
		GetVertexBuffer()->SetPosition(vertexBufferAccessor, index + 1, position - scaledUpMinusRight);
		GetVertexBuffer()->SetPosition(vertexBufferAccessor, index + 2, position + scaledUpPlusRight);
		GetVertexBuffer()->SetPosition(vertexBufferAccessor, index + 3, position + scaledUpMinusRight); 
	}

	UpdateModelSpace(VisualUpdateType::Normals);
	 
	RENDERER_MANAGE_SINGLETON.UpdateAll(GetConstVertexBuffer().get());
}

void Rendering::Particles
	::GetVisibleSet(Culler& culler, bool noCull)
{
	GenerateParticles(culler.GetCamera());
	ParentType::GetVisibleSet(culler, noCull);
}

Rendering::Particles
	::Particles(LoadConstructor value)
	:ParentType{ value }, impl{ make_shared<ImplType>() }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Particles
    ::GetStreamingSize () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    auto size = ParentType::GetStreamingSize();
    
    size += impl->GetStreamingSize();  
    
    return size;
}

uint64_t Rendering::Particles
    ::Register( const CoreTools::ObjectRegisterSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	return ParentType::Register(target);    
}

void Rendering::Particles
    ::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);
    
	ParentType::Save(target);
	
	impl->Save(target);    
     
	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Particles
    ::Link (const CoreTools::ObjectLinkSharedPtr& source)
{
	;
    
	ParentType::Link(source); 
}

void Rendering::Particles
    ::PostLink ()
{
	;
    
	ParentType::PostLink();     
}

void Rendering::Particles
    ::Load (const CoreTools::BufferSourceSharedPtr& source)
{
	;
    
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);
    
    ParentType::Load(source);
	
	impl->Load(source);
        
    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
#include STSTEM_WARNING_POP