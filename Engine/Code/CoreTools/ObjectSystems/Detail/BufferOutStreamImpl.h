// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:31)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

namespace CoreTools
{
	// дobjects���ڴ�顣������ʧ��ʱ���׳�Error�쳣��
	class CORE_TOOLS_HIDDEN_DECLARE BufferOutStreamImpl : private boost::noncopyable
	{
	public:
		using ClassType = BufferOutStreamImpl;
		using FileBufferPtr = std::shared_ptr<FileBuffer>;

	public:
		explicit BufferOutStreamImpl(const OutTopLevel& topLevel);

		CLASS_INVARIANT_DECLARE;

		FileBufferPtr GetBufferOutStreamInformation() const;

	private:
		using BufferTargetPtr = std::shared_ptr<BufferTarget>;

	private:
		void GenerateBuffer();
		void Register();
		int GetBufferSize();
		void ResetBufferSize(int bufferSize);
		void SaveToBuffer();

	private:
		// ������������
		OutTopLevel m_TopLevel;

		// �洢objects���Զ������ʹ��ͼ��������ȱ�����
		ObjectRegister m_ObjectRegister;

		FileBufferPtr m_BufferPtr;
		BufferTargetPtr m_TargetPtr;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_OUT_STREAM_IMPL_H
