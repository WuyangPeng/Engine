// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:27)

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
		
		// 访问中心(LOD)细节等级。
		const APoint GetModelCenter() const noexcept;		
		const APoint GetWorldCenter () const noexcept;

		void SetModelCenter(const APoint& modelCenter) noexcept;
                void SetWorldCenter(const FloatTransform& transform) noexcept;
		
		// 获得子节点的距离间隔。
		int GetNumLevelsOfDetail () const noexcept;
		float GetModelMinDistance (int index) const;
		float GetModelMaxDistance(int index) const;
		float GetWorldMinDistance(int index) const;
		float GetWorldMaxDistance(int index) const;
		void SetModelDistance(int index, float minDistance, float maxDistance);
		void SetWorldDistance( float uniformScale) noexcept;

	private:		
		// 该点的距离，相机决定正确的激活子节点。
		APoint m_ModelLodCenter;
		APoint m_WorldLodCenter;
		
		// 对于每个LOD区间的平方距离。

		// 子节点的数量
		int m_NumLevelsOfDetail;  
		std::vector<float> m_ModelMinDistance;
		std::vector<float> m_ModelMaxDistance;
		std::vector<float> m_WorldMinDistance;
		std::vector<float> m_WorldMaxDistance;
	};
}

#endif // RENDERING_DETAIL_DLOD_NODE_IMPL_H
