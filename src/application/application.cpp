#include "application.h"
#include "output_setup.h"

void Application::RunProgram(size_t mode) {
  if (mode == kConsoleMode) {
    OutputSetup::SetupTwoStreamsForOutput();
  }

  launcher_.RunInitialScreen();
}
