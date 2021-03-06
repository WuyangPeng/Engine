// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/22 11:40)

#ifndef RENDERING_SCENE_GRAPH_POLYSEGMENT_H
#define RENDERING_SCENE_GRAPH_POLYSEGMENT_H

#include "Rendering/RenderingDll.h"

#include "Visual.h" 

namespace Rendering
{	
	class RENDERING_DEFAULT_DECLARE Polysegment : public Visual	
	{
	public:
		using ClassType = Polysegment;
		using ParentType = Visual;
		using ClassShareType = CoreTools::CopyUnsharedClasses;
		using PolysegmentSharedPtr = std::shared_ptr<ClassType>;
		using ConstPolysegmentSharedPtr = std::shared_ptr<ClassType>;

	public:
		// 如果'contiguous'是'true'，则该顶点形成意义上真正的polysegment，每对连续的顶点是由线段连接。
		// 例如，{ V0, V1, V2, V3 } 形式线段<V0, V1>, <V1, V2>, and <V2, V3>。
		// 如果你想有一个封闭的polysegment，输入顶点缓冲区的最后一个元素必须是第一个元素的副本。
		// 例如，{V0, V1, V2, V3 = V0}形成具有线段的三角形<V0, V1>, <V1, V2>, and <V2, V0>。
		// 如果'contiguous'是'false'，顶点形成一组断开的线段。
		// 例如，{V0, V1, V2, V3}形式线段<V0, V1>和 <V2, V3>。
		// 在这种情况下，输入顶点缓冲器必须具有偶数数目的元素。
		Polysegment(const VertexFormatSharedPtr& vertexformat,const VertexBufferSharedPtr& vertexbuffer,bool contiguous);
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Polysegment); 
		
		// 允许应用程序指定的数量小于polysegment的线段数量用于绘制。
		// 对于一个连续的polysegment，0 <= numSegments <= numVertices - 1。
		// 对于不相交的线段，0 <= numSegments <= numVertices / 2。 
		int GetMaxNumSegments () const;
		void SetNumSegments (int numSegments);
                int GetNumSegments() const noexcept;

	    // 当'contiguous'是'true'，所述polysegment是连接线段的序列。
		// 当是一组不相交段时，'contiguous'是'false'。
                bool GetContiguous() const noexcept;

		  ControllerInterfaceSharedPtr Clone() const override;
                ObjectInterfaceSharedPtr CloneObject() const override;
	private:
		// 当前活动线段的数量
		int m_NumSegments;		
 
		// 折线是连续或不相交的线段
		bool m_Contiguous;
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(Polysegment);
#include STSTEM_WARNING_POP
        CORE_TOOLS_SHARED_PTR_DECLARE(   Polysegment);
}

#endif // RENDERING_SCENE_GRAPH_POLYSEGMENT_H
