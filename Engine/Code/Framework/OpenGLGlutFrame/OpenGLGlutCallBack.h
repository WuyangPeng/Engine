// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:18)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_H

#include "OpenGLGlutCallBackInterface.h"
#include "CoreTools/Time/CustomTime.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

namespace Framework
{
	template <typename ModelViewControllerMiddleLayerContainer>
	class OpenGLGlutCallBack : public OpenGLGlutCallBackInterface
	{
	public:
		typedef ModelViewControllerMiddleLayerContainer MiddleLayerType;
		typedef OpenGLGlutCallBack<MiddleLayerType> ClassType;
		typedef OpenGLGlutCallBackInterface ParentType;

	public:
		OpenGLGlutCallBack();
		virtual ~OpenGLGlutCallBack();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool RenderScene();
		virtual bool ChangeSize(int width, int height);
		virtual bool SpecialKeysDown(int key,int xCoordinate,int yCoordinate);
		virtual bool KeyboardDown(unsigned char key,int xCoordinate,int yCoordinate);
		virtual bool SpecialKeysUp(int key,int xCoordinate,int yCoordinate);
		virtual bool KeyboardUp(unsigned char key,int xCoordinate,int yCoordinate);
		virtual bool MotionFunction(int xCoordinate,int yCoordinate);
		virtual bool PassiveMotion(int xCoordinate,int yCoordinate);
		virtual bool MouseClick(int button,int state,int xCoordinate,int yCoordinate);
		virtual bool TimerFunction(TimerFunctionCallback callback);
		virtual bool IdleFunction();
		virtual bool ProcessMenu(int menuValue);
		virtual void DestroyWindow();

	private:
		typedef std::shared_ptr<MiddleLayerType> MiddleLayerTypePtr;

	private:
		void SetGLUTModifiers(int button,int state);

	private:
		MiddleLayerTypePtr m_MiddleLayerPtr;
		CoreTools::CustomTime m_LastTime;
		VirtualKeysTypes m_GLUTModifiers;
		MouseButtonsTypes m_Button;
	};
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_H
