// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 16:31)

#include "Rendering/RenderingExport.h"

#include "PickerImpl.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/Detail/SwitchNode.h"
#include "Rendering/Resources/VertexBufferAccessorDetail.h"
#include "Rendering/SceneGraph/PickRecord.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
 #include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
 #include SYSTEM_WARNING_DISABLE(26418)
Rendering::PickerImpl 
	::PickerImpl(const ConstSpatialSmartPointer& scene, const APoint& origin,const AVector& direction, float tMin, float tMax)
	:m_Origin{ origin }, m_Direction{ direction }, m_TMin{ tMin }, m_TMax{ tMax }, m_Records{}
{
	ExecuteRecursive(scene);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
void Rendering::PickerImpl
	::ExecuteRecursive(const ConstSpatialSmartPointer& object)
{
	m_Records = object->ExecuteRecursive(m_Origin, m_Direction, m_TMin, m_TMax);
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::PickerImpl
	::IsValid() const  noexcept
{
	if (m_TMin <= m_TMax)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	


bool Rendering::PickerImpl
	::IsRecordsExist() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return !m_Records.IsEmpty();
}

const Rendering::PickRecord Rendering::PickerImpl
	::GetClosestToZero() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
		 
	if (IsRecordsExist())
	{
		auto closest = Mathematics::Mathf::FAbs(m_Records.GetPickRecord(0).GetParameter());
		auto index = 0;
		const auto numRecords = m_Records.GetSize();
		for (auto i = 1; i < numRecords; ++i)
		{
			auto parameter = Mathematics::Mathf::FAbs(m_Records.GetPickRecord(i).GetParameter());
			if (parameter < closest)
			{
				closest = parameter;
				index = i;
			}
		}
		return m_Records.GetPickRecord(index);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("记录不存在！"s));
	}	
}

const Rendering::PickRecord Rendering::PickerImpl
	::GetClosestNonnegative() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (IsRecordsExist())
	{
		// 获取第一个正数。
		auto closest = Mathematics::Mathf::sm_MaxReal;
		 
		const auto numRecords = m_Records.GetSize();
		auto findIndex = -1;
		for (auto i = 0; i < numRecords; ++i)
		{
			auto parameter = m_Records.GetPickRecord(i).GetParameter();
			if (0.0f <= parameter)
			{
				closest = parameter;
				findIndex = i;
				break;
			}
		}
		if (findIndex == -1)
		{		
			THROW_EXCEPTION(SYSTEM_TEXT("记录的值都是负数！"s));		
		}

		for (auto i = findIndex + 1; i < numRecords; ++i)
		{
			auto parameter = m_Records.GetPickRecord(i).GetParameter();
			if (0.0f <= parameter && parameter < closest)
			{
				closest = parameter;
				findIndex = i;
			}
		}
		return m_Records.GetPickRecord(findIndex);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("记录不存在！"s));
	}	
}

const Rendering::PickRecord Rendering::PickerImpl
	::GetClosestNonpositive() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (IsRecordsExist())
	{
		// 获取第一个负数。
		auto closest = -Mathematics::Mathf::sm_MaxReal;

		const auto numRecords = m_Records.GetSize();
		auto findIndex = -1;

		for (auto i = 0; i < numRecords; ++i)
		{
			auto parameter = m_Records.GetPickRecord(i).GetParameter();
			if (parameter <= 0.0f)
			{
				closest = parameter;
				findIndex = i;
				break;
			}
		}
		if (closest == -1)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("记录的值都是正数！"s));
		}

		for (auto i = findIndex + 1; i < numRecords; ++i)
		{
			auto parameter = m_Records.GetPickRecord(i).GetParameter();
			if (closest < parameter && parameter <= 0.0f)
			{
				closest = parameter;
				findIndex = i;				
			}		
		}
		
		return m_Records.GetPickRecord(findIndex);

	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("记录不存在！"s));
	}	
}


#include STSTEM_WARNING_POP