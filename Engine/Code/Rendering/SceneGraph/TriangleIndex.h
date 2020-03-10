// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 14:49)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_INDEX_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_INDEX_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE TriangleIndex 
	{
	public:
		using ClassType = TriangleIndex;
			
	public:		
		TriangleIndex(int firstIndex,int secondIndex,int thirdIndex);

		CLASS_INVARIANT_DECLARE;

		int GetFirstIndex() const;
		int GetSecondIndex() const;
		int GetThirdIndex() const;

		int operator[](int index) const;

	private:
		int m_FirstIndex;
		int m_SecondIndex;
		int m_ThirdIndex;
	};	 
}

#endif // RENDERING_SCENE_GRAPH_TRIANGLES_INDEX_H
