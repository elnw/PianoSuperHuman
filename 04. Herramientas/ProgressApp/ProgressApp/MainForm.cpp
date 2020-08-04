#include "MainForm.h"

using namespace ProgressApp;

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew MainForm());
	return 0;
}

