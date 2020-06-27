// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 10:50)

#ifndef RENDERING_RESOURCES_BUFFER_H
#define RENDERING_RESOURCES_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "VertexFormat.h"
#include "Flags/BufferFlags.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/MemoryTools/ThirdSubclassSmartPointer.h"
#include "CoreTools/MemoryTools/ConstThirdSubclassSmartPointer.h"

RENDERING_EXPORT_SHARED_PTR(BufferImpl);

namespace CoreTools
{
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE Buffer : public CoreTools::Object
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(Buffer);
		using ParentType = Object;
		using BufferSmartPointer = CoreTools::ThirdSubclassSmartPointer<ClassType>;
	    using ConstBufferSmartPointer = CoreTools::ConstThirdSubclassSmartPointer<ClassType>;
		using ReadFileManager = CoreTools::ReadFileManager;
		using WriteFileManager = CoreTools::WriteFileManager;

	public:
		Buffer ();
		Buffer (int numElements, int elementSize, BufferUsage usage);
		virtual ~Buffer () = 0;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

				
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Buffer); 

		int GetNumElements () const;
		int GetElementSize () const;
		BufferUsage GetUsage () const;

		// Ӧ�ó��������Ҫ��ͬ�����Ļ�Ծ������ʹ������������á�
		// �����ı����ݴ洢,ֻ�ı仺������m_NumElements��Ա��
		// �����߸��𱣴��ԭʼ���������͵��������������ʱ���á�
		// �����߻���Ӧ�ô����ԭ�������������������������
		void SetNumElements (int numElements);
		
		// ������ϵͳ�ڴ滺�����ĸ�����
		// ��ѯϵͳ�ڴ������IndexBuffer��VertexBuffer��
		// GetData()������Ӧ�÷���ֻ�����ݡ�
		// ��Ӧ��ת������char*����д���ݣ�������Ⱦ������֪�������ѱ��޸ġ�
		int GetNumBytes () const;
		const char* GetReadOnlyData () const;
		const char* GetReadOnlyData(int index) const;

		void SetNewData(const std::vector<char>& newData);

	protected:
		void SaveBufferDataToFile(WriteFileManager& outFile) const;
		void ReadBufferDataFromFile(ReadFileManager& inFile);
		void SaveHeadToFile(WriteFileManager& outFile) const;
		void ReadHeadFromFile(ReadFileManager& inFile);
		void ReadBufferDataFromFile(ReadFileManager& inFile,const ConstVertexFormatSmartPointer& vertexformat);
		void SaveBufferDataToFile(WriteFileManager& outFile,const ConstVertexFormatSmartPointer& vertexformat) const;

		char* GetAccessWriteData(int index);
			
	private:
		IMPL_TYPE_DECLARE(Buffer);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(Buffer); 
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, Buffer); 
}

#endif // RENDERING_RESOURCES_BUFFER_H
