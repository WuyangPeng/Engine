// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 17:32)

#include "Rendering/RenderingExport.h"

#include "ProjectorMatrixConstantImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::vector;
using std::string;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455) 
Rendering::ProjectorMatrixConstantImpl
	::ProjectorMatrixConstantImpl(const ProjectorSmartPointer& projector,bool biased, int biasScaleMatrixIndex)
	:ParentType{ projector }, m_Biased{ biased },m_BiasScaleMatrixIndex{ biasScaleMatrixIndex }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ProjectorMatrixConstantImpl
	::ProjectorMatrixConstantImpl()
	:ParentType{}, m_Biased{ false },m_BiasScaleMatrixIndex{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

  
#ifdef OPEN_CLASS_INVARIANT
bool Rendering::ProjectorMatrixConstantImpl
	::IsValid() const noexcept
{
	if(ParentType::IsValid() && 0 <= m_BiasScaleMatrixIndex && m_BiasScaleMatrixIndex <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT 

void Rendering::ProjectorMatrixConstantImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_1;

	ParentType::Load(source);
	m_Biased = source.ReadBool();
	source.Read(m_BiasScaleMatrixIndex);
}

void Rendering::ProjectorMatrixConstantImpl
	::Save(BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	ParentType::Save(target);
	target.WriteBool(m_Biased);
	target.Write(m_BiasScaleMatrixIndex);
}

int Rendering::ProjectorMatrixConstantImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = ParentType::GetStreamingSize();
	size += CORE_TOOLS_STREAM_SIZE(m_Biased);
	size += CORE_TOOLS_STREAM_SIZE(m_BiasScaleMatrixIndex);

	return size;
}

const Rendering::ProjectorMatrixConstantImpl::Matrix Rendering::ProjectorMatrixConstantImpl
	::GetProjectionViewWorldMatrix( const Matrix& projectionViewWorldMatrix ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (m_Biased)
	{
		return Projector::GetBiasScaleMatrix(m_BiasScaleMatrixIndex) * projectionViewWorldMatrix;
	}

	return projectionViewWorldMatrix;
}



#include STSTEM_WARNING_POP