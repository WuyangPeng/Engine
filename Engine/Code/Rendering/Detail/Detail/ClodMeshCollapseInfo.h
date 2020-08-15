// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 10:18)

#ifndef RENDERING_DETAIL_CLOD_MESH_COLLAPSE_INFO_H
#define RENDERING_DETAIL_CLOD_MESH_COLLAPSE_INFO_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
	// 有关塌边的信息。
	class RENDERING_HIDDEN_DECLARE ClodMeshCollapseInfo
	{
	public:
		using ClassType = ClodMeshCollapseInfo;

	public:
		ClodMeshCollapseInfo(int vKeep = -1, int vThrow = -1) noexcept;

		CLASS_INVARIANT_DECLARE;

		int GetVKeep() const noexcept;
		void SetVKeep(int vKeep) noexcept;
		int GetVThrow() const noexcept;
		void SetVThrow(int vThrow) noexcept;
		int GetTThrow0() const noexcept;
		void SetTThrow0(int tThrow0) noexcept;
		int GetTThrow1() const noexcept;
		void SetTThrow1(int tThrow1) noexcept;

	private:	
		int m_VKeep;
		int m_VThrow;
		int m_TThrow0;
		int m_TThrow1;
	};
}

#endif // RENDERING_DETAIL_CLOD_MESH_COLLAPSE_INFO_H
