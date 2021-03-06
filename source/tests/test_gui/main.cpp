#include "../../punk_engine.h"

System::Proxy<Scene::SceneGraph> scene;

bool m_left_down = false;

OpenGL::SimpleRender render;
Scene::BoundingVolumeUpdater updater;

float x = 0;
float y = 0;

void OnMouseLeftButtonDown(System::Event* ee)
{
	m_left_down = true;
}

void OnMouseLeftButtonUp(System::Event* ee)
{
	m_left_down = false;
}

void OnMouseMove(System::Event* ee)
{
	System::MouseMoveEvent* e = static_cast<System::MouseMoveEvent*>(ee);

	//if (m_left_down)
	{
		x += 0.001 * (float)(e->x - e->x_prev);
		y += 0.001 * (float)(e->y - e->y_prev);		
		if (scene.IsValid())
		{
			System::Proxy<Virtual::FirstPersonCamera> c = scene->GetCameraNode()->GetCamera();
			c->SetYawRollPitch(x, y, 0);
		}
	}
}

void OnKeyDown(System::Event* ee)
{
	System::KeyDownEvent* e = static_cast<System::KeyDownEvent*>(ee);
	switch (e->key)
	{
	case System::PUNK_KEY_F5:
		{
			if (scene.IsValid())
			{
				std::ofstream stream("scene.save", std::ios_base::binary);
				scene->Save(stream);
			}
		}
		break;
	case System::PUNK_KEY_F9:
		{				
			scene.Reset(new Scene::SceneGraph);
			std::ifstream stream("scene.save", std::ios_base::binary);
			scene->Load(stream);
			render.SetScene(scene);
		}
	default:
		break;
	}
}

void Idle(System::Event*)
{		
	updater.Update();
	render.Render();
	if (scene.IsValid())
	{
		System::Proxy<Virtual::FirstPersonCamera> c = scene->GetCameraNode()->GetCamera();
		if (System::Keyboard::Instance()->GetKeyState(System::PUNK_KEY_A))
			c->SetPosition(c->GetPosition() + c->GetRightVector() * -0.01f);
		if (System::Keyboard::Instance()->GetKeyState(System::PUNK_KEY_D))
			c->SetPosition(c->GetPosition() + c->GetRightVector() * 0.01f);
		if (System::Keyboard::Instance()->GetKeyState(System::PUNK_KEY_W))
			c->SetPosition(c->GetPosition() + c->GetDirection() * 0.01f);
		if (System::Keyboard::Instance()->GetKeyState(System::PUNK_KEY_S))
			c->SetPosition(c->GetPosition() + c->GetDirection() * -0.01f);
	}
		
	//OpenGL::Driver* d = OpenGL::Driver::Instance();
	//OpenGL::RenderPass* pass = new OpenGL::RenderPass;
	//Math::mat4 m = Math::mat4::CreateRotation(1, 0, 0, y)*Math::mat4::CreateRotation(0, 1, 0, x);;
	//Render::SolidObjectRender::Parameters p(*m_object, &camera,pass, &m);
	//
	//pass->SetRenderTarget(rt);
	//render->Render(&p);
	//frame.Begin();
	//frame.AddRenderPass(pass);
	//frame.End();	
}

int main()
{
	System::GetFactory()->Init();

	System::Window::Instance()->SetTitle(L"OpenGL object test");
	System::Mouse::Instance()->LockInWindow(false);
	OpenGL::Driver::Instance()->Start();

	System::EventManager::Instance()->SubscribeHandler(System::EVENT_IDLE, System::EventHandler(Idle));
	System::EventManager::Instance()->SubscribeHandler(System::EVENT_MOUSE_LBUTTON_DOWN, System::EventHandler(OnMouseLeftButtonDown));
	System::EventManager::Instance()->SubscribeHandler(System::EVENT_MOUSE_LBUTTON_UP, System::EventHandler(OnMouseLeftButtonUp));
	System::EventManager::Instance()->SubscribeHandler(System::EVENT_MOUSE_MOVE, System::EventHandler(OnMouseMove));
	System::EventManager::Instance()->SubscribeHandler(System::EVENT_KEY_DOWN, System::EventHandler(OnKeyDown));

	//scene = System::GetFactory()->CreateFromTextFile(System::Environment::Instance()->GetModelFolder() + L"engineer4.pmd");

	System::Proxy<GUI::Widget> widget(new GUI::Widget(0.1, 0.1, 0.4, 0.4));
	widget->FixPosition(false);
	GUI::Manager::Instance()->AddRootWidget(widget);
	widget->SetText(L"Hello world!");

	System::Proxy<GUI::Widget> widget2(new GUI::Widget(0.2, 0.2, 0.4, 0.4, L"³���, ����������!", widget));
	widget2->FixPosition(false);
	widget->Add(widget2);

	render.SetGUIHud(widget);
	render.SetScene(scene);
	updater.SetScene(scene);

	System::Window::Instance()->Loop(); 

	return 0;
}
