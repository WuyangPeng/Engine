// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 10:27)

#ifndef RENDERING_DETAIL_DLOD_NODE_IMPL_H
#define RENDERING_DETAIL_DLOD_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"

#include <vector>
#include "Rendering/DataTypes/DataTypesFwd.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
	

	class RENDERING_HIDDEN_DECLARE DlodNodeImpl
	{
		using ClassType = DlodNodeImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using APoint = Mathematics::FloatAPoint;

	public:
		DlodNodeImpl();
		explicit DlodNodeImpl(int numLevelsOfDetail);

		CLASS_INVARIANT_DECLARE;

		void Load(BufferSource& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const;
		
		// ��������(LOD)ϸ�ڵȼ���
		const APoint GetModelCenter() const noexcept;		
		const APoint GetWorldCenter () const noexcept;

		void SetModelCenter(const APoint& modelCenter) noexcept;
                void SetWorldCenter(const FloatTransform& transform) noexcept;
		
		// ����ӽڵ�ľ�������
		int GetNumLevelsOfDetail () const noexcept;
		float GetModelMinDistance (int index) const;
		float GetModelMaxDistance(int index) const;
		float GetWorldMinDistance(int index) const;
		float GetWorldMaxDistance(int index) const;
		void SetModelDistance(int index, float minDistance, float maxDistance);
		void SetWorldDistance( float uniformScale) noexcept;

	private:		
		// �õ�ľ��룬���������ȷ�ļ����ӽڵ㡣
		APoint m_ModelLodCenter;
		APoint m_WorldLodCenter;
		
		// ����ÿ��LOD�����ƽ�����롣

		// �ӽڵ������
		int m_NumLevelsOfDetail;  
		std::vector<float> m_ModelMinDistance;
		std::vector<float> m_ModelMaxDistance;
		std::vector<float> m_WorldMinDistance;
		std::vector<float> m_WorldMaxDistance;
	};
}

#endif // RENDERING_DETAIL_DLOD_NODE_IMPL_H
