// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 10:51)

#ifndef RENDERING_RESOURCES_INDEX_BUFFER_H
#define RENDERING_RESOURCES_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"

namespace Rendering
{	
	class RENDERING_DEFAULT_DECLARE IndexBuffer : public Buffer
	{
	public:
		using ClassType = IndexBuffer;
		using ParentType = Buffer;
		using IndexBufferSmartPointer = CoreTools::FourthSubclassSmartPointer<ClassType>;
		using ConstIndexBufferSmartPointer = CoreTools::ConstFourthSubclassSmartPointer<ClassType>;
		using ClassShareType = CoreTools::CopyUnsharedClasses;

	public:
		IndexBuffer ();
		IndexBuffer (int numIndices, int indexSize,BufferUsage usage = BufferUsage::Static);
		virtual ~IndexBuffer (); 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
				
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(IndexBuffer); 

		// ������ƫ������ʹ������Ⱦ�����ơ�
		// ����������������ڶ������ͼԪ��������������ʱ����,
		// ÿ����Ԫʹ��һ������������
		// �����������,Ӧ�ó������ÿһ������Ԫ�ض�̬����SetNumElements��SetOffset��
		void SetOffset (int offset);
		int GetOffset () const;

		void SaveToFile(WriteFileManager& outFile) const;
		void ReadFromFile(ReadFileManager& inFile);

		virtual IndexBufferSmartPointer Clone() const;

		void InitIndexBuffer();
		void InitIndexBufferInParticles();
		void InitIndexBufferInRectangle(int index, int firstRectangleIndex, int secondRectangleIndex, int thirdRectangleIndex,int fourthRectangleIndex);
		void InitIndexBufferInDisk(int radialSamplesMinus1, int shellSamplesMinus1);
		void InitIndexBuffer(const std::vector<int> indices);

		void SetIndexBuffer(int index, int original, int current);

	private:
		int m_Offset;
	};

	CORE_TOOLS_STREAM_REGISTER(IndexBuffer);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, IndexBuffer); 
}

#endif // RENDERING_RESOURCES_INDEX_BUFFER_H

