// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.3.0 (2020/03/27 10:01)

#ifndef RENDERING_RENDERERS_PICKRAY_H
#define RENDERING_RENDERERS_PICKRAY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h" 

#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"

#include <boost/noncopyable.hpp> 

RENDERING_EXPORT_SHARED_PTR(PickRayImpl);

namespace Rendering
{
	// ����ָ����������Ļ���꣨x��y����ʹ�õ�ǰ�����������ߡ� 
	// ����ġ�ԭ�㡱�����λ�ã����������ǵ�λ����ʸ���� 
	// ���߶������������С� �����x��y���ڵ�ǰ�ӿ��е��򷵻�ֵΪ'true'��
	class RENDERING_DEFAULT_DECLARE PickRay
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(PickRay);
		using ClassType = PickRay;

	public:
		PickRay();
		PickRay(bool result, const Mathematics::FloatAPoint& origin, const Mathematics::FloatAVector& direction);
	
		CLASS_INVARIANT_DECLARE;

		bool IsResult() const noexcept;
		Mathematics::FloatAPoint GetOrigin() const noexcept;
		Mathematics::FloatAVector GetDirection() const noexcept;

	private:
		IMPL_TYPE_DECLARE(PickRay);
	};
}

#endif // RENDERING_RENDERERS_PICKRAY_H



