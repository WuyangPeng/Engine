// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:32)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_H

#include "Spatial.h"

#include "System/Helper/PragmaWarning/Operators.h"

RENDERING_EXPORT_SHARED_PTR(PickRecordImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE PickRecord : private boost::totally_ordered<PickRecord>
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(PickRecord);

	public:
		// 它存在支持const static PickRecord在Picker构造。
		PickRecord();

		CLASS_INVARIANT_DECLARE;

		ConstSpatialSmartPointer GetIntersected() const;
		float GetParameter() const;
		int GetTriangle() const;
		float GetBary(int index) const;

		void SetIntersected(const ConstSpatialSmartPointer& intersected);
		void SetParameter(float parameter);
		void SetTriangle(int triangle);
		void SetBary(float firstBary, float secondBary);

		bool operator== ( const PickRecord& rhs) const;
		bool operator< (const PickRecord& rhs) const;

	private:
		IMPL_TYPE_DECLARE(PickRecord);
	};
}

#endif // RENDERING_SCENE_GRAPH_PICK_RECORD_H
