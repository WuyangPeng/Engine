// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 09:42)

#ifndef RENDERING_RESOURCES_BUFFER_PARAMETER_H
#define RENDERING_RESOURCES_BUFFER_PARAMETER_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE BufferParameter
	{
	public:
		using ClassType = BufferParameter;

	public:	
		BufferParameter();
		BufferParameter(int offset, int componentSize, int numComponents);

		CLASS_INVARIANT_DECLARE;
		
		void Set(int offset, int componentSize, int numComponents);

		int GetOffset() const;
		int GetComponentSize() const;
		int GetNumComponents() const;
		
	private:
		int m_Offset;
		int m_ComponentSize;
		int m_NumComponents;
	};
}

#endif // RENDERING_RESOURCES_BUFFER_PARAMETER_H
