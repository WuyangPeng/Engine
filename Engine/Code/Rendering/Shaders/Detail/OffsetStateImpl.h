// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 14:33)

#ifndef RENDERING_SHADERS_OFFSET_STATE_IMPL_H
#define RENDERING_SHADERS_OFFSET_STATE_IMPL_H

#include "Rendering/RenderingDll.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE OffsetStateImpl
	{
	public:
		using ClassType = OffsetStateImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
                OffsetStateImpl() noexcept;

		CLASS_INVARIANT_DECLARE;

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const; 

		bool IsFillEnabled() const;
		bool IsLineEnabled() const;
		bool IsPointEnabled() const;
		float GetScale() const;
		float GetBias() const;

		void SetFillEnabled(bool fillEnabled);
		void SetLineEnabled(bool lineEnabled);
		void SetPointEnabled(bool pointEnabled);
		void SetScale(float scale);
		void SetBias(float bias);

		void SaveState(WriteFileManager& manager) const;
		void LoadState(ReadFileManager& manager);

	private:	
		// �����Ƿ�Ӧ��Ϊ���ֶ���λ�ͼģʽ����䣬�ߣ��㣩����ƫ�ơ�
		bool m_FillEnabled; // Ĭ��: false
		bool m_LineEnabled; // Ĭ��: false
		bool m_PointEnabled; // Ĭ��: false
		
		// ƫ������Scale * dZ + Bias * r��
		// ����DZ������ھ���Ļ�ռ�������ȵı仯��
		// r����С�ɷֱ���Ȳ��졣��ֵ��ʾ�ƶ�����νӽ��۾���
		float m_Scale; // Ĭ��: 0
		float m_Bias; // Ĭ��: 0
	}; 
}

#endif // RENDERING_SHADERS_OFFSET_STATE_IMPL_H
