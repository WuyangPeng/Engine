// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.3.0 (2020/03/27 10:01)

#ifndef RENDERING_RENDERERS_PICKRAY_IMPL_H
#define RENDERING_RENDERERS_PICKRAY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h" 

#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"

#include <boost/noncopyable.hpp> 

namespace Rendering
{
	// ����ָ����������Ļ���꣨x��y����ʹ�õ�ǰ�����������ߡ� 
	// ����ġ�ԭ�㡱�����λ�ã����������ǵ�λ����ʸ���� 
	// ���߶������������С� �����x��y���ڵ�ǰ�ӿ��е��򷵻�ֵΪ'true'��
	class RENDERING_HIDDEN_DECLARE PickRayImpl
	{
	public:
		using ClassType = PickRayImpl;

	public:
		PickRayImpl();
		PickRayImpl(bool result, const Mathematics::APointf& origin, const Mathematics::AVectorf& direction);
	
		CLASS_INVARIANT_DECLARE;

		bool IsResult() const noexcept;
		Mathematics::APointf GetOrigin() const;
		Mathematics::AVectorf GetDirection() const;

	private:
		bool m_Result;
		Mathematics::APointf m_Origin;
		Mathematics::AVectorf m_Direction;
	};
}

#endif // RENDERING_RENDERERS_PICKRAY_IMPL_H



