#ifndef _H_PUNK_APPLICATION
#define _H_PUNK_APPLICATION

#include "../config.h"

namespace System
{

	class PUNK_ENGINE Application : public Singletone(Application)
	{
	protected:
		//Render::SceneRender m_render;
		GUI::Manager* m_user_interface;
		OpenGL::Driver* m_video_driver;
	//	Scene::SceneGraph m_scene_graph;
		System::Timer m_timer;	

		void Step(System::Event* event);
		void Render();
		
		//
		//	to perform speed up and slow down	
		//
		__int64 m_time_scale_nominator;
		__int64 m_time_scale_denomiator;

	public:
		Application();
		void Init();
		Window* GetWindow();
		EventManager* GetEventManager();
		OpenGL::Driver* GetDriver();
		//GUI::Manager* GetUserInterface();

		int Run();
		~Application();

		virtual void OnStep (__int64 dt);
		virtual void OnInit ();		

		void SetTimeScale(__int64 nominator, __int64 denominator);
	};
}

#endif