#include "core/player.h"

#include "utils/debug.h"
using namespace Debug;
using Level = DebugLogger::Level;

int main(int argc, char const* argv[]) {
    initLog();

    Log("debug test", Level::INFO);

    closeLog();

    return 0;
}
