// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:32)

#ifndef RENDERING_SCENE_GRAPH_PICKER_H
#define RENDERING_SCENE_GRAPH_PICKER_H

#include "Rendering/RenderingDll.h" 

#include "Spatial.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(Picker,PickerImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE Picker
	{
	public:
            DELAY_COPY_UNSHARED_TYPE_DECLARE(Picker);
		using APoint = Mathematics::APoint<float>;
		using AVector = Mathematics::AVector<float>;

	public:
		Picker(const ConstSpatialSharedPtr& scene, const APoint& origin, const AVector& direction, float tMin, float tMax);

		CLASS_INVARIANT_DECLARE;

		bool IsRecordsExist() const noexcept;
		
		// ��������������������Լ���ļ�¼��
		// ����Ӧ����0 < m_Records.GetSize()ʱ���á�

		// ��λ��¼����С����ֵ��Tֵ��
		const PickRecord GetClosestToZero() const;

		// ��λ��¼��ӽ������Ǹ�ֵ��Tֵ��
		const PickRecord GetClosestNonnegative() const;

		// ��λ��¼��ӽ���������ֵ��Tֵ��
		const PickRecord GetClosestNonpositive() const;

	private:
                PackageType impl;
	};
}

#endif // RENDERING_SCENE_GRAPH_PICKER_H
