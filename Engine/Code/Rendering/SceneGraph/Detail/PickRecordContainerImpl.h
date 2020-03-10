// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 19:23)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_IMPL_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_IMPL_H

#include "Rendering/SceneGraph/PickRecord.h" 

#include <vector>

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE PickRecordContainerImpl
	{
	public:
		using ClassType = PickRecordContainerImpl;

	public:	
		PickRecordContainerImpl();

		CLASS_INVARIANT_DECLARE;

		void InsertPickRecord(const PickRecord& pickRecord);
		void InsertPickRecord(const PickRecordContainerImpl& pickRecordContainerImpl);

		int GetSize() const;
		const PickRecord GetPickRecord(int index) const;
		bool IsEmpty() const;

	private:
		std::vector<PickRecord> m_PickRecord;
	};
}

#endif // RENDERING_SCENE_GRAPH_PICK_RECORD_CONTAINER_IMPL_H
