#include <fstream>
#include <iostream>

#include "Engine.h"


int main() {
    gngr::Engine engine;
    engine.Initialize();
    engine.Run();
    engine.Shutdown();
    return 0;
}
