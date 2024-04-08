#include "Celestine/Application.h"
#include "Celestine/EntryPoint.h"

#include "Celestine/Image.h"

class ExampleLayer : public Celestine::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Hello");
		ImGui::Button("Button");
		ImGui::End();

		ImGui::ShowDemoWindow();
	}
};

Celestine::Application* Celestine::CreateApplication(int argc, char** argv)
{
	Celestine::ApplicationSpecification spec;
	spec.Name = "Celestine Example";

	Celestine::Application* app = new Celestine::Application(spec);
	app->PushLayer<ExampleLayer>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}
